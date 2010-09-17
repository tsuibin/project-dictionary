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
#include "hand_wdialog.h"

namespace Ui {
    class dictionary;
}

class dictionary : public QWidget
{
    Q_OBJECT

public:
    dictionary(QWidget *parent = 0);
    int read_dir(QString dir);
    bool load_dic(QString str);
    void keyPressEvent(QKeyEvent *k);
    ~dictionary();
    QSqlDatabase db;
    QSqlQuery *query;
    QString Text;
    hand_wdialog mydialog;
    void get_handinput(QString);

private:
    Ui::dictionary *ui;
    QString var;
    QTimer *timer;
    QToolBar *mainToolBar;
    QNetworkAccessManager *manager;
    QString word_selected;
    QDomDocument doc;
    QXmlInputSource inputSource;
    QXmlSimpleReader reader;
    char isCN;
    QString node_name;

private slots:
    void on_handw_input_clicked();
    void on_WebSearchButton_clicked();
    void on_pushButton_clicked();
    void on_WordIput_textEdited(QString );
    void on_listWidget_itemClicked(QListWidgetItem* item);
    void timeout_slot();
    void replyFinished(QNetworkReply* reply);
};

#endif // DICTIONARY_H
