#include "ControlStrip.h"

ControlStrip::ControlStrip(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Init();
}

ControlStrip::~ControlStrip()
{
	//delete ListItem;
}

void ControlStrip::Init()
{
	connect(ui.PB_AddOrder, &QPushButton::clicked, this, &ControlStrip::Slot_AddOrder);
	//QListWidgetItem* ListItem = new QListWidgetItem(ui.ListW_OrderList);
}

void ControlStrip::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_Return:
	case Qt::Key_Enter: Slot_AddOrder(); break;
	default:break;
	}
}

void ControlStrip::Slot_AddOrder()
{
	OrderBlock* Order = new OrderBlock(ui.LE_Order->text());
	connect(Order, &OrderBlock::Sgl_SendOrder, this, [=](QString Order) {emit Sgl_SendOrder(Order); });
	QListWidgetItem* Item = new QListWidgetItem(ui.ListW_OrderList);
	Item->setSizeHint(QSize(300, 43));
	ui.ListW_OrderList->setItemWidget(Item, Order);
}
