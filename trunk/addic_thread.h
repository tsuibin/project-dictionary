#ifndef ADDIC_THREAD_H
#define ADDIC_THREAD_H

#include <QThread>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class addic_thread : public QThread
{
    Q_OBJECT
public:
    addic_thread(QObject *parent = 0);
    addic_thread(QSqlDatabase tmp_db,QSqlQuery *tmp_query,QObject *parent = 0);

protected:
    void run();
public slots:
//    void open_adDialog(QSqlDatabase tmp_db,QSqlQuery *tmp_query);
private:
    bool load_dic(QString);
    QSqlDatabase db1;
    QSqlQuery *query1;

};

#endif // ADDIC_THREAD_H
