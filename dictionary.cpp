#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QtGui>
#include <QTimer>
#include <qfiledialog.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtXml>
#include <QXmlDefaultHandler>
#include "dictionary.h"
#include "ui_dictionary.h"


dictionary::dictionary(QWidget *parent) :
    QWidget(parent),/*QXmlDefaultHandler(),*/
    ui(new Ui::dictionary)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("dic.db");
    db.setUserName("root");
    db.setPassword("dearmoe");
    if(!db.open())
    {
        QMessageBox::warning(this,tr("waring"),tr("open db faile!"),QMessageBox::Yes,QMessageBox::Yes);
    }
    query = new QSqlQuery(db);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    connect(&mydialog,SIGNAL(sendWord(QString)),
            this,SLOT(insertWord(QString)));
}

dictionary::~dictionary()
{
    delete ui;
    db.close();
}


void dictionary::on_listWidget_itemClicked(QListWidgetItem* item)
{
    QString sql,temp;
    this->word_selected = item->text();
    ui->WordIput->setText(this->word_selected);
    if(isCN == 'N')
    {
        sql = "select * from dicc where word='" + this->word_selected+"';";
        query->exec(sql);
        query->next();
        temp += "["+query->value(3).toString()+"]"+"\n";
        temp += query->value(4).toString()+"\n";
        ui->MeanBrowser->setText(temp);

    }
    else
    {
        sql = "select * from dicc where mean='" + this->word_selected+"';";
//        qDebug() <<sql;
        query->exec(sql);
        query->next();
        temp += "["+query->value(3).toString()+"]"+"\n";
        temp += query->value(2).toString()+"\n";
        ui->MeanBrowser->setText(temp);
        this->word_selected = query->value(2).toString();
    }
    on_WebSearchButton_clicked();
}

void dictionary::timeout_slot()
{
    QString sql;
    ui->listWidget->clear();
    if(!var.isEmpty())
    {
        QStringList strlist;
        QString tmp1;
       if((var.at(0) >= 'A' && var.at(0) <= 'Z') ||(var.at(0) >= 'a' && var.at(0) <= 'z'))
       {
           isCN = 'N';
            sql = "select * from dicc where word like '" + var + "%';";
            query->exec(sql);
            while(query->next())
            {
                tmp1 = query->value(2).toString();
                if(!strlist.contains(tmp1))
                strlist.append(tmp1);
            }
       }
       else
       {
           isCN = 'Y';
            sql = "select * from dicc where mean like '" + var + "%';";
            query->exec(sql);
            while(query->next())
            {
                tmp1 = query->value(4).toString();
                if(!strlist.contains(tmp1))
                strlist.append(tmp1);
            }
       }
        qDebug()<<sql;
        ui->listWidget->addItems(strlist);
        tmp1.clear();

        if(ui->listWidget->item(0) != 0)
        {
            this->word_selected = ui->listWidget->item(0)->text();
            if(isCN == 'N')
            {
                sql = "select * from dicc where word='"+this->word_selected+"';";
                query->exec(sql);
                query->next();
                tmp1 = "["+query->value(3).toString()+"]"+"\n";
                tmp1 +=query->value(4).toString()+"\n";
                ui->MeanBrowser->setText(tmp1);
            }
            else
            {
                sql = "select * from dicc where mean='"+this->word_selected+"';";
                qDebug()<<sql;
                query->exec(sql);
                query->next();
                tmp1 = "["+query->value(3).toString()+"]"+"\n";
                tmp1 +=query->value(2).toString()+"\n";
                ui->MeanBrowser->setText(tmp1);
                this->word_selected = query->value(2).toString();
                qDebug()<<"this the word";
            }
            on_WebSearchButton_clicked();
        }
        else
        {
            ui->MeanBrowser->setText(tr("对不起，没有你找的单词！试试网络查询。"));
            this->word_selected = ui->WordIput->text();
        }
    }
    else
        ui->MeanBrowser->clear();
}

void dictionary::on_WordIput_textEdited(QString w)
{
    var = w;
    timer->stop();
    timer->setSingleShot(true);
    timer->start(500);
}

void dictionary::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_Enter)
    {
        this->timeout_slot();
    }
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

void dictionary::insertWord(QString word)
{
    ui->WordIput->clear();
    ui->WordIput->insert(word.trimmed());
    qDebug()<<ui->WordIput->text();
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
                            sql += w+"','";
                            sql += t+"','";
                        sql += m+"');";
                        query->exec(sql);
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


void dictionary::on_WebSearchButton_clicked()
{
    QString str="http://dict-co.iciba.com/api/dictionary.php?w=";
    str += this->word_selected;
    qDebug()<<str;
    manager->get(QNetworkRequest(QUrl(str)));
}
void dictionary::replyFinished(QNetworkReply *reply)
{
    QTextCodec* gbk_codec = QTextCodec::codecForName("utf8");
    QString str = gbk_codec->toUnicode(reply->readAll().data());
    if(!str.isEmpty())
    {
        ui->MeanBrowser->append(tr("<font color=red size=4> 金山词霸 </font>\n"));
        qDebug()<<str;
        doc.setContent(str);
        QDomElement docElem = doc.documentElement();
        QDomNode n = docElem.firstChild();
//        qDebug()<<n.toElement().text();
        while(!n.isNull())
        {
    //        qDebug()<<n.hasChildNodes();
//            qDebug()<<n.toElement().tagName()+"child";
            QString type1 = this->word_selected.replace(0,1,this->word_selected.at(0).toUpper());
            QString type2 = this->word_selected.replace(0,1,this->word_selected.at(0).toLower());
            if(!n.firstChild().toElement().tagName().isEmpty())
            {
                QDomNodeList list = n.childNodes();
                for(int i = 0; i < list.size();i++)
                {
                    QDomNode node = list.at(i);
                    if(node.isElement() && (!node.toElement().tagName().contains("pron")) && n.toElement().text().contains(type1))
                    {
                        QString temp = node.toElement().text().replace(type1,"<font color=blue>"+type1+"</font>");
                        ui->MeanBrowser->append(temp);
                    }
                    else if(node.isElement() && (!node.toElement().tagName().contains("pron")) && n.toElement().text().contains(type2))
                    {
                        QString temp = node.toElement().text().replace(type2,"<font color=blue>"+type2+"</font>");
                        ui->MeanBrowser->append(temp);
                    }
                    else if(node.isElement() && !node.toElement().tagName().contains("pron"))
                        ui->MeanBrowser->append(node.toElement().text());
                }
            }
            else if(n.toElement().tagName().compare("ps") == 0)
            {
                ui->MeanBrowser->append("["+n.toElement().text()+"]"+"<img src=/home/huguohu/term4/project-dictionary/laba.gif></img>");
            }
            else if(!n.toElement().tagName().contains("pron"))
            {
                if(n.toElement().text().contains(type1))
                {
                    qDebug()<<"type1"<<n.toElement().text();
                    QString temp = n.toElement().text().replace(type1,"<font color=blue>"+type1+"</font>");
                    ui->MeanBrowser->append(temp);
                }
                else if(n.toElement().text().contains(type2))
                {
                    qDebug()<<"type2"<<n.toElement().text();
                    QString temp = n.toElement().text().replace(type2,"<font color=blue>"+type2+"</font>");
                    ui->MeanBrowser->append(temp);
                }
                else
                    ui->MeanBrowser->append(n.toElement().text());
                qDebug()<<n.toElement().text();
            }
            n = n.nextSibling();
        }
    }
    else
    {
        ui->MeanBrowser->append(tr("<font color=blue size=3>>>网络查询失败</font>"));
    }
}

void dictionary::on_handw_input_clicked()
{
    mydialog.show();
    qDebug()<<"hand_w"<<mydialog.han_w;
//    this->ui->WordIput->setText(mydialog.han_w);
//    connect(this->mydialog.han_w,SIGNAL)
}

