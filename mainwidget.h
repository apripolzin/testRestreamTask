#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QList>

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

};

#endif // MAINWIDGET_H
