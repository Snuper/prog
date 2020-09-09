#include "abot_stud.h"
#include "ui_abot_stud.h"

abot_stud::abot_stud(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::abot_stud)
{
    ui->setupUi(this);
}

abot_stud::~abot_stud()
{
    delete ui;
}
