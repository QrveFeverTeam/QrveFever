#include "userswidget.h"
#include "ui_userswidget.h"
#include "userwidget.h"
#include <QDebug>
UsersWidget::UsersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsersWidget)
{
    ui->setupUi(this);

    addUser();
}

UsersWidget::~UsersWidget()
{
    delete ui;
}

const QList<User> UsersWidget::users() {
    QList<User> users;
    foreach (UserWidget* el, findChildren<UserWidget*>()) {
        users.append(el->user());
    }
    return users;
}

UserWidget* UsersWidget::addUser(UserWidget *user) {
    ui->verticalLayout->insertWidget(ui->verticalLayout->indexOf(ui->verticalSpacer->widget()), user);
    return user;
}