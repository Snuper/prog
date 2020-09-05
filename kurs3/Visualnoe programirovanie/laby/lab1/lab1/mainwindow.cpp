#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abot_stud.h"
#include "ui_abot_stud.h"
#include "QFileDialog"
#include "QTextDocumentWriter"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, SIGNAL(triggered()), this, SLOT(about_slot())); //сами делаем связку между объектом и функцией(

    //через код добовляем новый пункт в меню
    QAction *pactOpen = new QAction("file open action", 0);
    pactOpen->setText("&Открыть");
    pactOpen->setShortcut(QKeySequence("CTRL+O"));
    pactOpen->setToolTip("Окрытие документа");
    pactOpen->setStatusTip("Открыть файл");
    pactOpen->setWhatsThis("Открыть файл");
//    pactOpen->setIcon(QPixmap("background.jpg"));
    connect(pactOpen, SIGNAL(triggered()), SLOT(slot_open()));
    QMenu *pmuFile = new QMenu("Открыть");
    pmuFile->addAction(pactOpen);
    menuBar()->addMenu(pmuFile);
    //через код добовляем новый пункт в меню

    //так же, только теперь save
    QAction *pactSave = new QAction("file save action", 0);
    pactSave->setText("&Сохранить");
    pactSave->setShortcut(QKeySequence("CTRL+S"));
    pactSave->setToolTip("Сохранение содержимого textEdit");
    pactSave->setStatusTip("Сохранить файл");
    pactSave->setWhatsThis("Сохранить файл");
//    pactOpen->setIcon(QPixmap("background.jpg"));
    connect(pactSave, SIGNAL(triggered()), SLOT(slot_save()));
    QMenu *pmuFile_save = new QMenu("Сохранить");
    pmuFile_save->addAction(pactSave);
    menuBar()->addMenu(pmuFile_save);
    //так же, только теперь save

    //очистить
    QAction *pactClear = new QAction("textEdit clear", 0);
    pactClear->setText("&Очистить");
    pactClear->setShortcut(QKeySequence("CTRL+W"));
    pactClear->setToolTip("Очищаем textEdit");
    pactClear->setStatusTip("Очистить textEdit");
    pactClear->setWhatsThis("Очистить textEdit");
//    pactOpen->setIcon(QPixmap("background.jpg"));
    connect(pactClear, SIGNAL(triggered()), SLOT(slot_clear()));
    QMenu *pmuFile_clear = new QMenu("Очистить");
    pmuFile_clear->addAction(pactClear);
    menuBar()->addMenu(pmuFile_clear);
    //очистить

    //панель инстументов
    ui->toolBar->addAction(pactOpen);
    ui->toolBar->addAction(pactSave);
    ui->toolBar->addAction(pactClear);
    //панель инстументов
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about_slot()
{//вызываем новое окно
    abot_stud *dg = new abot_stud;
    dg->show();
}

void MainWindow::slot_open()
{//открываем
    QString filename = QFileDialog::getOpenFileName(0, "Открыть файл", QDir::currentPath(), "*.cpp *.txt");
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) ui->textEdit->setPlainText(file.readAll());
}

void MainWindow::slot_save()
{//сохраняем
    QString filename = QFileDialog::getSaveFileName(0, "Сохранить файл", QDir::currentPath(), "*.cpp *.txt");
    QTextDocumentWriter writer;
    writer.setFileName(filename);
    writer.write(ui->textEdit->document());
}

void MainWindow::slot_clear()
{//очищаем
    ui->textEdit->clear();
}
