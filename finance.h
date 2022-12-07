#ifndef FINANCE_H
#define FINANCE_H
#include <QApplication>
#include"connection.h"
#include<QMessageBox>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class finance
{
public:
    finance();
    finance(int,int,int,int,int,int,int);
    int getdatej();
    int getchiffredaffaires();
    int getremboursement();
    int getdepenses();
    int getprofit();
    int getperte();
    int getsalaires();
    QString gettype();
    void setdatej(int);
    void setchiffredaffaires(int);
    void setremboursement(int);
    void setdepenses(int);
    void setprofit(int);
    void setperte(int);
    void setsalaires(int);
    void settype(QString n);
    bool ajouter();

    QSqlQueryModel* chercher_finance(QString rech);
    QSqlQueryModel* afficher_finance_trie_chiffredaffaires();
    QSqlQueryModel* afficher_finance_trie_perte();
    QSqlQueryModel* afficher_finance_trie_profit();
    QSqlQueryModel* afficher();
    int calculer1(int choix,int choix2);
    bool supprimer(int);
    void modifier(finance f);
    bool DateValide(QDate Datej);
    void excel_dynamique();

private:
    int datej;
    int chiffredaffaires;
    int remboursement;
    int depenses;
    int profit;
    int perte;
    int salaires;
    QString type;
};

#endif // FINANCE_H
