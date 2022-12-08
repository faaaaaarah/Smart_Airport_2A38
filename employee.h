#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>


class employee
{
public:
    employee();
    employee(QString,QString,int,QString);
    int get_id();
    void Set_nom(QString val) ;
    QString get_nom();
    void Set_prenom(QString val) ;
    QString get_prenom();
    void Set_sexe(QString val) ;
    QString get_sexe();
    void Set_tel(int val) ;
    float get_tel();
    ///////////// crud /////////////////
    bool ajouter();
    bool  modifier(int,QString,QString,int,QString);
    bool supprimer(int idd);
    QSqlQueryModel * afficher();
    /////////// metier ///////////////
    QSqlQueryModel * trie_id();
    QSqlQueryModel * trie_nom();
    QSqlQueryModel * trie_prenom();
private:
    int id;
    QString nom;
    QString prenom;
    QString sexe;
    int tel;
};
#endif // EMPLOYEE_H
