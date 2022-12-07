#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "destination.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();
    void on_pushButton1_clicked();
    void on_pushButtonm_clicked();


private:
    Ui::MainWindow *ui;
   destination D;
};

#endif // MAINWINDOW_H
