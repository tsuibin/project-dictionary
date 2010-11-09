/********************************************************************************
** Form generated from reading UI file 'hand_wdialog.ui'
**
** Created: Tue Nov 9 19:49:07 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAND_WDIALOG_H
#define UI_HAND_WDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_hand_wdialog
{
public:
    QListWidget *wordlist;
    QPushButton *clearbt;

    void setupUi(QDialog *hand_wdialog)
    {
        if (hand_wdialog->objectName().isEmpty())
            hand_wdialog->setObjectName(QString::fromUtf8("hand_wdialog"));
        hand_wdialog->resize(321, 219);
        wordlist = new QListWidget(hand_wdialog);
        wordlist->setObjectName(QString::fromUtf8("wordlist"));
        wordlist->setGeometry(QRect(240, 10, 71, 171));
        clearbt = new QPushButton(hand_wdialog);
        clearbt->setObjectName(QString::fromUtf8("clearbt"));
        clearbt->setGeometry(QRect(240, 180, 71, 27));
        QIcon icon;
        icon.addFile(QString::fromUtf8("image/Broom.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearbt->setIcon(icon);

        retranslateUi(hand_wdialog);

        QMetaObject::connectSlotsByName(hand_wdialog);
    } // setupUi

    void retranslateUi(QDialog *hand_wdialog)
    {
        hand_wdialog->setWindowTitle(QApplication::translate("hand_wdialog", "\346\211\213\345\206\231\350\276\223\345\205\245", 0, QApplication::UnicodeUTF8));
        clearbt->setText(QApplication::translate("hand_wdialog", "\346\270\205\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class hand_wdialog: public Ui_hand_wdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAND_WDIALOG_H
