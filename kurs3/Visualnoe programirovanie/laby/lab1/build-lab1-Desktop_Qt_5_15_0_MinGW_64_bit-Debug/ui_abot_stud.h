/********************************************************************************
** Form generated from reading UI file 'abot_stud.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOT_STUD_H
#define UI_ABOT_STUD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_abot_stud
{
public:
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QWidget *abot_stud)
    {
        if (abot_stud->objectName().isEmpty())
            abot_stud->setObjectName(QString::fromUtf8("abot_stud"));
        abot_stud->resize(139, 300);
        abot_stud->setMinimumSize(QSize(139, 300));
        abot_stud->setMaximumSize(QSize(139, 300));
        label = new QLabel(abot_stud);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(11, 11, 119, 202));
        label->setPixmap(QPixmap(QString::fromUtf8("../background.jpg")));
        label->setScaledContents(true);
        textEdit = new QTextEdit(abot_stud);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(11, 219, 119, 71));
        textEdit->setReadOnly(true);

        retranslateUi(abot_stud);

        QMetaObject::connectSlotsByName(abot_stud);
    } // setupUi

    void retranslateUi(QWidget *abot_stud)
    {
        abot_stud->setWindowTitle(QCoreApplication::translate("abot_stud", "Form", nullptr));
        label->setText(QString());
        textEdit->setHtml(QCoreApplication::translate("abot_stud", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\241\321\202\321\203\320\264\320\265\320\275\321\202: \320\257\320\272\321\203\320\275\320\270\320\275 \320\220\320\275\320\264\321\200\320\265\320\271<br />\320\223\321\200\321\203\320\277\320\277\320\260: \320\230\320\237-814</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class abot_stud: public Ui_abot_stud {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOT_STUD_H
