/********************************************************************************
** Form generated from reading UI file 'yakunin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YAKUNIN_H
#define UI_YAKUNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yakunin
{
public:
    QWidget *centralwidget;
    QLabel *label_photo;
    QLabel *label_date_rod;
    QRadioButton *radioButton_m;
    QPushButton *pushButton_load;
    QPushButton *pushButton_ready;
    QDateEdit *dateEdit;
    QRadioButton *radioButton_j;
    QLineEdit *lineEdit_dlc;
    QLabel *label_fio;
    QLabel *label_dolg;
    QLabel *label_stag;
    QLineEdit *lineEdit_stag;
    QLineEdit *lineEdit_dolg;
    QLineEdit *lineEdit_fio;

    void setupUi(QMainWindow *yakunin)
    {
        if (yakunin->objectName().isEmpty())
            yakunin->setObjectName(QString::fromUtf8("yakunin"));
        yakunin->resize(440, 234);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(yakunin->sizePolicy().hasHeightForWidth());
        yakunin->setSizePolicy(sizePolicy);
        yakunin->setStyleSheet(QString::fromUtf8("background-color: rgb(14, 73, 85);"));
        centralwidget = new QWidget(yakunin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_photo = new QLabel(centralwidget);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(10, 15, 181, 171));
        label_photo->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);"));
        label_photo->setFrameShape(QFrame::Panel);
        label_photo->setScaledContents(true);
        label_date_rod = new QLabel(centralwidget);
        label_date_rod->setObjectName(QString::fromUtf8("label_date_rod"));
        label_date_rod->setGeometry(QRect(210, 176, 80, 18));
        label_date_rod->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);"));
        radioButton_m = new QRadioButton(centralwidget);
        radioButton_m->setObjectName(QString::fromUtf8("radioButton_m"));
        radioButton_m->setGeometry(QRect(260, 200, 29, 21));
        radioButton_m->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);"));
        pushButton_load = new QPushButton(centralwidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setGeometry(QRect(10, 200, 81, 23));
        pushButton_load->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        pushButton_ready = new QPushButton(centralwidget);
        pushButton_ready->setObjectName(QString::fromUtf8("pushButton_ready"));
        pushButton_ready->setGeometry(QRect(110, 200, 81, 23));
        pushButton_ready->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(298, 176, 131, 20));
        dateEdit->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        radioButton_j = new QRadioButton(centralwidget);
        radioButton_j->setObjectName(QString::fromUtf8("radioButton_j"));
        radioButton_j->setGeometry(QRect(360, 200, 31, 21));
        radioButton_j->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);"));
        lineEdit_dlc = new QLineEdit(centralwidget);
        lineEdit_dlc->setObjectName(QString::fromUtf8("lineEdit_dlc"));
        lineEdit_dlc->setGeometry(QRect(210, 140, 221, 20));
        lineEdit_dlc->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        label_fio = new QLabel(centralwidget);
        label_fio->setObjectName(QString::fromUtf8("label_fio"));
        label_fio->setGeometry(QRect(210, 10, 23, 47));
        label_fio->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);"));
        label_dolg = new QLabel(centralwidget);
        label_dolg->setObjectName(QString::fromUtf8("label_dolg"));
        label_dolg->setGeometry(QRect(210, 80, 57, 47));
        label_dolg->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);"));
        label_stag = new QLabel(centralwidget);
        label_stag->setObjectName(QString::fromUtf8("label_stag"));
        label_stag->setGeometry(QRect(210, 50, 71, 31));
        label_stag->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);"));
        lineEdit_stag = new QLineEdit(centralwidget);
        lineEdit_stag->setObjectName(QString::fromUtf8("lineEdit_stag"));
        lineEdit_stag->setGeometry(QRect(296, 58, 131, 20));
        lineEdit_stag->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        lineEdit_dolg = new QLineEdit(centralwidget);
        lineEdit_dolg->setObjectName(QString::fromUtf8("lineEdit_dolg"));
        lineEdit_dolg->setGeometry(QRect(296, 93, 131, 20));
        lineEdit_dolg->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        lineEdit_fio = new QLineEdit(centralwidget);
        lineEdit_fio->setObjectName(QString::fromUtf8("lineEdit_fio"));
        lineEdit_fio->setGeometry(QRect(296, 23, 131, 20));
        lineEdit_fio->setStyleSheet(QString::fromUtf8("border-color: rgb(6, 34, 40);\n"
"background-color: rgb(15, 81, 94);\n"
"color: rgb(225, 225, 225);"));
        yakunin->setCentralWidget(centralwidget);

        retranslateUi(yakunin);

        QMetaObject::connectSlotsByName(yakunin);
    } // setupUi

    void retranslateUi(QMainWindow *yakunin)
    {
        yakunin->setWindowTitle(QCoreApplication::translate("yakunin", "yakunin", nullptr));
        label_photo->setText(QCoreApplication::translate("yakunin", "\321\204\320\276\321\202\320\276", nullptr));
        label_date_rod->setText(QCoreApplication::translate("yakunin", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        radioButton_m->setText(QCoreApplication::translate("yakunin", "\320\274", nullptr));
        pushButton_load->setText(QCoreApplication::translate("yakunin", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        pushButton_ready->setText(QCoreApplication::translate("yakunin", "\320\223\320\276\321\202\320\276\320\262", nullptr));
        radioButton_j->setText(QCoreApplication::translate("yakunin", "\320\266", nullptr));
        label_fio->setText(QCoreApplication::translate("yakunin", "\320\244\320\230\320\236", nullptr));
        label_dolg->setText(QCoreApplication::translate("yakunin", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_stag->setText(QCoreApplication::translate("yakunin", "\320\241\321\202\320\260\320\266 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yakunin: public Ui_yakunin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YAKUNIN_H
