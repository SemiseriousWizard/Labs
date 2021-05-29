#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_inputDataBtn_clicked();

    void on_createBalancedTreeBtn_clicked();

    void on_clearSceneBtn_clicked();

public:
    Ui::Widget *ui;
};
#endif // WIDGET_H
