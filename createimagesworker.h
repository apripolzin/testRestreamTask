#ifndef CREATEIMAGESWORKER_H
#define CREATEIMAGESWORKER_H

#include <QThread>
#include <QSharedPointer>

#include "picturewidget.h"

#define IMG_PATH "images"

class CreateImagesWorker : public QThread
{
    Q_OBJECT
public:
    CreateImagesWorker(QObject *parent = nullptr);
    virtual ~CreateImagesWorker() override;

protected:
    virtual void run() override;

signals:
    void imageCreated(QSharedPointer<PictureWidget> pw);

};

#endif // CREATEIMAGESWORKER_H
