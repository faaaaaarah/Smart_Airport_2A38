#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTextDocument>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QDesktopServices>
#include <QHeaderView>
#include "QImage"
#include <QPainter>
#include "iostream"
#include <QSqlQuery>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include "connection.h"
#include <QtWidgets/QApplication>
#include <QtCore/QTime>
#include <QTextEdit>
#include <QIntValidator>
#include<QWidget>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <QTextStream>
#include <QRadioButton>
#include <QPixmap>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include<QDir>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include<QDirModel>
#include <QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QDesktopServices>
#include <QHeaderView>
#include "QImage"
#include <QPainter>
#include "iostream"
#include "qrcode.h"
#include "qrcodegenerateworker.h"
#include <QFileDialog>
#include <QDialog>
#include "stat.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_3->setValidator(new QIntValidator( 11111111,99999999,this));
    ui->tab_voyageurs->setModel(V.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
  int cin=ui->lineEdit_3->text().toInt();
  QString nom=ui->lineEdit_nomvoy->text();
  QString prenom=ui->lineEdit_2->text();
  QString num_passeport=ui->lineEdit_4->text();
  QString classe=ui->lineEdit_5->text();
  QString destination=ui->lineEdit_destination->text();
  Voyageur V(cin,nom,prenom,num_passeport,classe,destination);
  bool test=V.ajouter();

     if(test)
     {

      //Refresh

         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("Ajout effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
         ui->tab_voyageurs->setModel(V.afficher());
     }
     else
     {
         QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                 QObject::tr("Ajout non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
     }

}

void MainWindow::on_pushButton_ajouter_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_afficher_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pb_supprimer_clicked()
{
  int cin=ui->id_supp->text().toInt();
  bool test=V1.supprimer(cin);
  if(test)
  {
      //Refresh
     ui->tab_voyageurs->setModel(V1.afficher());
  }
  else
  {
      QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
              QObject::tr("Suppression non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
  }

}



void MainWindow::on_pushButton_HISTORIQUES_11_clicked()
{
  ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_HISTORIQUES_10_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_HISTORIQUES_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pb_modifier_clicked()
{
    {
        int cin=ui->lineEdit_CIN_VOY->text().toInt();
        QString nom=ui->lineEdit_NOM_VOY->text();
        QString prenom=ui->lineEdit_PRENOM_VOY->text();
        QString num_passeport=ui->lineEdit_NUM_PASSEPORT->text();
        QString classe=ui->lineEdit_CLASSE_VOY->text();
        QString destination=ui->lineEdit_DESTINATION->text();
      Voyageur V(cin,nom,prenom,num_passeport,classe,destination);

      bool test=V.modifier_voy(cin);
       if (test)
       {
           ui->tab_voyageurs->setModel(V.afficher());
           //Refresh
            QMessageBox::information(nullptr,QObject::tr("Effectué"),QObject::tr("Modifié.\n""Click Cancel to exit."),QMessageBox::Cancel);
            ui->lineEdit_CIN_VOY->clear();
            ui->lineEdit_NOM_VOY->clear();
            ui->lineEdit_PRENOM_VOY->clear();
            ui->lineEdit_NUM_PASSEPORT->clear();
            ui->lineEdit_CLASSE_VOY->clear();
            ui->lineEdit_DESTINATION->clear();
       }
       else
       {
           QMessageBox::critical(nullptr,QObject::tr("Non effectué"),QObject::tr("Non modifié!\n""Click Cancel to exit."),QMessageBox::Cancel);
           ui->lineEdit_CIN_VOY->clear();
           ui->lineEdit_NOM_VOY->clear();
           ui->lineEdit_PRENOM_VOY->clear();
           ui->lineEdit_NUM_PASSEPORT->clear();
           ui->lineEdit_CLASSE_VOY->clear();
           ui->lineEdit_DESTINATION->clear();
       }
    }
}

void MainWindow::on_pushButton_HISTORIQUES_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pb_trier_clicked()
{
    if(ui->radioButton_classe->isChecked())
    {
        bool
                test=V1.afficher_tri_classe();
        if(test)
        {//Refresh
            ui->tableTri->setModel(V1.afficher_tri_classe());
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("TRI par classe effectue\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("TRI par classe non effectue\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
        }
    else
    {
        if(ui->radioButton_nom->isChecked())
        {
            bool test=V1.afficher_tri_nom();
            if(test)
            {
                //Refresh
                ui->tableTri->setModel(V1.afficher_tri_nom());
                QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("TRI par nom effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
            }
               else
            {
                QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("TRI par nom non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
            }
            }
              else
            {
                if(ui->radioButton_num_passeport->isChecked())
                {
                    bool test=V1.afficher_tri_num_passeport();
                    if(test)
                    {
                        //Refresh
                        ui->tableTri->setModel(V1.afficher_tri_num_passeport());
                        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("TRI par num passeport effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

                    }
                       else
                    {
                       QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("TRI par num passeport non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
                    }
                }
            }
    }
}



void MainWindow::on_pushButton_rech_tri_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_HISTORIQUES_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pb_chercher_clicked()
{
    QString str= ui->lineEdit_chercher->text();
      bool test=V1.rechercher(str);

       if(test)
       {
                    //Refresh
                    ui->tableTri->setModel(V1.rechercher(str));

           QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr(" Recherche effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
       else
       {
           QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                   QObject::tr("Recherche non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}

}

void MainWindow::on_pb_pdf_clicked()
{
    QMessageBox::information(nullptr,QObject::tr("DONE"),
                QObject::tr("Fichier PDF generer\n""Click Cancel to exit."),QMessageBox::Cancel);


        QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tab_voyageurs->model()->rowCount();
                    const int columnCount =ui->tab_voyageurs->model()->columnCount();


                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("eleve")
                            <<  "</head>\n"
                            "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                                "<h1>Liste des Voyageurs</h1>"

                                "<table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tab_voyageurs->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tab_voyageurs->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tab_voyageurs->isColumnHidden(column)) {
                                       QString data = ui->tab_voyageurs->model()->data(ui->tab_voyageurs->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";



            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);


            //QTextDocument document;
            //document.setHtml(html);
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("VOYAGEURS.pdf");
            document->print(&printer);
}

void MainWindow::on_pushButton_historiques_clicked()
{

     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_HISTORIQUES_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_affiche_h_clicked()
{
    ui->table_histo->setModel(h.afficherh());
}


void MainWindow::on_pushButton_statistiques_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_statistiques_2_clicked()
{
    int res;
                statistiques w(this);
                w.setWindowTitle("Statistiques des classes");

                res = w.exec();
                qDebug() << res;
                if (res == QDialog::Rejected)
                  return;
}

void MainWindow::on_pushButton_HISTORIQUES_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushb_qrcode_clicked()
{
    if(ui->tab_voyageurs->currentIndex().row()==-1)

                                              QMessageBox::information(nullptr, QObject::tr("Suppression"),

                                                                       QObject::tr("Veuillez Choisir une CIN du Tableau.\n"

                                                                                   "Click Ok to exit."), QMessageBox::Ok);

                                          else

                                          {

                                               int CIN=ui->tab_voyageurs->model()->data(ui->tab_voyageurs->model()->index(ui->tab_voyageurs->currentIndex().row(),0)).toInt();

                                               const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(CIN).c_str(), qrcodegen::QrCode::Ecc::LOW);


                                               std::ofstream myfile;

                                               myfile.open ("qrcode.svg") ;

                                                  myfile << qr.toSvgString(2);

                                                  myfile.close();

                                                  QSvgRenderer svgRenderer(QString("qrcode.svg"));

                                                  QPixmap pix( QSize(90, 90));

                                                  QPainter pixPainter( &pix );

                                                  svgRenderer.render(&pixPainter);

                                               ui->label_11->setPixmap(pix);

                                          }
}

void MainWindow::on_pushButton_qr_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
