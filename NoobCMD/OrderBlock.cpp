#include "OrderBlock.h"

OrderBlock::OrderBlock(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Init();
}

OrderBlock::OrderBlock(QString Order,QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.LE_Order->setText(Order);
	Init();
}

OrderBlock::~OrderBlock()
{
}

void OrderBlock::Init()
{
	ui.frame->hide();
	connect(ui.PB_Send, &QPushButton::clicked, this, &OrderBlock::Slot_SendOrder);
	connect(ui.PB_Delete, &QPushButton::clicked, this, &OrderBlock::Slot_DeleteBlock);
	connect(ui.PB_Yes, &QPushButton::clicked, this, &OrderBlock::Slot_DeleteYes);
	connect(ui.PB_No, &QPushButton::clicked, this, &OrderBlock::Slot_DeleteNo);
}

void OrderBlock::Slot_SendOrder()
{
	emit Sgl_SendOrder(ui.LE_Order->text());
}

void OrderBlock::Slot_DeleteYes()
{
	ui.PB_Delete->show();
	ui.frame->hide();
	emit Sgl_DeleteBlock();
}

void OrderBlock::Slot_DeleteNo()
{
	ui.PB_Delete->show();
	ui.frame->hide();
}

void OrderBlock::Slot_DeleteBlock()
{
	ui.PB_Delete->hide();
	ui.frame->show();
}