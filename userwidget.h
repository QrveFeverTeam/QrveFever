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
    void user(const UserData& user);

protected:
    enum KeyRole { left, right };

    void keyPressEvent(QKeyEvent *e);

    void activateKeyButton();
    void deactivateKeyButton();

    int leftKey() const;
    void leftKey(int key);

    int rightKey() const;
    void rightKey(int key);

    const QColor color() const;
    void color(const QColor& color);

    const QString name() const;
    void name(const QString& name);

    QToolButton* activeKeyButton() const;

    void activeKey(int key);

    KeyRole activeKeyRole() const;
    void activeKeyRole(KeyRole role);

private:
    Ui::UserWidget *ui;
    int m_leftKey;
    int m_rightKey;
    QColor m_color;
    KeyRole m_activeKeyRole;

signals:
    void changed(const UserData& user);
    void closed();

private slots:
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_3_clicked();
    void emitChanged();
};

#endif // USERWIDGET_H
