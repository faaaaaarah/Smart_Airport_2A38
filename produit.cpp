#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Produit::Produit()
{
    id=0; type=""; prix=0; stock=0;mail="";
}


Produit::Produit(int id, QString type, int prix,int stock,QString mail){
    this->id=id ;  this->prix=prix ; this->stock=stock ; this->type=type;this->mail=mail;
}


int Produit::getid(){return id;}
QString Produit::gettype(){return type;}
int Produit::getprix(){return prix;}
int Produit::getstock(){return stock;}

void Produit::setid(int id){this->id=id ;}
void Produit::settype(QString type){this->type=type ;}
void Produit::setprix(int prix){this->prix=prix ;}
void Produit::setstock(int stock){this->stock=stock ;}


bool Produit::ajouter(){

    QSqlQuery query;
    QString id_string= QString::number(id);
    QString prix_string= QString::number(prix);
    QString stock_string= QString::number(stock);

         query.prepare("INSERT INTO Produit (id, type,  prix, stock,mail) "
                       "VALUES (:id, :type, :prix, :stock, :mail)");
         query.bindValue(":id", id_string);
         query.bindValue(":type", type);
         query.bindValue(":prix", prix_string);
         query.bindValue(":stock", stock_string);
         query.bindValue(":mail", mail);


         return query.exec();
}


bool Produit::supprimer(int id){
    QSqlQuery query;
        QString res=QString::number(id);
         query.prepare("DELETE FROM Produit WHERE id=:id ");
         query.bindValue(":id",res);

         return query.exec();
}





QSqlQueryModel* Produit::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM Produit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("stock"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("time"));


    return model;
}



bool Produit::ModifierProduit()
{
       QSqlQuery query;
       QString id_string=QString::number(id);
       QString prix_string= QString::number(prix);
       QString stock_string= QString::number(stock);

       query.prepare(" UPDATE Produit set id = :id ,type = :type ,prix = :prix, stock = :stock,mail=:mail WHERE  id = :id");
                          query.bindValue(":id", id_string);
                          query.bindValue(":type", type);
                          query.bindValue(":prix", prix_string);
                          query.bindValue(":stock", stock_string);
                          query.bindValue(":mail", mail);


                         return query.exec();

}


QSqlQueryModel * Produit::rechercher(QString a)
{

    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from Produit where id like'%"+a+"%' OR prix like '%"+a+"%' OR type like '%"+a+"%' OR  stock like '%"+a+"%' ");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("stock"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));

        return model;

}

QSqlQueryModel* Produit::TriCASC()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM Produit ORDER BY type ASC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("stock"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));

  return  model;
}
QSqlQueryModel* Produit::TriCDESC()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM Produit ORDER BY type DESC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("stock"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));

  return  model;
}

QSqlQueryModel* Produit::TriDASC()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM Produit ORDER BY prix ASC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("stock"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));

  return  model;
}
QSqlQueryModel* Produit::TriDDESC()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM Produit ORDER BY prix DESC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("stock"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));

  return  model;
}


QSqlQueryModel* Produit::TriEASC()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM Produit ORDER BY stock ASC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("stock"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));

  return  model;
}

QSqlQueryModel* Produit::TriEDESC()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM Produit ORDER BY stock DESC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("stock"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));

  return  model;
}




