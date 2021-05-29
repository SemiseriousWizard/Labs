#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myglwidget.h"
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myGLWidget *openGLW=new myGLWidget(this);
    QGridLayout *grid=new QGridLayout();
    grid->addWidget(openGLW,0,0);
    ui->centralwidget->setLayout(grid);
}

MainWindow::~MainWindow()
{
    delete ui;
}
