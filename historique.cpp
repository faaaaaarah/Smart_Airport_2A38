#include "historique.h"

historique::historique()
{
    cin=0;
    nom="xx";
    prenom="xx";
    num_passeport="xx";
    classe="xx";
    destination="xx";
}
historique::historique(int cin, QString nom, QString prenom,QString num_passeport, QString classe, QString destination)
{this->cin=cin; this->nom=nom; this->prenom=prenom; this->num_passeport=num_passeport; this->classe=classe; this->destination=destination; }

void historique::setcin (int cin) {this->cin=cin;}
void historique::setnom (QString nom) {this->nom=nom;}
void historique::setprenom (QString prenom) {this->prenom=prenom;}
void historique::setnumpasseport(QString num_passeport) {this->num_passeport=num_passeport;}
void historique::setclasse (QString classe) {this->classe=classe;}
void historique ::setdestination(QString destination) {this->destination=destination;}




QSqlQueryModel* historique::afficherh()
   {
     QSqlQueryModel* model=new QSqlQueryModel();
      model->setQuery("SELECT* FROM HISTORIQUES");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_PASSEPORT"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("CLASSE"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESTINATION"));
return  model;
 }

/*bool history ::supprimer(int cin )
    {  QSqlQuery query;

        query.prepare("DELETE FROM HISTORIQUES where cin=:cin");
        query.bindValue(0,cin);
        return query.exec();
    }*/
