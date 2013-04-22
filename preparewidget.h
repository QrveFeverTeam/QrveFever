#ifndef PREPAREWIDGET_H
#define PREPAREWIDGET_H

#include <QWidget>

namespace Ui {
class PrepareWidget;
}

class PrepareWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit PrepareWidget(QWidget *parent = 0);
    ~PrepareWidget();
    
private:
    Ui::PrepareWidget *ui;
};

#endif // PREPAREWIDGET_H
