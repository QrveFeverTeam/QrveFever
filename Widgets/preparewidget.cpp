#include "preparewidget.h"
#include "ui_preparewidget.h"

PrepareWidget::PrepareWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrepareWidget)
{
    ui->setupUi(this);
}

PrepareWidget::~PrepareWidget()
{
    delete ui;
}

void PrepareWidget::on_pushButton_clicked()
{
    QList<UserData> users = ui->users->users();
    if(!users.size())
        return;

    for(int i = 0; i < users.size(); i++) {
        UserData user = users[i];
        int n = 1;
        for(int j = i + 1; j < users.size(); j++) {
            UserData& u = users[j];
            if(user.name == u.name)
                u.name += "-" + QString::number(n++);
        }
    }

    emit play(users);
}

void PrepareWidget::enablePlay()
{
    ui->pushButton->show();
}

void PrepareWidget::disablePlay()
{
    ui->pushButton->hide();
}
