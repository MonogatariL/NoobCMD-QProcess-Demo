#pragma once
/*
¿ØÖÆÃæ°å
*/
#include <QWidget>
#include "ui_ControlStrip.h"
#include "OrderBlock.h"
#include<qevent.h>
#include<qsettings.h>

class ControlStrip : public QWidget
{
	Q_OBJECT

public:
	ControlStrip(QWidget *parent = nullptr);
	~ControlStrip();
private:
	void Init();
	void ReadBlocks();
	void SaveBlocks();
	QMap<OrderBlock*, QListWidgetItem*>Blocks;
	QSet<QString>Orders;
private:
	Ui::ControlStripClass ui;
	void AddOrder(QString o = "");
private slots:
	void Slot_AddOrder();
signals:
	void Sgl_SendOrder(QString);
protected:
	void keyPressEvent(QKeyEvent* event);
};
