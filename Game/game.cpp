#include "game.h"
#include <QDebug>
#include <QTime>

Game::Game(const QList<UserData> &users, int interval, QGraphicsScene *scene, QObject *parent) :
    QObject(parent),
    m_interval(interval),
    m_scene(scene),
    m_users(users),
    m_timer(-1)
{
    qsrand(QTime::currentTime().msec());
    foreach(UserData user, users)
        m_results[user.name] = 10;
    initRound();
}

Game::~Game()
{
    clearPlayers();
}

int Game::interval() const
{
    return m_interval;
}

bool Game::active() const
{
    return m_active;
}

QGraphicsScene *Game::scene() const
{
    return m_scene;
}

const QList<UserData> Game::users() const
{
    return m_users;
}

const QMap<QString, int> Game::results() const
{
    return m_results;
}

void Game::play()
{
    m_active = true;
    foreach(Player* player, m_players)
        player->play();
}

void Game::stop()
{
    m_active = false;
    foreach(Player* player, m_players)
        player->stop();
}

void Game::initRound()
{
    clearPlayers();
    scene()->clear();
    int w = qRound(scene()->width());
    int h = qRound(scene()->height());
    foreach(UserData user, m_users) {
        Player* player = new Player(user, interval(), scene(), PLAYER_WIDTH, PLAYER_STEP, rand() % 360, QPointF(rand() % (w - 200) + 100, rand() % (h - 200) + 100));
        connect(this, SIGNAL(keyDown(QKeyEvent*)), player, SLOT(keyDown(QKeyEvent*)));
        connect(this, SIGNAL(keyUp(QKeyEvent*)), player, SLOT(keyUp(QKeyEvent*)));
        connect(player, SIGNAL(collision()), SLOT(playerCollision()));
        m_players.append(player);
    }
}

void Game::clearPlayers()
{
    foreach(Player* player, m_players)
        player->deleteLater();
    m_players.clear();
}

void Game::timerEvent(QTimerEvent *)
{
    if(m_timer > -1)
        killTimer(m_timer);
    initRound();
    play();
}


void Game::playerCollision()
{
    Player *dead = qobject_cast<Player*>(sender());

    m_players.removeOne(dead);
    dead->deleteLater();

    QString deadName = dead->user().name;
    emit playerDead(deadName);

    foreach(Player* player, m_players) {
        QString name = player->user().name;
        emit updateResult(name, ++m_results[name]);
    }

    if(m_players.size() <= 1) {
        stop();
        m_timer = startTimer(1000);
    }
}
