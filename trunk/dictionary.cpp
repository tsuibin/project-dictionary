#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QtGui>
#include <QTimer>
#include <qfiledialog.h>
//#include <fnmatch.h>
//#include <ftw.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <iostream>
#include "dictionary.h"
#include "ui_dictionary.h"


dictionary::dictionary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dictionary)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("dic.db");
    db.setUserName("root");
    db.setPassword("dearmoe");
    if(!db.open()) //打开数据库
    {
        QMessageBox::warning(this,tr("waring"),tr("open db faile!"),QMessageBox::Yes,QMessageBox::Yes);
    }
    query = new QSqlQuery(db);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));

    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));

}

dictionary::~dictionary()
{
    delete ui;
    db.close();
}

void dictionary::on_SearchButton_clicked()
{
    QString sql;
    ui->listWidget->clear();
    if(!var.isEmpty())
    {
        sql = "select * from dicc where word like '" + var + "%';";
        qDebug()<<sql;
        query->exec(sql);
        QString tmp1,str;
        //tmp1 = "";
        QStringList strlist;
        while(query->next())
        {
            tmp1 = query->value(2).toString();
            if(!strlist.contains(tmp1))
            strlist.append(tmp1);
        }
        ui->listWidget->addItems(strlist);

        if(ui->listWidget->item(0) != 0)
        {
            sql = "select * from dicc where word='"+ui->listWidget->item(0)->text()+"';";
            query->exec(sql);
            query->next();
            tmp1 = "["+query->value(3).toString()+"]"+"\r\n";
            tmp1 +=query->value(4).toString()+"\r\n";
            ui->MeanBrowser->setText(tmp1);
        }
        else
            ui->MeanBrowser->setText(tr("对不起，没有你找的单词！"));;
    }
    else
        ui->MeanBrowser->clear();
}

void dictionary::on_listWidget_itemClicked(QListWidgetItem* item)
{
    QString sql;

    sql = "select * from dicc where word='" + item->text()+"';";
    qDebug() <<sql;
    query->exec(sql);
    QString temp;
    query->next();
    temp += "["+query->value(3).toString()+"]"+"\r\n";
    temp += query->value(4).toString()+"\r\n";
    ui->MeanBrowser->setText(temp);
}

void dictionary::timeout_slot()
{
    on_SearchButton_clicked();
}

void dictionary::on_WordIput_textEdited(QString w)
{
    var = w;
    timer->stop();
    timer->setSingleShot(true);
    timer->start(500);
}


void dictionary::on_pushButton_clicked()
{
    QFileDialog *fd = new QFileDialog(this,"file dialog","/home/",NULL);
    fd->setModal(QFileDialog::DirectoryOnly);
    fd->setViewMode(QFileDialog::Detail);
    QDir filename;
    if(fd->exec()== QDialog::Accepted)
    {
        filename = fd->directory();
        load_dic(filename.absolutePath());
    }
    qDebug()<<filename.absolutePath();
}


bool dictionary::load_dic(QString path)
{
    int nFiles = 0;
    QDir dir(path);
    if (!dir.exists())
    return false;
    dir.setFilter(QDir::Dirs|QDir::Files);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList list = dir.entryInfoList();
    int i=0;
    do{
        QFileInfo fileInfo = list.at(i);
        if(fileInfo.fileName()=="."|fileInfo.fileName()=="..")
        {
            i++;
            continue;
        }
        bool bisDir=fileInfo.isDir();
        if(bisDir)
        {
            nFiles++;
          //  std::cout << qPrintable(QString("%1 %2 %3").arg(fileInfo.size(), 10).arg(fileInfo.fileName(),10).arg(fileInfo.path()))<<endl;

            load_dic(fileInfo.filePath());
        }
        else
        {
            nFiles++;
            if(fileInfo.fileName().endsWith(".bok"))
            {
                QString file_path;
                file_path = fileInfo.path()+"/"+fileInfo.fileName();
                QFile file(file_path);
                if(file.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&file);
                    QString line,sql;
                    line = stream.readLine();
                    QString id;
                    int a,b;
                    a = line.indexOf("[N]");
                    b = line.indexOf("[C]");
                    sql = "insert into dicname(dicname) values('"+line.mid(a+3,b-a-3)+"');";
                    query->exec(sql);
                    sql.clear();
                    sql = "select id from dicname where dicname='"+line.mid(a+3,b-a-3)+"';";
                    query->exec(sql);
                    query->next();
                    id = query->value(0).toString();
                    sql.clear();
                    while(!stream.atEnd())
                    {
                        line.clear();
                        line = stream.readLine();
                        int w_index,t_index,m_index;
                        QString w,t,m;
                        w_index = line.indexOf("[W]");
                        if(line.contains("[T]"))
                        {
                            t_index = line.indexOf("[T]");
                            m_index = line.indexOf("[M]");
                            t = line.mid(t_index+3,m_index-t_index-3);
                            w = line.mid(w_index+3,t_index-w_index-3);
                        }
                        else
                        {
                            t = "";
                            m_index = line.indexOf("[M]");
                            w = line.mid(w_index+3,m_index-w_index-3);
                        }
                            m = line.mid(m_index+3,line.length()-m_index-1);
                        sql = "insert into dicc(dicid,word,t,mean) values("+id+",'";
//                        if(w.contains("'"))
//                            sql += w.replace(0,1,'"')+"','";
//                        else
                            sql += w+"','";
//                        if(t.contains("'"))
//                            sql += t.replace(0,1,'"')+"','";
//                        else
                            sql += t+"','";
                        sql += m+"');";
                        query->exec(sql);
                       // qDebug()<<"insert dicc"<<sql;
                    }
                }
                file.close();
            }
        //    std::cout << qPrintable(QString("%1 %2 %3").arg(fileInfo.size(), 10).arg(fileInfo.fileName(),10).arg(fileInfo.path()))<<endl;
        }
        i++;
    }while(i<list.size());

    return true;
}

