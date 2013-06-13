#include "game.h"
#include <QDebug>
#include <QTime>

Game::Game(const QList<UserData> &users, int interval, QGraphicsScene *scene, QObject *parent) :
    QObject(parent),
    m_interval(interval),
    m_scene(scene),
    m_users(users),
    m_toReach(users.size() * 10 - 10)
{
    qsrand(QTime::currentTime().msec());
    foreach(UserData user, users)
        m_results[user.name] = 0;

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

int Game::toReach() const
{
    return m_toReach;
}

void Game::play()
{
    m_timer.start();
    m_active = true;
    foreach(Player* player, m_players)
        player->play();
}

void Game::stop()
{
    m_active = false;
    m_timer.stop();
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
        player->visible(false);
        m_players.append(player);
    }
    emit newRound();
    connect(&m_timer, SIGNAL(timeout()), SLOT(showPlayers()));
    m_timer.setSingleShot(true);
    m_timer.start(2000);
}

void Game::clearPlayers()
{
    foreach(Player* player, m_players)
        player->deleteLater();
    m_players.clear();
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

    if(m_players.size() == 1) {
        connect(&m_timer, SIGNAL(timeout()), SLOT(roundEnd()));
        m_timer.setSingleShot(true);
        m_timer.start(2000);
    }
}

void Game::roundEnd()
{
    m_timer.disconnect(this, SLOT(roundEnd()));

    stop();
    QList<int> values = m_results.values();
    qSort(values.begin(), values.end(), qGreater<int>());
    if(values[0] >= toReach()) {
        if(values.size() < 2 || values[0] - values[1] > 1) {
            emit finished(m_results.key(values[0]));
            clearPlayers();
            return;
        }
        else {
            m_toReach = values[1] + 2;
            emit updateToReach(toReach());
        }
    }
    initRound();
    play();
}

void Game::showPlayers()
{
    m_timer.disconnect(this, SLOT(showPlayers()));

    foreach(Player* player, m_players)
        player->visible(true);
}
