#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QMainWindow>
#include <QDateTime>
#include<QSqlQuery>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include<QtDebug>
#include<QObject>
#include <QMessageBox>

class historique
{
public:
    historique();
    historique(int,QString,QString,QString,QString,QString);
   void setcin(int cin);
   void setnom(QString nom);
   void setprenom(QString prenom);
   void setnumpasseport(QString num_passeport);
   void setclasse(QString classe);
   void setdestination(QString destination);

   int getcin ();
   QString getnom ();
   QString getprenom ();
   QString getnum_passeport ();
   QString getclasse ();
   QString getdestination();

QSqlQueryModel* afficherh();

   //bool supprimer(int cin );


private:
   int cin;
    QString nom,prenom,num_passeport,classe,destination;



};

#endif // HISTORIQUE_H

