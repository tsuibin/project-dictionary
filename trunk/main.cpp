#include <QtGui/QApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QTextCodec>
#include "dictionary.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    dictionary w;
    w.show();
    return a.exec();
}
