#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>


class Produit
{

public:
    Produit();
    Produit(int,QString,int,int,QString);
    int getid();
    QString gettype ();
    int getprix();
    int getstock();


    void setid(int);
    void settype(QString);
    void setprix(int);
    void setstock(int);

    bool ajouter();
    bool ModifierProduit();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel* rechercher(QString);

    QSqlQueryModel* TriCASC();
    QSqlQueryModel* TriCDESC();
    QSqlQueryModel* TriDASC();
    QSqlQueryModel* TriDDESC();
    QSqlQueryModel* TriEASC();
    QSqlQueryModel* TriEDESC();




private:
    int id;
    QString type;
    int prix;
    int stock;
    QString mail;
};

#endif // PRODUIT_H
