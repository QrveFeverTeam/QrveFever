#ifndef USERSWIDGET_H
#define USERSWIDGET_H

#include <QWidget>
#include <QList>
#include "userwidget.h"
#include "datatypes.h"

namespace Ui {
class UsersWidget;
}

class UsersWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit UsersWidget(QWidget *parent = 0);
    ~UsersWidget();

    const QList<UserData> users() const;

    UserWidget* addUser(UserWidget *user = 0);
    
protected:
    const QColor newColor();
    QList<QColor>& availableColors();
    int& usersCount();

private:
    static const QColor COLORS[MAX_USERS];

    Ui::UsersWidget *ui;
    QList<QColor> m_availableColors;
    int m_users_count;

private slots:
    void userChanged();
    void userRemoved();
};

#endif // USERSWIDGET_H
