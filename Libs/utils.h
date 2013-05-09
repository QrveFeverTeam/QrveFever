#ifndef UTILS_H
#define UTILS_H

#include <QObject>

int rand(int min, int max) {
    return qrand() % (max + 1 - min) + min;
}

#endif // UTILS_H
