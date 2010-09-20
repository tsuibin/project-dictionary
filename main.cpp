#include <QtGui/QApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QTextCodec>
#include <QWidget>
#include <qwidget.h>
#include <QApplication>
#include <qapplication.h>
#include "dictionary.h"
#include "hand_wdialog.h"
#include "communicat.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
//    dictionary w;
//    w.show();

    communicat commu;
    commu.start();
//     a.setMainWidget(&commu.dic);
    return a.exec();
}
