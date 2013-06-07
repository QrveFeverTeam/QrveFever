#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "datatypes.h"

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameWidget(const QList<UserData>& users, QWidget *parent = 0);
    ~GameWidget();
    
private:
    Ui::GameWidget *ui;
};

#endif // GAMEWIDGET_H
