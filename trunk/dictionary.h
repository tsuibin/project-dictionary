#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

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

private slots:
    void on_SearchButton_clicked();
};

#endif // DICTIONARY_H
