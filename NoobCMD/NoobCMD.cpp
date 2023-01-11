#include "NoobCMD.h"

NoobCMD::NoobCMD(QWidget* parent) :
     QWidget(parent)
{
    ui.setupUi(this);
    init();
}

NoobCMD::~NoobCMD()
{

}

void NoobCMD::init()
{
    proc = new QProcess();

    connect(proc, &QProcess::readyReadStandardOutput, this, &NoobCMD::Slot_RightMessage);
    connect(proc, &QProcess::readyReadStandardError, this, &NoobCMD::Slot_WrongMessage);
    connect(proc, &QProcess::started, this, &NoobCMD::Slot_AfterProcStarted);
    connect(proc, static_cast<void (QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &NoobCMD::Slot_AfterProcFinished);
    

    connect(ui.PB_Process, &QPushButton::clicked, this, &NoobCMD::Slot_Process);
    connect(ui.PB_CtrlC, &QPushButton::clicked, this, [=]() {proc->close(); proc->start("BREAK"); });
}

void NoobCMD::Slot_Process()
{
    QString str_command;

    /* clear text report */
    ui.TXT_Report->clear();

    /* create string command and argument */
    str_command = ui.LE_Command->text();

    proc->start(QString(str_command));
}

void NoobCMD::Slot_AfterProcStarted()
{
    ui.PB_Process->setDisabled(true);
}

void NoobCMD::Slot_AfterProcFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    ui.PB_Process->setEnabled(true);
    proc->close();
}

// show right message
void NoobCMD::Slot_RightMessage()
{
    QByteArray strdata = proc->readAllStandardOutput();
    QTextCodec* pTextCodec = QTextCodec::codecForName("System");
    assert(pTextCodec != nullptr);
    QString str = pTextCodec->toUnicode(strdata);

    ui.TXT_Report->setTextColor(Qt::black);
    ui.TXT_Report->append(str);
}

// show wrong message
void NoobCMD::Slot_WrongMessage()
{
    QByteArray strdata = proc->readAllStandardError();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    ui.TXT_Report->setTextColor(Qt::red);
    ui.TXT_Report->append(strdata);
}
