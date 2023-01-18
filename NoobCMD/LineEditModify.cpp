#include "LineEditModify.h"

LineEditModify::LineEditModify(QWidget *parent)
	: QLineEdit(parent)
{}

LineEditModify::~LineEditModify()
{}

//bool LineEditModify::event(QEvent * event)
//{
//    if (event->type() == QEvent::KeyPress)
//    {
//        qDebug() << tr("mylineEdit��event�����Ѿ�����");
//    }
//    return QLineEdit::event(event);//ִ��QlineEdit���event������Ĭ�ϲ���
//}

void LineEditModify::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Backspace)
    {
        if (text().size() < currentPath)
            return;
    }
    QLineEdit::keyPressEvent(event);//ִ��
    event->ignore();//����󣬲Ž�����ִ�������ڵ�keypressEvent�¼�
}
