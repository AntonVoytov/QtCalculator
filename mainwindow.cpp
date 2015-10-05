#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_0_clicked()
{
    expr += "0";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_1_clicked()
{
    expr += "1";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_2_clicked()
{
    expr += "2";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_3_clicked()
{
    expr += "3";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_4_clicked()
{
    expr += "4";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_5_clicked()
{
    expr += "5";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_6_clicked()
{
    expr += "6";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_7_clicked()
{
    expr += "7";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_8_clicked()
{
    expr += "8";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_9_clicked()
{
    expr += "9";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_dot_clicked()
{
    expr += ".";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_plus_clicked()
{
    expr += "+";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_minus_clicked()
{
    expr += "-";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_multiple_clicked()
{
    expr += "*";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_divide_clicked()
{
    expr += "/";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_Obracket_clicked()
{
    expr += "(";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_Cbracket_clicked()
{
    expr += ")";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_power_clicked()
{
    expr += "^";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_clear_clicked()
{
    expr.clear();
    ui->lineEdit->setText(expr);
}

void MainWindow::on_pushButton_equalls_clicked()
{
    QString res;
    if (expr.isEmpty())
    {
        expr = ui->lineEdit->text();
        res = QString::fromStdString(receive(expr.toUtf8().constData()));
    }
    else
    {
        res = QString::fromStdString(receive(expr.toUtf8().constData()));
    }
    expr = res;
    ui->lineEdit->setText(res);

}

