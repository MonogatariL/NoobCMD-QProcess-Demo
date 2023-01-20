#pragma once

#include <QWidget>
#include "ui_OrderBlock.h"

class OrderBlock : public QWidget
{
	Q_OBJECT

public:
	OrderBlock(QWidget* parent = nullptr);
	OrderBlock(QString Order,QWidget *parent = nullptr);
	~OrderBlock();
private:
	void Init();
private slots:
	void Slot_SendOrder();
	void Slot_DeleteBlock();
	void Slot_DeleteYes();
	void Slot_DeleteNo();
signals:
	void Sgl_SendOrder(QString);
	void Sgl_DeleteBlock();
private:
	Ui::OrderBlockClass ui;
};
