#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPointer>

class PictureWidget : public QWidget
{
    Q_OBJECT
public:
    PictureWidget(const QString &img_filename, QWidget *parent = nullptr);
    ~PictureWidget() override;

protected:
    virtual void paintEvent(QPaintEvent *e) override;

private:
    QString m_img_filepath;
    QPixmap thumbnail;

};

#endif // PICTUREWIDGET_H
