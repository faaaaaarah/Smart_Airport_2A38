#include "connection.h"
#include <QSqlDatabase>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test_bd");
db.setUserName("fathi");//inserer nom de l'utilisateur
db.setPassword("fathi");//inserer mot de passe de cet utilisateur

if (db.open())
 return true;




    return false;

}
