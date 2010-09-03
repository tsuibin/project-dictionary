#include <QtGui/QApplication>
#include <QtSql/QSqlDatabase>
#include "dictionary.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dictionary w;
    w.show();

    return a.exec();
}
