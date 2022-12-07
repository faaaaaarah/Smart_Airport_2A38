#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "destination.h"

destination::destination()
{
    code=0; pays="";ville="";
}

destination::destination (int code,QString pays,QString ville ,QString aeroport)
{
    this->code=code;this->pays=pays;this->ville=ville;this->aeroport=aeroport;}
    int destination::getcode(){return code;}
    QString destination::getpays(){return pays;}
    QString destination::getville(){return ville;}
    QString destination::getaeroport(){return aeroport;}
    void destination::setcode(int code){this->code=code;}
    void destination::setpays(QString pays){this->pays=pays;}
    void destination::setville(QString ville){this->ville=ville;}
    void destination::setaeroport(QString aeroport){this->aeroport=aeroport;}


    bool destination::ajouter()
    {
        QSqlQuery query;
        QString code_string=QString::number(code);

              query.prepare("INSERT INTO DESTINATION (CODE,PAYS,VILLE,AEROPORT) "
                            "VALUES (:code, :pays,:ville,:aeroport)");
              query.bindValue(":code",code_string);
               query.bindValue(":ville",ville);
               query.bindValue(":pays",pays);
                query.bindValue(":aeroport",aeroport);
              return query.exec();


    }
bool destination::supprimer(int code)
{
    QSqlQuery query;
          query.prepare("Delete from DESTINATION where code=:code");
          query.bindValue(0,code);
          return query.exec();
}


QSqlQueryModel* destination::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM DESTINATION");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("pays"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Aeroport"));

    return model;
}

QSqlQueryModel* destination::chercher_destination(QString rech){
    QString sQuery="SELECT code,pays,ville,aeroport FROM DESTINATION WHERE nom LIKE'%"+rech+"%' or prenom LIKE'%"+rech+"%'";

    QSqlQueryModel*model4=new QSqlQueryModel();

    QSqlQuery qry;

    qry.prepare(sQuery);

    qry.exec();
    model4->setQuery(qry);
    return model4;
}
bool destination::modifier(QString code,QString pays,QString ville,QString aeroport)
{
     QSqlQuery query;

     query.prepare("UPDATE DESTINATION SET pays=:pays,ville=:ville,aeroport=:aeroport where code=:code");
     query.bindValue(":pays",pays);
     query.bindValue(":ville",ville);
     query.bindValue(":aeroport",aeroport);
     query.bindValue(":code",code);


     return query.exec(); 
}

//******REMPLIR COMBO BOX

QSqlQueryModel * destination::remplircombo()
{
    QSqlQueryModel * mod= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select code from DESTINATION");
    query.exec();
    mod->setQuery(query);
    return mod;
}

QSqlQueryModel * destination::remplircomboCalcul()
{
    QSqlQueryModel * mod= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select DISTINCT Ville from DESTINATION");
    query.exec();
    mod->setQuery(query);
    return mod;
}




QSqlQuery destination::request(QString id)
{
    QSqlQuery query;
    query.prepare("select * from DESTINATION where code= '"+id+"'");
    query.addBindValue(id);
    query.exec();
    return query;
}

//******RECHERCHE AVANCEE

QSqlQueryModel * destination::afficherecherche(QString res)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from DESTINATION  where (code LIKE '%"+res+"%' OR pays LIKE '%"+res+"%' OR ville LIKE '%"+res+"%' OR aeroport LIKE '%"+res+"%' )");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("pays"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Aeroport"));

    return model;
}

//*************Calculer

int destination::Calculer(QString ville)
{
    QSqlQuery query;
     query.prepare("select  * from DESTINATION  WHERE ville= :ville ");
     query.bindValue(":ville",ville);

     query.exec();
      int total=0;

     while(query.next()){
       total++;

     }


     return total;
}

//********STAT

//STAT
QStringList destination::listpays(){
    QSqlQuery query;
    query.prepare("select DISTINCT pays from DESTINATION");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;
}

int destination::calculpays(QString pays){
    QSqlQuery query;
     query.prepare("select  * from DESTINATION  WHERE pays=:pays");
     query.bindValue(":pays", pays );
     query.exec();
      int total=0;

     while(query.next()){
       total++;
     }


     return total;
}
