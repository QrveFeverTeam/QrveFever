#ifndef USERSWIDGET_H
#define USERSWIDGET_H

#include <QWidget>
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

    const QList<User> users();

    UserWidget* addUser(UserWidget *user = new UserWidget());
    
private:
    Ui::UsersWidget *ui;
private slots:
    void emptyUser();
};

#endif // USERSWIDGET_H
