/********************************************************************************
** Form generated from reading UI file 'dictionary.ui'
**
** Created: Tue Nov 9 19:49:07 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTIONARY_H
#define UI_DICTIONARY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dictionary
{
public:
    QListWidget *listWidget;
    QTextBrowser *MeanBrowser;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *WordIput;
    QPushButton *hwinput_bt;
    QPushButton *loaddic_bt;
    QPushButton *page_bt;
    QPushButton *add_dic_bt;
    QPushButton *set_bt;
    QPushButton *save_bt;
    QPushButton *sound_bt;

    void setupUi(QWidget *dictionary)
    {
        if (dictionary->objectName().isEmpty())
            dictionary->setObjectName(QString::fromUtf8("dictionary"));
        dictionary->resize(608, 411);
        dictionary->setCursor(QCursor(Qt::PointingHandCursor));
        dictionary->setAutoFillBackground(true);
        listWidget = new QListWidget(dictionary);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 50, 221, 331));
        listWidget->setMaximumSize(QSize(1677700, 16777215));
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        MeanBrowser = new QTextBrowser(dictionary);
        MeanBrowser->setObjectName(QString::fromUtf8("MeanBrowser"));
        MeanBrowser->setGeometry(QRect(240, 50, 361, 331));
        MeanBrowser->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        label = new QLabel(dictionary);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 390, 41, 17));
        label_2 = new QLabel(dictionary);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 387, 181, 20));
        WordIput = new QLineEdit(dictionary);
        WordIput->setObjectName(QString::fromUtf8("WordIput"));
        WordIput->setGeometry(QRect(11, 17, 221, 27));
        hwinput_bt = new QPushButton(dictionary);
        hwinput_bt->setObjectName(QString::fromUtf8("hwinput_bt"));
        hwinput_bt->setGeometry(QRect(242, 13, 46, 34));
        hwinput_bt->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("image/handw.png"), QSize(), QIcon::Normal, QIcon::Off);
        hwinput_bt->setIcon(icon);
        hwinput_bt->setIconSize(QSize(24, 24));
        hwinput_bt->setAutoDefault(true);
        hwinput_bt->setDefault(false);
        loaddic_bt = new QPushButton(dictionary);
        loaddic_bt->setObjectName(QString::fromUtf8("loaddic_bt"));
        loaddic_bt->setGeometry(QRect(294, 13, 46, 34));
        loaddic_bt->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image/ciku.png"), QSize(), QIcon::Normal, QIcon::Off);
        loaddic_bt->setIcon(icon1);
        page_bt = new QPushButton(dictionary);
        page_bt->setObjectName(QString::fromUtf8("page_bt"));
        page_bt->setGeometry(QRect(346, 13, 46, 34));
        page_bt->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("image/fulltext.png"), QSize(), QIcon::Normal, QIcon::Off);
        page_bt->setIcon(icon2);
        add_dic_bt = new QPushButton(dictionary);
        add_dic_bt->setObjectName(QString::fromUtf8("add_dic_bt"));
        add_dic_bt->setGeometry(QRect(398, 13, 46, 34));
        add_dic_bt->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("image/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_dic_bt->setIcon(icon3);
        set_bt = new QPushButton(dictionary);
        set_bt->setObjectName(QString::fromUtf8("set_bt"));
        set_bt->setGeometry(QRect(554, 13, 46, 34));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("image/option.png"), QSize(), QIcon::Normal, QIcon::Off);
        set_bt->setIcon(icon4);
        save_bt = new QPushButton(dictionary);
        save_bt->setObjectName(QString::fromUtf8("save_bt"));
        save_bt->setGeometry(QRect(450, 13, 46, 34));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_bt->setIcon(icon5);
        sound_bt = new QPushButton(dictionary);
        sound_bt->setObjectName(QString::fromUtf8("sound_bt"));
        sound_bt->setGeometry(QRect(502, 13, 46, 34));
        sound_bt->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("image/laba.png"), QSize(), QIcon::Normal, QIcon::Off);
        sound_bt->setIcon(icon6);
        QWidget::setTabOrder(listWidget, WordIput);
        QWidget::setTabOrder(WordIput, MeanBrowser);
        QWidget::setTabOrder(MeanBrowser, hwinput_bt);
        QWidget::setTabOrder(hwinput_bt, loaddic_bt);
        QWidget::setTabOrder(loaddic_bt, page_bt);
        QWidget::setTabOrder(page_bt, add_dic_bt);
        QWidget::setTabOrder(add_dic_bt, set_bt);
        QWidget::setTabOrder(set_bt, save_bt);
        QWidget::setTabOrder(save_bt, sound_bt);

        retranslateUi(dictionary);

        QMetaObject::connectSlotsByName(dictionary);
    } // setupUi

    void retranslateUi(QWidget *dictionary)
    {
        dictionary->setWindowTitle(QApplication::translate("dictionary", "AKA\345\244\232\345\212\237\350\203\275\350\257\215\345\205\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dictionary->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("dictionary", "\347\212\266\346\200\201\346\240\217", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dictionary", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\205\263\344\272\216\346\210\221\344\273\254</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        WordIput->setToolTip(QApplication::translate("dictionary", "\346\211\213\345\212\250\345\242\236\345\212\240\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        WordIput->setText(QString());
#ifndef QT_NO_TOOLTIP
        hwinput_bt->setToolTip(QApplication::translate("dictionary", "\346\211\213\345\206\231\350\276\223\345\205\245", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        hwinput_bt->setText(QString());
#ifndef QT_NO_TOOLTIP
        loaddic_bt->setToolTip(QApplication::translate("dictionary", "\346\267\273\345\212\240\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        loaddic_bt->setText(QString());
#ifndef QT_NO_TOOLTIP
        page_bt->setToolTip(QApplication::translate("dictionary", "\345\205\250\346\226\207\347\277\273\350\257\221", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        page_bt->setText(QString());
#ifndef QT_NO_TOOLTIP
        add_dic_bt->setToolTip(QApplication::translate("dictionary", "\346\211\213\345\212\250\345\242\236\345\212\240\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        add_dic_bt->setText(QString());
#ifndef QT_NO_TOOLTIP
        set_bt->setToolTip(QApplication::translate("dictionary", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        set_bt->setText(QString());
#ifndef QT_NO_TOOLTIP
        save_bt->setToolTip(QApplication::translate("dictionary", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        save_bt->setText(QString());
#ifndef QT_NO_TOOLTIP
        sound_bt->setToolTip(QApplication::translate("dictionary", "\345\217\221\351\237\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        sound_bt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dictionary: public Ui_dictionary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONARY_H
