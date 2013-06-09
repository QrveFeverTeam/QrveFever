#include "game.h"
#include <QDebug>

Game::Game(const QList<UserData> &users, int interval, QGraphicsScene *scene, QObject *parent) :
    QObject(parent),
    m_interval(interval),
    m_scene(scene)
{
    foreach(UserData user, users) {
        Player* player = new Player(user, interval, scene, PLAYER_WIDTH, PLAYER_STEP);
        connect(this, SIGNAL(keyDown(QKeyEvent*)), player, SLOT(keyDown(QKeyEvent*)));
        connect(this, SIGNAL(keyUp(QKeyEvent*)), player, SLOT(keyUp(QKeyEvent*)));
        connect(player, SIGNAL(collision()), SLOT(playerCollision()));
        m_players.append(player);
    }
}

Game::~Game()
{
    foreach(Player* player, m_players)
        delete player;
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


void Game::playerCollision()
{
    Player *player = qobject_cast<Player*>(sender());
    qDebug() << player->user().name;
}
