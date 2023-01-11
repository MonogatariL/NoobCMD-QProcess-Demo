#include "NoobCMD.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NoobCMD w;
    w.show();
    return a.exec();
}
