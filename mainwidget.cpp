#include <QDebug>
#include <QApplication>
#include <algorithm>
#include <cmath>

#include "mainwidget.h"
#include "random.hpp"


MainWidget::MainWidget(QWidget *parent/* = nullptr*/)
    : QWidget(parent), firstIsSelected(false)
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

    if (!firstIsSelected){
        pw->setSelected(true);
        firstIsSelected = true;
    }
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
            qApp->processEvents();
            return getRandomPoint();
        }
    }
    return widTopleft;
}

bool MainWidget::collides(const QRect &r1, const QRect &r2) const
{
    QPoint topLeft1     = r1.topLeft();
    QPoint bottomLeft1  = r1.bottomLeft();
    QPoint topRight1    = r1.topRight();
    //QPoint bottomRight1 = r1.bottomRight();

    QPoint topLeft2     = r2.topLeft();
    QPoint bottomLeft2  = r2.bottomLeft();
    QPoint topRight2    = r2.topRight();
    //QPoint bottomRight2 = r2.bottomRight();

    if (topLeft1.x() <= topLeft2.x() && topRight1.x() >= topLeft2.x() && topLeft1.y() <= topLeft2.y() && bottomLeft1.y() >= topLeft2.y())
        return true;
    if (topLeft1.x() <= topRight2.x() &&  topRight1.x() >= topRight2.x() && topLeft1.y() <= topLeft2.y() &&  bottomLeft1.y() <= bottomLeft2.y())
        return true;
    if (topLeft2.x() <= topLeft1.x() && topRight2.x() >= topLeft1.x() && topLeft2.y() <= topLeft1.y() && bottomLeft2.y() >= topLeft1.y())
        return true;
    if (topLeft2.x() <= topRight1.x() && topRight2.x() >= topRight1.x() && topLeft2.y() <= topLeft1.y() && bottomLeft2.y() >= topLeft1.y())
        return true;

    return false;
}

void MainWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case Qt::Key_Up:
        selectNextImage(PATH_TOP);
        break;
    case Qt::Key_Down:
        selectNextImage(PATH_BOTTOM);
        break;
    case Qt::Key_Left:
        selectNextImage(PATH_LEFT);
        break;
    case Qt::Key_Right:
        selectNextImage(PATH_RIGHT);
        break;
    default:
        break;
    }
    e->accept();
}

void MainWidget::selectNextImage(const MainWidget::PathToSelect path)
{
    //Get Picture now seleted
    PictureWidget *selectedpw = getSeletedPicture();

    if (!selectedpw){
        return;
    }

    //Get candidates for next selection
    QPoint selectedCenter = selectedpw->getCenter();
    QList<PictureWidget *> candidatesToBeSelected;
    foreach (PictureWidget *pw, pics){
        //Now selected
        if (pw->getIsSelected())
            continue;

        QPoint center = pw->getCenter();
        switch (path) {
        case PATH_LEFT:
            if (selectedCenter.x() > center.x())
                candidatesToBeSelected.append(pw);
            break;
        case PATH_RIGHT:
            if (selectedCenter.x() < center.x())
                candidatesToBeSelected.append(pw);
            break;
        case PATH_TOP:
            if (selectedCenter.y() > center.y())
                candidatesToBeSelected.append(pw);
            break;
        case PATH_BOTTOM:
            if (selectedCenter.y() < center.y())
                candidatesToBeSelected.append(pw);
            break;
        }
    }

    if (!candidatesToBeSelected.size())
        return;

    //Get candidate to be more close to now selected

    std::sort(candidatesToBeSelected.begin(), candidatesToBeSelected.end(),
              [=](const PictureWidget* p1, const PictureWidget* p2){
        switch (path)
        {
        case PATH_LEFT:
        case PATH_RIGHT:{
            int dx1 = abs(selectedCenter.x() - p1->getCenter().x());
            int dx2 = abs(selectedCenter.x() - p2->getCenter().x());
            return dx1 < dx2;
        }
        case PATH_TOP:
        case PATH_BOTTOM:{
            int dy1 = abs(selectedCenter.y() - p1->getCenter().y());
            int dy2 = abs(selectedCenter.y() - p2->getCenter().y());
            return dy1 < dy2;
        }
        }
        return true;
    });

    candidatesToBeSelected[0]->setSelected(true);
    selectedpw->setSelected(false);
}

PictureWidget *MainWidget::getSeletedPicture() const
{
    foreach (PictureWidget* pw, pics){
        if (pw->getIsSelected())
            return pw;
    }
    return nullptr;
}

void MainWidget::closeEvent(QCloseEvent *e)
{
    emit closing();
    e->accept();
}
