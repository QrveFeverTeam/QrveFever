#include "userswidget.h"
#include "ui_userswidget.h"
#include "userwidget.h"
#include <QLineEdit>
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

const QList<UserData> UsersWidget::users() {
    QList<UserData> users;
    foreach (UserWidget* el, findChildren<UserWidget*>()) {
        users.append(el->user());
    }
    return users;
}

UserWidget* UsersWidget::addUser(UserWidget *user) {
    ui->verticalLayout->insertWidget(ui->verticalLayout->indexOf(ui->verticalSpacer->widget()), user);
    connect(user, SIGNAL(changed(const UserData&)), SLOT(addEmptyUser()));
    connect(user, SIGNAL(closed()), SLOT(addEmptyUser()));
    return user;
}

void UsersWidget::addEmptyUser() {
    if(findChildren<UserWidget*>().last() == sender())
        addUser();
}
