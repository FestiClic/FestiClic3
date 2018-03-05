#include "database.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "login.h"
#include "accueil.h"

Database::Database()
{

}

/*
//ouverture de la connexion bdd
bool Database::openConnexion()
{
    maBaseDeDonnee = QSqlDatabase::addDatabase("QSQLITE");
    //maBaseDeDonnee.setDatabaseName("Z:/Projet C++/Codes/Fclic/database.db");  //CCI
    maBaseDeDonnee.setDatabaseName("C:/Users/Mourad/Desktop/ADAI/Fclic/database.db");   //Maison


    if(maBaseDeDonnee.open())
    {
        qDebug()<<("Connexion...");
        return true;
    }
    else
    {
        qDebug()<<("Echec de la connexion");
        return false;
    }
}

//fermeture de la connexion bdd
void Database::closeConnexion()
{
    maBaseDeDonnee.close();
    maBaseDeDonnee.removeDatabase(QSqlDatabase::defaultConnection);

}
*/
