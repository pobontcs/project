#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item_add.h"
#include "addproduct.h"
int pricing=0;
qint32 points=0;
QString init_display="tk";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
   // db = QSqlDatabase :: addDatabase("QSQLITE");

   // db.setDatabaseName("D:/supermarket/entry/shopping.db");
    //db1.setDatabaseName("D:/supermarket/entry/product.db");
    //db.open();




}
MainWindow::~MainWindow()
{
    db.close();
   // db1.close();
    delete ui;
}
void MainWindow::on_sign_up_first_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_login_button_clicked()
{
    db = QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("D:/supermarket/entry/shopping.db");
    db.open();
    login_Id=ui->login_emaIl_input->text();
    login_password=ui->login_password_input->text();
    QSqlQuery query;
    query.exec("SELECT * FROM user WHERE ID = '"+login_Id+"' AND password = '"+login_password+"'");
    if(login_Id==""&&login_password=="")
    {
        QMessageBox::warning(this,"ERROR!","Invalid Email or Password");
        return;
    }
    if(query.next())
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->supermarket_name_display->setText("Fendloin Mart");
    }
    else{
           QMessageBox::warning(this,"ERROR!","Invalid Email or Password");
    }
    ui->login_emaIl_input->clear();
    ui->login_password_input->clear();
}
void MainWindow::on_Logout_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Signup_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Membership_enable_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_Membership_Value_entry_Button_clicked()
{
    db= QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("D:/supermarket/entry/membership.db");
    db.open();
    QSqlQuery query;

    Membership_Id=ui->Membership_entry_input->text();
    query.exec("SELECT * FROM member WHERE id='"+Membership_Id+"' OR phone='"+Membership_Id+"'");
    if(query.next())
    {
    ui->Membership_entry_input->clear();
    ui->stackedWidget->setCurrentIndex(2);
    ui->Membership_Id_Display->setText(Membership_Id);
    ui->bill_page_membership->setText("ID : "+Membership_Id);
    }
    else{
        QMessageBox :: warning(this,"ERROR","Invalid ID");
    }
}

void MainWindow::on_discount_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Dicount_page_logout_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_Discount_Input_Button_clicked()
{
    ui->Discount_membership_id_input->clear();
    ui->Discount_code_input->clear();
}


void MainWindow::on_Add_item_Button_clicked()
{
   /* item_add itemadd;
    itemadd.setModal(true);
    itemadd.exec();  */
    int select=ui->Product_List_Display->currentRow();
    qDebug()<< select;
    QString s1;
    s1=QString::number(points++);
    if(ui->Membership_Id_Display->text()!=""&& pricing>500)
    {
        ui->Membership_Point_Display->setText(s1);
    }
    if(select==0)
    {
        int prc=1200;
        pricing+=prc;
        QString s =QString::number(pricing);
        ui->Ammount_display->setText(s+"tk");

    }
   else if(select==1)
    {
        int prc=120;
        pricing+=prc;
        QString s =QString::number(pricing);
        ui->Ammount_display->setText(s+"tk");

    }
    else if(select==2)
     {
         int prc=500;
         pricing+=prc;
         QString s =QString::number(pricing);
         ui->Ammount_display->setText(s+"tk");

     }
    else if(select==3)
    {
        int prc=650;
        pricing+=prc;
        QString s =QString::number(pricing);
        ui->Ammount_display->setText(s+"tk");
    }
    else if(select==4)
    {
        int prc=50;
        pricing+=prc;
        QString s =QString::number(pricing);
        ui->Ammount_display->setText(s+"tk");
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(2);
    }

}


void MainWindow::on_Add_Product_Button_clicked()
{
   AddProduct addproduct;
    addproduct.setModal(true);
    addproduct.exec();

}


void MainWindow::on_SIGNUP_CONFIRM_clicked()
{
    signup_email=ui->signup_email_input->text();
    signup_password=ui->Signup_password_input->text();
    signup_id=ui->Signup_ID_input->text();
    shop_name_signup=ui->signup_name_input->text();
    signup_phone=ui->signup_phone_input->text();
    confirm_password=ui->Signup_confirm_Password->text();
    if(signup_password!=confirm_password)
    {
        QMessageBox :: warning(this,"ERROR","WRONG PASSWORD TRY AGAIN");
        ui->Signup_password_input->clear();
        ui->Signup_confirm_Password->clear();
    }
    else{
      db = QSqlDatabase :: addDatabase("QSQLITE");

        db.setDatabaseName("D:/supermarket/entry/shopping.db");
        db.open();
    QSqlQuery query;
    query.exec("INSERT INTO user (shop,email,phone,id,password) VALUES ('"+shop_name_signup+"','"+signup_email+"','"+signup_phone+"','"+signup_id+"','"+signup_password+"')");
    ui->stackedWidget->setCurrentIndex(0);

    ui->Signup_password_input->clear();
    ui->Signup_confirm_Password->clear();
    ui->signup_name_input->clear();
    ui->signup_phone_input->clear();
    ui->signup_email_input->clear();
    ui->Signup_ID_input->clear();
}
 db.close();
}



void MainWindow::on_reload_button_clicked()
{

   ui->Product_List_Display->addItem("soyabin oil");
   ui->Product_List_Display->addItem("eggs");
   ui->Product_List_Display->addItem("beans");
   ui->Product_List_Display->addItem("MEAT");
   ui->Product_List_Display->addItem("bread");
}





void MainWindow::on_Delete_Product_Active_Button_clicked()
{
    QListWidgetItem *it= ui->Product_List_Display->takeItem(mnselect);
    delete it;
}



void MainWindow::on_Product_List_Display_currentRowChanged(int currentRow)
{
    mnselect = currentRow;
}


void MainWindow::on_Bill_confirm_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    QString bill_price=ui->Ammount_display->text();
    QString s2=ui->Membership_Point_Display->text();
    ui->bill_page_ammount->setText(bill_price);
    ui->bill_page_points->setText(s2);
    pricing=0;



}


void MainWindow::on_Membership_signup_button_clicked()
{
    db = QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("D:/supermarket/entry/membership.db");
    db.open();
    QSqlQuery query;
    QString name,phone,id;
    id =ui->Membership_ID_entry_input->text();
    phone=ui->Membership_phone_input->text();
    name=ui->Membership_name_input->text();
    query.exec("INSERT INTO member (id,phone,name) VALUES('"+id+"','"+phone+"','"+name+"')");
    db.close();


}

