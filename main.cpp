#include <QApplication>

#include "mainwidget.h"
#include "picturewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    PictureWidget pw("images/Autumn.jpg");
    pw.setParent(&w);
    pw.move(10,10);
    pw.show();

    return a.exec();
}
