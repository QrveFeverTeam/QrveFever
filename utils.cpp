#include "utils.h"

void setBackground(QWidget *widget, const QColor &color) {
    QPalette p = widget->palette();
    p.setColor(widget->backgroundRole(), color);
    widget->setPalette(p);
}
