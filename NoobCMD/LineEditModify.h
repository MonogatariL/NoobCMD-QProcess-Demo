#pragma once

#include <QLineEdit>
#include <qevent.h>
#include <qdebug.h>
class LineEditModify  : public QLineEdit
{
	Q_OBJECT
public:
	LineEditModify(QWidget *parent);
	~LineEditModify();
	//bool event(QEvent* event);
protected:
	void keyPressEvent(QKeyEvent* event);
};
