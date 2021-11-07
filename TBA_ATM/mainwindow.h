#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addNumber(QString str, QTextBrowser *widget, int len);
private:
    Ui::MainWindow *ui;
    QString cardNum = "";
    QString pin = "";
    QString chosenCharity = "";

private slots:
    //pin window
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

    //check balance window
    void on_backBank_clicked();

    //change pin window
    void on_p_back_clicked();

    //charity enumeration window
    void on_back_clicked();
    void pushButtonClicked(QString str);
};
#endif // MAINWINDOW_H
