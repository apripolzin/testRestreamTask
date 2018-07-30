#ifndef CREATEIMAGESWORKER_H
#define CREATEIMAGESWORKER_H

#include <QThread>

#define IMG_PATH "images"

class QPixmap;

class CreateImagesWorker : public QThread
{
    Q_OBJECT
public:
    CreateImagesWorker(QObject *parent = nullptr);
    virtual ~CreateImagesWorker() override;

protected:
    virtual void run() override;

signals:
    void imageCreated(QPixmap *pixmap);
    void pathNotExists(const QString& mes);

};

#endif // CREATEIMAGESWORKER_H
