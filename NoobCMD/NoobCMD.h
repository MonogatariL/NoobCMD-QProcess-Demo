#pragma once

#include <QtWidgets/QWidget>
#include <QProcess>
#include <QTextCodec>
#include <QDebug>
#include <QTextStream>
#include<qkeyeventtransition.h>
#include<qevent.h>

#include "ui_NoobCMD.h"

class NoobCMD : public QWidget
{
    Q_OBJECT

public:
    NoobCMD(QWidget *parent = nullptr);
    ~NoobCMD();
    void init();
private slots:
    /*QProcess–≈∫≈*/
    void Slot_AfterProcStarted();
    void Slot_AfterProcFinished(int exitCode, QProcess::ExitStatus);
    void Slot_RightMessage();// show right message
    void Slot_WrongMessage();// show wrong message

    void Slot_Process();
    void Slot_CtrlC();
protected:
    bool eventFilter(QObject* obj, QEvent* event);
    void keyPressEvent(QKeyEvent* event);
private:
    Ui::NoobCMDClass ui;

    QString CurrenPath;
    QProcess* proc;
};
