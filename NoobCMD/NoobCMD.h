#pragma once

#include <QtWidgets/QWidget>
#include <QProcess>
#include <QTextCodec>
#include <QDebug>
#include <QTextStream>
#include<qevent.h>

#include "ui_NoobCMD.h"
#include "LineEditModify.h"
#include "ControlStrip.h"

class NoobCMD : public QWidget
{
    Q_OBJECT

public:
    NoobCMD(QWidget *parent = nullptr);
    ~NoobCMD();
private:
    void Init();
private slots:
    /*QProcess�ź�*/
    void Slot_AfterProcStarted();
    void Slot_AfterProcFinished(int exitCode, QProcess::ExitStatus);
    void Slot_RightMessage();// show right message
    void Slot_WrongMessage();// show wrong message

    void Slot_Process();
    void Slot_Process(QString);
    void Slot_CtrlC();
protected:
    void keyPressEvent(QKeyEvent* event);
private:
    Ui::NoobCMDClass ui;

    QString CurrenPath;
    QProcess* proc;
    bool isProcessEnable;
};
