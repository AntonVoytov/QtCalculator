#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString expr;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_dot_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_multiple_clicked();
    void on_pushButton_divide_clicked();
    void on_pushButton_Obracket_clicked();
    void on_pushButton_Cbracket_clicked();
    void on_pushButton_power_clicked();
    void on_pushButton_equalls_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
