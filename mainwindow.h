#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Widgets/preparewidget.h"

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

protected:
    void showView(QWidget* m_view);
    void showPrepareView();

private slots:
    void play(const OptionsData& options);
};

#endif // MAINWINDOW_H
