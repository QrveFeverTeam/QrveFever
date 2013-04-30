#ifndef PREPAREWIDGET_H
#define PREPAREWIDGET_H

#include <QWidget>
#include "datatypes.h"

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
signals:
    void play(const OptionsData& options);
private slots:
    void on_pushButton_clicked();
};

#endif // PREPAREWIDGET_H
