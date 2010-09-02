#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QDebug>
#include <QtGui>

#include "dictionary.h"
#include "ui_dictionary.h"

dictionary::dictionary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dictionary)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("topsvr.com");
    db.setDatabaseName("/home/huguohu/term4/0831/dic.db");
    db.setUserName("");
    db.setPassword("");
}

dictionary::~dictionary()
{
    delete ui;
    db.close();
}

void dictionary::on_SearchButton_clicked()
{
    QSqlQuery query;
    QString w;
    QString sql;
    if(!db.open()) //打开数据库
    {
        QMessageBox::warning(this,tr("waring"),tr("open db fiale!"),QMessageBox::Yes,QMessageBox::Yes);
        //QMessageBox::warning(this,tr(“Warning”),tr(“open db fiale!”),QMessageBox::Yes);
    }
    sql.append("select * from dicc where word ='");
    w = ui->WordIput->text();
    sql.append(w);
    sql.append("';");
    query.exec(sql);
    while(query.next())
    {
        QString ele1 = query.value(1).toString();
        QString ele2 = query.value(2).toString();
        QString ele3 = query.value(3).toString();
        ui->WordBrowser<<ele1<<ele2<<ele3 ;
    }
}
