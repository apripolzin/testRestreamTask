#include <QApplication>
#include <QDebug>

#include "mainwidget.h"
#include "picturewidget.h"
#include "createimagesworker.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    CreateImagesWorker worker;
    worker.start();

    QObject::connect(&worker, &CreateImagesWorker::imageCreated, &w, &MainWidget::appendPicture);

    return a.exec();
}
