#ifndef BONUSWIDGET_H
#define BONUSWIDGET_H

#include <QWidget>
#include "datatypes.h"

namespace Ui {
class bonuswidget;
}

class BonusWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit BonusWidget(const BonusData& bonus = BonusData(), QWidget *parent = 0);
    ~BonusWidget();

    const BonusData bonus() const;
    void bonus(const BonusData& bonus);

    const QString name() const;
    void name(const QString& name);

    int frequency() const;
    void frequency(int frequency);
    
private slots:
    void on_toolButton_clicked();

private:
    Ui::bonuswidget *ui;
    QString m_name;
};

#endif // BONUSWIDGET_H
