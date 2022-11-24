#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "voyageur.h"

namespace Ui {
class MainWindow;
}
class QTcpocket;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_ajouter_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_afficher_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_HISTORIQUES_11_clicked();

    void on_pushButton_HISTORIQUES_10_clicked();

    void on_pushButton_HISTORIQUES_6_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_HISTORIQUES_12_clicked();

    void on_pushButton_RECH_TRI_clicked();

    void on_pb_modifier_trier_clicked();

    void on_pb_trier_clicked();

    void on_pushButton_rech_tri_clicked();

    void on_pushButton_HISTORIQUES_13_clicked();

    void on_pb_chercher_clicked();

    void on_pb_pdf_clicked();

    void on_pushButton_historiques_clicked();

    void on_pushButton_HISTORIQUES_14_clicked();

    void on_pushButton_affiche_h_clicked();

    void on_pushButton_statistiques_clicked();

    void on_pushButton_statistiques_2_clicked();

    void on_pushButton_HISTORIQUES_15_clicked();

    void on_pushb_qrcode_clicked();

    void on_pushButton_qr_clicked();

private:
    Ui::MainWindow *ui;
    Voyageur V;
    Voyageur V1;
    historique h;

};

#endif // MAINWINDOW_H
