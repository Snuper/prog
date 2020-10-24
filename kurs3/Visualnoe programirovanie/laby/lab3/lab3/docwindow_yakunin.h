#ifndef DOCWINDOW_YAKUNIN_H
#define DOCWINDOW_YAKUNIN_H

#include <QTextEdit>



class DocWindow_yakunin : public QTextEdit
{
    Q_OBJECT

private:
    QString m_strFileName;

public:
    DocWindow_yakunin(QWidget *parent = nullptr);

signals:
    void changeWindowTitle(const QString&);

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
};


#endif // DOCWINDOW_YAKUNIN_H
