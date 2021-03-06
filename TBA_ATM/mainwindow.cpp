#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <QSqlQuery>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    cryptor = new Cryptor();
    storage = new Storage(cryptor);
    auth = new Authorization(storage, cryptor);
    transactionService = new TransactionService(storage);
    charityAcc = storage->getAllCharitiyTitles();
        foreach (QString k, charityAcc.keys()){
            QPushButton *pushButton = new QPushButton(charityAcc.take(k));
            pushButton->setObjectName(k);
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
     widget->setStyleSheet("font: 20pt \"MS Shell Dlg 2\"");
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="0";
    }
    addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_1_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="1";
    }
    addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_2_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="2";
    }
   addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_3_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="3";
    }
    addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_4_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="4";
    }
    addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_5_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="5";
    }
    addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_6_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="6";
    }
    addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_7_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="7";
    }
    addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_8_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="8";
    }
    addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_9_clicked()
{
    if(isVisible)
          on_see_clicked();
    if(ui->inputPin->toPlainText().length()< 4 )
    {
        pin+="9";
    }
    addNumber("*", ui->inputPin,4);
}
void MainWindow::on_pushButton_c_clicked()
{
    if(isVisible)
          on_see_clicked();
    QString current = ui->inputPin->toPlainText();
    if (current.length()>0){
       ui->inputPin->setText(current.first(current.length() - 1));
       pin = pin.first(pin.length() - 1);
    }
}
void MainWindow::on_pushButton_ca_clicked()
{
    if(isVisible)
          on_see_clicked();
   ui->inputPin->setText("");
   pin= "";
}
void MainWindow::on_see_clicked()
{
    if(!isVisible){
      ui->inputPin->setText(pin);
      ui->see->setText("Hide");
      isVisible=true;
    }
    else
    {
      isVisible=false;
      QString str = "";
      for(int i=0;i<pin.length();++i)
      {
          str+="*";
      }
      ui->inputPin->setText(str);
      ui->see->setText("See");
    }
}
void MainWindow::on_pushButton_10_clicked()
{
    if(!isVisible){
      ui->oldPin->setText(oldPin);
      ui->pushButton_10->setText("Hide");
      isVisible=true;
    }
    else
    {
      isVisible=false;
      QString str = "";
      for(int i=0;i<oldPin.length();++i)
      {
          str+="*";
      }
      ui->oldPin->setText(str);
      ui->pushButton_10->setText("See");
    }
}
void MainWindow::on_pushButton_11_clicked()
{
    if(!isVisible){
      ui->newPin->setText(newPin);
      ui->pushButton_11->setText("Hide");
      isVisible=true;
    }
    else
    {
      isVisible=false;
      QString str = "";
      for(int i=0;i<newPin.length();++i)
      {
          str+="*";
      }
      ui->newPin->setText(str);
      ui->pushButton_11->setText("See");
    }
}
void MainWindow::on_pushButton_12_clicked()
{
    if(!isVisible){
      ui->newPinRepeat->setText(newPinRepeat);
      ui->pushButton_12->setText("Hide");
      isVisible=true;
    }
    else
    {
      isVisible=false;
      QString str = "";
      for(int i=0;i<newPinRepeat.length();++i)
      {
          str+="*";
      }
      ui->newPinRepeat->setText(str);
      ui->pushButton_12->setText("See");
    }
}
void MainWindow::on_pushButton_submit_clicked()
{
    //check pin from database and value to isCorrect
    bool isCorrect = (ui->inputPin->toPlainText().length() == 4);
    if(isCorrect)
    {
        try{
        authCard.pincode(pin);
        }catch(AuthCard::BadAuthCard ba)
        {
            ui->errorPin->setText(ba.diagnose());
            return;
        }
        try{
            if (! auth->checkAuthorizationData(authCard))
            {
              ui->errorPin->setText("Incorrect PIN or card. Try again");
              return;
            }
            card = auth->authorize(authCard);
            ui->errorPin->setText("");
            ui->stackedWidget->setCurrentIndex(2);
        }
        catch(IAuthorization::BadAuthorization ba)
        {
            ui->errorPin->setText(ba.diagnose());
        }
        authCard = AuthCard();
    }else
    {
        ui->errorPin->setText("Incorrect PIN for indicated card number. Try again");
    }
}

void MainWindow::on_psubmit_clicked()
{
    //check card num from database and value to isCorrect
    bool isCorrect = (ui->input->toPlainText().length() == 4);
    if(isCorrect)
    {
        try{
        authCard = AuthCard();
        authCard.cardNumber(ui->input->toPlainText());

        }catch(AuthCard::BadAuthCard ba)
        {
            ui->errorCardNum->setText(ba.diagnose());
            return;
        }
        ui->stackedWidget->setCurrentIndex(1);
        ui->p_error->setText("");

    }else
    {
        ui->errorCardNum->setText("Incorrect card number. Try again");
    }
}

void MainWindow::on_withdrawMoney2_clicked()
{
    ui->trT->setVisible(false);
    ui->stackedWidget->setCurrentIndex(3);
    ui->lastOpSuccess->setText("");
    isTransferToFilled = true;
}
void MainWindow::on_moneyTransfer_clicked()
{
    ui->transferTo_2->setText("Enter card number: ");
    ui->stackedWidget->setCurrentIndex(3);
    isCardTransfer = true;
    ui->lastOpSuccess->setText("");
}
void MainWindow::on_charityTransfer_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->lastOpSuccess->setText("");
    isCharityTransfer = true;
    isTransferToFilled = true;
}
void MainWindow::pushButtonClicked()
{
    QPushButton *bu = qobject_cast<QPushButton*>(sender());
    ui->charityMessage->setStyleSheet("font: 75 11pt \"MS Shell Dlg 2\"");
    ui->charityMessage->setAlignment(Qt::AlignCenter);
    ui->charityMessage->setText("Transfer to: " + bu->text());
    ui->trT->setVisible(false);
    ui->stackedWidget->setCurrentIndex(3);
    charity = bu->objectName();
}
void MainWindow::on_mobileTransfer_clicked()
{
    isMobileTransfer = true;
    ui->transferTo_2->setText("Enter phone: ");
    ui->trT->setStyleSheet("font: 20pt \"MS Shell Dlg 2\"");
    ui->trT->setText("0");
    ui->stackedWidget->setCurrentIndex(3);
    ui->lastOpSuccess->setText("");
}

void MainWindow::on_changePin_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->lastOpSuccess->setText("");
}

void MainWindow::on_checkBalance_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
    // QString balance = ""; //getBalance(cardNum)
     ui->balanceLabel->setStyleSheet("font: 75 30pt \"MS Shell Dlg 2\"");
     card = storage->getCard(card.cardNumber());
     ui->balanceLabel->setText("Your balance is: " + QString::number(card.balance()));
     ui->lastOpSuccess->setText("");
}
void MainWindow::on_pushButton_back_clicked()
{
    pin = "";
    cardNum = "";
    ui->stackedWidget->setCurrentIndex(0);
    ui->input->setText("");
    ui->errorPin->setText("");
    ui->inputPin->setText("");
}
void MainWindow::on_logOut_clicked()
{
    pin = "";
    cardNum = "";
    ui->inputPin->setText("");
    ui->input->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_bck_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->transferTo_2->setText("");
    ui->trT->setVisible(true);
    ui->trT->setEnabled(true);
    ui->trT->setText("");
    ui->p_error->setText("");
    ui->inputAmount->setText("");
    ui->charityMessage -> setText("");
    isMobileTransfer = false;
    isTransferToFilled = false;
    isCardTransfer = false;
    isCharityTransfer = false;
    ui->la_error->setText("");
}
void MainWindow::on_backBank_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_p_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->oldPin->setText("");
    ui->newPin->setText("");
    ui->newPinRepeat->setText("");
    oldPin ="";
    newPin ="";
    newPinRepeat="";
    ui->p_error->setText("");
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
    card = storage->getCard(card.cardNumber());
    if (ui->inputAmount->toPlainText().toInt() > card.balance())
    {
        ui->la_error->setText("Not enough money");
        ui->inputAmount->setText("");
        checkTransferField();
        return;
    }
    if (isCardTransfer)
    {
        Card toCard;
        try
        {
         toCard = storage->getCard(ui->trT->toPlainText());
        }catch(IStorage::BadStorage bs)
        {
            ui->la_error->setText(bs.diagnose());
            ui->inputAmount->setText("");
            checkTransferField();
            return;
        }catch(Card::BadCard)
        {
            ui->la_error->setText("Not existing card. Try again");
            ui->inputAmount->setText("");
            ui->trT->setText("");
            checkTransferField();
            return;
        }
        TransactionsCards transactionCard;
        try{
        transactionCard = TransactionsCards(ui->inputAmount->toPlainText().toInt(),QDate().currentDate(), "");
        }catch(ITransaction::BadTransction bs)
        {
            ui->la_error->setText(bs.diagnose());
            ui->inputAmount->setText("");
            ui->trT->setText("");
            checkTransferField();
            return;
        }
        try
        {
           transactionService->transactionCards(transactionCard, card, toCard);
        }catch(ITransactionService::BadTransactionService bs)
        {
            ui->la_error->setText(bs.diagnose());
            ui->inputAmount->setText("");
            checkTransferField();
            return;
        }
         ui->lastOpSuccess->setText("Transfer succeded");
         balance -= ui->inputAmount->toPlainText().toInt();
         on_bck_clicked();
    }
    else if (isCharityTransfer)
    {
        Account toAccount;
        try
        {
         toAccount = storage->getAccount(charity);
        }catch(IStorage::BadStorage bs)
        {
            ui->la_error->setText(bs.diagnose());
            ui->inputAmount->setText("");
            checkTransferField();
            return;
        }
        TransactionsCardAccount transactionAccount;
        try{
        transactionAccount = TransactionsCardAccount(ui->inputAmount->toPlainText().toInt(),QDate().currentDate(), "");
        }catch(ITransaction::BadTransction bs)
        {
            ui->la_error->setText(bs.diagnose());
            ui->inputAmount->setText("");
            ui->trT->setText("");
            checkTransferField();
            return;
        }
        try
        {
           transactionService->transactionCardAccount(transactionAccount, card, toAccount);
        }catch(ITransactionService::BadTransactionService bs)
        {
            ui->la_error->setText(bs.diagnose());
            ui->inputAmount->setText("");
            checkTransferField();
            return;
        }
         ui->lastOpSuccess->setText("Transfer succeded");
         balance -= ui->inputAmount->toPlainText().toInt();
         on_bck_clicked();
    }else
    {
        TransactionCash transactionCash;
        try{
        transactionCash = TransactionCash(ui->inputAmount->toPlainText().toInt(),QDate().currentDate());
        }catch(ITransaction::BadTransction bs)
        {
            ui->la_error->setText(bs.diagnose());
            ui->inputAmount->setText("");
            if(isMobileTransfer)
                 ui->trT->setText("0");
            else
                ui->trT->setText("");
            checkTransferField();
            return;
        }
        try
        {
           transactionService->transactionCash(transactionCash, card);
        }catch(ITransactionService::BadTransactionService bs)
        {
            ui->la_error->setText(bs.diagnose());
            if(isMobileTransfer)
                 ui->trT->setText("0");
            else
                ui->trT->setText("");
            ui->inputAmount->setText("");
            checkTransferField();
            return;
        }
         ui->lastOpSuccess->setText("Transfer succeded");
         balance -= ui->inputAmount->toPlainText().toInt();
         on_bck_clicked();
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
    caseTransfer("3");
    checkTransferField();
}
void MainWindow::on_pu_4_clicked()
{
    caseTransfer("4");
    checkTransferField();
}
void MainWindow::on_pu_5_clicked()
{
    caseTransfer("5");
    checkTransferField();
}
void MainWindow::on_pu_6_clicked()
{
    caseTransfer("6");
    checkTransferField();
}
void MainWindow::on_pu_7_clicked()
{
    caseTransfer("7");
    checkTransferField();
}
void MainWindow::on_pu_8_clicked()
{
    caseTransfer("8");
    checkTransferField();
}
void MainWindow::on_pu_9_clicked()
{
    caseTransfer("9");
    checkTransferField();
}
void MainWindow::on_pu_c_clicked()
{
    if(isTransferToFilled){
     QString current = ui->inputAmount->toPlainText();
     if (current.length()>0)
        ui->inputAmount->setText(current.first(current.length() - 1));
    }else
    {
        QString current = ui->trT->toPlainText();
        if (current.length()>0)
           ui->trT->setText(current.first(current.length() - 1));
    }
    }
void MainWindow::on_pu_cA_clicked()
{
    if(isTransferToFilled)
       ui->inputAmount->setText("");
    else if (isMobileTransfer)
       ui->trT->setText("0");
    else
        ui->trT->setText("");

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
    if(!isFilledOld){
        if(isVisible)
              on_pushButton_10_clicked();
        if(ui->oldPin->toPlainText().length()< 4 )
        {
            oldPin+=str;
        }
        addNumber("*", ui->oldPin, 4);
    }
    else if(!isFilledNew){
        if(isVisible)
              on_pushButton_11_clicked();
        if(ui->newPin->toPlainText().length()< 4 )
        {
            newPin+=str;
        }
        addNumber("*", ui->newPin, 4);
    }
    else if(!isFilledNewRepeat){
        if(isVisible)
              on_pushButton_12_clicked();
        if(ui->newPinRepeat->toPlainText().length()< 4 )
        {
            newPinRepeat+=str;
        }
        addNumber("*", ui->newPinRepeat,4);
    }
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
        if (current.length()>0){
           ui->oldPin->setText(current.first(current.length() - 1));
           oldPin = oldPin.first(oldPin.length() - 1);
        }
    }
    else if(!isFilledNew){
        QString current = ui->newPin->toPlainText();
        if (current.length()>0){
           ui->newPin->setText(current.first(current.length() - 1));
           newPin = newPin.first(newPin.length() - 1);
        }
    }
    else if(!isFilledNewRepeat){
        QString current = ui->newPinRepeat->toPlainText();
        if (current.length()>0){
           ui->newPinRepeat->setText(current.first(current.length() - 1));
           newPinRepeat = newPinRepeat.first(newPinRepeat.length() - 1);
        }
    }
}
void MainWindow::on_p_c_a_clicked()
{
    if(!isFilledOld){
        ui->oldPin->setText("");
        oldPin ="";
    }
    else if(!isFilledNew){
        ui->newPin->setText("");
        newPin ="";
    }
    else if(!isFilledNewRepeat){
        ui->newPinRepeat->setText("");
        newPinRepeat ="";
    }
}
void MainWindow::on_p_submit_clicked()
{
    if( ui->newPin->toPlainText()!= ui->newPinRepeat->toPlainText())
    {
        ui->p_error->setText("Fileds new pin and repeat new pin are not the same");
        clearPins();
        return;
    }
    if(!isFilledOld||!isFilledNew||!isFilledNewRepeat)
    {
        ui->p_error->setText("Fill all fields");
        clearPins();
        return;
    }
    if(newPin!=newPinRepeat)
    {
        ui->p_error->setText("Fileds new pin and repeat new pin are not the same");
        clearPins();
        return;
    }
    authCard.cardNumber(card.cardNumber());
    authCard.pincode(oldPin);
        try{
        if (! auth->checkAuthorizationData(authCard))
        {
          ui->p_error->setText("Incorrect old PIN. Try again");
          clearPins();
          return;
        }
        auth->authorize(authCard);
         }
        catch(IAuthorization::BadAuthorization ba)
            {
            ui->p_error->setText(ba.diagnose());
            return;
        }
     authCard.pincode(newPin);
    try
    {
        auth->checkAuthorizationData(authCard);

    }catch(IAuthorization::BadAuthorization)
    {
         ui->p_error->setText("Incorrect old Pin");
         clearPins();
         return;
    }
    authCard = AuthCard();
    try
    {
        storage->changePassword(card, newPin);
        clearPins();
        ui->stackedWidget->setCurrentIndex(2);
        ui->lastOpSuccess->setText("Pin changed!");
    }catch(IStorage::BadStorage ba)
    {
        ui->p_error->setText(ba.diagnose());
        clearPins();
    }
}
void MainWindow::clearPins()
{
    ui->oldPin->setText("");
    ui->newPin->setText("");
    ui->newPinRepeat->setText("");
    oldPin = "";
    newPin ="";
    newPinRepeat ="";
    changeField();
}
