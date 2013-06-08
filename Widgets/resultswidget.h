#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

#include <QWidget>
#include "resultwidget.h"
#include "datatypes.h"
#include <QMap>

namespace Ui {
class ResultsWidget;
}

class ResultWidgetGreater {
public:
    bool operator()(ResultWidget* l, ResultWidget* r) {
        return l->points() > r->points();
    }
};

class ResultsWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ResultsWidget(QWidget *parent = 0);
    ~ResultsWidget();

    void setUsers(const QList<UserData>& users);

    const QMap<QString, int> results() const;

    int result(const QString& name) const;
    void result(const QString& name, int points);
    
protected:
    ResultWidget* addResult(const UserData& user);
    void arrangeResults();

private:
    Ui::ResultsWidget *ui;
    QMap<QString, ResultWidget*> m_results;
};

#endif // RESULTSWIDGET_H
