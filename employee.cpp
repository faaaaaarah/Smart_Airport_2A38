#include "employee.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QString>
#include <QFile>
#include <QTextDocument>
#include<QTextStream>
#include<QIODevice>
#include<QDate>
#include <QSystemTrayIcon>

using namespace std;

employee::employee()
{
    nom=" ";
    prenom=" ";
    tel=0;
    sexe=" ";
}

employee::employee(QString nom,QString prenom,int tel,QString sexe)
{

   this->nom=nom.toUpper();
   this->prenom=prenom.toUpper();
   this->tel=tel;
   this->sexe=sexe.toUpper();
}


int employee::get_id(){return id;}
void employee::Set_nom(QString val) { nom = val; }
QString employee::get_nom(){return nom;}
void employee::Set_prenom(QString val) { prenom = val; }
QString employee:: get_prenom(){return prenom;}
void employee::Set_sexe(QString val) { sexe = val; }
QString employee::get_sexe(){return sexe;}
void employee::Set_tel(int val) { tel = val; }
float employee::get_tel(){return tel;}


bool employee::ajouter()
{
    QSqlQuery query;  //variable d'accees lel BD
    query.prepare("INSERT INTO empl (NOM,PRENOM,SEXE,TEL)"
                          "VALUES (:nom, :prenom, :sexe, :tel)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);
    query.bindValue(":sexe",sexe);
    return query.exec();
}


QSqlQueryModel *employee::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel();
 model->setQuery("SELECT * FROM empl");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("SEXE"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("TEL"));
 return model;
}

QSqlQueryModel * employee::trie_id()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM empl order by id");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("TEL"));
    return model;
}

QSqlQueryModel * employee::trie_nom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM empl order by nom");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("TEL"));
    return model;
}

QSqlQueryModel * employee::trie_prenom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM empl order by prenom");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("TEL"));
    return model;
}

bool employee::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from empl where id = :id ");
    query.bindValue(":id",idd);
    return query.exec();

}

bool employee :: modifier(   int id ,QString nom,QString prenom,int tel,QString sexe)
{

        QSqlQuery qry;
        qry.prepare("UPDATE empl set NOM=(?),PRENOM=(?),TEL=(?),SEXE=(?) where ID=(?) ");
        qry.addBindValue(nom);
        qry.addBindValue(prenom);
        qry.addBindValue(tel);
        qry.addBindValue(sexe);
        qry.addBindValue(id);
        return  qry.exec();
}






