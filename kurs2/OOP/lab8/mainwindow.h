#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_editor_textChanged(const QString &arg1);

    void on_reset_clicked();

    void on_actionAbout_F1_triggered();

    void on_actionExit_Alt_X_triggered();

    void on_actionSave_F2_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
