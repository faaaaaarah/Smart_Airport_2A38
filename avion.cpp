#include "avion.h"
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

avion::avion()
{
    marque=" ";
    etat=" ";
    place=0;
    dispo=" ";
}

avion::avion(QString marque,QString etat,int place,QString dispo)
{

   this->marque=marque.toUpper();
   this->etat=etat.toUpper();
   this->place=place;
   this->dispo=dispo.toUpper();
}


int avion::get_id(){return id;}
void avion::Set_marque(QString val) { marque = val; }
QString avion::get_marque(){return marque;}
void avion::Set_etat(QString val) { etat = val; }
QString avion:: get_etat(){return etat;}
void avion::Set_dispo(QString val) { dispo = val; }
QString avion::get_dispo(){return dispo;}
void avion::Set_place(int val) { place = val; }
float avion::get_place(){return place;}


bool avion::ajouter()
{
    QSqlQuery query;  //variable d'accees lel BD
    query.prepare("INSERT INTO avion (MARQUE,ETAT,DISPO,PLACE)"
                          "VALUES (:marque, :etat, :dispo, :place)");
    query.bindValue(":marque",marque);
    query.bindValue(":etat",etat);
    query.bindValue(":dispo",dispo);
    query.bindValue(":place",place);
    return query.exec();
}


QSqlQueryModel *avion::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM avion");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("MARQUE"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("ETAT"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("DISPONIBILITE"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("NBR PLACE"));
 return model;
}

QSqlQueryModel * avion::trie_id()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM avion order by id");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("NBR PLACE"));
    return model;
}

QSqlQueryModel * avion::trie_marque()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM avion order by marque");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("NBR PLACE"));
    return model;
}

QSqlQueryModel * avion::trie_place()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM avion order by place");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("NBR PLACE"));
    return model;
}

bool avion::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from avion where id = :id ");
    query.bindValue(":id",idd);
    return query.exec();

}


bool avion :: modifier(int id ,QString marque,QString etat,int place,QString dispo)
{

    QSqlQuery qry;
    qry.prepare("UPDATE avion set marque=(?),etat=(?),dispo=(?),place=(?) where id=(?) ");
    qry.addBindValue(marque);
    qry.addBindValue(etat);
    qry.addBindValue(dispo);
    qry.addBindValue(place);
    qry.addBindValue(id);
    return  qry.exec();
}




