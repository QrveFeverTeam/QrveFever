#ifndef BONUSESWIDGET_H
#define BONUSESWIDGET_H

#include <QWidget>
#include "datatypes.h"
#include "bonuswidget.h"

namespace Ui {
class BonusesWidget;
}

class BonusesWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit BonusesWidget(QWidget *parent = 0);
    ~BonusesWidget();

    const QList<BonusData> bonuses() const;
    void addBonus(BonusWidget* bonus);
    BonusWidget* addBonus(const QString& bonus);
    
private:
    Ui::BonusesWidget *ui;
};

#endif // BONUSESWIDGET_H
