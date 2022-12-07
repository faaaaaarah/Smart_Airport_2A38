#ifndef DESTINATION_H
#define DESTINATION_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtGui>
#include <QtSql>
#include <QtCore>

class destination
{
public:
    destination();
    destination(int,QString,QString,QString);
    int getcode();
    QString getpays();
    QString getville();
    QString getaeroport();
    void setcode(int);
    void setpays(QString);
    void setville(QString);
    void setaeroport(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel*chercher_destination(QString rech);
    bool modifier(QString,QString,QString,QString);

    QSqlQueryModel * remplircombo();
    QSqlQueryModel * remplircomboCalcul();
    QSqlQuery request(QString);
    QSqlQueryModel * afficherecherche(QString);
    int Calculer(QString);
    QStringList listpays();
    int calculpays(QString);
private:
    int code;
    QString pays;
    QString ville;
    QString aeroport;
};
#endif // DESTINATION_H
