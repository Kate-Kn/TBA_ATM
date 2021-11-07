#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QStringList charityTitles= {"Kind hands","Love and peace", "Take responsibility", "Lala", "djd"}; //getCharityTitle()
    for(int i=0;i<charityTitles.length();++i){
        QPushButton *pushButton = new QPushButton(charityTitles.at(i));
        ui->gridLayout->addWidget(pushButton);
        this->connect(pushButton, SIGNAL( clicked() ), this, SLOT(pushButtonClicked()));
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
     widget->setStyleSheet("font: 75 20pt \"MS Shell Dlg 2\"");
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
    isCardTransfer = true;
}
void MainWindow::on_charityTransfer_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::pushButtonClicked()
{
    QPushButton *bu = qobject_cast<QPushButton*>(sender());
    ui->charityMessage->setStyleSheet("font: 75 11pt \"MS Shell Dlg 2\"");
    ui->charityMessage->setAlignment(Qt::AlignCenter);
    ui->charityMessage->setText("Transfer to: " + bu->text());
    ui->trT->setVisible(false);
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_mobileTransfer_clicked()
{
    isMobileTransfer = true;
    ui->transferTo_2->setText("Enter phone: ");
    ui->trT->setText("0");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_changePin_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_checkBalance_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
     QString balance = ""; //getBalance(cardNum)
     ui->balanceLabel->setStyleSheet("font: 75 30pt \"MS Shell Dlg 2\"");
     ui->balanceLabel->setText("Your balance is: " + balance);
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
    ui->trT->setText("");
    ui->inputAmount->setText("");
    ui->charityMessage -> setText("");
    isMobileTransfer = false;
    isTransferToFilled = false;
    isCardTransfer = false;
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
void MainWindow::on_sbm_clicked()
{
    if(isMobileTransfer)
    {

    }else if (isCardTransfer)
    {

    }else
    {
        //database check
        bool isAmountAvailable = true;
        if(isAmountAvailable)
        {
            ui->lastOpSuccess->setText("Transfer succeded");
            on_bck_clicked();
        }else
        {
            ui->la_error->setText("Amount of money is not available");
            ui->inputAmount->setText("");
            checkTransferField();
        }
    }
}
void MainWindow::on_pu_0_clicked()
{
    caseTransfer("0");
    checkTransferField();
}
void MainWindow::on_pu_1_clicked()
{
     caseTransfer("1");
     checkTransferField();
}
void MainWindow::on_pu_2_clicked()
{
    caseTransfer("2");
    checkTransferField();
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

void MainWindow::checkTransferField()
{
    if(isMobileTransfer)
    {
        if(ui->trT->toPlainText().length() == 9)
            isTransferToFilled = true;
        else
            isTransferToFilled=false;
    }else if(isCardTransfer)
    {
        if(ui->trT->toPlainText().length() == 4)
            isTransferToFilled = true;
        else
            isTransferToFilled = false;
    }

}
void MainWindow::caseTransfer(QString num)
{
    if (isMobileTransfer){
    if(isTransferToFilled)
        addNumber(num, ui->inputAmount,9);
    else
        addNumber(num, ui->trT, 9);
    }else if(isCardTransfer)
    {
        if(isTransferToFilled)
            addNumber(num, ui->inputAmount,9);
        else
            addNumber(num, ui->trT, 4);
    }else
    {
        addNumber(num, ui->inputAmount,9);
    }
}
void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->p_error->setText("");
}
void MainWindow::changeField()
{
    if(ui->oldPin->toPlainText().length() == 4)
        isFilledOld = true;
    else
        isFilledOld = false;

    if(ui->newPin->toPlainText().length() == 4)
        isFilledNew = true;
    else
        isFilledNew =false;

    if(ui->newPinRepeat->toPlainText().length() == 4)
        isFilledNewRepeat = true;
    else
        isFilledNewRepeat = false;
}
void MainWindow::checkCase(QString str)
{
    if(!isFilledOld)
        addNumber(str, ui->oldPin, 4);
    else if(!isFilledNew)
        addNumber(str, ui->newPin, 4);
    else if(!isFilledNewRepeat)
        addNumber(str, ui->newPinRepeat,4);
}
void MainWindow::on_p_1_clicked()
{
    checkCase("1");
    changeField();
}
void MainWindow::on_p_0_clicked()
{
    checkCase("0");
    changeField();
}
void MainWindow::on_p_2_clicked()
{
    checkCase("2");
    changeField();
}
void MainWindow::on_p_3_clicked()
{
    checkCase("3");
    changeField();
}
void MainWindow::on_p_4_clicked()
{
    checkCase("4");
    changeField();
}
void MainWindow::on_p_5_clicked()
{
    checkCase("5");
    changeField();
}
void MainWindow::on_p_6_clicked()
{
    checkCase("6");
    changeField();
}
void MainWindow::on_p_7_clicked()
{
    checkCase("7");
    changeField();
}
void MainWindow::on_p_8_clicked()
{
    checkCase("8");
    changeField();
}
void MainWindow::on_p_9_clicked()
{
    checkCase("9");
    changeField();
}
void MainWindow::on_p_c_clicked()
{
    if(!isFilledOld){
        QString current = ui->oldPin->toPlainText();
        if (current.length()>0)
           ui->oldPin->setText(current.first(current.length() - 1));
    }
    else if(!isFilledNew){
        QString current = ui->newPin->toPlainText();
        if (current.length()>0)
           ui->newPin->setText(current.first(current.length() - 1));
    }
    else if(!isFilledNewRepeat){
        QString current = ui->newPinRepeat->toPlainText();
        if (current.length()>0)
           ui->newPinRepeat->setText(current.first(current.length() - 1));
    }
}
void MainWindow::on_p_c_a_clicked()
{
    if(!isFilledOld){
        ui->oldPin->setText("");
    }
    else if(!isFilledNew){
        ui->newPin->setText("");
    }
    else if(!isFilledNewRepeat){
        ui->newPinRepeat->setText("");
    }
}
void MainWindow::on_p_submit_clicked()
{
    if(!isFilledOld||!isFilledNew||!isFilledNewRepeat)
    {
        ui->p_error->setText("Fill all fields");
        return;
    }
    if(newPin!=newPinRepeat)
    {
        ui->p_error->setText("Fileds new pin and repeat new pin are not the same");
        ui->newPin->setText("");
        ui->newPinRepeat->setText("");
        changeField();
        return;
    }
    //check old pin from database
    bool isCorrect = true;
    if(isCorrect)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->lastOpSuccess->setText("Pin successfully changed");
        ui->p_error->setText("");
    }else
    {
        ui->p_error->setText("Incorrect old pin");
        ui->oldPin->setText("");
        changeField();
        return;
    }
}
