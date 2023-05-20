#include "addproduct.h"
#include "ui_addproduct.h"
#include "mainwindow.h"
#include<string>
AddProduct::AddProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProduct)
{
    ui->setupUi(this);
    db = QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("D:/supermarket/entry/product.db");
    db.open();

}

AddProduct::~AddProduct()
{
    db.close();
    delete ui;
}
void AddProduct::on_Adding_product_confirm_button_clicked()
{
  QSqlQuery querry;
  name=ui->Product_add_Name_entry->text();
  code=ui->Product_add_code_entry->text();
  price=ui->Product_add_code_entry->text();
  prc=price.toInt();

  querry.exec("INSERT INTO product (code,name,price) VALUES('"+code+"','"+name+"','"+price+"')");
   ui->Product_add_code_entry->clear();
   ui->Product_add_price_entry->clear();
   ui->Product_add_Name_entry->clear();
}

