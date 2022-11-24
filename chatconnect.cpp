#include "chatconnect.h"
#include "ui_chatconnect.h"

//namespace chatconnect
//{
chatconnect::chatconnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chatconnect)
{
    ui->setupUi(this);
}

chatconnect::~chatconnect()
{
    delete ui;
}

void chatconnect::on_ok_clicked()
{
    mHostname = ui->hostname->text();
    mPort = ui->port->value();
    accept();
}

void chatconnect::on_cancel_clicked()
{
     reject();
}
//} //end namespace chatconnect
