#pragma once

#include <QtWidgets/QWidget>
#include <QProcess>
#include <QTextCodec>
#include <QDebug>
#include <QTextStream>

#include "ui_NoobCMD.h"

class NoobCMD : public QWidget
{
    Q_OBJECT

public:
    NoobCMD(QWidget *parent = nullptr);
    ~NoobCMD();
    void init();
private slots:
    void Slot_AfterProcStarted();
    void Slot_AfterProcFinished(int exitCode, QProcess::ExitStatus);
    void Slot_RightMessage();
    void Slot_WrongMessage();

    void Slot_Process();
private:
    Ui::NoobCMDClass ui;

    QProcess* proc;
};
