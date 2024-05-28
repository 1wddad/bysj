#include "loading.h"
#include "fun.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loading w;
    w.setWindowTitle("用户信息");
    w.show();
    return a.exec();
}
