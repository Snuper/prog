#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QMenu>
#include <fstream>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    int saveSize = 0;//Для десирилизации

    struct Info
    {//Структура хранения данных
        bool gender;    //Пол
                        //True = М
                        //False = Ж

        int category;   //Категория
                        //0 - Пожилой
                        //1 - Взрослый
                        //2 - Подросток
                        //3 - Ребенок

        int year;       //Год
        int month;      //Месяц
        int day;        //День
        int session;    //Сеанс
    };

    std::vector<Info*> Data;

    void Save();
    void Load();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
