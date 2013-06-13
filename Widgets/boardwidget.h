#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QGraphicsView>

namespace Ui {
class BoardWidget;
}

class BoardWidget : public QGraphicsView
{
    Q_OBJECT
    
public:
    explicit BoardWidget(QWidget *parent = 0);
    ~BoardWidget();
    
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::BoardWidget *ui;

signals:
    void keyDown(QKeyEvent *event);
    void keyUp(QKeyEvent *event);
};

#endif // BOARDWIDGET_H
