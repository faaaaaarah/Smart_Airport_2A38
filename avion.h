#ifndef AVION_H
#define AVION_H


#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>


class avion
{
public:
    avion();
    avion(QString,QString,int,QString);
    int get_id();
    void Set_marque(QString val) ;
    QString get_marque();
    void Set_etat(QString val) ;
    QString get_etat();
    void Set_dispo(QString val) ;
    QString get_dispo();
    void Set_place(int val) ;
    float get_place();
    ///////////// crud /////////////////
    bool ajouter();
    bool  modifier(int,QString,QString,int,QString);
    bool supprimer(int idd);
    QSqlQueryModel * afficher();
    /////////// metier ///////////////
    QSqlQueryModel * trie_id();
    QSqlQueryModel * trie_marque();
    QSqlQueryModel * trie_place();
private:
    int id;
    QString marque;
    QString etat;
    QString dispo;
    int place;
};
#endif // AVION_H
