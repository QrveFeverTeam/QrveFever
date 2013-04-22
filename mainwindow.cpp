#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "preparewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    view(0),
    prepareWidget(0)
{
    ui->setupUi(this);

    showPrepareWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setView(QWidget *view) {
    if(this->view) {
        this->view->hide();
    }
    this->view = view;
    view->setParent(this);
    ui->verticalLayout->addWidget(view);
    view->show();
}

void MainWindow::showPrepareWidget() {
    if(!prepareWidget) {
        prepareWidget = new PrepareWidget();
    }
    setView(prepareWidget);
}
