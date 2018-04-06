#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QtDebug>



class Database
{
public:
    Database();

    QSqlDatabase maBaseDeDonnee;

    //ouverture de la connexion bdd
    bool openConnexion();

    //fermeture de la connexion bdd
    void closeConnexion();
private:



};

#endif // DATABASE_H
