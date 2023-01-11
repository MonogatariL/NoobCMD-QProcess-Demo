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
    connect(ui.PB_CtrlC, &QPushButton::clicked, this, &NoobCMD::Slot_CtrlC);

    QObject::installEventFilter(this);//注册事件过滤器
    //QObject::installEventFilter(ui.LE_Command);

    QLineEdit;

    CurrenPath = QApplication::applicationDirPath();
}

void NoobCMD::Slot_Process()
{
    if (ui.PB_Process->isEnabled() == false)
        return;
    //ui.TXT_Report->clear();
    proc->start(QString(ui.LE_Command->text()));
}

void NoobCMD::Slot_CtrlC()
{
    proc->close(); 
    proc->start("BREAK");
    ui.TXT_Report->append(CurrenPath);
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

void NoobCMD::Slot_RightMessage()
{
    QByteArray strdata = proc->readAllStandardOutput();
    QTextCodec* pTextCodec = QTextCodec::codecForName("System");
    assert(pTextCodec != nullptr);
    QString str = pTextCodec->toUnicode(strdata);

    ui.TXT_Report->setTextColor(Qt::black);
    ui.TXT_Report->append(str);
}

void NoobCMD::Slot_WrongMessage()
{
    QByteArray strdata = proc->readAllStandardError();
    QTextCodec* pTextCodec = QTextCodec::codecForName("System");
    assert(pTextCodec != nullptr);
    QString str = pTextCodec->toUnicode(strdata);

    ui.TXT_Report->setTextColor(Qt::red);
    ui.TXT_Report->append(str);
}

bool NoobCMD::eventFilter(QObject* obj, QEvent* event)
{
    if (obj==ui.LE_Command)
    {
        int a = 5;
        a = 3;
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);//将事件转化为键盘事件
            switch(keyEvent->key())
            {
                case Qt::Key_Return:
                case Qt::Key_Enter : Slot_Process();break;
                case Qt::ControlModifier: {
                    if (keyEvent->modifiers() == Qt::ControlModifier && keyEvent->key() == Qt::Key_C)
                        Slot_CtrlC();
                    break;
                }
            }
        }
    }
    //其余事件由系统来处理
    return QObject::eventFilter(obj, event);
}

void NoobCMD::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_C)
    {
        Slot_CtrlC();
    }
}
