#include "yakunin.h"
#include "ui_yakunin.h"

yakunin::yakunin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::yakunin)
{
    ui->setupUi(this);
    myform2 = new yakunin_2();
    connect(ui->pushButton_ready, SIGNAL(clicked()), myform2, SLOT(on_pushButton_ready_clicked()));
    connect(this, SIGNAL(sendData(QString)), myform2, SLOT(recieveData(QString)));
}

yakunin::~yakunin()
{
    delete ui;
}

void yakunin::on_pushButton_load_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, "Выберете изображение", QDir::currentPath(), "*.png *.jpg *.gif *.jpeg");
    ui->lineEdit_dlc->setText(filename);
    QImage image1(filename);
    ui->label_photo->setPixmap(QPixmap::fromImage(image1));
}

void yakunin::on_pushButton_ready_clicked()
{
    if( ui->lineEdit_dlc->text() != NULL and
        ui->lineEdit_fio->text() != NULL and
        ui->lineEdit_dolg->text() != NULL and
        ui->lineEdit_stag->text() != NULL)
    {
        connect(ui->pushButton_ready, SIGNAL(clicked()), myform2, SLOT(show()));
        QString st = ui->lineEdit_dlc->text() + "*" +
                     "ФИО: " +ui->lineEdit_fio->text() + "\n" +
                     "Должность: " +ui->lineEdit_dolg->text() + "\n" +
                     "Стаж работы: " + ui->lineEdit_stag->text() + "\n" +
                     "Дата рождения: " + ui->dateEdit->text();
        if(ui->radioButton_m->isChecked() == true) st += "\nПол: Мужской";
        else st += "\nПол: Женский";
        emit sendData(st);
    }
}
