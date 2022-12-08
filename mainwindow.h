#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include "avion.h"
#include "vol.h"
#include "voyageur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QTcpocket;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_envoyer_2_clicked();

    void sendMail();
    void mailSent(QString) ;


    void on_lineEdit_15_textChanged(const QString &arg1);

    void on_pushButton_23_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_lineEdit_20_textChanged(const QString &arg1);

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::MainWindow *ui;
    employee e;
    avion a;
    vol v;
    Voyageur V;
    Voyageur V1;
    historique h;
};
#endif // MAINWINDOW_H
