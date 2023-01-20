#pragma once

#include <QWidget>
#include "ui_ControlStrip.h"
#include "OrderBlock.h"
#include<qevent.h>

class ControlStrip : public QWidget
{
	Q_OBJECT

public:
	ControlStrip(QWidget *parent = nullptr);
	~ControlStrip();
private:
	void Init();

private:
	Ui::ControlStripClass ui;
	QListWidgetItem* ListItem;
private slots:
	void Slot_AddOrder();
signals:
	void Sgl_SendOrder(QString);
protected:
	void keyPressEvent(QKeyEvent* event);
};
