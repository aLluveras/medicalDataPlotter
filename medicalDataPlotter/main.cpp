#include "selection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Selection w;
    w.show();

    return a.exec();
}
