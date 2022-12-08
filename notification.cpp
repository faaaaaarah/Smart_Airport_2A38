#include "notification.h"

#include <QSystemTrayIcon>
notification::notification()
{

}
void notification::ajout_notification()
{

      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

      notifyIcon->setIcon(QIcon("C:/Users/PC/Desktop/notification.PNG"));
      notifyIcon->show();

      notifyIcon->showMessage("Entree Ajoutee ","Une nouvelle Entree a été ajoutée",QSystemTrayIcon::Information,15000);

}
void notification::notification_supprimer()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/Users/PC/Desktop/notification.PNG"));
    notifyIcon->show();
    notifyIcon->showMessage("Donnees supprimees","Les donnees ont été  supprimées ",QSystemTrayIcon::Critical,15000);
}
void notification::notification_modifier()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/PC/Desktop/notification.PNG"));
    notifyIcon->show();
    notifyIcon->showMessage("Donnees modifiees","Les donnees ont éte modifiés ",QSystemTrayIcon::Warning,15000);
}
