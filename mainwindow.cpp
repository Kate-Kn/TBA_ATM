#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

