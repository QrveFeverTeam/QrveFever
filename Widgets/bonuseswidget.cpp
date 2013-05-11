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

const QList<BonusData> BonusesWidget::bonuses() const
{
    QList<BonusData> bonuses;
    foreach (BonusWidget* el, findChildren<BonusWidget*>()) {
        bonuses.append(el->bonus());
    }
    return bonuses;
}

void BonusesWidget::addBonus(BonusWidget *bonus)
{
    ui->verticalLayout->insertWidget(ui->verticalLayout->indexOf(ui->verticalSpacer->widget()), bonus);
}

BonusWidget *BonusesWidget::addBonus(const QString &bonus)
{
    BonusWidget* widget = new BonusWidget(BonusData(bonus, 30));
    addBonus(widget);
    return widget;
}
