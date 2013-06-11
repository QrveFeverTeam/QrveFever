#include "player.h"
#include <QKeyEvent>
#include <QDebug>
#include <qmath.h>
#include <QGraphicsTextItem>
#include <QTimerEvent>
#include <QTime>

Player::Player(const UserData& user, int interval, QGraphicsScene *scene, float width, float step, float direction, QPointF position, QObject *parent) :
    QObject(parent),
    m_user(user),
    m_interval(interval),
    m_active(false),
    m_visible(true),
    m_holeN(0),
    m_scene(scene),
    m_step(step),
    m_radius(step * 400 / interval),
    m_direction(0),
    m_lastDirection(direction),
    m_position(position),
    m_pen(user.color, width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
{
    qsrand(QTime::currentTime().msec());

    m_head = scene->addEllipse(0, 0, width, width, Qt::NoPen, user.color);
}

int Player::interval() const
{
    return m_interval;
}

bool Player::active() const
{
    return m_active;
}

bool Player::visible() const
{
    return m_visible;
}

void Player::visible(bool visible)
{
    m_visible = visible;
}

const UserData Player::user() const
{
    return m_user;
}

QGraphicsScene *Player::scene() const
{
    return m_scene;
}

float Player::step() const
{
    return m_step;
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
    if(m_holeN) {
        m_holeN++;
        if(m_holeN > M_PI * pen().width() / step()) {
            m_holeN = 0;
            visible(true);
        }
    }
    else if(visible() && rand() % 100 == 0) {
        m_holeN = 1;
        visible(false);
    }
    paint();
}

void Player::paint()
{
    QPainterPath path;
    path.moveTo(position());

    int a = m_lastDirection;
    if(direction() == 0) {
        float h = qCos(a * M_PI / 180.0) * step();
        float y = position().y() - h;

        float l = qTan(a * M_PI / 180.0) * h;
        float x = position().x() - l;
        if(visible())
            path.lineTo(x, y);
        else
            path.moveTo(x, y);
    }
    else {
        float r = m_radius;
        float b = 90 - a;
        float h  = r * qCos(b * M_PI / 180.0);
        float l = h * qTan(b * M_PI / 180.0);

        float length = (direction() > 0) ? direction() : -direction();
        float x = position().x() - l - r;
        float y = position().y() + h - r;

        if(visible()) {
            path.arcMoveTo(x, y, 2 * r, 2 * r, a);
            path.arcTo(x, y, 2 * r, 2 * r, a, length);
        }
        else
            path.arcMoveTo(x, y, 2 * r, 2 * r, a + length);
        m_lastDirection += direction();
    }
    position(path.currentPosition());

    moveHead();

    QGraphicsPathItem* item = scene()->addPath(path, pen());
    if(collides(item))
        emit collision();
}

bool Player::collides(QGraphicsItem *item)
{
    return item->collidingItems().size() > (int)(pen().width() / step()) + 2;
}

void Player::moveHead()
{
    m_head->setPos(position().x() - (m_head->rect().width() / 2.0), position().y() - (m_head->rect().height() / 2.0));
}

void Player::keyDown(QKeyEvent *event)
{
    float length = step() / m_radius * 180 / M_PI;
    if(event->key() == user().leftKey) {
        if(m_direction < 0)
            m_direction = 0;
        m_direction += length;
    }
    else if(event->key() == user().rightKey) {
        if(m_direction > 0)
            m_direction = 0;
        m_direction -= length;
    }
}

void Player::keyUp(QKeyEvent *event)
{
    if((event->key() == user().leftKey && direction() > 0) || (event->key() == user().rightKey && direction() < 0))
        direction(0);
}
