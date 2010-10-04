#ifndef COMMUNICAT_H
#define COMMUNICAT_H

#include <QObject>
#include "dictionary.h"
#include "hand_wdialog.h"
#include "set_dialog.h"

class communicat : public QObject
{
    Q_OBJECT
public:
    explicit communicat(QObject *parent = 0);
    void start();
    dictionary dic;
    hand_wdialog hand_w;
    set_Dialog set;
private:
    int dic_w;
    int dic_h;
    int dic_set_w;
    int dic_set_h;

    QSettings *sys_setting;

signals:
    void sendWord(QString);

public slots:
    void set_windowColor(QColor);
    void set_dictionary_wid(int);
    void set_dictionary_height(int);
    void set_all_tm(int);
    void sys_init();
};

#endif // COMMUNICAT_H
