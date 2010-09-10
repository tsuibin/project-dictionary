#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QListWidgetItem>
#include <QTimer>
#include <QToolBar>
#define N 1024
#define M 500

namespace Ui {
    class dictionary;
}

class dictionary : public QWidget
{
    Q_OBJECT

public:
    dictionary(QWidget *parent = 0);
    //int myfunc(const char *pathname, const struct stat *statptr, int type);
    int read_dir(QString dir);
    bool load_dic(QString str);
    ~dictionary();
    QSqlDatabase db;
    QSqlQuery *query;

private:
    Ui::dictionary *ui;
    QString var;
    QTimer *timer;
    QToolBar *mainToolBar;

private slots:
    void on_pushButton_clicked();
    void on_WordIput_textEdited(QString );
    void on_listWidget_itemClicked(QListWidgetItem* item);
    void on_SearchButton_clicked();
    void timeout_slot();

};

#endif // DICTIONARY_H
