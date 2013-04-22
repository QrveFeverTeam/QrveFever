#ifndef BONUSESWIDGET_H
#define BONUSESWIDGET_H

#include <QWidget>

namespace Ui {
class BonusesWidget;
}

class BonusesWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit BonusesWidget(QWidget *parent = 0);
    ~BonusesWidget();
    
private:
    Ui::BonusesWidget *ui;
};

#endif // BONUSESWIDGET_H
