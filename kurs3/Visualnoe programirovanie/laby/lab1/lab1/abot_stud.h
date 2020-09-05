#ifndef ABOT_STUD_H
#define ABOT_STUD_H

#include <QWidget>

namespace Ui {
class abot_stud;
}

class abot_stud : public QWidget
{
    Q_OBJECT

public:
    explicit abot_stud(QWidget *parent = nullptr);
    ~abot_stud();

private:
    Ui::abot_stud *ui;
};

#endif // ABOT_STUD_H
