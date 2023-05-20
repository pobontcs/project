#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QDebug>
#include<QString>
#include<QMessageBox>
#include<QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_sign_up_first_clicked();
    void on_login_button_clicked();
    void on_Logout_admin_clicked();
    void on_Signup_back_button_clicked();
    void on_Membership_enable_button_clicked();
    void on_Membership_Value_entry_Button_clicked();
    void on_discount_button_clicked();
    void on_Dicount_page_logout_button_clicked();
    void on_Discount_Input_Button_clicked();

    void on_Add_item_Button_clicked();

    void on_Add_Product_Button_clicked();

private slots:
    void on_SIGNUP_CONFIRM_clicked();

    void on_reload_button_clicked();



    void on_Delete_Product_Active_Button_clicked();

    void on_Product_List_Display_currentRowChanged(int currentRow);

    void on_Bill_confirm_button_clicked();

    void on_Membership_signup_button_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

    QSqlDatabase db1;


    QString login_Id;
    QString login_password;
    QString login_phone;
    QString Membership_Id;
    QString signup_email;
    QString shop_name_signup;
    QString signup_phone;
    QString signup_id;
    QString signup_password,confirm_password;
    int mnselect=-1;

};
#endif // MAINWINDOW_H
