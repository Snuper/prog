#ifndef YAKUNIN_2_H
#define YAKUNIN_2_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <iostream>
#include <fstream>
#include <string>

namespace Ui {
class yakunin_2;
}

class yakunin_2 : public QWidget
{
    Q_OBJECT

public:
    explicit yakunin_2(QWidget *parent = nullptr);
    ~yakunin_2();

public slots:
    void recieveData(QString st);

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_load_clicked();

private:
    Ui::yakunin_2 *ui;
};

#endif // YAKUNIN_2_H
