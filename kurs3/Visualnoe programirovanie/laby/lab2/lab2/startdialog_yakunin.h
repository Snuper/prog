#ifndef STARTDIALOG_YAKUNIN_H
#define STARTDIALOG_YAKUNIN_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog_yakunin.h"

class StartDialog_Yakunin : public QPushButton
{
    Q_OBJECT
public:
    StartDialog_Yakunin(QWidget* pwgt = 0) : QPushButton("Нажми", pwgt)
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked()
    {
        inputdialog* pInputDialog = new inputdialog;
        if(pInputDialog->exec() == QDialog::Accepted)
        {
            QMessageBox::information(0,
                                     "Ваша информация: ",
                                     "Имя: "
                                     + pInputDialog->firstName(),
                                     + "\nФамилия: "
                                     + pInputDialog->lastName()
                                     );
        }
        delete pInputDialog;
    }

};

#endif // STARTDIALOG_YAKUNIN_H
