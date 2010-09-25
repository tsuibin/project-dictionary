#ifndef COMMUNICAT_H
#define COMMUNICAT_H

#include <QObject>
#include "dictionary.h"
#include "hand_wdialog.h"
#include "addic_thread.h"

class communicat : public QObject
{
    Q_OBJECT
public:
    explicit communicat(QObject *parent = 0);
    void start();
    dictionary dic;
    hand_wdialog hand_w;
    addic_thread add_dic;
signals:
    void sendWord(QString);

public slots:

};

#endif // COMMUNICAT_H
