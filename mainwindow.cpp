#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "destination.h"
#include"mainwindow.h"
#include <QMessageBox>
#include"modifier.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_code->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_aff->setModel(D.afficher());

    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int code=ui->le_code->text().toInt();
    QString pays=ui->le_pays->text();
    QString ville=ui->le_ville->text();
    QString aeroport=ui->le_aeroport->text();
    destination D(code,pays,ville,aeroport) ;
    bool test=D.ajouter();

    if(test)
    {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("ajout effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_aff->setModel(D.afficher());

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("ajout non effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
     destination D1; D1.setcode(ui->le_code_sup->text().toInt());
     bool test=D1.supprimer(D1.getcode());
     QMessageBox msgBox;
     if(test)
     {

                 msgBox.setText("suppression ok");
                 ui->tab_aff->setModel(D.afficher());
     }
             else
         msgBox.setText("suppression not ok");
     msgBox.exec();
}
void MainWindow::on_pushButton1_clicked()
{
   destination D;
QString rech =ui->le_code_sup->text();
 ui->tab_aff->setModel(D.chercher_destination(rech));
}
void MainWindow::on_pushButtonm_clicked()
{


     modifier m;
    m.setModal(true);
    m.exec();
      ui->tab_aff->setModel(D.afficher());
}
