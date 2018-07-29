#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QWidget>
#include <QPixmap>

class PictureWidget : public QWidget
{
    Q_OBJECT
public:
    PictureWidget(QPixmap *image, QWidget *parent = nullptr);
    ~PictureWidget() override;

protected:
    virtual void paintEvent(QPaintEvent *e) override;

private:
    QPixmap *thumbnail;
};

#endif // PICTUREWIDGET_H
