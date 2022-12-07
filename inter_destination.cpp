#include "inter_destination.h"
#include "ui_inter_destination.h"
#include <QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>


Inter_Destination::Inter_Destination(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inter_Destination)
{
    ui->setupUi(this);
    ui->ajout_code->setValidator(new QIntValidator(0, 9999999, this));
    //Column size
    ui->table_destination->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    refresh();

    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();
    stat();

}

Inter_Destination::~Inter_Destination()
{
    delete ui;
}

void Inter_Destination::refresh()
{
    ui->table_destination->setModel(D.afficher());

    ui->modif_comboBox->setModel(D.remplircombo());
    ui->supp_comboBox->setModel(D.remplircombo());
    ui->comboBox->setModel(D.remplircomboCalcul());


}
void Inter_Destination::on_btn_ajout_clicked()
{
    int code=ui->ajout_code->text().toInt();
    QString pays=ui->ajout_pays->text();
    QString ville=ui->ajout_ville->text();
    QString aeroport=ui->ajout_aero->text();
    destination D(code,pays,ville,aeroport) ;
    bool test=D.ajouter();
    if(test)
    {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("ajout effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            refresh();
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("ajout non effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

//modifier

void Inter_Destination::on_modif_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->modif_comboBox->currentText();

    query =D.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->modif_pays->setText(query.value(1).toString());
            ui->modif_ville->setText(query.value(2).toString());
            ui->modif_aero->setText(query.value(3).toString());
        }
    }

}

void Inter_Destination::on_btn_modif_clicked()
{
        if(D.modifier(ui->modif_comboBox->currentText() ,ui->modif_pays->text(),ui->modif_ville->text(),ui->modif_aero->text()))
        {
            //refresh combobox + tableau
            refresh();



        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Modifier un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

//supprimer

void Inter_Destination::on_supp_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->supp_comboBox->currentText();

    query =D.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->supp_pays->setText(query.value(1).toString());
            ui->supp_ville->setText(query.value(2).toString());
            ui->supp_aero->setText(query.value(3).toString());
        }
    }

}

void Inter_Destination::on_btn_supp_clicked()
{
    QMessageBox::StandardButton reply =QMessageBox::question(this,
                          "Supprimer","Voulez-vous vraiment supprimer ?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        bool test=D.supprimer(ui->supp_comboBox->currentText().toInt());
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("Supprimer effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            //refresh combobox + tableau
            refresh();

        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Supprimer un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }
}

//recherche

void Inter_Destination::on_recherche_cursorPositionChanged(int arg1, int arg2)
{
    ui->table_destination->setModel(D.afficherecherche(ui->recherche->text()));


    if(ui->recherche->text()=="")
    {
        ui->table_destination->setModel(D.afficher());//refresh
    }

}

void Inter_Destination::on_btn_pdf_clicked()
{
    QString strStream;
               QTextStream out(&strStream);
               const int rowCount = ui->table_destination->model()->rowCount();
               const int columnCount =ui->table_destination->model()->columnCount();

               out <<  "<html>\n"
                       "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                       <<  QString("<title>%1</title>\n").arg("eleve")
                       <<  "</head>\n"
                       "<body bgcolor=#F4B8B8 link=#5000A0>\n"
                          // "<img src='C:/Users/ksemt/Desktop/final/icon/logo.webp' width='20' height='20'>\n"
                           "<img src='C:/Users/DeLL/Desktop/logooo.png' width='100' height='100'>\n"
                           "<h1> Liste des Destinations </h1>"
                            "<h1>  </h1>"

                           "<table border=1 cellspacing=0 cellpadding=2>\n";


               // headers
                   out << "<thead><tr bgcolor=#f0f0f0>";
                   for (int column = 0; column < columnCount; column++)
                       if (!ui->table_destination->isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(ui->table_destination->model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";
                   // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_destination->isColumnHidden(column)) {
                                  QString data = ui->table_destination->model()->data(ui->table_destination->model()->index(row, column)).toString().simplified();
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

                      QPrinter printer;

                      QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                      if (dialog->exec() == QDialog::Accepted) {
                          document->print(&printer);
                   }

}

void Inter_Destination::on_btn_calcul_clicked()
{
    QString total=QString::number(D.Calculer(ui->comboBox->currentText()));

    ui->label_total->setText(total);

}

// STATISTIQUE

void Inter_Destination::stat()
{

    QPieSeries *series=new QPieSeries();
    QStringList l=D.listpays();

    for (int i = 0; i < l.size(); ++i){

        series->append(l[i] ,D.calculpays(l[i]));
    }

    QPieSlice *slice1=series->slices().at(1);
    slice1->setExploded(true);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("statistiques");
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartview=new QChartView(chart);
    chartview->setUpdatesEnabled(true);
    QGridLayout *mainLayout=new QGridLayout();
    mainLayout->addWidget(chartview,0,0);

    ui->label_stat->setLayout(mainLayout);
    ui->label_stat->layout()->update();


}
