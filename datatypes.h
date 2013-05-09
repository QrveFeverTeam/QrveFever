#ifndef DATATYPES_H
#define DATATYPES_H

#include <QString>
#include <QList>
#include <QColor>
#include "settings.h"

struct UserData {
    QString name;
    QColor color;
    int leftKey;
    int rightKey;
    UserData() : name(""), color(Qt::red), leftKey(Qt::Key_Left), rightKey(Qt::Key_Right) {}
    UserData(const QString& name, const QColor& color, int leftKey, int rightKey) :
        name(name), color(color), leftKey(leftKey), rightKey(rightKey) {}
};

struct OptionsData {
    QList<UserData> users;
    OptionsData() {}
    OptionsData(const QList<UserData>& users) :
        users(users) {}
};

#endif // DATATYPES_H
