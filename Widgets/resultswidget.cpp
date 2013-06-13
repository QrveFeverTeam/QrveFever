#include "resultswidget.h"
#include "ui_resultswidget.h"
#include <QLayoutItem>

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

void ResultsWidget::arrangeResults()
{
    QList<ResultWidget*> results = m_results.values();
    qSort(results.begin(), results.end(), ResultWidgetGreater());
    for(int i = 0; i < results.size(); i++)
        ui->verticalLayout->insertWidget(i, results[i]);
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
    return m_results.contains(name) ? m_results[name]->points() : -1;
}

void ResultsWidget::result(const QString &name, int points)
{
    if(!m_results.contains(name))
        return;
    m_results[name]->points(points);
    arrangeResults();
}
