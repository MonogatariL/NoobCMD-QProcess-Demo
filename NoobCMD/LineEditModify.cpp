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
//        qDebug() << tr("mylineEdit的event函数已经触发");
//    }
//    return QLineEdit::event(event);//执行QlineEdit类的event函数的默认操作
//}

void LineEditModify::keyPressEvent(QKeyEvent* event)
{
    QLineEdit::keyPressEvent(event);//执行
    event->ignore();//输出后，才将继续执行主窗口的keypressEvent事件
}
