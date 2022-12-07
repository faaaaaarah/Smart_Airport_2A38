#include "modifier.h"
#include "ui_modifier.h"
#include "connection.h"
#include "mainwindow.h"
#include "mainwindow.h"
modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);

}

modifier::~modifier()
{
    delete ui;
}

void modifier::on_pushButton_k_clicked()
{
    Connection c;

   //c.createconnect();
      int code=ui->lineEditc->text().toInt();


    QString pays=ui->lineEditn->text();
    QString ville=ui->lineEditp->text();

          QString aeroport=ui->lineEditm->text();

             int totvol=ui->lineEditp->text().toInt();
             QString sex="";
     destination D ;
  //  bool test=  D.modifier();
        // ui->tab_aff->setModel(D.afficher());



}
