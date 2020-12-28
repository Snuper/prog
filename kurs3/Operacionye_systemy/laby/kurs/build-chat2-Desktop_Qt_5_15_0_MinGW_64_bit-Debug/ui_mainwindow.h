/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit_main;
    QLineEdit *lineEdit_send;
    QPushButton *pushButton_send;
    QPushButton *pushButton_update;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(203, 353);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit_main = new QTextEdit(centralwidget);
        textEdit_main->setObjectName(QString::fromUtf8("textEdit_main"));
        textEdit_main->setGeometry(QRect(10, 10, 181, 261));
        lineEdit_send = new QLineEdit(centralwidget);
        lineEdit_send->setObjectName(QString::fromUtf8("lineEdit_send"));
        lineEdit_send->setGeometry(QRect(10, 289, 181, 21));
        pushButton_send = new QPushButton(centralwidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(110, 320, 81, 23));
        pushButton_update = new QPushButton(centralwidget);
        pushButton_update->setObjectName(QString::fromUtf8("pushButton_update"));
        pushButton_update->setGeometry(QRect(10, 320, 81, 23));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\321\202\321\214", nullptr));
        pushButton_update->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
