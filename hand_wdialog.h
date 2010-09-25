#ifndef HAND_WDIALOG_H
#define HAND_WDIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QTimer>
#include <QListWidgetItem>
#include "zinnia.h"

namespace Ui {
    class hand_wdialog;
}

class hand_wdialog : public QDialog
{
    Q_OBJECT

public:
    explicit hand_wdialog(QWidget *parent = 0);
    ~hand_wdialog();
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    QString han_w;
//    dictionary dic;

private:
    Ui::hand_wdialog *ui;
    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;
    QList<QPoint> last_list;
    QList<QPoint> end_list;
    zinnia::Recognizer *recognizer;
    zinnia::Character *character;
    zinnia::Result *result;
    QTimer *timer;
signals:
    void sendWord(QString);

public slots:
    void on_wordlist_itemClicked(QListWidgetItem* item);
    void close_hanw();
private slots:
    void on_clearbt_clicked();
    void timeout_slot();
};

#endif // HAND_WDIALOG_H
