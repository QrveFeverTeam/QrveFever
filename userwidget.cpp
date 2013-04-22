#include "userwidget.h"
#include "ui_userwidget.h"
#include <QKeyEvent>
#include <QDebug>

UserWidget::UserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWidget)
{
    ui->setupUi(this);
}

UserWidget::~UserWidget()
{
    delete ui;
}

const User UserWidget::user() const {
    return User(ui->lineEdit->text(), leftKey, rightKey, 0);
}

void UserWidget::keyPressEvent(QKeyEvent *e) {
    if(e->nativeScanCode() != 9)
        *currentKey = e->nativeScanCode();
    clearFocus();
}

void UserWidget::on_toolButton_clicked()
{
    currentKey = &leftKey;
    setFocus();
}

void UserWidget::on_toolButton_2_clicked()
{
    currentKey = &rightKey;
    setFocus();
}

void UserWidget::on_toolButton_3_clicked()
{
    deleteLater();
}
