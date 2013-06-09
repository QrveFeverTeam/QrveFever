#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(const QList<UserData> &users, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    ui->results->setUsers(users);

    m_game = new Game(users, GAME_INTERVAL, ui->board->scene());
    connect(ui->board, SIGNAL(keyDown(QKeyEvent*)), game(), SIGNAL(keyDown(QKeyEvent*)));
    connect(ui->board, SIGNAL(keyUp(QKeyEvent*)), game(), SIGNAL(keyUp(QKeyEvent*)));
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
    if(game()->active())
        game()->stop();
    else
        game()->play();
}
