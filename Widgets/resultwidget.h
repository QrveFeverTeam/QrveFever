#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class ResultWidget;
}

class ResultWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ResultWidget(const QString& name, const QColor& color, QWidget *parent = 0);
    ~ResultWidget();

    const QString name() const;
    void name(const QString& name);

    int points() const;
    void points(int points);

    const QColor color() const;
    void color(const QColor& color);
    
private:
    Ui::ResultWidget *ui;
    QColor m_color;
    QString m_name;
    int m_points;
};

#endif // RESULTWIDGET_H
