#ifndef HAND_WDIALOG_H
#define HAND_WDIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QTimer>
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
//    dictionary dic;

private:
    Ui::hand_wdialog *ui;
    QPixmap pix;
    QPixmap pix1;
    QPoint lastPoint;
    QPoint endPoint;
    QList<QPoint> last_list;
    QList<QPoint> end_list;
    zinnia::Recognizer *recognizer;
    zinnia::Character *character;
    zinnia::Result *result;
    QTimer *timer;


private slots:
//    void on_wordlist_itemClicked(QListWidgetItem* item);
    void on_clearbt_clicked();
    void timeout_slot();
};

#endif // HAND_WDIALOG_H
