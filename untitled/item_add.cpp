#include "item_add.h"
#include "ui_item_add.h"
#include "mainwindow.h"
#include "addproduct.h"
item_add::item_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::item_add)
{
    ui->setupUi(this);
    db = QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("D:/supermarket/entry/product.db");
    db.open();
   // qDebug() << db1.isOpen();
}

item_add::~item_add()
{
   db.close();
    delete ui;
}





