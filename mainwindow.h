#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Widgets/preparewidget.h"
#include "Widgets/gamewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QWidget* m_view;
    PrepareWidget* m_prepareWidget;
    GameWidget* m_gameWidget;

protected:
    void showView(QWidget* m_view);
    void showPrepareView();
    void showGameView(const QList<UserData>& users);

private slots:
    void play(const QList<UserData>& users);
    void gameExit();
};

#endif // MAINWINDOW_H
