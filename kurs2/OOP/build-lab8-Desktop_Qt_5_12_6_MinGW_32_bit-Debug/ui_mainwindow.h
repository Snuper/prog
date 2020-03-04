/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_F2;
    QAction *actionExit_Alt_X;
    QAction *actionAbout_F1;
    QWidget *centralWidget;
    QPushButton *exit;
    QPushButton *reset;
    QLabel *label;
    QLineEdit *editor;
    QMenuBar *menuBar;
    QMenu *File;
    QMenu *Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actionSave_F2 = new QAction(MainWindow);
        actionSave_F2->setObjectName(QString::fromUtf8("actionSave_F2"));
        actionExit_Alt_X = new QAction(MainWindow);
        actionExit_Alt_X->setObjectName(QString::fromUtf8("actionExit_Alt_X"));
        actionAbout_F1 = new QAction(MainWindow);
        actionAbout_F1->setObjectName(QString::fromUtf8("actionAbout_F1"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(160, 170, 80, 21));
        reset = new QPushButton(centralWidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(160, 130, 80, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 40, 151, 16));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        editor = new QLineEdit(centralWidget);
        editor->setObjectName(QString::fromUtf8("editor"));
        editor->setGeometry(QRect(40, 60, 331, 21));
        editor->setTabletTracking(false);
        editor->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        File = new QMenu(menuBar);
        File->setObjectName(QString::fromUtf8("File"));
        Help = new QMenu(menuBar);
        Help->setObjectName(QString::fromUtf8("Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(File->menuAction());
        menuBar->addAction(Help->menuAction());
        File->addSeparator();
        File->addAction(actionSave_F2);
        File->addAction(actionExit_Alt_X);
        Help->addAction(actionAbout_F1);

        retranslateUi(MainWindow);
        QObject::connect(exit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave_F2->setText(QApplication::translate("MainWindow", "Save F2", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_F2->setShortcut(QApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit_Alt_X->setText(QApplication::translate("MainWindow", "Exit Alt+X", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit_Alt_X->setShortcut(QApplication::translate("MainWindow", "Alt+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout_F1->setText(QApplication::translate("MainWindow", "About F1", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAbout_F1->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        reset->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\236\320\266\320\270\320\264\320\260\320\275\320\270\320\265 \320\262\320\262\320\276\320\264\320\260 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        File->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        Help->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
