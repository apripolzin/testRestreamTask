#include <QDebug>
#include <QThread>
#include <QApplication>
#include <QRandomGenerator>
#include <QTime>

#include "mainwidget.h"
#include "picturewidget.h"
#include "random.hpp"


MainWidget::MainWidget(QWidget *parent/* = nullptr*/)
    : QWidget(parent)
{
    this->setFixedSize(1280, 720);
}

MainWidget::~MainWidget()
{
}

void MainWidget::appendPicture(QPixmap *pix)
{
    PictureWidget *pw = new PictureWidget(pix);
    pics.append(pw);
    pw->setParent(this);
    int x = getRandomX();
    int y = getRandomY();
    qDebug() << x << y;
    pw->move(x,y);
    pw->show();
}

int MainWidget::getRandomX() const
{
    return Random::get(0, this->width()-100);
}

int MainWidget::getRandomY() const
{
    return Random::get(0, this->height()-100);
}
