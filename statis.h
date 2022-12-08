#ifndef STATISTIQUES_H
#define STATISTIQUES_H
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
#include <QDialog>
using namespace std;

namespace Ui {
class statis;
}

class statis : public QDialog
{
    Q_OBJECT

public:
    explicit statis(QWidget *parent = nullptr);
        int Statis_partie2() ;
        int Statis_partie3() ;
        int Statis_partie4() ;
        int Statis_partie5() ;
        int Statis_partie6() ;
        void paintEvent(QPaintEvent *) ;

    ~statis();

private:
    Ui::statis *ui;
private slots :
};

#endif // STATISTIQUE_H
