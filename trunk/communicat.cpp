#include "communicat.h"

communicat::communicat(QObject *parent) :
    QObject(parent)
{
}

void communicat::start()
{
    this->dic.show();
    connect(&this->hand_w,SIGNAL(sendWord(QString)),
            &this->dic,SLOT(insertWord(QString)));
    connect(&this->dic,SIGNAL(openHanw()),&this->hand_w,SLOT(show()));
    connect(&this->dic,SIGNAL(dic_window_close()),&this->hand_w,SLOT(close()));
}
