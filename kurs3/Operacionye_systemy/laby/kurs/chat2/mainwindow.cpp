#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hPipe = CreateFileA(lpPipeName,
                        GENERIC_READ |
                        GENERIC_WRITE,
                        0,
                        NULL,
                        OPEN_EXISTING,
                        0,
                        NULL);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_send_clicked()
{
    memset(output_buff, 0, 255);
    strcpy(output_buff, ui->lineEdit_send->text().toStdString().c_str());
    ui->lineEdit_send->clear();
    WriteFile(hPipe, output_buff, strlen(output_buff), NULL, NULL);
}

void MainWindow::on_pushButton_update_clicked()
{
    memset(input_buff, 0, 265);
    ReadFile(hPipe, input_buff, sizeof(input_buff), NULL, NULL);

    ui->textEdit_main->append(input_buff);
}
