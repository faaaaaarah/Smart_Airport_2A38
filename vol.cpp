#include "vol.h"

#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QString>
#include <QFile>
#include <QTextDocument>
#include<QTextStream>
#include<QIODevice>
#include<QDate>
#include <QSystemTrayIcon>

using namespace std;

vol::vol()
{
    idav=0;
    datevl=" ";
}

vol::vol(int id,QString date)
{

   this->idav=id;
   this->datevl=date;
}


int vol::get_id(){return idav;}
void vol::Set_date(QString val) { datevl = val; }
QString vol::get_date(){return datevl;}

bool vol::ajouter()
{
    QSqlQuery query;  //variable d'accees lel BD
    query.prepare("INSERT INTO volav (idav,datevl)"
                          "VALUES (:idav, :datevl)");
    query.bindValue(":idav",idav);
    query.bindValue(":datevl",datevl);
    return query.exec();
}


QSqlQueryModel *vol::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM volav");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID avion"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("date vol"));
 return model;
}


bool vol::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from volav where idav = :id ");
    query.bindValue(":id",idd);
    return query.exec();

}


bool vol :: modifier(int id ,QString date)
{

    QSqlQuery qry;
    qry.prepare("UPDATE volav set datevl=(?) where idav=(?) ");
    qry.addBindValue(date);
    qry.addBindValue(id);
    return  qry.exec();
}




