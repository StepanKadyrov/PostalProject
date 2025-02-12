#include "postalproject.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PostalProject w;
    w.show();
    w.resize(600, 500);
    return a.exec();
}
