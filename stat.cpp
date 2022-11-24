#include "stat.h"
//#include "ui_stat.h"
#include <qvariant.h>
#include "voyageur.h"
#include <QGridLayout>
#include <QWidget>
#include <QtCore>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>
#include <qwindow.h>
#include <QChartView>

statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
   // ui->setupUi(this);
       QBarSet *set=new QBarSet("classe ");
       QString   economie,affaires,premiere;
      *set<<A.calculer1("economie")<<A.calculer1("affaires")<<A.calculer1("premiere");
       QBarSeries *series=new QBarSeries();

       series->append(set);
       QChart *chart=new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistiques des classes"); //le titre
       chart->setAnimationOptions(QChart::AllAnimations); //l'animation
       QStringList categories;  // contient les categories de classe
       categories<<"economie"<<"affaires"<<"premiere";
       QBarCategoryAxis *axis=new QBarCategoryAxis();
       axis->append(categories); //axis comprend les differentes categories
       chart->createDefaultAxes(); // des colonnes (sur x)
       chart->setAxisX(axis,series);

       QChartView *chartview=new QChartView(chart); //display the chart

       QGridLayout *mainLayout = new QGridLayout;
       mainLayout->addWidget(chartview, 5, 5);
       this->setLayout(mainLayout);
}
statistiques ::~statistiques()
{
delete ui;
}
