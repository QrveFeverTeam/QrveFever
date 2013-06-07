#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(const QList<UserData> &users, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    ui->results->setUsers(users);
}

GameWidget::~GameWidget()
{
    delete ui;
}
