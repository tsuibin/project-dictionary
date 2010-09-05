#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QListWidgetItem>
#include <QTimer>

namespace Ui {
    class dictionary;
}

class dictionary : public QWidget
{
    Q_OBJECT

public:
    dictionary(QWidget *parent = 0);
    ~dictionary();
    QSqlDatabase db;

private:
    Ui::dictionary *ui;
    QSqlQuery *query;
    QString var;
    QTimer *timer;
    //void on_timeout_search1();

private slots:
    void on_WordIput_textEdited(QString );
    void on_listWidget_itemClicked(QListWidgetItem* item);
    void on_SearchButton_clicked();
    void timeout_slot();

};

#endif // DICTIONARY_H
