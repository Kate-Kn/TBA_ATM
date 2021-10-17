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
    QString current = ui->textBrowser_2->toPlainText();
    ui->textBrowser_2->setText( current + str);
    ui->textBrowser_2->setStyleSheet("font: 75 24pt \"MS Shell Dlg 2\"");
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
    QString current = ui->textBrowser_2->toPlainText();
    if (current.length()>0)
        ui->textBrowser_2->setText(current.first(current.length() - 1));
}
void MainWindow::on_pushButton_13_clicked()
{
     ui->textBrowser_2->setText("");
}
void MainWindow::on_pushButton_submit_clicked()
{
    //check card num from database and value to isCorrect
    bool isCorrect = true;
    if(isCorrect)
    {
//        ui->textBrowser_2->setText("");
//        ui->label->setText("Enter PIN: ");
//        ui->label->setStyleSheet("font: 75 24pt \"MS Shell Dlg 2\"");
//        ui->pushButton_submit->setEnabled(false);
//        ui->pushButton_submit->setVisible(false);
//        ui->pushButton_submit_2->setEnabled(true);
//        ui->pushButton_submit_2->setVisible(true);
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
