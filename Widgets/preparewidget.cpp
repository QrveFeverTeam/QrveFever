#include "preparewidget.h"
#include "ui_preparewidget.h"

PrepareWidget::PrepareWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrepareWidget)
{
    ui->setupUi(this);

    addBonuses();
}

PrepareWidget::~PrepareWidget()
{
    delete ui;
}

void PrepareWidget::addBonuses()
{
    ui->bonuses->addBonus("");
    ui->bonuses->addBonus("");
    ui->bonuses->addBonus("");
    ui->bonuses->addBonus("");
}

void PrepareWidget::on_pushButton_clicked()
{
    emit play(OptionsData(ui->users->users()));
}
