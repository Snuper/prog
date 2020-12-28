#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <stdio.h>
#include <string.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    HANDLE hPipe;
    LPSTR lpPipeName = (LPSTR)("\\\\.\\pipe\\MyPipe2");

    char input_buff[255 + 10];
    char output_buff[255] = " ";

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
