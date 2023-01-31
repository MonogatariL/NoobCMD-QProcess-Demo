#include "ControlStrip.h"

ControlStrip::ControlStrip(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Init();
}

ControlStrip::~ControlStrip()
{
	SaveBlocks();
}

void ControlStrip::Init()
{
	connect(ui.PB_AddOrder, &QPushButton::clicked, this, &ControlStrip::Slot_AddOrder);
	ReadBlocks();
}

void ControlStrip::ReadBlocks()
{
	QSettings m_psetting("OrderBlocks.ini", QSettings::IniFormat);
	m_psetting.beginGroup("Orders");
	for (int i = 1; 1; i++)
	{
		QString str = QString("CustomOrder%1").arg(i);
		if (m_psetting.contains(str))
			AddOrder(m_psetting.value(str).toString());
		else
			break;
	}
	m_psetting.endGroup();
}

void ControlStrip::SaveBlocks()
{
	QFile file("OrderBlocks.ini");
	if (file.exists())
	{
		file.remove("OrderBlocks.ini");
	}
	QSettings m_psetting("OrderBlocks.ini", QSettings::IniFormat);
	int i = 1;
	for (auto order=Blocks.begin();order!=Blocks.end();order++,i++)
	{
		m_psetting.setValue(QString("/Orders/CustomOrder%1").arg(i), order.key()->ui.LE_Order->text());
	}
}

void ControlStrip::AddOrder(QString o)
{
	QString order;
	if (o == "")
	{
		if (ui.LE_Order->text() == "")
			return;
		else
			order = ui.LE_Order->text();
		ui.LE_Order->clear();
	}
	else
		order = o;
	QListWidgetItem* Item = new QListWidgetItem(ui.ListW_OrderList);
	Item->setSizeHint(QSize(300, 45));
	OrderBlock* Order = new OrderBlock(order);
	Blocks.insert(Order, Item);
	Orders.insert(order);
	connect(Order, &OrderBlock::Sgl_SendOrder, this, [=](QString Order) {emit Sgl_SendOrder(Order); });
	connect(Order, &OrderBlock::Sgl_DeleteBlock, this, [this, order, Item, Order]() {
		ui.ListW_OrderList->removeItemWidget(Item);
		Orders.remove(order);
		Blocks.remove(Order);
		delete Item;
		delete Order;
		});
	ui.ListW_OrderList->setItemWidget(Item, Order);
}

void ControlStrip::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_Return:
	case Qt::Key_Enter: AddOrder(); break;
	default:break;
	}
}

void ControlStrip::Slot_AddOrder()
{
	AddOrder();
}
