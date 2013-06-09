#include "player.h"
#include <QKeyEvent>
#include <QDebug>

#include <QGraphicsTextItem>

Player::Player(const UserData& user, int interval, QGraphicsScene *scene, float width, float direction, QPointF position, QObject *parent) :
    QObject(parent),
    m_user(user),
    m_interval(interval),
    m_active(false),
    m_scene(scene),
    m_direction(direction),
    m_lastDirection(direction),
    m_position(position),
    m_pen(user.color, width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
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

void Player::direction(float direction)
{
    m_direction = direction;
}

QPointF Player::position() const
{
    return m_position;
}

void Player::position(const QPointF &position)
{
    m_position = position;
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
    QPainterPath path;
    path.moveTo(position());
    QPointF newPos(position().x() + 10, position().y() + 10);
    path.lineTo(newPos);
    scene()->addPath(path, pen());
    position(newPos);
}

bool Player::collides()
{
    return false;
}


void Player::keyDown(QKeyEvent *event)
{

}

void Player::keyUp(QKeyEvent *event)
{
}
