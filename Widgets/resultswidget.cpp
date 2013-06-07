#include "resultswidget.h"
#include "ui_resultswidget.h"

ResultsWidget::ResultsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultsWidget)
{
    ui->setupUi(this);
}

ResultsWidget::~ResultsWidget()
{
    delete ui;
}

void ResultsWidget::setUsers(const QList<UserData> &users)
{
    foreach(UserData user, users)
        addResult(user);
}

ResultWidget *ResultsWidget::addResult(const UserData &user)
{
    ResultWidget* result = new ResultWidget(user.name, user.color);
    ui->verticalLayout->insertWidget(ui->verticalLayout->indexOf(ui->verticalSpacer->widget()), result);
    m_results[user.name] = result;
    return result;
}


const QMap<QString, int> ResultsWidget::results() const
{
    QMap<QString, int> results;
    foreach(QString name, m_results.keys()) {
        results[name] = m_results[name]->points();
    }
    return results;
}

int ResultsWidget::result(const QString &name) const
{
    return m_results[name]->points();
}

void ResultsWidget::result(const QString &name, int points)
{
    m_results[name]->points(points);
}
