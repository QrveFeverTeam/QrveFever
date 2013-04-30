#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_view(0),
    m_prepareWidget(0)
{
    ui->setupUi(this);

    showPrepareView();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_prepareWidget;
}

void MainWindow::showView(QWidget *view) {
    if(this->m_view) {
        this->m_view->hide();
    }
    this->m_view = view;
    view->setParent(this);
    ui->verticalLayout->addWidget(view);
    view->show();
}

void MainWindow::showPrepareView() {
    if(!m_prepareWidget) {
        m_prepareWidget = new PrepareWidget();
    }
    connect(m_prepareWidget, SIGNAL(play(OptionsData)), SLOT(play(OptionsData)));
    showView(m_prepareWidget);
}

void MainWindow::play(const OptionsData& options) {
    qDebug() << options.users.front().leftKey;
}
