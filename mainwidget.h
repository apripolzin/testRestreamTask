#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QList>
#include "picturewidget.h"

#include "picturewidget.h"

#define IMG_FILES_PATH "images"

class QPixmap;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget() override;

public slots:
    void appendPicture(QPixmap *pix);

private:
    QList<PictureWidget*> pics;

private:
    int getRandomX() const;
    int getRandomY() const;
    mutable uint seed;

};

#endif // MAINWIDGET_H
