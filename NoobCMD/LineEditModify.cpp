#include "LineEditModify.h"

LineEditModify::LineEditModify(QWidget* parent)
    : QLineEdit(parent)
{
    
}

LineEditModify::~LineEditModify()
{}

void LineEditModify::setModOpen(LE_Modify mod, bool value)
{
    Mod[mod] = value;
}

void LineEditModify::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Backspace)
    {
        if (Mod[LE_Modify::CmdCurrentPath]&&text().size() < currentPath)
            return;
    }
    QLineEdit::keyPressEvent(event);//ִ��
    event->ignore();//����󣬲Ž�����ִ�������ڵ�keypressEvent�¼�
}
