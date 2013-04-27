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

const UserData UserWidget::user() const {
    return UserData(ui->lineEdit->text(), leftKey, rightKey, 0);
}

void UserWidget::keyPressEvent(QKeyEvent *e) {
    if(e->nativeScanCode() != 9)
        *currentKey = e->nativeScanCode();
    blurKeyButton();
}

void UserWidget::on_toolButton_clicked()
{
    currentKey = &leftKey;
    activeKeyButton(ui->toolButton);
}

void UserWidget::on_toolButton_2_clicked()
{
    currentKey = &rightKey;
    activeKeyButton(ui->toolButton_2);
}

void UserWidget::on_toolButton_3_clicked()
{
    emit closed();
    deleteLater();
}

void UserWidget::activeKeyButton(QToolButton *button) {
    currentKeyButton = button;
    button->setProperty("active", true);
    button->setStyleSheet(button->styleSheet());
    setFocus();
}

void UserWidget::blurKeyButton() {
    currentKeyButton->setProperty("active", false);
    currentKeyButton->setStyleSheet(currentKeyButton->styleSheet());
    clearFocus();
}

void UserWidget::emitChanged() {
    emit changed(user());
}
