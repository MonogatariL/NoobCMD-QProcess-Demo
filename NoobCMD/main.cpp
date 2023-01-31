#include "NoobCMD.h"
#include <QtWidgets/QApplication>
#include "OrderBlock.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NoobCMD w;
    w.show();
    return a.exec();
}
