#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include "AuthCard.h"
#include "Card.h"
#include "TransactionService.h"
#include "Authorization.h"
#include "TransactionsCardAccount.h"
#include "TransactionsCards.h"
#include "TransactionCash.h"
#include "Cryptor.h"
#include "Storage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//as database is not ready for usage all proccesses are simulated in here
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    AuthCard authCard;
    Card card;
    IAuthorization* auth;
    ITransactionService* transactionService;
    ICryptor* cryptor;
    IStorage* storage;

    QString cardNum = "";
    QString pin = "";
    bool isVisible = false;
    QString chosenCharity = "";
    bool isFilledOld = false;
    bool isFilledNew = false;
    bool isFilledNewRepeat = false;
    bool isTransferToFilled = false;
    QString oldPin ="";
    QString newPin = "";
    QString newPinRepeat = "";
    bool isMobileTransfer = false;
    bool isCardTransfer = false;
    void addNumber(QString str, QTextBrowser *widget, int len);
    void changeField();
    void checkCase(QString num);
    void caseTransfer(QString num);
    void checkTransferField();
    void clearPins();
    int balance = 0;
private slots:
    //pin window
    void pushButtonClicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_c_clicked();
    void on_pushButton_ca_clicked();
    void on_pushButton_submit_clicked();
    void on_pushButton_back_clicked();
    void on_see_clicked();

    //card window
    void on_psubmit_clicked();
    void on_p0_clicked();
    void on_p1_clicked();
    void on_p2_clicked();
    void on_p3_clicked();
    void on_p4_clicked();
    void on_p5_clicked();
    void on_p6_clicked();
    void on_p7_clicked();
    void on_p8_clicked();
    void on_p9_clicked();
    void on_pc_clicked();
    void on_pca_clicked();


    //bank operations window
    void on_withdrawMoney2_clicked();
    void on_changePin_clicked();
    void on_checkBalance_2_clicked();
    void on_logOut_clicked();
    void on_mobileTransfer_clicked();
    void on_moneyTransfer_clicked();
    void on_charityTransfer_clicked();

    //withdrow money window
    void on_bck_clicked();
    void on_pu_0_clicked();
    void on_pu_1_clicked();
    void on_pu_2_clicked();
    void on_pu_3_clicked();
    void on_pu_4_clicked();
    void on_pu_5_clicked();
    void on_pu_6_clicked();
    void on_pu_7_clicked();
    void on_pu_8_clicked();
    void on_pu_9_clicked();
    void on_pu_c_clicked();
    void on_pu_cA_clicked();
    void on_sbm_clicked();

    //check balance window
    void on_backBank_clicked();
    void on_p_0_clicked();
    void on_p_1_clicked();
    void on_p_2_clicked();
    void on_p_3_clicked();
    void on_p_4_clicked();
    void on_p_5_clicked();
    void on_p_6_clicked();
    void on_p_7_clicked();
    void on_p_8_clicked();
    void on_p_9_clicked();
    void on_p_c_clicked();
    void on_p_c_a_clicked();
    void on_p_submit_clicked();

    //change pin window
    void on_p_back_clicked();

    //charity enumeration window
    void on_back_clicked();
};
#endif // MAINWINDOW_H
