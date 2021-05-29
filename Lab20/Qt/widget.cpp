#include "widget.h"
#include "ui_widget.h"
#include <QProcess>
#include "binarytree.h"
#include <QFile>
#include <QTextStream>
QGraphicsScene *scene;

int amountOfLinesInFile = 0;
int count_lines_in_file(QFile &file_path){
    int index = 0;
    file_path.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file_path);
    QString line = "";
    while ((line = file_path.readLine()) != "")
        index++;
    file_path.flush();
    file_path.close();
    return index;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this); //создание экземпляров виджетов, информация о которых берется из формы
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 2000, 2000);
    ui->graphicsView->setScene(scene); //отображение сцены с элементами
    scene->clear();
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_inputDataBtn_clicked()
{
    scene->clear();
    QProcess process(this);
    process.startDetached("C:/Users/user/Documents/BinTreeQt/Lab20_qt/run.bat");
}

void Widget::on_createBalancedTreeBtn_clicked()
{
    scene->clear();
    BinaryTree *balancedTree = new BinaryTree;
    QFile inputFile("C:/Users/user/Documents/BinTreeQt/Lab20_qt/elements.txt");
    amountOfLinesInFile = count_lines_in_file(inputFile);
    balancedTree->create_balanced_binary_tree(amountOfLinesInFile);
    balancedTree->print_tree(scene);
}

void Widget::on_clearSceneBtn_clicked()
{
    scene->clear();
}
