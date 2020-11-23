#ifndef YAKUNIN_H
#define YAKUNIN_H

#include <QMainWindow>
#include <QFileDialog>
#include "yakunin_2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class yakunin; }
QT_END_NAMESPACE

class yakunin : public QMainWindow
{
    Q_OBJECT

public:
    yakunin(QWidget *parent = nullptr);
    ~yakunin();

signals:
    void sendData(QString str);

private slots:
    void on_pushButton_load_clicked();
    void on_pushButton_ready_clicked();

private:
    yakunin_2 *myform2;
    Ui::yakunin *ui;
};
#endif // YAKUNIN_H


