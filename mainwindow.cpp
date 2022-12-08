#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include <QMessageBox>
#include<QSystemTrayIcon>
#include <QRegExp>
#include "connection.h"
#include <QFileDialog>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include "avion.h"
#include "vol.h"
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include <QApplication>
#include <QIntValidator>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QtCore>
#include "smtp.h"
#include "qrcode.h"
#include "qrcodegenerateworker.h"
#include <QFileDialog>
#include <QDialog>
#include "stat.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //affichage
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->tableView->setModel(e.afficher());
    ui->tableView_2->setModel(v.afficher());
    ui->tableView_3->setModel(a.afficher());
    ui->tab_voyageurs->setModel(V.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}
//////////////////////////////////////////////////////////////// gestion employee ///////////////////////////////////////////
//ajout
void MainWindow::on_pushButton_2_clicked()
{
    QString nom =ui->lineEdit_3->text();
    QString prenom =ui->lineEdit_4->text();
    QString sexe =ui->comboBox->currentText();
    int tel =ui->lineEdit_5->text().toUInt();
    employee e(nom,prenom,tel,sexe);
    bool test=e.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_4->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_5->clear();
        ui->tableView->setModel(e.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

}
// supprimer
void MainWindow::on_pushButton_3_clicked()
{
    int id =ui->lineEdit_6->text().toUInt();
    bool test=e.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Supprimé \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_6->clear();
        ui->tableView->setModel(e.afficher());
    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from empl  where id='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or SEXE='"+val+"' or TEL='"+val+"'");

    if (qry.exec())
    { while (qry.next())
        {
            //update
            //id
            ui->lineEdit_10->setText(qry.value(0).toString());
            ui->lineEdit_8->setText(qry.value(1).toString());
            ui->lineEdit_7->setText(qry.value(2).toString());
            ui->lineEdit_9->setText(qry.value(4).toString());
            //delete
            //id
            ui->lineEdit_6->setText(qry.value(0).toString()); //pour supprimer


        }
    }
}
// modifier
void MainWindow::on_pushButton_4_clicked()
{
    int id =ui->lineEdit_10->text().toUInt();
    QString nom =ui->lineEdit_8->text();
    QString prenom =ui->lineEdit_7->text();
    QString sexe =ui->comboBox_2->currentText();
    int tel =ui->lineEdit_9->text().toInt();
    bool test=e.modifier(id ,nom,prenom,tel,sexe);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modifié \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_10->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->tableView->setModel(e.afficher());
    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("modification non effectué"),QMessageBox::Cancel);
}
//trie
void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView->setModel(e.trie_id());
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView->setModel(e.trie_nom());
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tableView->setModel(e.trie_prenom());

}
//pdf
void MainWindow::on_pushButton_8_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                "/home",
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);
    qDebug()<<dir;
    QPdfWriter pdf(dir+"/PdfList.pdf");
                           QPainter painter(&pdf);
                          int i = 4000;

                                painter.drawPixmap(QRect(100,100,2500,2500),QPixmap("C:/Users/ABDOU/Desktop/project/1.png"));
                                painter.drawText(900,650,"Smart airport");
                               painter.setPen(Qt::red);
                               painter.setFont(QFont("Time New Roman", 25));
                               painter.drawText(3000,1400,"Liste des employees");
                               painter.setPen(Qt::black);
                               painter.setFont(QFont("Time New Roman", 15));
                               painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                               painter.drawRect(100,3000,9400,500);
                               painter.setFont(QFont("Time New Roman", 9));
                               painter.drawText(300,3300,"ID");
                               painter.drawText(2000,3300,"Nom");
                               painter.drawText(4000,3300,"Prenom");
                               painter.drawText(5600,3300,"Sexe");
                               painter.drawText(7000,3300,"Tel");
                               painter.drawRect(100,3000,9400,10700);
                               //QTextDocument previewDoc;
                               QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");
                               //QTextCursor cursor(&previewDoc);
                               QSqlQuery query;
                               query.prepare("select * from empl");
                               query.exec();
                               while (query.next())
                               {
                                   painter.drawText(300,i,query.value(0).toString());
                                   painter.drawText(2000,i,query.value(1).toString());
                                   painter.drawText(4000,i,query.value(2).toString());
                                   painter.drawText(5600,i,query.value(3).toString());
                                   painter.drawText(7000,i,query.value(4).toString());
                                   painter.drawText(8000,i,query.value(5).toString());
                                  i = i +500;
                               }
                               int reponse = QMessageBox::question(this, "Générer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                   QMessageBox::Yes|QMessageBox::No);
                                   if (reponse == QMessageBox::Yes)
                                   {
                                       QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                       painter.end();
                                   }
                                   else
                                   {
                                        painter.end();
                                   }
}
// login
void MainWindow::on_pushButton_clicked()
{
    QString nom =ui->lineEdit->text();
    QString pass =ui->lineEdit_2->text();
    if(nom=="naim"&&pass=="admin"){
        this->ui->stackedWidget->setCurrentIndex(1);
    }else if(nom=="mohamed"&&pass=="admin"){
        this->ui->stackedWidget->setCurrentIndex(2);
    }else if(nom=="farah"&&pass=="admin"){
        this->ui->stackedWidget->setCurrentIndex(3);
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("nom ou mot de passe incorrect"),QMessageBox::Cancel);
    }
}
// logout
void MainWindow::on_pushButton_10_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}
// stat
void MainWindow::on_pushButton_9_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                    model->setQuery("select * from empl where SEXE = 'Homme' ");
                                    float e=model->rowCount();
                                    model->setQuery("select * from empl where SEXE = 'Femme' ");
                                    float ee=model->rowCount();
                                    float total=e+ee;
                                    QString a=QString("Homme"+QString::number((e*100)/total,'f',2)+"%" );
                                    QString b=QString("Femme"+QString::number((ee*100)/total,'f',2)+"%" );
                                    QPieSeries *series = new QPieSeries();
                                    series->append(a,e);
                                    series->append(b,ee);
                            if (e!=0)
                            {QPieSlice *slice = series->slices().at(0);
                             slice->setLabelVisible();
                             slice->setPen(QPen());}
                            if ( ee!=0)
                            {
                                     // Add label, explode and define brush for 2nd slice
                                     QPieSlice *slice1 = series->slices().at(1);
                                     //slice1->setExploded();
                                     slice1->setLabelVisible();
                            }
                                    // Create the chart widget
                                    QChart *chart = new QChart();
                                    // Add data to chart with title and hide legend
                                    chart->addSeries(series);
                                    chart->setTitle("Pourcentage des homme et femme : nombre total : "+ QString::number(total));
                                    chart->legend()->hide();
                                    // Used to display the chart
                                    QChartView *chartView = new QChartView(chart);
                                    chartView->setRenderHint(QPainter::Antialiasing);
                                    chartView->resize(1000,500);
                                    chartView->show();
}

void MainWindow::on_envoyer_2_clicked()
{
    connect(ui->envoyer_2, SIGNAL(clicked()),this, SLOT(sendMail()));
}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("alarassaa147@gmail.com", "xwgasmdtzmkoiltb","smtp.gmail.com",465,30000);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("promotion", ui->lineEdit_14->text() , ui->lineEdit_13->text(),ui->textEdit_2->toPlainText());
}



void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_lineEdit_15_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM empl WHERE id  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or prenom  LIKE'"+arg1+"%' or sexe LIKE'"+arg1+"%'");
             query->exec();
             if (query->next()) {
             model->setQuery(*query);
             ui->tableView->setModel(model);
             }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !!\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
              ui->lineEdit_15->clear();}
}
//////////////////////////////////////////////////////////////// gestion avion ////////////////////////////////////////////////////////////
//logout
void MainWindow::on_pushButton_23_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}
//ajout
void MainWindow::on_pushButton_11_clicked()
{
    QString marque =ui->lineEdit_11->text();
    QString etat =ui->comboBox_4->currentText();
    QString dispo =ui->comboBox_3->currentText();
    int place =ui->lineEdit_12->text().toUInt();
    avion a(marque,etat,place,dispo);
    bool test=a.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_11->clear();
        ui->lineEdit_12->clear();
        ui->tableView_3->setModel(a.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);
}
//supprimer
void MainWindow::on_pushButton_12_clicked()
{
    int id =ui->lineEdit_16->text().toUInt();
    bool test=a.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Supprimé \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_16->clear();
        ui->tableView_3->setModel(a.afficher());
    }
    else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}
//remplissage
void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
    QString val=ui->tableView_3->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from avion  where id='"+val+"' or marque='"+val+"' or etat='"+val+"' or dispo='"+val+"' or place='"+val+"'");

    if (qry.exec())
    { while (qry.next())
        {
            //update
            //id
            ui->lineEdit_19->setText(qry.value(0).toString());
            ui->lineEdit_17->setText(qry.value(1).toString());
            ui->lineEdit_18->setText(qry.value(4).toString());
            //delete
            //id
            ui->lineEdit_16->setText(qry.value(0).toString()); //pour supprimer


        }
    }
}
//modifier
void MainWindow::on_pushButton_13_clicked()
{
    int id =ui->lineEdit_19->text().toUInt();
    QString marque =ui->lineEdit_17->text();
    QString etat =ui->comboBox_6->currentText();
    QString dispo =ui->comboBox_5->currentText();
    int place =ui->lineEdit_18->text().toUInt();
    bool test=a.modifier(id ,marque,etat,place,dispo);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modifié \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_19->clear();
        ui->lineEdit_17->clear();
        ui->lineEdit_18->clear();
        ui->tableView_3->setModel(a.afficher());
    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("modification non effectué"),QMessageBox::Cancel);
}
//trie id
void MainWindow::on_pushButton_14_clicked()
{
    ui->tableView_3->setModel(a.trie_id());
}
//trie marque
void MainWindow::on_pushButton_15_clicked()
{
    ui->tableView_3->setModel(a.trie_marque());
}
//trie nbr place
void MainWindow::on_pushButton_16_clicked()
{
    ui->tableView_3->setModel(a.trie_place());
}
//recherche
void MainWindow::on_lineEdit_20_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM avion WHERE id  LIKE'"+arg1+"%' or marque  LIKE'"+arg1+"%' or etat  LIKE'"+arg1+"%' or dispo LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) {
     model->setQuery(*query);
     ui->tableView->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !!\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
      ui->lineEdit_20->clear();}
}
//pdf
void MainWindow::on_pushButton_17_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                "/home",
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);
    qDebug()<<dir;
    QPdfWriter pdf(dir+"/PdfList.pdf");
                           QPainter painter(&pdf);
                          int i = 4000;

                               painter.drawPixmap(QRect(100,100,2500,2500),QPixmap("C:/Users/ABDOU/Desktop/project/1.png"));
                               painter.drawText(900,650,"Smart airport");
                               painter.setPen(Qt::red);
                               painter.setFont(QFont("Time New Roman", 25));
                               painter.drawText(3000,1400,"Liste des avions");
                               painter.setPen(Qt::black);
                               painter.setFont(QFont("Time New Roman", 15));
                               painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                               painter.drawRect(100,3000,9400,500);
                               painter.setFont(QFont("Time New Roman", 9));
                               painter.drawText(300,3300,"ID");
                               painter.drawText(2000,3300,"Marque");
                               painter.drawText(4000,3300,"Etat");
                               painter.drawText(5600,3300,"Disponibilite");
                               painter.drawText(7000,3300,"Nombre de place");
                               painter.drawRect(100,3000,9400,10700);
                               //QTextDocument previewDoc;
                               QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");
                               //QTextCursor cursor(&previewDoc);
                               QSqlQuery query;
                               query.prepare("select * from avion");
                               query.exec();
                               while (query.next())
                               {
                                   painter.drawText(300,i,query.value(0).toString());
                                   painter.drawText(2000,i,query.value(1).toString());
                                   painter.drawText(4000,i,query.value(2).toString());
                                   painter.drawText(5600,i,query.value(3).toString());
                                   painter.drawText(7000,i,query.value(4).toString());
                                   painter.drawText(8000,i,query.value(5).toString());
                                  i = i +500;
                               }
                               int reponse = QMessageBox::question(this, "Générer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                   QMessageBox::Yes|QMessageBox::No);
                                   if (reponse == QMessageBox::Yes)
                                   {
                                       QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                       painter.end();
                                   }
                                   else
                                   {
                                        painter.end();
                                   }
}
//stat
void MainWindow::on_pushButton_18_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                    model->setQuery("select * from avion where dispo = 'DISPONIBLE' ");
                                    float e=model->rowCount();
                                    model->setQuery("select * from avion where dispo = 'NON DISPONIBLE' ");
                                    float ee=model->rowCount();
                                    float total=e+ee;
                                    QString a=QString("disponible"+QString::number((e*100)/total,'f',2)+"%" );
                                    QString b=QString("non disponible"+QString::number((ee*100)/total,'f',2)+"%" );
                                    QPieSeries *series = new QPieSeries();
                                    series->append(a,e);
                                    series->append(b,ee);
                            if (e!=0)
                            {QPieSlice *slice = series->slices().at(0);
                             slice->setLabelVisible();
                             slice->setPen(QPen());}
                            if ( ee!=0)
                            {
                                     // Add label, explode and define brush for 2nd slice
                                     QPieSlice *slice1 = series->slices().at(1);
                                     //slice1->setExploded();
                                     slice1->setLabelVisible();
                            }
                                    // Create the chart widget
                                    QChart *chart = new QChart();
                                    // Add data to chart with title and hide legend
                                    chart->addSeries(series);
                                    chart->setTitle("Pourcentage des avion disponible : nombre total des avions: "+ QString::number(total));
                                    chart->legend()->hide();
                                    // Used to display the chart
                                    QChartView *chartView = new QChartView(chart);
                                    chartView->setRenderHint(QPainter::Antialiasing);
                                    chartView->resize(1000,500);
                                    chartView->show();
}
//csv
void MainWindow::on_pushButton_19_clicked()
{
    QTableView *table;
                              table = ui->tableView;

                              QString filters("CSV files (.xlsx);;All files (.*)");
                              QString defaultFilter("CSV files (*.xlsx)");
                              QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                 filters, &defaultFilter);
                              QFile file(fileName);

                              QAbstractItemModel *model =  table->model();
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
                                  QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                                            QObject::tr("Export avec succes .\n"
                                                                        "Click OK to exit."), QMessageBox::Ok);
                              }

}
// 2eme crud
// ajouter vol
void MainWindow::on_pushButton_20_clicked()
{
    int idav =ui->lineEdit_21->text().toUInt();
    QString datevl=ui->dateEdit->date().toString("dd/MM/yyyy");
    vol v(idav,datevl);
    bool test=v.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("vol ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);

        ui->lineEdit_21->clear();
        ui->tableView_2->setModel(v.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);
}
// supprimer vol
void MainWindow::on_pushButton_21_clicked()
{
    int id =ui->lineEdit_22->text().toUInt();
    bool test=v.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("vol Supprimé \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_22->clear();
        ui->tableView_2->setModel(v.afficher());
    }
    else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}
//modifier
void MainWindow::on_pushButton_22_clicked()
{
    int id =ui->lineEdit_23->text().toUInt();
    QString date =ui->dateEdit_2->date().toString("dd/MM/yyyy");
    bool test=v.modifier(id ,date);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("vol modifié \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->lineEdit_23->clear();
        ui->tableView_2->setModel(v.afficher());
    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("modification non effectué"),QMessageBox::Cancel);
}
///////////////////////////////////////////////////////////// gestion voyageur //////////////////////////////////////////////////////////
void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->lineEdit_25->text().toInt();
    QString nom=ui->lineEdit_nomvoy->text();
    QString prenom=ui->lineEdit_24->text();
    QString num_passeport=ui->lineEdit_26->text();
    QString classe=ui->lineEdit_27->text();
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
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

void MainWindow::on_pushButton_modifier_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pushButton_afficher_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
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
    ui->stackedWidget_2->setCurrentIndex(7);
}

void MainWindow::on_pushButton_HISTORIQUES_10_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(7);
}

void MainWindow::on_pushButton_HISTORIQUES_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(7);
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
    ui->stackedWidget_2->setCurrentIndex(7);
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
    ui->stackedWidget_2->setCurrentIndex(4);
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
    ui->stackedWidget_2->setCurrentIndex(5);
}

void MainWindow::on_pushButton_HISTORIQUES_14_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(7);
}

void MainWindow::on_pushButton_affiche_h_clicked()
{
    ui->table_histo->setModel(h.afficherh());
}

void MainWindow::on_pushButton_statistiques_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(6);
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
    ui->stackedWidget_2->setCurrentIndex(7);
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
    ui->stackedWidget_2->setCurrentIndex(2);

}
