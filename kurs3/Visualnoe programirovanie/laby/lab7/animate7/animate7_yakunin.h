#ifndef ANIMATE7_YAKUNIN_H
#define ANIMATE7_YAKUNIN_H

#include "endlesscycle.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class animate7_yakunin; }
QT_END_NAMESPACE

class animate7_yakunin : public QWidget
{
    Q_OBJECT

public:
    animate7_yakunin();

private:
    endlesscycle elc;
};
#endif // ANIMATE7_YAKUNIN_H
