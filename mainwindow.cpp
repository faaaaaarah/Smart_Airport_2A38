#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finance.h"
#include<QtDebug>
#include <QDebug>
#include <QDate>
#include <QDateEdit>
#include <QFile>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtona_clicked()
{
    int datej=ui->line1->text().toInt();
        int chiffredaffaires=ui->line2->text().toInt();
        int depense=ui->line3->text().toInt();
        int remboursement=ui->line4->text().toInt();
        int salaires=ui->line5->text().toInt();
        int profit=ui->line6->text().toInt();
        int perte=ui->line7->text().toInt();
    finance f(datej,chiffredaffaires,depense,remboursement,salaires,profit,perte);
bool test=f.ajouter();

}



void MainWindow::on_pushButton_clicked()
{
    finance f1;f1.setdatej(ui->ladates->text().toInt());
    bool test=f1.supprimer(f1.getdatej());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
        ui->tabj->setModel(f1.afficher());
    }
    else
        msgBox.setText("echec de suppression");
    msgBox.exec();
}
void MainWindow::on_pushButton_3_clicked()
{
        finance f;


        f.setdatej(ui->line1->text().toInt());
        f.setchiffredaffaires(ui->line2->text().toInt());
        f.setremboursement(ui->line4->text().toInt());
        f.setdepenses(ui->line3->text().toInt());
        f.setprofit(ui->line6->text().toInt());
        f.setperte(ui->line7->text().toInt());
           f.setsalaires(ui->line5->text().toInt());

       f.modifier(f);
        ui->line1->setText("");
        ui->line2->setText("");
        ui->line3->setText("");
        ui->line4->setText("");
        ui->line5->setText("");
        ui->line6->setText("");
         ui->line7->setText("");
        ui->tabj->setModel(f.afficher());




}



void MainWindow::on_pushButton_2_clicked()
{
    int heure,prix;
    int nombre_employes,salaires;
    nombre_employes=ui->lineEdit->text().toUInt();
    heure=ui->lineEdit_2->text().toUInt();
    prix=ui->lineEdit_3->text().toUInt();
    salaires=prix*heure*nombre_employes;
        salaires=ui->lineEdit_4->text().toUInt();
            qDebug() << salaires;


        }




void MainWindow::on_pushButton_5_clicked()
{ int nbre_avions,prixa,estmaion_de_batiment;
    int estimation_des_equipements,compte_bancaire,gestion_de_la_patrimoine;
   nbre_avions=ui->lineEdit_5->text().toUInt();
  prixa=ui->lineEdit_6->text().toUInt();
    estmaion_de_batiment=ui->lineEdit_7->text().toUInt();
    estimation_des_equipements=ui->lineEdit_7->text().toUInt();
   compte_bancaire=ui->lineEdit_8->text().toUInt();
      gestion_de_la_patrimoine=(nbre_avions*prixa)+ estmaion_de_batiment+ compte_bancaire;
}

void MainWindow::on_pushButton_6_clicked()
{{
       QString nom,destination;
        int prix,remboursement;
       int facture;
        QString id;
        id=ui->lineEdit_12->text();
        destination=ui->lineEdit_13->text();
        prix=ui->lineEdit_14->text().toUInt();
        remboursement=ui->lineEdit_15->text().toUInt();
        QSqlQuery query(" SELECT  *FROM FINANCET where id like '"+id+"%'");
        query.bindValue(0, id);
        while (query.next()){
            QString nom =query.value(1).toString();
            ui->lineEdit_18->setText(nom);
           facture=prix-remboursement;
            //QString facture=QString::toInt(facture);
          //  ui->lineEdit_11->setText(facture);
            qDebug() << facture;


        }


    }

}

void MainWindow::on_pushButton_4_clicked()
{
    QDateTime date = QDateTime::currentDateTime();
        QString dates=date.toString();
        QFile file2 ("");
         if (!file2.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream in(&file2);

        QString strStream;
                   QTextStream out(&strStream);
                   const int rowCount = ui->tabj->model()->rowCount();
                   const int columnCount = ui->tabj->model()->columnCount();
                                   QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                                   out <<  "<html>\n"
                                       "<head>\n"
                                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                       <<  QString("<title>%1</title>\n").arg("strTitle")
                                       <<  "</head>\n"
                                       "<body bgcolor=#ffffff link=#5000A0>\n"

                                      //     "<align='right'> " << datefich << "</align>"
                                           "<img src='C:/Users/zraib/OneDrive/Bureau/ifinal/logo.png' width='300' height='150'>"


                                       "<center> <H1>Liste des Employe "+TT+" </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                   // headers
                                   out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
                                   for (int column = 0; column < columnCount; column++)
                                       if (!ui->tabj->isColumnHidden(column))
                                           out << QString("<th>%1</th>").arg(ui->tabj->model()->headerData(column, Qt::Horizontal).toString());
                                   out << "</tr></thead>\n";

                                   // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tabj->isColumnHidden(column)) {
                                               QString data = ui->tabj->model()->data(ui->tabj->model()->index(row, column)).toString().simplified();
                                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));


                                           }
                                       }
                                       out << "</tr>\n";
                                   }
                                   out <<  "</table> </center>\n";
              out << "<tr>\n"

                                       "</body>\n"
                                       "</html>\n";

                                   QTextDocument *document = new QTextDocument();
                                   document->setHtml(strStream);
                                   QPrinter printer;

                                   QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                                   if (dialog->exec() == QDialog::Accepted) {
                                       document->print(&printer);
                                   }


                                   delete document;

}
