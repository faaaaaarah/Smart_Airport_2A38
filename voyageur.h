#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QSqlQueryModel>
#include "historique.h"

class Voyageur
{
public:
    Voyageur();
    Voyageur(int,QString,QString,QString,QString,QString);
    int getcin ();
    QString getnom ();
    QString getprenom ();
    QString getnum_passeport ();
    QString getclasse ();
    QString getdestination();
    void setcin (int);
    void setnom (QString);
    void setprenom (QString);
    void setnum_passeport (QString);
    void setclasse (QString);
    void setdestination (QString);
    bool ajouter ();
   QSqlQueryModel *afficher();
   bool supprimer (int);
   bool modifier_voy(int cin);
   QSqlQueryModel *afficher_tri_nom();
   QSqlQueryModel *afficher_tri_classe();
   QSqlQueryModel *afficher_tri_num_passeport();
   QSqlQueryModel * rechercher(const QString&);
   int calculer1(QString str);
  private:
    int cin;
    QString nom, prenom, num_passeport, classe, destination;
};

#endif // VOYAGEUR_H
