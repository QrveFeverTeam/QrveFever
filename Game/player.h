#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsScene>
#include "datatypes.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(const UserData& user, int interval, QGraphicsScene* scene, QObject *parent = 0);

    int interval() const;
    bool active() const;
    const UserData user() const;
    QGraphicsScene* scene() const;
    float direction() const;
    QPointF position() const;
    QPen pen() const;

    void play();
    void stop();

protected:
    void timerEvent(QTimerEvent *);
    void paint();
    bool collides();

private:
    int m_timer;
    int m_interval;
    bool m_active;
    UserData m_user;
    QGraphicsScene* m_scene;
    float m_direction;
    QPointF m_position;
    QPen m_pen;

signals:
    void collision();

public slots:
    void keyDown(QKeyEvent* event);
    void keyUp(QKeyEvent* event);
};

#endif // PLAYER_H
