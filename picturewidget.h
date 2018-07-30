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

public:
    QPoint getCenter() const;

    bool getIsSelected() const;
    void setSelected(bool value);

private:
    bool selected;
};

#endif // PICTUREWIDGET_H
