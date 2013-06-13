#include "boardwidget.h"
#include "ui_boardwidget.h"
#include <QDebug>
#include <QKeyEvent>

BoardWidget::BoardWidget(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::BoardWidget)
{
    ui->setupUi(this);
    setRenderHints(QPainter::Antialiasing | QPainter::HighQualityAntialiasing);
}

BoardWidget::~BoardWidget()
{
    delete ui;
}

void BoardWidget::keyPressEvent(QKeyEvent *event)
{
    emit keyDown(event);
}

void BoardWidget::keyReleaseEvent(QKeyEvent *event)
{
    emit keyUp(event);
}
