#pragma once
/*
�޸ĺ��LineEdit����Ҫ�����ͷż����¼��ź�
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
