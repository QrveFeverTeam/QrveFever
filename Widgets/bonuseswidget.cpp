#include "bonuseswidget.h"
#include "ui_bonuseswidget.h"

BonusesWidget::BonusesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BonusesWidget)
{
    ui->setupUi(this);
}

BonusesWidget::~BonusesWidget()
{
    delete ui;
}
