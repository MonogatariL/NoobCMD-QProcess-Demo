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
	QString currentPath;
protected:
	void keyPressEvent(QKeyEvent* event);
};
