#include "createimagesworker.h"
#include <QDir>
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QString>

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
    };
    foreach (QFileInfo entry, appdir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot)){
        QSharedPointer<PictureWidget> pw(new PictureWidget(entry.absoluteFilePath()));
        emit imageCreated(pw);
    }
}
