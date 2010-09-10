/********************************************************************************
** Form generated from reading UI file 'dictionary.ui'
**
** Created: Fri Sep 10 14:14:26 2010
**      by: Qt User Interface Compiler version 4.6.3
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
    QLineEdit *WordIput;
    QPushButton *SearchButton;
    QLabel *label;
    QTextBrowser *MeanBrowser;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *dictionary)
    {
        if (dictionary->objectName().isEmpty())
            dictionary->setObjectName(QString::fromUtf8("dictionary"));
        dictionary->resize(584, 412);
        WordIput = new QLineEdit(dictionary);
        WordIput->setObjectName(QString::fromUtf8("WordIput"));
        WordIput->setGeometry(QRect(180, 40, 251, 27));
        SearchButton = new QPushButton(dictionary);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));
        SearchButton->setGeometry(QRect(450, 40, 101, 27));
        SearchButton->setAutoDefault(true);
        SearchButton->setDefault(false);
        label = new QLabel(dictionary);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 81, 21));
        MeanBrowser = new QTextBrowser(dictionary);
        MeanBrowser->setObjectName(QString::fromUtf8("MeanBrowser"));
        MeanBrowser->setGeometry(QRect(180, 90, 371, 281));
        listWidget = new QListWidget(dictionary);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 90, 121, 281));
        pushButton = new QPushButton(dictionary);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 380, 92, 27));

        retranslateUi(dictionary);

        QMetaObject::connectSlotsByName(dictionary);
    } // setupUi

    void retranslateUi(QWidget *dictionary)
    {
        dictionary->setWindowTitle(QApplication::translate("dictionary", "dictionary", 0, QApplication::UnicodeUTF8));
        SearchButton->setText(QApplication::translate("dictionary", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dictionary", "\350\257\267\350\276\223\345\205\245\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("dictionary", "\345\242\236\345\212\240\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dictionary: public Ui_dictionary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONARY_H
