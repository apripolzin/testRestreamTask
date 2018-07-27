#include "mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent/* = nullptr*/)
    : QWidget(parent)
{
    this->setFixedSize(1280, 720);

}

MainWidget::~MainWidget()
{
}

void MainWidget::paintEvent(QPaintEvent *e)
{

    QWidget::paintEvent(e);
}
