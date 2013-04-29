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
    return UserData(name(), color(), leftKey(), rightKey());
}

void UserWidget::user(const UserData &user) {
    name(user.name);
    color(user.color);
    leftKey(user.leftKey);
    rightKey(user.rightKey);
}

void UserWidget::keyPressEvent(QKeyEvent *e) {
    if(e->key() != Qt::Key_Escape) {
        activeKey(e->key());
    }
    deactivateKeyButton();
}

void UserWidget::on_toolButton_clicked()
{
    activeKeyRole(left);
    activateKeyButton();
}

void UserWidget::on_toolButton_2_clicked()
{
    activeKeyRole(right);
    activateKeyButton();
}

void UserWidget::on_toolButton_3_clicked()
{
    emit closed();
    deleteLater();
}

void UserWidget::activateKeyButton() {
    QToolButton* button = activeKeyButton();
    button->setProperty("active", true);
    button->setStyleSheet(button->styleSheet());
    setFocus();
}

void UserWidget::deactivateKeyButton() {
    QToolButton* button = activeKeyButton();
    button->setProperty("active", false);
    button->setStyleSheet(button->styleSheet());
    clearFocus();
}

void UserWidget::emitChanged() {
    emit changed(user());
}

int UserWidget::leftKey() const {
    return m_leftKey;
}
void UserWidget::leftKey(int key) {
    emitChanged();
    m_leftKey = key;
}

int UserWidget::rightKey() const {
    return m_rightKey;
}
void UserWidget::rightKey(int key) {
    emitChanged();
    m_rightKey = key;
}

const QColor UserWidget::color() const {
    return m_color;
}
void UserWidget::color(const QColor &color) {
    emitChanged();
    m_color = color;
}

const QString UserWidget::name() const {
    return ui->lineEdit->text();
}
void UserWidget::name(const QString &name) {
    emitChanged();
    ui->lineEdit->setText(name);
}

UserWidget::KeyRole UserWidget::activeKeyRole() const {
    return m_activeKeyRole;
}

void UserWidget::activeKeyRole(KeyRole role) {
    m_activeKeyRole = role;
}

QToolButton* UserWidget::activeKeyButton() const {
    return (activeKeyRole() == left) ? ui->toolButton : ui->toolButton_2;
}

void UserWidget::activeKey(int key) {
    if(activeKeyRole() == left)
        leftKey(key);
    else
        rightKey(key);
}
