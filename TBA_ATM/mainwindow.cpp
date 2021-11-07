#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QRegularExpression rx("[0-9]{4}");
    QRegularExpressionValidator *v = new QRegularExpressionValidator(rx);
    ui->newPinRepeat->setValidator(v);
    ui->newPin->setValidator(v);
    ui->oldPin->setValidator(v);
    QStringList charityTitles= {"Kind hands","Love and peace", "Take responsibility", "Lala", "djd"}; //getCharityTitle()
    for(int i=0;i<charityTitles.length();++i){
        QPushButton *pushButton = new QPushButton(charityTitles.at(i));
        ui->gridLayout->addWidget(pushButton);
        ui->charityEnumeration->connect(pushButton, SIGNAL( clicked() ), ui->charityEnumeration, SLOT(pushButtonClicked(charityTitles[i])));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addNumber(QString str, QTextBrowser *widget, int lengthLessThan)
{
   if(widget->toPlainText().length()< lengthLessThan ){
     QString current = widget->toPlainText();
     widget->setText( current + str);
     widget->setStyleSheet("font: 75 24pt \"MS Shell Dlg 2\"");
    }
}

void MainWindow::on_pushButton_clicked()
{
    addNumber("0", ui->inputPin,4);
}
void MainWindow::on_pushButton_1_clicked()
{
    addNumber("1", ui->inputPin,4);
}
void MainWindow::on_pushButton_2_clicked()
{
   addNumber("2", ui->inputPin,4);
}
void MainWindow::on_pushButton_3_clicked()
{
    addNumber("3", ui->inputPin,4);
}
void MainWindow::on_pushButton_4_clicked()
{
    addNumber("4", ui->inputPin,4);
}
void MainWindow::on_pushButton_5_clicked()
{
    addNumber("5", ui->inputPin,4);
}
void MainWindow::on_pushButton_6_clicked()
{
    addNumber("6", ui->inputPin,4);
}
void MainWindow::on_pushButton_7_clicked()
{
    addNumber("7", ui->inputPin,4);
}
void MainWindow::on_pushButton_8_clicked()
{
    addNumber("8", ui->inputPin,4);
}
void MainWindow::on_pushButton_9_clicked()
{
    addNumber("9", ui->inputPin,4);
}
void MainWindow::on_pushButton_c_clicked()
{
    QString current = ui->inputPin->toPlainText();
    if (current.length()>0)
       ui->inputPin->setText(current.first(current.length() - 1));
}
void MainWindow::on_pushButton_ca_clicked()
{
   ui->inputPin->setText("");
}

void MainWindow::on_pushButton_submit_clicked()
{
    //check pin from database and value to isCorrect
    bool isCorrect = true;
    if(isCorrect)
    {
        pin = ui->inputPin ->toPlainText();
        ui->stackedWidget->setCurrentIndex(2);

    }else
    {
        ui->errorPin->setText("Incorrect PIN for indicated card number. Try again");
    }
}

void MainWindow::on_psubmit_clicked()
{
    //check card num from database and value to isCorrect
    bool isCorrect = true;
    if(isCorrect)
    {
        cardNum = ui->input->toPlainText();
        ui->stackedWidget->setCurrentIndex(1);

    }else
    {
        ui->errorCardNum->setText("Incorrect card number. Try again");
    }
}

void MainWindow::on_withdrawMoney2_clicked()
{
    ui->trT->setVisible(false);
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_moneyTransfer_clicked()
{
    ui->transferTo_2->setText("Enter card number: ");
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_charityTransfer_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::pushButtonClicked(QString str)
{
    ui->trT->setText(str);
    ui->trT->setEnabled(false);
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_mobileTransfer_clicked()
{
    ui->transferTo_2->setText("Enter phone: ");
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
void MainWindow::on_pushButton_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_logOut_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_bck_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->transferTo_2->setText("");
    ui->trT->setVisible(true);
    ui->trT->setEnabled(true);
}
void MainWindow::on_backBank_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_p_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_p0_clicked()
{
    addNumber("0", ui->input,4);
}
void MainWindow::on_p1_clicked()
{
    addNumber("1", ui->input,4);
}
void MainWindow::on_p2_clicked()
{
    addNumber("2", ui->input,4);
}
void MainWindow::on_p3_clicked()
{
    addNumber("3", ui->input,4);
}
void MainWindow::on_p4_clicked()
{
    addNumber("4", ui->input,4);
}
void MainWindow::on_p5_clicked()
{
    addNumber("5", ui->input,4);
}
void MainWindow::on_p6_clicked()
{
    addNumber("6", ui->input,4);
}
void MainWindow::on_p7_clicked()
{
    addNumber("7", ui->input,4);
}
void MainWindow::on_p8_clicked()
{
    addNumber("8", ui->input,4);
}
void MainWindow::on_p9_clicked()
{
    addNumber("9", ui->input,4);
}
void MainWindow::on_pc_clicked()
{
    QString current = ui->input->toPlainText();
    if (current.length()>0)
       ui->input->setText(current.first(current.length() - 1));
}
void MainWindow::on_pca_clicked()
{
    ui->input->setText("");
}

void MainWindow::on_pu_0_clicked()
{
    addNumber("0", ui->inputAmount,9);
}
void MainWindow::on_pu_1_clicked()
{
    addNumber("0", ui->inputAmount,9);
}
void MainWindow::on_pu_2_clicked()
{
    addNumber("2", ui->inputAmount,9);
}
void MainWindow::on_pu_3_clicked()
{
    addNumber("3", ui->inputAmount,9);
}
void MainWindow::on_pu_4_clicked()
{
    addNumber("4", ui->inputAmount,9);
}
void MainWindow::on_pu_5_clicked()
{
    addNumber("5", ui->inputAmount,9);
}
void MainWindow::on_pu_6_clicked()
{
    addNumber("6", ui->inputAmount,9);
}
void MainWindow::on_pu_7_clicked()
{
    addNumber("7", ui->inputAmount,9);
}
void MainWindow::on_pu_8_clicked()
{
    addNumber("8", ui->inputAmount,9);
}
void MainWindow::on_pu_9_clicked()
{
    addNumber("9", ui->inputAmount,9);
}
void MainWindow::on_pu_c_clicked()
{
    QString current = ui->inputAmount->toPlainText();
    if (current.length()>0)
       ui->inputAmount->setText(current.first(current.length() - 1));
}
void MainWindow::on_pu_cA_clicked()
{
    ui->inputAmount->setText("");
}

void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
