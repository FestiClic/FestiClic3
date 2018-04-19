#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

/**
 * @brief La class Database pour la création de la base de données et des tables
 */
class Database
{

public:
    Database();

    /**
     * @brief maBaseDeDonnee base de données
     */
    QSqlDatabase maBaseDeDonnee;


    /**
     * @brief openConnexion Méthode pour l'ouverture de la connexion à la base de données
     * @return
     */
    bool openConnexion();

    /**
     * @brief closeConnexion Méthode pour la fermeture de la connexion à la base de données
     */
    void closeConnexion();

    /**
     * @brief CreerLesTablesDeLaBDD Méthode pour lacréation de la base de données er la création des tables de la BDD
     */
    void CreerLesTablesDeLaBDD();

private:

};


#endif // DATABASE_H
