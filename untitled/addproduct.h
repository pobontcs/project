#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H
#include <QDialog>
#include<QDebug>
#include<QString>
#include<QMessageBox>
#include<QDebug>
#include <QSqlDatabase>

namespace Ui {
class AddProduct;
}

class AddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = nullptr);
    ~AddProduct();

public slots:
    void on_Adding_product_confirm_button_clicked();

private:
    Ui::AddProduct *ui;
    QString code;
    QString name;
    QString price; int prc;
    QSqlDatabase db;
};

#endif // ADDPRODUCT_H
