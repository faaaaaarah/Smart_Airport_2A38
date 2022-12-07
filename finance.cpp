#include "finance.h"
#include<QSqlQuery.h>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QDate>
finance::finance()
{
    datej=0;
    remboursement=0;
    salaires=0;
    chiffredaffaires=0;
    depenses=0;
    profit=0;
    perte=0;
    type ="";
}
finance::finance(int datej,int chiffredaffaires,int remboursement,int depenses,int profit,int perte,int salaires)
{

    this->datej=datej;
    this->chiffredaffaires=chiffredaffaires;
    this->remboursement=remboursement;
    this->depenses=depenses;
    this->profit=profit;
    this->perte=perte;
    this->salaires=salaires;}
    int finance:: getdatej(){return datej;}
    int finance::getchiffredaffaires(){return chiffredaffaires;}
    int finance::getremboursement(){return remboursement;}
    int finance::getdepenses(){return depenses;}
    int finance::getprofit(){return profit;}
    int finance::getperte(){return perte;}
    int finance::getsalaires(){return salaires;}
    void finance::setdatej(int datej){this->datej=datej;}
     void finance::setchiffredaffaires(int chiffredaffaires){this->chiffredaffaires=chiffredaffaires;}
      void finance::setremboursement(int remboursement){this->remboursement=remboursement;}
      void finance::setdepenses(int depenses){this->depenses=depenses;}
        void finance::setprofit(int profit){this->profit=profit;}
         void finance::setperte(int perte){this->perte=perte;}
         void finance::setsalaires(int salaires){this->salaires=salaires;}
bool finance::ajouter()
{bool test=false;
QSqlQuery query;
QString datej_string=QString::number(datej);
QString chiffredaffaires_string=QString::number(chiffredaffaires);
QString depenses_string=QString::number(depenses);
QString remboursement_string=QString::number(remboursement);
QString salaires_string=QString::number(salaires);
QString profit_string=QString::number(profit);
QString perte_string=QString::number(perte);





      query.prepare("INSERT INTO finance (dateg, chiffredaffaire, depense,remboursement,salaires,profit,perte) "
                    "VALUES (:Datej, :chiffredaffaire, :depense,:remboursement,:salaires,:profit,:perte)");
      query.bindValue(":dateg",datej_string );
      query.bindValue(":chiffredaffaire",chiffredaffaires_string );
      query.bindValue(":depense)", depenses_string);
      query.bindValue(":remboursement", remboursement_string);
      query.bindValue(":salaires", salaires_string);
      query.bindValue(":profit", profit_string);
      query.bindValue(":perte", perte_string);

    query.exec();


 return  test;

}
bool finance::supprimer(int datej)
{
    QSqlQuery query;

    query.prepare("Delete frome finance where dateg=:dateg");

    query.bindValue(":dateg",datej);
    return query.exec();


}
QSqlQueryModel* finance::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT*  FROM finance");
     model->setHeaderData(0, Qt::Horizontal, QObject:: tr("Datejournee"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("chiffredaffaires"));
     model->setHeaderData(2, Qt::Horizontal, QObject:: tr("depense"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("remboursement"));
     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("salaires"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("profit"));
     model->setHeaderData(6, Qt::Horizontal, QObject:: tr("perte"));
      model->setHeaderData(7, Qt::Horizontal, QObject:: tr("type"));



}
void finance::modifier(finance f){
 QSqlQuery query;
 query.prepare("INSERT INTO finance (dateg, chiffredaffaire, depense,remboursement,salaires,profit,perte) "
               "VALUES (:Datej, :chiffredaffaire, :depense,:remboursement,:salaires,:profit,:perte)");
 query.bindValue(":dateg", datej);
 query.bindValue(":chiffredaffaire", chiffredaffaires);
 query.bindValue(":depense)", depenses);
 query.bindValue(":remboursement", remboursement);
 query.bindValue(":salaires", salaires);
 query.bindValue(":profit", profit);
 query.bindValue(":perte",perte );
        if(query.exec())
    {
        QMessageBox::critical(nullptr, QObject::tr("sql query successful"),
                           QObject::tr("row updated and saved.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("sql query unsuccessful"),
                           QObject::tr("row not updated and not saved.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

int finance::calculer1(int choix,int choix2)
{
    QSqlQuery query;
          query.prepare("SELECT * FROM finance WHERE TYPE BETWEEN (:profit) AND (:perte)");
          query.bindValue(":choix",choix);
          query.bindValue(":choix2",choix2);

          query.exec();
          int total = 0;
          while (query.next()) {
            total++;
 }

          return total;
}
QSqlQueryModel* finance::afficher_finance_trie_profit()
{
    QString sQuery="SELECT chiffredaffairee FROM finance ORDER BY profit";


    QSqlQueryModel*model1=new QSqlQueryModel();

    QSqlQuery qry;

    qry.prepare(sQuery);

    qry.exec();
    model1->setQuery(qry);
return model1;
}
QSqlQueryModel* finance::afficher_finance_trie_perte()
{
    QString sQuery="select * from finance order by perte";

    QSqlQueryModel*model1=new QSqlQueryModel();

    QSqlQuery qry;

    qry.prepare(sQuery);

    qry.exec();
    model1->setQuery(qry);
return model1;
}




QSqlQueryModel* finance::chercher_finance(QString rech)
{
    QSqlQueryModel* model=new QSqlQueryModel();

 model->setQuery("SELECT* FROM finance where datej='"+rech+"' ");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("chiffredaffaires"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("remboursement"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("depenses"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("profit"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("perte"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("salaires"));
    return model;
}
bool finance::DateValide(QDate Datej)

    {

        if (Datej > QDate::currentDate())

           {return true;}

        else
            return false;
}

 /*void finance::excel_dynamique()
        {

                           QFile file("C:\esprit1/sheet.csv");
                           QSqlQueryModel* model=new QSqlQueryModel();
                           model->setQuery("SELECT* FROM  finances");

                           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                               QTextStream data(&file);
                               QStringList strList;
                               for (int i = 0; i < model->columnCount(); i++) {
                                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") << "\n";
                               for (int i = 0; i < model->rowCount(); i++) {
                                   strList.clear();
                                   for (int j = 0; j < model->columnCount(); j++) {

                                       if (model->data(model->index(i, j)).toString().length() > 0)
                                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                       else
                                           strList.append("");
                                   }
                                   data << strList.join(";") + "\n";
                               }
                               file.close();

                           }
        }

*/
