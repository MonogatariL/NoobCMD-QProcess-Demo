#pragma once
/*
修改后的LineEdit，主要用于释放键盘事件信号
*/
#include <QLineEdit>
#include <qevent.h>
#include <qdebug.h>

enum LE_Modify
{
	Normal = 0,
	CmdCurrentPath,
};

class LineEditModify  : public QLineEdit
{
	Q_OBJECT
public:
	LineEditModify(QWidget *parent);
	~LineEditModify();
	QString currentPath;
	void setModOpen(LE_Modify, bool);

private:
	bool Mod[2];
protected:
	void keyPressEvent(QKeyEvent* event);
};
