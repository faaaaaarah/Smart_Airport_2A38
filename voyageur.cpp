#include "voyageur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Voyageur::Voyageur()
{
cin=0;  nom=" "; prenom=" "; num_passeport=" ";  classe=" ";  destination=" ";
}
Voyageur::Voyageur(int cin, QString nom, QString prenom,QString num_passeport, QString classe, QString destination)
{this->cin=cin; this->nom=nom; this->prenom=prenom; this->num_passeport=num_passeport; this->classe=classe; this->destination=destination; }
int Voyageur::getcin(){return cin;}
QString Voyageur::getnom (){return nom;}
QString Voyageur::getprenom (){return prenom;}
QString Voyageur::getnum_passeport (){return num_passeport;}
QString Voyageur::getclasse (){return classe;}
QString Voyageur::getdestination (){return  destination;}

void Voyageur::setcin (int cin){this->cin=cin;}
void Voyageur::setnom (QString nom){this->nom=nom;}
void Voyageur:: setprenom (QString prenom){this->prenom=prenom;}
void Voyageur:: setnum_passeport(QString num_passeport){this->num_passeport=num_passeport;}
void Voyageur::setclasse (QString classe){this->classe=classe;}
void Voyageur::setdestination(QString destination){this->destination=destination;}
bool Voyageur::ajouter()
{bool test=false;

QSqlQuery query;
   QString cin_string=QString::number(cin);
      query.prepare("INSERT INTO VOYAGEURS (cin,nom,prenom,num_passeport,classe,destination) " "VALUES (:cin, :nom, :prenom, :num_passeport, :classe, :destination)");
      query.bindValue(":cin", cin_string);
      query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
      query.bindValue(":num_passeport", num_passeport);
      query.bindValue(":classe",classe );
      query.bindValue(":destination", destination);
     return query.exec();

     return test;
     }

QSqlQueryModel* Voyageur::afficher()

{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT* FROM VOYAGEURS");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_passeport"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Classe"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Destination"));
       return model;
}
bool Voyageur::supprimer(int cin)
{
    QSqlQuery query;
    QString supp=QString::number(cin);
    query.prepare("Delete from voyageurs where cin= :cin");
    query.bindValue(":cin",supp);


         return query.exec();


}
bool Voyageur::modifier_voy(int cin)
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
  query.prepare("UPDATE VOYAGEURS SET cin=:cin,nom=:nom,prenom=:prenom,num_passeport=:num_passeport,classe=:classe,destination=:destination WHERE cin=:cin");
    query.bindValue(":cin",cin_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num_passeport",num_passeport);
    query.bindValue(":classe",classe);
    query.bindValue(":destination",destination);


    return query.exec();
}


QSqlQueryModel *Voyageur::afficher_tri_nom()
 {
     QSqlQueryModel * model= new QSqlQueryModel();


 model->setQuery("SELECT* FROM VOYAGEURS order by Nom ");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_passeport"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Classe"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("Destination"));

     return model;
 }


QSqlQueryModel *Voyageur::afficher_tri_classe()
 {
     QSqlQueryModel * model= new QSqlQueryModel();


 model->setQuery("SELECT* FROM VOYAGEURS order by Classe");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_passeport"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Classe"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("Destination"));

     return model;
 }


QSqlQueryModel *Voyageur::afficher_tri_num_passeport()
 {
     QSqlQueryModel * model= new QSqlQueryModel();


 model->setQuery("SELECT* FROM VOYAGEURS order by num_passeport ");

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_passeport"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Classe"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Destination"));
     return model;
 }

QSqlQueryModel* Voyageur::rechercher(const QString &str)
 {
      /* QSqlQuery query2;
       QSqlQueryModel *model=new QSqlQueryModel();
       model->setQuery("SELECT* FROM VOYAGEURS where Nom like '"+str+"%' or CIN like '"+str+"%' or Classe like '"+str+"%'");
      QString squery2=" INSERT INTO HISTORIQUES SELECT cin ,nom,prenom,num_passeport,classe,destination from VOYAGEURS WHERE NOM  LIKE '"+str+"%' or CIN like '"+str+"%' or Classe like '"+str+"%' ";
      query2.prepare(squery2);
       query2.exec();
      // model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_passeport"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Classe"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Destination"));*/
    QSqlQuery query,query2;
        QString squery=("SELECT* FROM VOYAGEURS where Nom like '"+str+"%' or CIN like '"+str+"%' or Classe like '"+str+"%'");
       QString squery2=" INSERT INTO HISTORIQUES SELECT cin ,nom,prenom,num_passeport,classe,destination from VOYAGEURS WHERE NOM  LIKE '"+str+"%' or CIN like '"+str+"%' or Classe like '"+str+"%' ";
       QSqlQueryModel*model=new QSqlQueryModel();
      query.prepare(squery);
      query.exec();
      query2.prepare(squery2);
      query2.exec();
      model->setQuery(query);
      return model;



}
//************   statistiques    *********************//

int Voyageur::calculer1(QString str)
     {
         QSqlQuery query;
               query.prepare("SELECT* FROM VOYAGEURS where Classe like '"+str+"%'");
              // query.bindValue(":str",str);
                query.bindValue(":classe",classe);

               query.exec();
               int total = 0;
               while (query.next()) {
                 total++;
      }

               return total;
     }
