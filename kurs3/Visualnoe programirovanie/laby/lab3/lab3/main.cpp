#include "sdiprogram_yakunin.h"

#include <QApplication>
#include <QtWidgets>

void loadModules(QSplashScreen *psplash)
{
    QTime time;
    time.start();
    for (int i = 0; i < 100; )
    {
        if(time.elapsed() > 40)
        {
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: "
                             + QString::number(i) + "%",
                             Qt::AlignCenter|Qt::AlignCenter,
                             Qt::black
                             );
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap("load.png"));
    splash.show();
    SDIProgram_yakunin w;
    loadModules(&splash);
    splash.finish(&w);
    w.show();
    return a.exec();
}
