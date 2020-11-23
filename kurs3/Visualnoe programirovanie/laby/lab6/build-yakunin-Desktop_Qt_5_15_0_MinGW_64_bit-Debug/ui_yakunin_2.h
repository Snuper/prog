/********************************************************************************
** Form generated from reading UI file 'yakunin_2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YAKUNIN_2_H
#define UI_YAKUNIN_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yakunin_2
{
public:
    QTextEdit *textEdit_main;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_save;
    QPushButton *pushButton_load;
    QLabel *label_photo;

    void setupUi(QWidget *yakunin_2)
    {
        if (yakunin_2->objectName().isEmpty())
            yakunin_2->setObjectName(QString::fromUtf8("yakunin_2"));
        yakunin_2->resize(476, 218);
        yakunin_2->setStyleSheet(QString::fromUtf8("background-color: rgb(14, 73, 85);"));
        textEdit_main = new QTextEdit(yakunin_2);
        textEdit_main->setObjectName(QString::fromUtf8("textEdit_main"));
        textEdit_main->setGeometry(QRect(213, 10, 251, 171));
        textEdit_main->setStyleSheet(QString::fromUtf8(""));
        pushButton_clear = new QPushButton(yakunin_2);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(214, 190, 71, 21));
        pushButton_clear->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        pushButton_save = new QPushButton(yakunin_2);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(300, 190, 75, 21));
        pushButton_save->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        pushButton_load = new QPushButton(yakunin_2);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setGeometry(QRect(390, 190, 71, 21));
        pushButton_load->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        label_photo = new QLabel(yakunin_2);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(10, 10, 181, 171));
        label_photo->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);"));
        label_photo->setFrameShape(QFrame::Panel);
        label_photo->setScaledContents(true);

        retranslateUi(yakunin_2);
        QObject::connect(pushButton_clear, SIGNAL(clicked()), textEdit_main, SLOT(clear()));
        QObject::connect(pushButton_clear, SIGNAL(clicked()), label_photo, SLOT(clear()));

        QMetaObject::connectSlotsByName(yakunin_2);
    } // setupUi

    void retranslateUi(QWidget *yakunin_2)
    {
        yakunin_2->setWindowTitle(QCoreApplication::translate("yakunin_2", "Form", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("yakunin_2", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        pushButton_save->setText(QCoreApplication::translate("yakunin_2", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_load->setText(QCoreApplication::translate("yakunin_2", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label_photo->setText(QCoreApplication::translate("yakunin_2", "\321\204\320\276\321\202\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yakunin_2: public Ui_yakunin_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YAKUNIN_2_H
