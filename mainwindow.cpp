#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_view(0),
    m_prepareWidget(0),
    m_gameWidget(0)
{
    ui->setupUi(this);

    showPrepareView();

    layout()->setSizeConstraint(QLayout::SetFixedSize);
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
        connect(m_prepareWidget, SIGNAL(play(QList<UserData>)), SLOT(play(QList<UserData>)));
    }
    showView(m_prepareWidget);
}

void MainWindow::showGameView(const QList<UserData> &users)
{
    GameWidget* m_gameWidget = new GameWidget(users);
    connect(m_gameWidget, SIGNAL(exit()), SLOT(gameExit()));
    showView(m_gameWidget);
}

void MainWindow::play(const QList<UserData> &users) {
    showGameView(users);
}

void MainWindow::gameExit()
{
    showPrepareView();
}
