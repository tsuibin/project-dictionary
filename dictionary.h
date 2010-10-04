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
#include <QLayout>
#include <QSystemTrayIcon>
#include <QtGui>

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
    void dic_init();
    QDialog *exitDialog;
    QDialog *wordSaveDialog;
    void set_wordcolor(QColor);
    QFileDialog *fd;
    QWidget *translate;
    void word_sort(QString);


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
    QGridLayout *topLayout;
    QGridLayout *midLayout;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *mainLayout;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QRadioButton * closeButton;
    QRadioButton * miniButton;
    QPushButton * sureButton;
    QPushButton *button;
    void createActions();
    void createTrayIcon();
    void showMessage(QString msg);
    void dic_layout();
    void system_tray();
    void init_db();
    void init_translate();

signals:
    void openHanw();
    void dic_window_close();
    void set_open();

public slots:
    void insertWord(QString word);
    void exitDialogWindow();
private slots:
    void on_save_bt_clicked();
    void on_page_bt_clicked();
    void on_loaddic_bt_clicked();
    void on_sound_bt_clicked();
    void on_set_bt_clicked();
    void on_hwinput_bt_clicked();
    void on_WordIput_textEdited(QString );
    void on_listWidget_itemClicked(QListWidgetItem* item);
    void timeout_slot();
    void replyFinished(QNetworkReply* reply);
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

};

#endif // DICTIONARY_H
