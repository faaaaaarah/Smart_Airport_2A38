#ifndef VOL_H
#define VOL_H


#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QDebug>

class vol
{
public:
    vol();
    vol(int,QString);
    int get_id();
    void Set_date(QString val) ;
    QString get_date();
    ///////////// crud /////////////////
    bool ajouter();
    bool  modifier(int,QString);
    bool supprimer(int idd);
    QSqlQueryModel * afficher();
private:
    int idav;
    QString datevl;
};
#endif // VOL_H
