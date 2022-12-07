/*#ifndef STATI_H
#define STATI_H
#include"finance.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include"connection.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include<QString>
#include<qsqlquerymodel.h>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stati;
}

class stati : public QDialog
{
    Q_OBJECT

public:
    explicit stati(QWidget *parent = nullptr);
    ~stati();
    QChartView *chartView ;
    void choix_bar();
    void choix_pie();
private:
    Ui::stati *ui;
    //stati s;
   finance f ;
};

#endif // STATI_H
*/
