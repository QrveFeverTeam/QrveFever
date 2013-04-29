#include "userwidget.h"
#include "ui_userwidget.h"
#include <QKeyEvent>
#include <QDebug>

UserWidget::UserWidget(const UserData& user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWidget)
{
    ui->setupUi(this);
    setAutoFillBackground(true);

    this->user(user);
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
    if((e->key() >= Qt::Key_Left && e->key() <= Qt::Key_Down) || (e->key() >= Qt::Key_A && e->key() <= Qt::Key_Z) || (e->key() >= Qt::Key_0 && e->key() <= Qt::Key_9)) {
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
    m_leftKey = key;
    displayKey(ui->toolButton, key);
    emitChanged();
}

int UserWidget::rightKey() const {
    return m_rightKey;
}
void UserWidget::rightKey(int key) {
    m_rightKey = key;
    displayKey(ui->toolButton_2, key);
    emitChanged();
}

void UserWidget::displayKey(QToolButton *button, int key) {
    QString c = QChar(activeKey());
    if(key == Qt::Key_Left)
        c = "Left";
    else if(key == Qt::Key_Right)
        c = "Right";
    else if(key == Qt::Key_Up)
        c = "Up";
    else if(key == Qt::Key_Down)
        c = "Down";
    button->setText(c);
}

const QColor UserWidget::color() const {
    return m_color;
}
void UserWidget::color(const QColor &color) {
    m_color = color;

    QPalette p = palette();
    p.setColor(backgroundRole(), color);
    setPalette(p);

    emitChanged();
}

const QString UserWidget::name() const {
    return ui->lineEdit->text();
}
void UserWidget::name(const QString &name) {
    ui->lineEdit->setText(name);
    emitChanged();
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

int UserWidget::activeKey() const {
    return (activeKeyRole() == left) ? leftKey() : rightKey();
}

void UserWidget::activeKey(int key) {
    if(activeKeyRole() == left)
        leftKey(key);
    else
        rightKey(key);
}
