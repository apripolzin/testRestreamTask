#include <QDebug>
#include <QThread>
#include <QApplication>
#include "mainwidget.h"
#include "picturewidget.h"

MainWidget::MainWidget(QWidget *parent/* = nullptr*/)
    : QWidget(parent)
{
    this->setFixedSize(1280, 720);
}

MainWidget::~MainWidget()
{
}

//void MainWidget::paintEvent(QPaintEvent *e)
//{
//    QWidget::paintEvent(e);
//}

void MainWidget::appendPicture(QPixmap *pix)
{
    PictureWidget *pw = new PictureWidget(pix);
    pw->setParent(this);
    pw->show();
}
