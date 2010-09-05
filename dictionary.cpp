#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QtGui>
#include <QTimer>
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
}

dictionary::~dictionary()
{
    delete ui;
    db.close();
}

void dictionary::on_SearchButton_clicked()
{
    QString sql;
    sql = "select * from dicc where word like '" + ui->WordIput->text() + "%';";
    query->exec(sql);
    QString tmp1;
    while(query->next())
    {
        tmp1 = query->value(2).toString();
        ui->listWidget->addItem(tmp1);
    }
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
/*
void dictionary::on_WordIput_textChanged(QString w)
{
    QString sql;
    ui->listWidget->clear();
    sql = "select * from dicc where word like '" + w + "%';";
    query->exec(sql);
    QString tmp1;
    while(query->next())
    {
        //tmp += query.value(1).toString() + " ";
        tmp1 = query->value(2).toString();
        //tmp1 += "\r\n";
        ui->listWidget->addItem(tmp1);
    }
}
*/
void dictionary::timeout_slot()
{
    QString sql;
    ui->listWidget->clear();
    if(var != "")
    {
        sql = "select * from dicc where word like '" + var + "%';";
        qDebug()<<sql;
        query->exec(sql);
        QString tmp1;
        tmp1 = "";
        while(query->next())
        {
            tmp1 = query->value(2).toString();
            ui->listWidget->addItem(tmp1);
        }
    }
   // timer->stop();
}

void dictionary::on_WordIput_textEdited(QString w)
{
    var = w;
    timer->stop();
    timer->setSingleShot(true);
    timer->start(500);
}

