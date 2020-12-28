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
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_input;
    QPushButton *pushButton_delete;
    QLineEdit *lineEdit_all;
    QDateTimeEdit *dateTimeEdit_from;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_menuGender;
    QPushButton *pushButton_menuCategory;
    QLabel *label_gender;
    QLabel *label_category;
    QLabel *label_all;
    QDateTimeEdit *dateTimeEdit_before;
    QLabel *label_curretday;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 468);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_input = new QPushButton(centralwidget);
        pushButton_input->setObjectName(QString::fromUtf8("pushButton_input"));
        pushButton_input->setGeometry(QRect(10, 50, 141, 23));
        pushButton_delete = new QPushButton(centralwidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(10, 90, 141, 23));
        lineEdit_all = new QLineEdit(centralwidget);
        lineEdit_all->setObjectName(QString::fromUtf8("lineEdit_all"));
        lineEdit_all->setGeometry(QRect(492, 20, 131, 20));
        dateTimeEdit_from = new QDateTimeEdit(centralwidget);
        dateTimeEdit_from->setObjectName(QString::fromUtf8("dateTimeEdit_from"));
        dateTimeEdit_from->setGeometry(QRect(10, 130, 249, 20));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 160, 621, 301));
        pushButton_menuGender = new QPushButton(centralwidget);
        pushButton_menuGender->setObjectName(QString::fromUtf8("pushButton_menuGender"));
        pushButton_menuGender->setGeometry(QRect(492, 53, 131, 23));
        pushButton_menuCategory = new QPushButton(centralwidget);
        pushButton_menuCategory->setObjectName(QString::fromUtf8("pushButton_menuCategory"));
        pushButton_menuCategory->setGeometry(QRect(492, 89, 131, 23));
        label_gender = new QLabel(centralwidget);
        label_gender->setObjectName(QString::fromUtf8("label_gender"));
        label_gender->setGeometry(QRect(378, 53, 54, 21));
        label_category = new QLabel(centralwidget);
        label_category->setObjectName(QString::fromUtf8("label_category"));
        label_category->setGeometry(QRect(378, 90, 54, 21));
        label_all = new QLabel(centralwidget);
        label_all->setObjectName(QString::fromUtf8("label_all"));
        label_all->setGeometry(QRect(378, 13, 54, 32));
        dateTimeEdit_before = new QDateTimeEdit(centralwidget);
        dateTimeEdit_before->setObjectName(QString::fromUtf8("dateTimeEdit_before"));
        dateTimeEdit_before->setGeometry(QRect(376, 130, 249, 20));
        label_curretday = new QLabel(centralwidget);
        label_curretday->setObjectName(QString::fromUtf8("label_curretday"));
        label_curretday->setGeometry(QRect(10, 10, 141, 31));
        label_curretday->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_input->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_menuGender->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273", nullptr));
        pushButton_menuCategory->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        label_gender->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273", nullptr));
        label_category->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        label_all->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265\320\263\320\276", nullptr));
        label_curretday->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
