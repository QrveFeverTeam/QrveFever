#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include "datatypes.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(const UserData& user, int interval, QGraphicsScene* scene, float width, float step, float direction = 0, QPointF position = QPointF(200, 200), QObject *parent = 0);

    const UserData user() const;
    int interval() const;
    bool active() const;
    bool visible() const;
    void visible(bool visible);
    QGraphicsScene* scene() const;
    float step() const;
    float direction() const;
    void direction(float direction);
    QPointF position() const;
    void position(const QPointF& position);
    QPen pen() const;

    void play();
    void stop();

protected:
    void timerEvent(QTimerEvent *);
    void paint();
    bool collides(QGraphicsItem* item);
    void moveHead();

private:
    int m_timer;
    UserData m_user;
    int m_interval;
    bool m_active;
    bool m_visible;
    int m_holeN;
    QGraphicsScene* m_scene;
    float m_step;
    float m_radius;
    float m_direction;
    float m_lastDirection;
    QPointF m_position;
    QPen m_pen;
    QGraphicsEllipseItem* m_head;

signals:
    void collision();

public slots:
    void keyDown(QKeyEvent* event);
    void keyUp(QKeyEvent* event);
};

#endif // PLAYER_H
