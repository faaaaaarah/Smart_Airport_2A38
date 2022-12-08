#include "statis.h"
#include "ui_statis.h"
#include "ui_mainwindow.h"
#include<iostream>
#include "mainwindow.h"


statis::statis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statis)
{
    ui->setupUi(this);
}

statis::~statis()
{
    delete ui;
}
int statis::Statis_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from Produit where stock >=20") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}

int statis::Statis_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from Produit where stock <20") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}


void statis::paintEvent(QPaintEvent *)
{

    int b=Statis_partie2();
    cout<<b<<endl ;
    int c=Statis_partie3();
    cout<<c<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
    QPainter painter(this);
    QRectF size=QRectF(150,40,this->width()-600,this->width()-600);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText(" Plus que 20") ;
    painter.setBrush(Qt::green);
    ui->label_3->setNum(q2) ;
    painter.drawPie(size,16*y,16*m);
    ui->label_4->setText("Moins que 20") ;
    ui->label_6->setNum(q3) ;


}

