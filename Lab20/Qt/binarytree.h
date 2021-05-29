#ifndef BINARYTREE_H
#define BINARYTREE_H
#pragma once
#include <QFile>
#include <QGraphicsScene>
#include "nodeshape.h"

struct Node {
    double data;
    Node* left, * right;
};

class BinaryTree
{
private:
    Node* root;
    void delete_tree(Node* leaf);
    //нахождение количества узлов в поддеревьях
    void get_subtrees_sizes(const int size, int& left_size, int& right_size);
    void create_balanced_binary_tree(Node*& leaf, int size);
    int depth_tree(Node* leaf);
    void print_tree(Node*& leaf, QGraphicsScene *scene);
public:
    NodeShape *nodeshape;
    BinaryTree();
    ~BinaryTree();
    void create_balanced_binary_tree(int size);
    int depth_tree();
    void print_tree(QGraphicsScene *scene);
};

#endif // BINARYTREE_H
