#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QGraphicsScene>
#include <QMessageBox>

GameWidget::GameWidget(const QList<UserData> &users, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    ui->board->setFocus();

    ui->results->setUsers(users);

    QGraphicsScene* scene = new QGraphicsScene(ui->board->sceneRect());
    scene->setBackgroundBrush(ui->board->backgroundBrush());
    ui->board->setScene(scene);

    m_game = new Game(users, GAME_INTERVAL, scene);
    ui->label->setText(QString::number(m_game->toReach()));
    connect(ui->board, SIGNAL(keyDown(QKeyEvent*)), game(), SIGNAL(keyDown(QKeyEvent*)));
    connect(ui->board, SIGNAL(keyUp(QKeyEvent*)), game(), SIGNAL(keyUp(QKeyEvent*)));
    connect(m_game, SIGNAL(updateResult(QString,int)), ui->results, SLOT(result(QString,int)));
    connect(m_game, SIGNAL(updateToReach(int)), SLOT(toReachChanged(int)));
    connect(m_game, SIGNAL(finished(QString)), SLOT(finished(QString)));
    game()->play();
}

GameWidget::~GameWidget()
{
    emit exit();
    delete ui;
    delete m_game;
}

Game *GameWidget::game() const
{
    return m_game;
}

void GameWidget::on_pushButton_clicked()
{
    if(game()->active()) {
        game()->stop();
        ui->pushButton->setText(tr("Play"));
    }
    else {
        ui->board->setFocus();
        game()->play();
        ui->pushButton->setText(tr("Pause"));
    }
}

void GameWidget::toReachChanged(int toReach)
{
    ui->label->setText(QString::number(toReach));
}

void GameWidget::finished(const QString &winner)
{
    QMessageBox::information(this, "Game over", "Player <b>" + winner + "</b> wins!");
    emit exit();
}
