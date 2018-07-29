#include "createimagesworker.h"
#include <QDir>
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QSharedPointer>

CreateImagesWorker::CreateImagesWorker(QObject *parent /*= nullptr*/ )
    : QThread (parent)
{
}

CreateImagesWorker::~CreateImagesWorker()
{
}

void CreateImagesWorker::run()
{
    QDir appdir = QDir (QCoreApplication::applicationDirPath());
    if (!appdir.cd(IMG_PATH)){
        QMessageBox::critical(nullptr, "Path not found", QString("There is no \"images\" folder in\n%1").arg(QCoreApplication::applicationDirPath()));
        return;
    };
    foreach (QFileInfo entry, appdir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot)){
        QPixmap pixmap = QPixmap(entry.absoluteFilePath());
        QPixmap *pPix = new QPixmap(pixmap.scaledToWidth(80));
        emit imageCreated(pPix);
    }
}
