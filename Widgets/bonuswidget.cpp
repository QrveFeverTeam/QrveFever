#include "bonuswidget.h"
#include "ui_bonuswidget.h"

BonusWidget::BonusWidget(const BonusData &bonus, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bonuswidget)
{
    ui->setupUi(this);

    this->bonus(bonus);
}

BonusWidget::~BonusWidget()
{
    delete ui;
}

const BonusData BonusWidget::bonus() const
{
    return BonusData(name(), frequency());
}
void BonusWidget::bonus(const BonusData &bonus) {
    name(bonus.name);
    frequency(bonus.frequency);
}


const QString BonusWidget::name() const
{
    return m_name;
}
void BonusWidget::name(const QString &name) {
    m_name = name;
    if(!name.isEmpty())
        ui->label->setPixmap(QPixmap(name + ".jpg"));;
}

int BonusWidget::frequency() const {
    return ui->horizontalSlider->value();
}
void BonusWidget::frequency(int frequency) {
    ui->horizontalSlider->setValue(frequency);
}


void BonusWidget::on_toolButton_clicked()
{
    ui->horizontalSlider->setValue(0);
}
