#include "widget.h"
#include "animate7_yakunin.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>

//! [0]
animate7_yakunin::animate7_yakunin()
{
    setWindowTitle(tr("Yaku"));

    widget *native = new widget(&elc, this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(native, 0, 0);
    setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, native, &widget::animate);
    timer->start(50);
}
