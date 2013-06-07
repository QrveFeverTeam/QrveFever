#include "resultwidget.h"
#include "ui_resultwidget.h"
#include "utils.h"

ResultWidget::ResultWidget(const QString &name, const QColor &color, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultWidget)
{
    ui->setupUi(this);
    setAutoFillBackground(true);

    this->name(name);
    this->color(color);
    points(0);

    setBackground(ui->widget, Qt::white);
    setBackground(ui->widget_2, Qt::white);
}

ResultWidget::~ResultWidget()
{
    delete ui;
}

const QString ResultWidget::name() const
{
    return m_name;
}

void ResultWidget::name(const QString &name)
{
    m_name = name;

    ui->label->setText(name);
}

int ResultWidget::points() const
{
    return m_points;
}

void ResultWidget::points(int points)
{
    m_points = points;

    ui->label_2->setText(QString::number(points));
}

const QColor ResultWidget::color() const
{
    return m_color;
}

void ResultWidget::color(const QColor &color)
{
    m_color = color;

    setBackground(this, color);
}
