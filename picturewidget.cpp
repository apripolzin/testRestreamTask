#include "picturewidget.h"
#include <QPainter>
#include <QDebug>
#include <QMoveEvent>

PictureWidget::PictureWidget(QPixmap *image, QWidget *parent/*=nullptr*/) :
      QWidget(parent), thumbnail(image), selected(false)
{
    this->setFixedSize(100, 100);
}

PictureWidget::~PictureWidget()
{
    delete thumbnail;
}

void PictureWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QPainter painter(this);

    painter.save();
    QRect rect = thumbnail->rect();
    rect.moveCenter(this->rect().center());
    painter.drawPixmap(rect, *thumbnail);
    painter.restore();

    if (!selected)
        return;

    painter.save();
    painter.setPen(QPen(QBrush(Qt::red), 5));
    painter.drawRect(QRectF( 2.5,2.5, 95.0, 95.0 ));
    painter.restore();
}

QPoint PictureWidget::getCenter() const
{
    QRect rect(this->pos(), this->size());
    return rect.center();
}

bool PictureWidget::getIsSelected() const
{
    return selected;
}

void PictureWidget::setSelected(bool selected)
{
    this->selected = selected;
    this->repaint();
}
