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
    ~MainWidget();

protected:
    virtual void paintEvent(QPaintEvent *e) override;

private:
    QList<QPointer<QPixmap>> pixmapList;
};

#endif // MAINWIDGET_H
