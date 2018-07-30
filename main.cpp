#include <QApplication>
#include <QDebug>
#include <QPointer>

#include "mainwidget.h"
#include "picturewidget.h"
#include "createimagesworker.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    QPointer<CreateImagesWorker> worker = new CreateImagesWorker;
    worker->start();

    QObject::connect(worker, &CreateImagesWorker::imageCreated, &w, &MainWidget::appendPicture);
    QObject::connect(&w, &MainWidget::closing, [=](){
        worker->terminate();
    });
    QObject::connect(worker, &CreateImagesWorker::pathNotExists, &w, &MainWidget::pathNotFound);

    return a.exec();
}
