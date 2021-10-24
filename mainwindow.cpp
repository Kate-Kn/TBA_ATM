#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addNumber(QString str)
{
    QString current = ui->input->toPlainText();
    ui->input->setText( current + str);
    ui->input->setStyleSheet("font: 75 24pt \"MS Shell Dlg 2\"");
}
void MainWindow::on_pushButton_2_clicked()
{
   addNumber("2");
}

void MainWindow::on_pushButton_clicked()
{
    addNumber("0");
}
void MainWindow::on_pushButton_1_clicked()
{
    addNumber("1");
}
void MainWindow::on_pushButton_3_clicked()
{
    addNumber("3");
}
void MainWindow::on_pushButton_4_clicked()
{
    addNumber("4");
}
void MainWindow::on_pushButton_5_clicked()
{
    addNumber("5");
}
void MainWindow::on_pushButton_6_clicked()
{
    addNumber("6");
}
void MainWindow::on_pushButton_7_clicked()
{
    addNumber("7");
}
void MainWindow::on_pushButton_8_clicked()
{
    addNumber("8");
}
void MainWindow::on_pushButton_9_clicked()
{
    addNumber("9");
}
void MainWindow::on_pushButton_12_clicked()
{
    QString current = ui->input->toPlainText();
    if (current.length()>0)
        ui->input->setText(current.first(current.length() - 1));
}
void MainWindow::on_pushButton_13_clicked()
{
     ui->input->setText("");
}
void MainWindow::on_pushButton_submit_clicked()
{
    //check card num from database and value to isCorrect
    bool isCorrect = true;
    if(isCorrect)
    {
        ui->stackedWidget->setCurrentIndex(2);

    }else
    {
        ui->label_2->setText("Incorrect card number. Try again");
    }
}
void MainWindow::on_psubmit_clicked()
{
    //check card num from database and value to isCorrect
    bool isCorrect = true;
    if(isCorrect)
    {
        ui->stackedWidget->setCurrentIndex(1);

    }else
    {
        ui->label_2->setText("Incorrect card number. Try again");
    }
}
void MainWindow::on_pushButton_submit_2_clicked()
{
    //check pin from database and value to isCorrect
    bool isCorrect = true;
    if(isCorrect)
    {
         ui->stackedWidget->setCurrentIndex(2);
    }else
    {
        ui->label_2->setText("Incorrect PIN for indicated card number. Try again");
    }
}
void MainWindow::on_withdrawMoney2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_changePin_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_checkBalance_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

