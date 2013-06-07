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
    if(users.size())
        emit play(ui->users->users());
}
