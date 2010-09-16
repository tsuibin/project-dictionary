#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QtGui>
#include <QTimer>
#include <qfiledialog.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtXml>
#include <QXmlDefaultHandler>
#include "dictionary.h"
#include "ui_dictionary.h"


dictionary::dictionary(QWidget *parent) :
    QWidget(parent),QXmlDefaultHandler(),
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
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
}

dictionary::~dictionary()
{
    delete ui;
    db.close();
}


void dictionary::on_listWidget_itemClicked(QListWidgetItem* item)
{
    QString sql;
    this->word_selected = item->text();
    ui->WordIput->setText(this->word_selected);
    sql = "select * from dicc where word='" + this->word_selected+"';";
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
    QString sql;
    ui->listWidget->clear();
    if(!var.isEmpty())
    {
        sql = "select * from dicc where word like '" + var + "%';";
        qDebug()<<sql;
        query->exec(sql);
        QString tmp1;
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
            this->word_selected = ui->listWidget->item(0)->text();
            sql = "select * from dicc where word='"+this->word_selected+"';";
            query->exec(sql);
            query->next();
            tmp1 = "["+query->value(3).toString()+"]"+"\r\n";
            tmp1 +=query->value(4).toString()+"\r\n";
            ui->MeanBrowser->setText(tmp1);
        }
        else
        {
            ui->MeanBrowser->setText(tr("对不起，没有你找的单词！"));
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
    //this->timeout_slot();
    ui->MeanBrowser->append(tr("<font='title' color= red> <-金山词霸-> </font>"));
    QString str="http://dict-co.iciba.com/api/dictionary.php?w=";
    str += this->word_selected;
    qDebug()<<str;
    manager->get(QNetworkRequest(QUrl(str)));

}
void dictionary::replyFinished(QNetworkReply *reply)
{
    QTextCodec* gbk_codec = QTextCodec::codecForName("utf8");
    QString str = gbk_codec->toUnicode(reply->readAll().data());
    qDebug()<<str;
//    doc.setContent(str);
//    QDomElement docElem = doc.documentElement();
//    QDomNode n = docElem.firstChild();
//    qDebug()<<n.toElement().text();
//    while(!n.isNull())
//    {
////        qDebug()<<n.hasChildNodes();
//        if(n.firstChild().isNull())
//        {
//            qDebug()<<"n.firstChild().isNull()"+n.firstChild().isNull();
//        }
//        else if(n.toElement().tagName().compare("ps") == 0)
//        {
//            ui->MeanBrowser->append("["+n.toElement().text()+"]");
//        }
//        else
//        {
//            ui->MeanBrowser->append(n.toElement().text());
//            qDebug()<<n.toElement().text();
//        }
//        n = n.nextSibling();
//    }


    inputSource.setData(str);
    reader.setContentHandler(this);
    reader.setErrorHandler(this);
    reader.parse(inputSource);

}

bool dictionary::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    node_name = qName;
    qDebug()<<node_name;
    return true;
}

bool dictionary::characters(const QString &ch)
{
    QString tmp = ch;
    if(!node_name.contains("pron"))
    {
//        Text.clear();
//        Text = ch;
//        qDebug()<<"Text:"+Text;
//        const QString tmp = Text;
        ui->MeanBrowser->append(tmp);
    }
}

bool dictionary::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    return true;
}

bool dictionary::fatalError(const QXmlParseException &exception)
{
    qDebug()<<exception.message();
    return false;
}
