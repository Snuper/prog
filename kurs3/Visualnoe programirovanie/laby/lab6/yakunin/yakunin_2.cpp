#include "yakunin_2.h"
#include "ui_yakunin_2.h"

yakunin_2::yakunin_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yakunin_2)
{
    ui->setupUi(this);
}

yakunin_2::~yakunin_2()
{
    delete ui;
}

void yakunin_2::recieveData(QString str)
{
    QStringList lst = str.split("*");
    ui->textEdit_main->setText(lst.at(1) + "\n" + lst.at(0));
    if(lst.size() > 1)
    {
        QImage image1(lst.at(0));
        ui->label_photo->setPixmap(QPixmap::fromImage(image1));
    }
}

void yakunin_2::on_pushButton_save_clicked()
{
    std::ofstream out("outup.txt");
    out << ui->textEdit_main->toPlainText().toUtf8().constData();
    out.close();
}

void yakunin_2::on_pushButton_load_clicked()
{
    std::ifstream in("outup.txt");
    std::string temp, str;
    while(!in.eof())
    {
        getline(in, temp);
        str += temp + "\n";
        QImage image1(QString::fromStdString(temp));
        ui->label_photo->setPixmap(QPixmap::fromImage(image1));
    }
    ui->textEdit_main->setText(QString::fromStdString(str));
    in.close();
}
