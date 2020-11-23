#include "yakunin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    yakunin w;
    w.show();
    return a.exec();
}
