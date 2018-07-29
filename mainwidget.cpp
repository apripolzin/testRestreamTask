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
    pw->setParent(this);
    pw->move(getRandomPoint());
    pics.append(pw);
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

QPoint MainWidget::getRandomPoint() const
{
    //Create rect for widget
    QPoint widTopleft(getRandomX(), getRandomY());
    QRect widrect(widTopleft, QSize(100, 100));

    foreach (PictureWidget *pic, pics){
        qApp->processEvents();
        QPoint topLeft = pic->pos();
        QRect rect(topLeft, QSize(100,100));
        if (collides(widrect, rect)){
            return getRandomPoint();
        }
    }

    return widTopleft;
}

bool MainWidget::collides(const QRect &r1, const QRect &r2) const
{
    QPoint topLeft1 = r1.topLeft();
    QPoint topLeft2 = r2.topLeft();

    QPoint bottomRight1 = r1.bottomRight();
    QPoint bottomRight2 = r2.bottomRight();

    return false;
}
