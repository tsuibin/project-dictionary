#include <QtGui>
#include "communicat.h"

communicat::communicat(QObject *parent) :
    QObject(parent)
{
    this->dic_h = 411;
    this->dic_w = 608;
    this->dic_set_h = this->dic.height();
    this->dic_set_w = this->dic.width();
    this->sys_init();
}

void communicat::start()
{
    this->dic.show();
    connect(&this->hand_w,SIGNAL(sendWord(QString)),
            &this->dic,SLOT(insertWord(QString)));
    connect(&this->dic,SIGNAL(openHanw()),&this->hand_w,SLOT(show()));
    connect(&this->dic,SIGNAL(dic_window_close()),&this->hand_w,SLOT(close()));
    connect(&this->dic,SIGNAL(dic_window_close()),&this->set,SLOT(close()));
    connect(&this->dic,SIGNAL(set_open()),&this->set,SLOT(show()));
    connect(&this->set,SIGNAL(window_color(QColor)),this,SLOT(set_windowColor(QColor)));
    connect(&this->set,SIGNAL(dictionary_wid_changed(int)),this,SLOT(set_dictionary_wid(int)));
    connect(&this->set,SIGNAL(dictionary_hight_changed(int)),this,SLOT(set_dictionary_height(int)));
    connect(&this->set,SIGNAL(all_tm_changed(int)),this,SLOT(set_all_tm(int)));
    connect(&this->set,SIGNAL(set_cancel()),this,SLOT(sys_init()));
}
void communicat::set_windowColor(QColor color)
{

    QPalette palette;
//    QPixmap pixmap("image/gudian.jpg");
//    palette.setBrush(QPalette::Background,QBrush(pixmap));
//    palette.setBrush(this->dic.backgroundRole(),QBrush(pixmap));
    palette.setBrush(QPalette::Background,color);
    this->dic.setPalette(palette);
    this->set.setPalette(palette);
//    this->dic.setMask(pixmap.mask());
    this->dic.setAutoFillBackground(true);
    this->set.setAutoFillBackground(true);
    this->dic.exitDialog->setPalette(palette);
    this->set.set_tbaleWidget_color(color);
//    this->dic.setObjectName("mydictionary");
//    this->dic.setStyleSheet("background-image:url(image/gudian.jpg);");
//    this->set.setStyleSheet("background-image:url(image/gudian.jpg);");
    this->hand_w.setStyleSheet("background-color:url(image/gudian.jpg);");
}

void communicat::set_dictionary_wid(int a)
{
    int h,w;
    h = this->dic_h;
    w = this->dic_w;
    this->dic_set_w = double(w)*double(a)/100.0+w;
    this->dic.resize(this->dic_set_w,this->dic_set_h);
}
void communicat::set_dictionary_height(int b)
{
    int h,w;
    h = this->dic_h;
    w = this->dic_w;
    this->dic_set_h = double(h)*double(b)/100.0+h;
    this->dic.resize(this->dic_set_w,this->dic_set_h);
}

void communicat::set_all_tm(int c)
{
    this->dic.setWindowOpacity(double(c)/100.0);
    this->set.setWindowOpacity(double(c)/100.0);
    this->hand_w.setWindowOpacity(double(c)/100.0);
}

void communicat::sys_init()
{
    this->sys_setting = new QSettings(QApplication::applicationDirPath()+"/start.ini",QSettings::IniFormat);
    QColor sys_color = this->sys_setting->value("windowColor").value<QColor>();
    QPalette palette;
    palette.setColor(QPalette::Base,sys_color);
    palette.setBrush(QPalette::Background,sys_color);
    this->dic.setPalette(palette);
    this->hand_w.setPalette(palette);
    this->set.setPalette(palette);
    this->dic.exitDialog->setPalette(palette);
    this->dic.fd->setPalette(palette);
    this->dic.translate->setPalette(palette);

    QFont sys_font = this->sys_setting->value("wordFont").value<QFont>();
    this->dic.setFont(sys_font);
    this->hand_w.setFont(sys_font);
    this->dic.exitDialog->setFont(sys_font);
    this->dic.translate->setFont(sys_font);

    int dic_chang_width = this->sys_setting->value("windowWidth").toInt();
    int w = double(this->dic_w)*double(dic_chang_width)/100.0+this->dic_w;
    int dic_chang_height = this->sys_setting->value("windowHeight").toInt();
    int h = double(this->dic_h)*double(dic_chang_height)/100.0+this->dic_h;
    this->dic.resize(w,h);

    int sys_Clarity = this->sys_setting->value("windowClarity").toInt();
    this->dic.setWindowOpacity(double(sys_Clarity)/100.0);
    this->set.setWindowOpacity(double(sys_Clarity)/100.0);
    this->hand_w.setWindowOpacity(double(sys_Clarity)/100.0);
    this->dic.exitDialog->setWindowOpacity(double(sys_Clarity)/100.0);

    QColor word_font_color = this->sys_setting->value("wordColor").value<QColor>();
    this->dic.set_wordcolor(word_font_color);

    QString word_sort = this->sys_setting->value("wordSort").toString();
    this->dic.word_sort(word_sort);


    bool ifOpenWeb = this->sys_setting->value("wordSavePath").toBool();
    this->set.set_ifOpenWebSearch = ifOpenWeb;

    QStringList WebNameList = this->sys_setting->value("webNameList").toStringList();
    QStringList UrlList = this->sys_setting->value("webUrlList").toStringList();
    this->set.set_webName = WebNameList;
    this->set.set_URL = UrlList;
}
