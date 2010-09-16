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
#define N 1024
#define M 500

namespace Ui {
    class dictionary;
}

class dictionary : public QWidget,public QXmlDefaultHandler
{
    Q_OBJECT

public:
    dictionary(QWidget *parent = 0);
    //int myfunc(const char *pathname, const struct stat *statptr, int type);
    int read_dir(QString dir);
    bool load_dic(QString str);
    void keyPressEvent(QKeyEvent *k);
    ~dictionary();
    QSqlDatabase db;
    QSqlQuery *query;
    QString Text;

protected:
    bool startElement(const QString &namespaceURI,const QString &localName,
                      const QString &qName,const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI,const QString &localName,const QString &qName);
    bool characters(const QString &ch);
    bool fatalError(const QXmlParseException &exception);
private:
    Ui::dictionary *ui;
    QString var;
    QTimer *timer;
    QToolBar *mainToolBar;
    QNetworkAccessManager *manager;
    QString word_selected;
//    QDomDocument doc;
    QXmlInputSource inputSource;
    QXmlSimpleReader reader;

    QString node_name;

private slots:
    void on_WebSearchButton_clicked();
    void on_pushButton_clicked();
    void on_WordIput_textEdited(QString );
    void on_listWidget_itemClicked(QListWidgetItem* item);
    void timeout_slot();
    void replyFinished(QNetworkReply* reply);
};

#endif // DICTIONARY_H
