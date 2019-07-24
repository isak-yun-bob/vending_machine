#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>
using namespace std;



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbCola->setEnabled(false);
    ui->pbTea->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

// Member function
// Write 'Widget::' in front

void Widget::changeMoney(int n) {
    Widget::money += n;
    ui->lcdNumber->display(money);

    if (Widget::money < 100) {
        ui->pbCoffee->setEnabled(false);
        ui->pbCola->setEnabled(false);
        ui->pbTea->setEnabled(false);
    }
    else if (100 <= Widget::money && Widget::money < 150) {
        ui->pbCoffee->setEnabled(true);
        ui->pbCola->setEnabled(false);
        ui->pbTea->setEnabled(false);
    }
    else if (150 <= Widget::money && Widget::money < 200) {
        ui->pbCoffee->setEnabled(true);
        ui->pbCola->setEnabled(true);
        ui->pbTea->setEnabled(false);
    }
    else {
        ui->pbCoffee->setEnabled(true);
        ui->pbCola->setEnabled(true);
        ui->pbTea->setEnabled(true);
    }
}


void Widget::on_pb_10_clicked()
{
    changeMoney(10);
    // QMessageBox msg;
    // msg.information(nullptr, "title", "text");

}

void Widget::on_pb_50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb_100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb_500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCola_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    // change : 10, 50, 100, 500 won
    int ten = 0, fifty = 0, hund = 0, fiveHund = 0;
    fiveHund = (Widget::money / 500);
    Widget::money %= 500;

    hund = (Widget::money / 100);
    Widget::money %= 100;

    fifty = (Widget::money / 50);
    Widget::money %= 50;

    ten = (Widget::money / 10);
    
    QMessageBox msg;

    // Set message and use integer with QVariant().tostring()
    QString msgDetail = "500won : " + QVariant(fiveHund).toString() + \
            "\n100won : " + QVariant(hund).toString() + \
            "\n50won : " + QVariant(fifty).toString() + \
            "\n10won : " + QVariant(ten).toString();

    // QString msgDetail = QStringLiteral("500won : %d\n100won : %d\n").arg(fiveHund, hund);
    msg.information(nullptr, "Change", msgDetail);
    Widget::money = 0;
    ui->lcdNumber->display(money);


}
