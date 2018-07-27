#include "picturewidget.h"
#include <QPainter>
#include <QDebug>
#include <QFile>

PictureWidget::PictureWidget(const QString &img_filename, QWidget *parent/*=nullptr*/) :
      QWidget(parent), m_img_filepath(img_filename)
{
    //qDebug() << QFile(m_img_filepath).exists() ;
    this->setFixedSize(100, 100);
    thumbnail = QPixmap(m_img_filepath).scaledToWidth(this->width()-10);
}

PictureWidget::~PictureWidget()
{
}

void PictureWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QPainter painter(this);

    painter.save();
    QRect rect = thumbnail.rect();
    rect.moveCenter(this->rect().center());
    painter.drawPixmap(rect, thumbnail);
    painter.restore();

    painter.save();
    painter.setPen(QPen(QBrush(Qt::red), 5));
    painter.drawRect(QRectF( 2.5,2.5, 95.0, 95.0 ));
    painter.restore();
}
