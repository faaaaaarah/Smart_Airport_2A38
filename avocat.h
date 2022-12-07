#ifndef AVOCAT_H
#define AVOCAT_H
#include <QString>
#include <QSqlQueryModel>
class avocat
{
public:
    avocat();
    avocat(int,QString,QString,QString,int);
    int getcin();
     int getphone();
    QString getnom();
    QString getprenom();
    QString getmail();
    void setcin(int);
     void setphone(int);
    void setnom(QString);
    void setprenom(QString);
    void setmail(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel*chercher_avocat(QString rech);
    bool modifier();
private:
    int cin;
    QString nom;
    QString prenom;
    QString mail;
    int phone;
};

#endif // AVOCAT_H
