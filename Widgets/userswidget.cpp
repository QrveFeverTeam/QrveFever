#include "userswidget.h"
#include "ui_userswidget.h"
#include "userwidget.h"
#include <QLineEdit>
#include <QDebug>
#include <list>
#include <algorithm>

UsersWidget::UsersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsersWidget),
    m_users_count(0)
{
    ui->setupUi(this);

    m_availableColors = m_availableColors.fromStdList(std::list<QColor>(COLORS, COLORS + sizeof(COLORS) / sizeof(*COLORS)));
    std::random_shuffle(m_availableColors.begin(), m_availableColors.end());

    addUser();
}

UsersWidget::~UsersWidget()
{
    delete ui;
}

const QList<UserData> UsersWidget::users() const {
    QList<UserData> users;
    foreach (UserWidget* el, findChildren<UserWidget*>()) {
        UserData user = el->user();
        if(!user.name.isEmpty())
            users.append(user);
    }
    return users;
}

UserWidget* UsersWidget::addUser(UserWidget *user) {
    if(usersCount() >= MAX_USERS)
        return 0;
    if(!user) {
        UserData data;
        data.color = newColor();
        user = new UserWidget(data);
    }
    ui->verticalLayout->insertWidget(ui->verticalLayout->indexOf(ui->verticalSpacer->widget()), user);
    connect(user, SIGNAL(changed(const UserData&)), SLOT(userChanged()));
    connect(user, SIGNAL(closed()), SLOT(userRemoved()));
    connect(user, SIGNAL(closed()), SLOT(userChanged()));
    ++usersCount();
    return user;
}

const QColor UsersWidget::newColor()
{
    return availableColors().takeFirst();
}

QList<QColor> &UsersWidget::availableColors()
{
    return m_availableColors;
}

int &UsersWidget::usersCount()
{
    return m_users_count;
}

void UsersWidget::userChanged() {
    if(!findChildren<UserWidget*>().last()->user().name.isEmpty())
        addUser();
}

void UsersWidget::userRemoved()
{
    UserWidget* user = qobject_cast<UserWidget*>(sender());
    availableColors().push_back(user->user().color);
    --usersCount();
    UserWidget* last = findChildren<UserWidget*>().last();
    if(user == last)
        addUser();
}

const QColor UsersWidget::COLORS[MAX_USERS] = {
    QColor(255, 0, 0),
    QColor(0, 255, 0),
    QColor(0, 0, 255),
    QColor(0, 0, 0)
};
