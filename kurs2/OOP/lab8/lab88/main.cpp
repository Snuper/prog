#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_editor_textChanged(const QString &arg1)
{
    if(arg1.isNull())
        ui->label->setText("Ожидается ввод текста.");
    else
        ui->label->setText("Идет ввод текста.");
}

void MainWindow::on_reset_clicked()
{
    ui->editor->clear();
    ui->label->setText("Ожидается ввод текста.");
}

void MainWindow::on_actionAbout_F1_triggered()
{
    QMessageBox::information(nullptr, "Information", "Приложение версия 1.0");
}

void MainWindow::on_actionExit_Alt_X_triggered()
{
    ui->exit->click();
}



void MainWindow::on_actionSave_F2_triggered()
{
    QFile file("text.txt");
    if( file.open( QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(ui->editor->text().toUtf8());
        file.close();
    }
}
