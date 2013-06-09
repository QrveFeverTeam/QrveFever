#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QSignalMapper>
#include "player.h"
#include <QList>
#include <QMap>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(const QList<UserData>& users, int interval, QGraphicsScene* scene, QObject *parent = 0);
    ~Game();

    int interval() const;
    bool active() const;
    QGraphicsScene* scene() const;
    const QMap<QString, int> results() const;

public slots:
    void play();
    void stop();

protected:
    void reset();

protected slots:
    void playerCollision(Player* player);

private:
    QSignalMapper m_mapper;
    int m_interval;
    bool m_active;
    QGraphicsScene* m_scene;
    QList<Player*> m_players;
    QMap<QString, int> m_results;

signals:
    void keyDown(QKeyEvent* event);
    void keyUp(QKeyEvent* event);
    void updateResult(const QString& name, int points);
    void playerDead(const QString& name);
    void newRound();
    void finished();
};

#endif // GAME_H
