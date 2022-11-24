#ifndef CHATCONNECT_H
#define CHATCONNECT_H

#include <QDialog>

namespace Ui {
class chatconnect;
}
//namespace chatconnect
//{
class chatconnect : public QDialog
{
    Q_OBJECT

public:
    explicit chatconnect(QWidget *parent = nullptr);
    ~chatconnect();
    QString hostname() const;
    quint16 port() const;
private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::chatconnect *ui;
    QString mHostname;
    quint16 mPort;
};
inline QString chatconnect::hostname() const
{
    return mHostname;
}
inline quint16 chatconnect::port() const
{
    return mPort;
}
//} //end namespace chatconnect
#endif // CHATCONNECT_H

