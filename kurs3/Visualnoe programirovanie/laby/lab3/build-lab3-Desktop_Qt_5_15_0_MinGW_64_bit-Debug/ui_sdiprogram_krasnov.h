/********************************************************************************
** Form generated from reading UI file 'sdiprogram_krasnov.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDIPROGRAM_KRASNOV_H
#define UI_SDIPROGRAM_KRASNOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDIProgram_Evtuhova
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SDIProgram_Evtuhova)
    {
        if (SDIProgram_Evtuhova->objectName().isEmpty())
            SDIProgram_Evtuhova->setObjectName(QString::fromUtf8("SDIProgram_Evtuhova"));
        SDIProgram_Evtuhova->resize(800, 600);
        centralwidget = new QWidget(SDIProgram_Evtuhova);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SDIProgram_Evtuhova->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SDIProgram_Evtuhova);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        SDIProgram_Evtuhova->setMenuBar(menubar);
        statusbar = new QStatusBar(SDIProgram_Evtuhova);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SDIProgram_Evtuhova->setStatusBar(statusbar);

        retranslateUi(SDIProgram_Evtuhova);

        QMetaObject::connectSlotsByName(SDIProgram_Evtuhova);
    } // setupUi

    void retranslateUi(QMainWindow *SDIProgram_Evtuhova)
    {
        SDIProgram_Evtuhova->setWindowTitle(QCoreApplication::translate("SDIProgram_Evtuhova", "SDIProgram_Evtuhova", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SDIProgram_Evtuhova: public Ui_SDIProgram_Evtuhova {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDIPROGRAM_KRASNOV_H
