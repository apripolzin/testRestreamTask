#include "picturewidget.h"
#include <QPainter>
#include <QDebug>


PictureWidget::PictureWidget(QPixmap *image, QWidget *parent/*=nullptr*/) :
      QWidget(parent), thumbnail(image)
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

    painter.save();
    painter.setPen(QPen(QBrush(Qt::red), 5));
    painter.drawRect(QRectF( 2.5,2.5, 95.0, 95.0 ));
    painter.restore();
}
