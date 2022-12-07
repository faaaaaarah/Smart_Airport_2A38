#include "statistiques.h"
//#include "ui_statistiques.h"
#include "connection.h"
#include "mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include "ui_dialog.h"
#include "finance.h"
#include <QGridLayout>
#include <QDebug>
statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stati)
{
    QString type1="profit";
     QString type2="perte";
    ui->setupUi(this);
    Connection c;
    QBarSet *set=new QBarSet("Nombre Des journees");
   *set<<f.calculer1(type2)<<f.calculer1(type1);
    QBarSeries *series=new QBarSeries();
    series->append(set);
    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des journees");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList bilan;
    bilan<<"[ perte ]"<<"[profit]"
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(profession);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);

    QChartView *chartview=new QChartView(chart);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(chartview, 0, 0);
    this->setLayout(mainLayout);
       // bool test=c.createconnect();
}

stati::~stati()
{
    delete ui;
}
void stati::choix_bar()
{
QSqlQuery q1,q2,q3;
qreal tot=0,c1=0,c2=0;

q1.prepare("SELECT * FROM financet");
q1.exec();

q2.prepare("SELECT * FROM financet WHERE type='profit'");
q2.exec();

q3.prepare("SELECT * FROM employ WHERE type='perte'");
q3.exec();



while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}

c1=c1/tot;
c2=c2/tot;

// Assign names to the set of bars used
        QBarSet *set0 = new QBarSet("choix 1");
        QBarSet *set1 = new QBarSet("choix 2");


        // Assign values for each bar
        *set0 << c1;
        *set1 << c2;



        // Add all sets of data to the chart as a whole
        // 1. Bar Chart
        QBarSeries *series = new QBarSeries();

        // 2. Stacked bar chart
        series->append(set0);
        series->append(set1);


        // Used to define the bar chart to display, title
        // legend,
        QChart *chart = new QChart();

        // Add the chart
        chart->addSeries(series);
        QPalette pal = qApp->palette();

        // Change the color around the chart widget and text
        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x4545));

        // Apply palette changes to the application
        qApp->setPalette(pal);


// Used to display the chart
chartView = new QChartView(chart);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(1000,900);

chartView->show();
}
void stati::choix_pie()
{
     QString type1="profit";
      QString type2="perte";

QSqlQuery q1,q2,q3;
qreal tot=0,c1=0,c2=0;

q1.prepare("SELECT * FROM financet");
q1.exec();

q2.prepare("SELECT * FROM financet WHERE role='"+type2+"'");
q2.exec();

q3.prepare("SELECT * FROM financet WHERE role='"+type1+"'");
q3.exec();


while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}

c1=(c1/tot);
c2=c2/tot;
qDebug()<<c1;

// Define slices and percentage of whole they take up
QPieSeries *series = new QPieSeries();
series->append("profit",c1);
series->append("perte",c2);




// Create the chart widget
QChart *chart = new QChart();

// Add data to chart with title and show legend
chart->addSeries(series);
chart->legend()->show();


// Used to display the chart
chartView = new QChartView(chart,ui->label);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(900,700);

chartView->show();
}
