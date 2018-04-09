#include "database.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "login.h"
#include "accueil.h"

Database::Database()
{
    openConnexion();

}

bool Database::openConnexion()
{
    maBaseDeDonnee=QSqlDatabase::addDatabase("QSQLITE");

    //maBaseDeDonnee.setDatabaseName("Z:/Projet C++/FestiClic3/database.db");  //CCI Z:
    maBaseDeDonnee.setDatabaseName("C:/Users/adai10/Desktop/projet Qt C++/FestiClic3/database.db"); //CCI C:


    //maBaseDeDonnee.setDatabaseName("C:/Users/Mourad/Desktop/ADAI/Fclic/database.db");   //Maison Projet B
    //maBaseDeDonnee.setDatabaseName("C:/Users/Mourad/Desktop/ADAI/FestiClic3/database.db");  //Maison Projet C

    //maBaseDeDonnee.setDatabaseName("C:/Users/Mourad/Desktop/ADAI/FestiClic3/database.db");  //Maison Projet C


    if(maBaseDeDonnee.open())
    {
        qDebug()<<("Connexion...");
        return true;
    }
    else
    {
        qDebug()<<("Connexion a ouvrir");
        return false;
    }
}

void Database::closeConnexion()
{
    maBaseDeDonnee.close();
    maBaseDeDonnee.removeDatabase(QSqlDatabase::defaultConnection);
}

