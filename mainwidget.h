#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QList>
#include <QPixmap>
#include <QPointer>

#define IMG_FILES_PATH "images"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget() override;

protected:
    virtual void paintEvent(QPaintEvent *e) override;

};

#endif // MAINWIDGET_H
