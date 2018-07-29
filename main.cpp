#include <QApplication>
#include <QThread>
#include <QDebug>

#include "mainwidget.h"
#include "picturewidget.h"
#include "createimagesworker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    CreateImagesWorker worker;
    worker.start();

    QObject::connect(&worker, &CreateImagesWorker::imageCreated, [=](){
        qDebug() << "Image Created";
    });

//    PictureWidget pw("images/Autumn.jpg");
//    pw.setParent(&w);
//    pw.move(10,10);
//    pw.show();

    return a.exec();
}
