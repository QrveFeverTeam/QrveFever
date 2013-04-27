#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QToolButton>
#include "datatypes.h"

namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit UserWidget(QWidget *parent = 0);
    ~UserWidget();
    const UserData user() const;
    
private:
    Ui::UserWidget *ui;
    int leftKey, rightKey;
    int* currentKey;
    QToolButton* currentKeyButton;

    void activeKeyButton(QToolButton* button);
    void blurKeyButton();

signals:
    void changed(const UserData& user);
    void closed();

protected:
    void keyPressEvent(QKeyEvent *e);

private slots:
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_3_clicked();
    void emitChanged();
};

#endif // USERWIDGET_H
