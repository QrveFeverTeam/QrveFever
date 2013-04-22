#ifndef DATATYPES_H
#define DATATYPES_H

#include <QString>

class User {
public:
    QString name;
    int leftKey;
    int rightKey;
    int score;
    User() {}
    User(const QString& name, int leftKey, int rightKey, int score) :
        name(name), leftKey(leftKey), rightKey(rightKey), score(score) {}
};

#endif // DATATYPES_H
