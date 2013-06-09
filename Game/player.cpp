#include "player.h"
#include <QDebug>

Player::Player(const UserData& user, int interval, QGraphicsScene *scene, QObject *parent) :
    QObject(parent),
    m_user(user),
    m_interval(interval),
    m_scene(scene)
{
}

int Player::interval() const
{
    return m_interval;
}

bool Player::active() const
{
    return m_active;
}

const UserData Player::user() const
{
    return m_user;
}

QGraphicsScene *Player::scene() const
{
    return m_scene;
}

float Player::direction() const
{
    return m_direction;
}

QPointF Player::position() const
{
    return m_position;
}

QPen Player::pen() const
{
    return m_pen;
}

void Player::play()
{
    m_timer = startTimer(interval());
}

void Player::stop()
{
    killTimer(m_timer);
}

void Player::timerEvent(QTimerEvent *)
{
    paint();
}

void Player::paint()
{

}

bool Player::collides()
{
}


void Player::keyDown(QKeyEvent *event)
{
}

void Player::keyUp(QKeyEvent *event)
{
}
