#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include "avion.h"
#include "vol.h"
#include "voyageur.h"
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
#include "statis.h"
#include "QSystemTrayIcon"
#include <QPushButton>
#include "produit.h"
#include "arduino.h"
#include "qrcodegen.hpp"

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
    int getselectedtran();
 void update_label();

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
    
    void on_pb_trier_clicked();
    
    void on_pushButton_rech_tri_clicked();
    
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
    
    void on_pushButton_HISTORIQUES_13_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_UpdateTran_clicked();

    void on_rec_textChanged(const QString &arg1);

    void on_pushButton_01_clicked();

    void on_pushButton_02_clicked();

    void on_pushButton_03_clicked();

    void on_pushButton_04_clicked();

    void on_pushButton_05_clicked();

    void on_pushButton_06_clicked();

    void on_Statistique_clicked();

    void on_pb_print_clicked();

    void on_pushButton_24_clicked();

    void on_tab_prod_activated(const QModelIndex &index);

    void on_pushButton_27_clicked();

    void update_labell();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

private:
    Ui::MainWindow *ui;
    employee e;
    avion a;
    vol v;
    Voyageur V;
    Voyageur V1;
    historique h;
    Produit P;
    QSystemTrayIcon *info;
    Arduino ar;
    QByteArray data;
    QByteArray set; // variable contenant les données reçues
    int i=0;
    int wait=0;
    int inc=0;
    Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
