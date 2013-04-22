#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "preparewidget.h"

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
    QWidget* view;
    PrepareWidget* prepareWidget;

protected:
    void setView(QWidget* view);
    void showPrepareWidget();
};

#endif // MAINWINDOW_H
