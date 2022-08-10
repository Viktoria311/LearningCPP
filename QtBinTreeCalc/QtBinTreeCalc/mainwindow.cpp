#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "bin_tree.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      operation(-1),
      pushed_number(-1)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // CLEAR ALL
{
    numbers_vec.clear();
    numbers_tree.clear();
    operation = -1;
    pushed_number = -1;
}

void MainWindow::on_pushButton_2_clicked() // DELETE
{
    operation = Delete;
}

void MainWindow::on_pushButton_3_clicked() // INSERT
{
    operation = Insert;
}

void MainWindow::on_pushButton_4_clicked() // Parent
{
    operation = Parent;
}

void MainWindow::on_pushButton_5_clicked() // LEFT
{
    operation = Left;
}

void MainWindow::on_pushButton_6_clicked() // RIGHT
{
    operation = Right;
}

void MainWindow::on_pushButton_13_clicked() // 1
{
   pushed_number = 1;
   what_to_do();
   operation = -1;
   pushed_number = -1;
}

void MainWindow::on_pushButton_14_clicked() // 2
{
    pushed_number = 2;
    what_to_do();
    operation = -1;
    pushed_number = -1;
}

void MainWindow::on_pushButton_15_clicked() // 3
{
    pushed_number = 3;
    what_to_do();
    operation = -1;
    pushed_number = -1;
}

void MainWindow::on_pushButton_10_clicked() // 4
{
    pushed_number = 4;
    what_to_do();
    operation = -1;
    pushed_number = -1;
}

void MainWindow::on_pushButton_11_clicked() // 5
{
    pushed_number = 5;
    what_to_do();
    operation = -1;
    pushed_number = -1;
}

void MainWindow::on_pushButton_12_clicked() // 6
{
    pushed_number = 6;
    what_to_do();
    operation = -1;
    pushed_number = -1;
}

void MainWindow::on_pushButton_7_clicked() // 7
{
    pushed_number = 7;
    what_to_do();
    operation = -1;
    pushed_number = -1;
}

void MainWindow::on_pushButton_8_clicked() // 8
{
    pushed_number = 8;
    what_to_do();
    operation = -1;
    pushed_number = -1;
}

void MainWindow::on_pushButton_9_clicked() // 9
{
    pushed_number = 9;
    what_to_do();
    operation = -1;
    pushed_number = -1;
}

void MainWindow::show_vec() const
{
    for(auto i : numbers_vec)
        std::cout << i;
    std::cout << std::endl;
}

void MainWindow::what_to_do()
{
    if (pushed_number == -1 || operation == -1)
    {
        // Nothing to do
    }
    else
    {
                    if (operation == Delete)
                    {
                        if (numbers_tree.is_elem_in_tree(pushed_number))
                        {
                            auto i = numbers_vec.begin();
                            while( *i != pushed_number && i != numbers_vec.end())
                                ++i;

                            numbers_vec.erase(i);
                            numbers_tree.remote(pushed_number);
                        }
                        else
                            std::cout << "There is no " << pushed_number << " in the tree" << std::endl;
                    }
                    else if (operation == Insert)
                    {
                        if (numbers_tree.is_elem_in_tree(pushed_number))
                            std::cout << "There has already been " << pushed_number << " element in the tree" << std::endl;
                        else
                        {
                            numbers_vec.push_back(pushed_number);
                            numbers_tree.insert(pushed_number);
                        }

                        show_vec();
                    }
                    else if (operation == Parent)
                    {
                        const Node<int> * p_elem = numbers_tree.find(pushed_number);
                        const Node<int> * parent = numbers_tree.find_parent(pushed_number);

                        if (p_elem == nullptr) // элемента нет
                            std::cout << "There is no " << pushed_number << " in the tree" << std::endl;
                        else if (parent == nullptr)
                            std::cout << pushed_number << " is a root " << std::endl; // root
                        else
                            std::cout << "The parent of " << pushed_number << " is " << parent->value << std::endl;
                    }
                    else if (operation == Left)
                    {
                        if (!(numbers_tree.is_elem_in_tree(pushed_number)))
                            std::cout << "There is no " << pushed_number << " in the tree" << std::endl;
                        else
                        {
                            const Node<int> * left_elem = numbers_tree.find(pushed_number)->left;

                            if (left_elem != nullptr)
                                std::cout << "The left element of " << pushed_number << " is " << left_elem->value << std::endl;
                            else
                                std::cout << "The left element of " << pushed_number << " is nullptr" << std::endl;
                        }
                    }
                    else if (operation == Right)
                    {
                        if (!(numbers_tree.is_elem_in_tree(pushed_number)))
                            std::cout << "There is no " << pushed_number << " in the tree" << std::endl;
                        else
                        {
                            const Node<int> * right_elem = numbers_tree.find(pushed_number)->right;

                            if (right_elem != nullptr)
                                std::cout << "The right element of " << pushed_number << " is " << (numbers_tree.find(pushed_number)->right)->value << std::endl;
                            else
                                std::cout << "The right element of " << pushed_number << " is nullptr" << std::endl;
                        }
                    }
    }

}
