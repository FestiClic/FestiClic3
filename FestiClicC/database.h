#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database
{
public:
    Database();

    QSqlDatabase maBaseDeDonnee;

    //ouverture de la connexion bdd
    bool openConnexion();

    //fermeture de la connexion bdd
    void closeConnexion();

    //Création des tables de la Base de données
    void CreerLesTablesDeLaBDD();

private:

};

#endif // DATABASE_H
