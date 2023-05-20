#ifndef ITEM_ADD_H
#define ITEM_ADD_H
#include <QDialog>
#include<QDebug>
#include<QString>
#include<QMessageBox>
#include <QSqlDatabase>

namespace Ui {
class item_add;
}

class item_add : public QDialog
{
    Q_OBJECT

public:
    explicit item_add(QWidget *parent = nullptr);
    ~item_add();

private slots:




private:
    Ui::item_add *ui;
    QSqlDatabase db;
    QString prc;
    qint32 price;
    QString rack;
    QString code;
};

#endif // ITEM_ADD_H
