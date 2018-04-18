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
    //maBaseDeDonnee=QSqlDatabase::addDatabase("QSQLITE");

    //CCI C:
    //maBaseDeDonnee.setDatabaseName("C:/Users/adai10/Desktop/ProjetQtC++/FestiClic3/database.db");

    //Maison Projet C
    //maBaseDeDonnee.setDatabaseName("C:/Users/Mourad/Desktop/ADAI/FestiClic3/database.db");

    //maBaseDeDonnee=QSqlDatabase::addDatabase("QSQLITE");


    //Création des tables de la bdd
    CreerLesTablesDeLaBDD();



/*
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
 */
}

void Database::CreerLesTablesDeLaBDD()
{

    //Creation du fichier de la base de donées.
    maBaseDeDonnee = QSqlDatabase::addDatabase("QSQLITE");
    maBaseDeDonnee.setDatabaseName("./festiclic.db");

    maBaseDeDonnee.open();

    //Créer la table billets
    QSqlQuery query;

    query.exec("CREATE TABLE IF NOT EXISTS Billets ( "
                       "`IdBillet` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                       "`NumBillet` TEXT, "
                       "`IdClient` INTEGER, "
                       "`IdSpectacle` INTEGER, "
                       "`IdTarif` INTEGER, "
                       "`IdPlace` INTEGER, FOREIGN KEY(`IdSpectacle`) "
                       "REFERENCES `Spectacles`(`IdSpectacle`), "
                       "FOREIGN KEY(`IdPlace`) REFERENCES `Places`(`IdPlace`), "
                       "FOREIGN KEY(`IdClient`) REFERENCES `Clients`(`IdClient`), "
                       "FOREIGN KEY(`IdTarif`) REFERENCES `Tarifs`(`IdTarif`) );");


    //Créer la table clients
    //QSqlQuery creerTableClients;

    query.exec("CREATE TABLE IF NOT EXISTS Clients ( "
                              "`IdClient` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                              "`Civilite` TEXT, "
                              "`NomClient` TEXT NOT NULL, "
                              "`PrenomClient` TEXT NOT NULL, "
                              "`EmailClient` TEXT, "
                              "`AdresseClient` TEXT, "
                              "`Cp` TEXT, "
                              "`Ville` TEXT, "
                              "`TelClient` NUMERIC, "
                              "`MobClient` NUMERIC, "
                              "`Abonne` TEXT );");

    //Créer la table configuration des salles
    //QSqlQuery creerTableConfigSalle;

    query.exec("CREATE TABLE IF NOT EXISTS ConfigSalle ( "
                                  "`IdConfigSalle` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                                  "`IntituleConfigSalle` TEXT, "
                                  "`Jauge` INTEGER, "
                                  "`IdPlace` INTEGER, "
                                  "FOREIGN KEY(`IdPlace`) REFERENCES `Places`(`IdPlace`) );");

    //Créer la table modes de paiement
    //QSqlQuery creerTableModePaiement;

    query.exec("CREATE TABLE IF NOT EXISTS ModePaiement ( "
                                   "`IdModePaiement` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                                   "`TypeModePaiement` TEXT );");

    //Créer la table places
    //QSqlQuery creerTablePlaces;

    query.exec("CREATE TABLE IF NOT EXISTS Places ( "
                             "`IdPlace` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                             "`NumPlace` TEXT NOT NULL, "
                             "`NumPlacePlan` TEXT, "
                             "`Reserve` NUMERIC DEFAULT 0, "
                             "`IdSpectacleP` INTEGER, "
                             "FOREIGN KEY(`IdSpectacleP`) REFERENCES `Spectacles`(`IdSpectacle`) );");

    //Créer la table Sièges
    //QSqlQuery creerTableSieges;

    query.exec("CREATE TABLE IF NOT EXISTS Sieges ( "
                             "`IdSiege` INTEGER NOT NULL, "
                             "`NumSiege` TEXT, PRIMARY KEY(`IdSiege`) );");

    //Créer la table Spectacles
    //QSqlQuery creerTableSpectacles;

    query.exec("CREATE TABLE IF NOT EXISTS Spectacles ( "
                                 "`IdSpectacle` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                                 "`Spectacle` TEXT NOT NULL, "
                                 "`Date` TEXT NOT NULL, "
                                 "`Heure` NUMERIC NOT NULL, "
                                 "`JaugeSpectacle` INTEGER, "
                                 "`IdConfigSalle` INTEGER, FOREIGN KEY(`IdConfigSalle`) REFERENCES `ConfigSalle`(`IdConfigSalle`) );");

    //Créer la table Tarifs
    //QSqlQuery creerTableTarifs;

    query.exec("CREATE TABLE IF NOT EXISTS Tarifs ( "
                             "`IdTarif` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                             "`IntituleTarif` TEXT NOT NULL, "
                             "`Prix` REAL );");

    //Créer la table Transactions
    //QSqlQuery creerTableTransactions;

    query.exec("CREATE TABLE IF NOT EXISTS Transactions ( "
                                   "`IdTransaction` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                                   "`IdClient` INTEGER, "
                                   "`IdSpectacle` INTEGER, "
                                   "`IdTarif` INTEGER, "
                                   "`IdModePaiement` INTEGER, "
                                   "`NombreDePlaces` INTEGER, "
                                   "FOREIGN KEY(`IdTarif`) REFERENCES `Tarifs`(`IdTarif`), "
                                   "FOREIGN KEY(`IdSpectacle`) REFERENCES `Spectacles`(`IdSpectacle`), "
                                   "FOREIGN KEY(`IdModePaiement`) REFERENCES `ModePaiement`(`IdModePaiement`), "
                                   "FOREIGN KEY(`IdClient`) REFERENCES `Clients`(`IdClient`) );");

    //Créer la table Utilisateurs
    //QSqlQuery creerTableUtilisateurs;

    query.exec("CREATE TABLE IF NOT EXISTS Utilisateurs ( "
                                   "`IdUtilisateur` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                                   "`NomUtilisateur` TEXT NOT NULL, "
                                   "`PrenomUtilisateur` TEXT NOT NULL, "
                                   "`Administrateur` NUMERIC DEFAULT 0, "
                                   "`Username` TEXT NOT NULL, "
                                   "`Password` TEXT );");





}

void Database::closeConnexion()
{
    maBaseDeDonnee.close();
    maBaseDeDonnee.removeDatabase(QSqlDatabase::defaultConnection);
}

