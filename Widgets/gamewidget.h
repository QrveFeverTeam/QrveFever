#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "datatypes.h"
#include "Game/game.h"

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameWidget(const QList<UserData>& users, QWidget *parent = 0);
    ~GameWidget();

    Game* game() const;
    
private:
    Ui::GameWidget *ui;
    Game* m_game;

signals:
    void exit();
private slots:
    void on_pushButton_clicked();
    void toReachChanged(int toReach);
    void finished(const QString& winner);
};

#endif // GAMEWIDGET_H
