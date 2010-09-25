#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QListWidgetItem>
#include <QTimer>
#include <QToolBar>
#include <QtNetwork/QNetworkAccessManager>
#include <QtXml>
#include <QXmlDefaultHandler>
#include "addic_thread.h"

namespace Ui {
    class dictionary;
}

class dictionary : public QWidget
{
    Q_OBJECT

public:
    dictionary(QWidget *parent = 0);
    int read_dir(QString dir);
    void keyPressEvent(QKeyEvent *k);
    ~dictionary();
    QSqlDatabase db;
    QSqlQuery *query;
    QString Text;
    void on_WebSearchButton_clicked();
    void closeEvent(QCloseEvent *event);
    bool load_dic(QString);

private:
    Ui::dictionary *ui;
    QString var;
    QTimer *timer;
    QToolBar *mainToolBar;
    QNetworkAccessManager *manager;
    QString word_selected;
    QDomDocument doc;
    char isCN;
    QString node_name;
    QStringList sound_url;
    QProcess *myprocess;



signals:
    void openHanw();
    void dic_window_close();
//    void add_isclicked(QSqlDatabase db,QSqlQuery *query);

public slots:
    void insertWord(QString word);  
private slots:
    void on_soundbt_clicked();
    void on_handw_input_clicked();
    void on_pushButton_clicked();
    void on_WordIput_textEdited(QString );
    void on_listWidget_itemClicked(QListWidgetItem* item);
    void timeout_slot();
    void replyFinished(QNetworkReply* reply);


};

#endif // DICTIONARY_H
