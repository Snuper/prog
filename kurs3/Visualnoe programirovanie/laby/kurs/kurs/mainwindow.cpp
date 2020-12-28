#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Задаем сегодняшнюю дату
    QDate *currentDate = new QDate;
    ui->label_curretday->setText(currentDate->currentDate().toString());

    delete currentDate;
    //[0]

    //Делаем кастомное меню для выбора пола
    QAction *man = new QAction;
    QAction *women = new QAction;
    QAction *nan = new QAction;

    man->setText("М");
    women->setText("Ж");
    nan->setText("NaN");

    QMenu *menuGender = new QMenu;
    menuGender->addAction(man);
    menuGender->addAction(women);
    menuGender->addAction(nan);

    ui->pushButton_menuGender->setMenu(menuGender);
    //[1]

    //Делаем кастомное меню для выбора категории
    QAction *elderly = new QAction;
    QAction *grown = new QAction;
    QAction *teenagers = new QAction;
    QAction *children = new QAction;

    elderly->setText("Пожилой");
    grown->setText("Взрослый");
    teenagers->setText("Подросток");
    children->setText("Ребенок");

    QMenu *menuCategory = new QMenu;
    menuCategory->addAction(elderly);
    menuCategory->addAction(grown);
    menuCategory->addAction(teenagers);
    menuCategory->addAction(children);
    menuCategory->addAction(nan);

    ui->pushButton_menuCategory->setMenu(menuCategory);
    //[2]

    Load(); //Загружаем базу данных
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Load()
{
    Info *tempLoad = nullptr;

    std::ifstream in("Data.bin", std::ios::binary); //Открвыем бинарник

    if(in.is_open())
    {
        in.read((char*)&saveSize, sizeof(saveSize));

        for(int i = 0; i < saveSize; i++)
        {//Считываем блоки
            tempLoad = new Info;

            in.read((char*)tempLoad, sizeof(Info));

            Data.push_back(tempLoad);
        }

        delete tempLoad;
    }

    in.close();
}

void MainWindow::Save()
{
    std::ofstream out("Data.bin", std::ios::binary); //Открвыем бинарник

    if(out.is_open())
    {
        out.write((char*)Data.size(), sizeof(Data.size()));

        for(unsigned long long int i = 0; i < Data.size(); i++) //Записываем блоки
            out.write((char*)Data[i], sizeof(Info));
    }

    out.close();
}
