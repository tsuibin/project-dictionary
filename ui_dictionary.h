/********************************************************************************
** Form generated from reading UI file 'dictionary.ui'
**
** Created: Fri Sep 3 15:50:55 2010
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
#include <QtGui/QListView>
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
    QListView *listView;

    void setupUi(QWidget *dictionary)
    {
        if (dictionary->objectName().isEmpty())
            dictionary->setObjectName(QString::fromUtf8("dictionary"));
        dictionary->resize(595, 414);
        WordIput = new QLineEdit(dictionary);
        WordIput->setObjectName(QString::fromUtf8("WordIput"));
        WordIput->setGeometry(QRect(180, 40, 251, 27));
        SearchButton = new QPushButton(dictionary);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));
        SearchButton->setGeometry(QRect(450, 40, 101, 27));
        label = new QLabel(dictionary);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 81, 21));
        MeanBrowser = new QTextBrowser(dictionary);
        MeanBrowser->setObjectName(QString::fromUtf8("MeanBrowser"));
        MeanBrowser->setGeometry(QRect(180, 100, 361, 281));
        listView = new QListView(dictionary);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(20, 100, 131, 281));

        retranslateUi(dictionary);

        QMetaObject::connectSlotsByName(dictionary);
    } // setupUi

    void retranslateUi(QWidget *dictionary)
    {
        dictionary->setWindowTitle(QApplication::translate("dictionary", "dictionary", 0, QApplication::UnicodeUTF8));
        SearchButton->setText(QApplication::translate("dictionary", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dictionary", "\350\257\267\350\276\223\345\205\245\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dictionary: public Ui_dictionary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONARY_H
