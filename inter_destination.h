#ifndef INTER_DESTINATION_H
#define INTER_DESTINATION_H

#include <QMainWindow>
#include "destination.h"

namespace Ui {
class Inter_Destination;
}

class Inter_Destination : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inter_Destination(QWidget *parent = nullptr);
    ~Inter_Destination();

private slots:
    void on_btn_ajout_clicked();

    void on_btn_modif_clicked();

    void refresh();

    void stat();

    void on_modif_comboBox_currentIndexChanged(const QString &arg1);

    void on_supp_comboBox_currentIndexChanged(const QString &arg1);

    void on_btn_supp_clicked();

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_btn_pdf_clicked();

    void on_btn_calcul_clicked();

private:
    Ui::Inter_Destination *ui;
    destination D;

};

#endif // INTER_DESTINATION_H
