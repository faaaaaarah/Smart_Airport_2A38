#ifndef CHAT_H
#define CHAT_H
#include <QTcpSocket>
#include <QDialog>

namespace Ui {
class chat;
}
namespace chatconnect
{
class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();

private slots:
    void on_send_clicked();

    void on_bind_clicked();

private:
    Ui::chat *ui;
    QTcpSocket *mSocket;

};
//} // end namespace chatconnect
#endif // CHAT_H
