#include "startdialog_yakunin.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_Yakunin startDialog;
    startDialog.show();

    return a.exec();
}
