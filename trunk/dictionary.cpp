#include <QtSql/QSqlDatabase>
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
    db.setHostName("localhost");
    db.setDatabaseName("dic.db");
    db.setUserName("root");
    db.setPassword("dearmoe");
    if(!db.open()) //打开数据库
    {
        QMessageBox::warning(this,tr("waring"),tr("open db fiale!"),QMessageBox::Yes,QMessageBox::Yes);
    }
    query = new QSqlQuery(db);
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
    QString tmp;
    while(query->next())
    {
        //tmp += query.value(1).toString() + " ";
        tmp += query->value(2).toString() + " ";
        tmp += query->value(3).toString() + " ";
        tmp += query->value(4).toString() + " ";
        tmp += "\r\n";
    }
    ui->MeanBrowser->setText(tmp);
}
