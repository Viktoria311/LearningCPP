#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    number_1 = 0.0;
    number_2 = 0.0;
    operation = Addition;
    //connect(ui->pushButton, SIGNAL(valueChanged(1)), ui->textBrowser, SLOT(append("1")));
    //connect(ui->pushButton, SIGNAL(),ui->textBrowser, SLOT()); // отобразить
    //connect(ui->pushButton, SIGNAL(),ui->textBrowser, SLOT()); // закинуть цифрц в буфер, чтобы потом умножать на степерь десятки

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::is_there_a_dot(const std::vector<int>& vec) const
{
    for (auto elem : vec)
        if (elem == -1) return true;

    return false;
}

double MainWindow::make_a_number()
{
    double num = 0.0;

    if (!is_there_a_dot(buffer))
    {
        auto it = buffer.rbegin();

        for(int i = 0; it != buffer.rend(); ++it, ++i)
           num += (*it)* std::pow(10, i);
    }
    else
    {
        int dot_index;

        double fractional_part = 0.0;

        auto it = buffer.begin();

        for(int i = 0; i < buffer.size(); ++i)
        {
            if (buffer[i] == -1) dot_index = i;
        }

        for(int i = 0; it != buffer.end(); ++it, ++i)
        {
          if ( i < dot_index)
              num += (*it)* std::pow(10, dot_index - i - 1);

          else if (i > dot_index)
              fractional_part += (*it)* std::pow(10, buffer.size() - i);
        }

        fractional_part /= std::pow(10, buffer.size() - dot_index);

        num += fractional_part;
    }

    return num;
}

void MainWindow::on_pushButton_clicked()
{
    buffer.push_back(1);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_2_clicked()
{
    buffer.push_back(2);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_3_clicked()
{
    buffer.push_back(3);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_4_clicked()
{
    buffer.push_back(4);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_5_clicked()
{
    buffer.push_back(5);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_6_clicked()
{
    buffer.push_back(6);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_7_clicked()
{
    buffer.push_back(7);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_8_clicked()
{
    buffer.push_back(8);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_9_clicked()
{
    buffer.push_back(9);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_10_clicked()
{
    buffer.push_back(0);
    ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_16_clicked()
{
    operation = Addition;

    number_1 += make_a_number();

    buffer.clear();
}

void MainWindow::on_pushButton_12_clicked()
{
    number_2 += make_a_number();

    switch (operation) {
    case Addition:
        number_1 += number_2;
        number_2 = 0.0;
        ui->lcdNumber->display(number_1);
        break;
    case Substraction:
        number_1 -= number_2;
        number_2 = 0.0;
        ui->lcdNumber->display(number_1);
        break;
    case Multiplication:
        number_1 *= number_2;
        number_2 = 0.0;
        ui->lcdNumber->display(number_1);
        break;
    case Division:
        number_1 /= number_2;
        number_2 = 0.0;
        ui->lcdNumber->display(number_1);
         break;
    case Division_100:
        number_1 /= 100;
        number_2 = 0.0;
        ui->lcdNumber->display(number_1);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    operation = Substraction;

    number_1 += make_a_number();

    buffer.clear();

}

void MainWindow::on_pushButton_14_clicked()
{
    operation = Multiplication;

    number_1 += make_a_number();

    buffer.clear();
}

void MainWindow::on_pushButton_11_clicked()
{
    operation = Division;

    number_1 += make_a_number();

    buffer.clear();
}

void MainWindow::on_pushButton_13_clicked()
{
    //DOT
    ui->lcdNumber->display(make_a_number());
    buffer.push_back(-1);
}

void MainWindow::on_pushButton_17_clicked()
{
    //BACKSPACE
    if (!buffer.empty())
        buffer.pop_back();

     ui->lcdNumber->display(make_a_number());
}

void MainWindow::on_pushButton_18_clicked()
{
    //CLEAR
    buffer.clear();
    number_1 = number_2 = 0.0;
    ui->lcdNumber->display(0);
}

void MainWindow::on_pushButton_19_clicked()
{
    // %
    on_pushButton_12_clicked(); // =

    operation = Division_100;

    buffer.clear();

    on_pushButton_12_clicked(); // =
}
