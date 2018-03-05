#ifndef DATABASE_H
#define DATABASE_H

#include "accueil.h"
#include "login.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QString>


class Database
{
public:
    Database();

    //ouverture de la connexion bdd
//    bool openConnexion();

    //fermeture de la connexion bdd
//    void closeConnexion();
private:
    QString maBaseDeDonnee;


};

#endif // DATABASE_H
