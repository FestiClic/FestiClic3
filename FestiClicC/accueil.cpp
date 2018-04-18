#include "accueil.h"
#include "ui_accueil.h"

#include "login.h"
#include "database.h"
#include "spectacles.h"
#include "clients.h"
#include "billetterie.h"
#include "plandesalle.h"
#include "utilisateur.h"
#include "administrationbillet.h"
#include "frequentation.h"
#include <QDate>
#include <QDateTime>
#include <QTime>
#include <QTabWidget>
#include <QDesktopWidget>

Accueil::Accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);

    //Ouverture de la connexion
    Database connexion;
    connexion.openConnexion();

    //Insérer les données en base de données
    InsererDonneesDansBDD();

    //ouverture de la page login
    Login login;
    login.setModal(true);


    if (login.exec() == QDialog::Accepted)
    {
        //Ok
        lanceApp=true;

        /*      Recupérer les données utilisateur pour les affecter au label NomUtilisateur
 *      //Affectation nom et prenom utilisateur
        QSqlQuery query;
        query.prepare("SELECT NomUtilisateur, PrenomUtilisateur FROM Utilisateurs "
                      "WHERE IdUtilisateur = 1 ");
        if(query.exec())
        {
            while (query.next())
            {
                ui->aLabelNomUtilisateur->setText(query.value(1).toString() + " " + query.value(2).toString());
            }
        }
*/
    }
    else
    {
        //Echec
        lanceApp=false;
    }

    //Label Bonjour
    ui->aLabelHello->setStyleSheet("color: white;");
    ui->aLabelHello->setText("Bonjour");

    //Label saison culturelle
    ui->aLabelNomUtilisateur->setStyleSheet("color: white;");
    ui->aLabelNomUtilisateur->setText("Connexion Monoposte \n Saison 2017 / 2018");

    //Affectation de la date du jour
    ui->aLabelDate->setStyleSheet("color: white;");
    ui->aLabelDate->setText(QDate::currentDate().toString("dd - MM - yyyy"));

}

void Accueil::InsererDonneesDansBDD()
{
    //Insérer un compte utilisateur de démonstartion
    QSqlQuery query;

    query.exec("INSERT INTO Utilisateurs (IdUtilisateur, NomUtilisateur, PrenomUtilisateur, Username, Password) "
                            "VALUES (1, 'CompteDemonstration', 'Demonstation', 'demo', 'demo')");



    //Insérer données pour le compte de démonstration
 /*
    //Billet
    query.exec("INSERT INTO Billets ( "
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
*/

    //Clients
    query.exec("INSERT INTO Clients (`IdClient`, `Civilite`, `NomClient`, `PrenomClient`, `EmailClient`, "
                              "`AdresseClient`, `Cp`,`Ville`, `TelClient`, `MobClient`, `Abonne` )"
                              "VALUES (1, 'Mme', 'ADNET', 'Francoise', 'adnet.francoise@yahoo.fr',"
                              "'Route de Scherwiller', '67600', 'Sélestat', '0301234567', '0601234567', 'Abonné(e)' )");

    query.exec("INSERT INTO Clients (`IdClient`, `Civilite`, `NomClient`, `PrenomClient`, `EmailClient`, "
                              "`AdresseClient`, `Cp`,`Ville`, `TelClient`, `MobClient`, `Abonne` )"
                              "VALUES (2, 'Mme', 'ADNES', 'Emmanuelle', 'addes.emmanuelle@yahoo.fr',"
                              "'Route des Blés', '68000', 'Colmar', '0381234568', '0681234569', 'Non abonné(e)' )");

    query.exec("INSERT INTO Clients (`IdClient`, `Civilite`, `NomClient`, `PrenomClient`, `EmailClient`, "
                              "`AdresseClient`, `Cp`,`Ville`, `TelClient`, `MobClient`, `Abonne` )"
                              "VALUES (3, 'Mr', 'PIGNON', 'François', 'ddc@lediner.fr',"
                              "'Route George Van Brugel', '67000', 'Strasbourg', '0388234568', '0681234569', 'Abonné(e)' )");

    //Configuration des salles
    query.exec("INSERT INTO Clients (`IdConfigSalle`, `IntituleConfigSalle`, `Jauge` )"
                              "VALUES (1, 'Placement numérotée', '50' )");

    query.exec("INSERT INTO Clients (`IdConfigSalle`, `IntituleConfigSalle`, `Jauge` )"
                              "VALUES (2, 'Placement libre', '50' )");

    query.exec("INSERT INTO Clients (`IdConfigSalle`, `IntituleConfigSalle`, `Jauge` )"
                              "VALUES (3, 'Assis debout', '150' )");

    query.exec("INSERT INTO Clients (`IdConfigSalle`, `IntituleConfigSalle`, `Jauge` )"
                              "VALUES (4, 'Fosse concert', '300' )");

    query.exec("INSERT INTO Clients (`IdConfigSalle`, `IntituleConfigSalle`, `Jauge` )"
                              "VALUES (5, 'Café concert', '40' )");

/*

    //Modes de paiement
    query.exec("CREATE TABLE IF NOT EXISTS ModePaiement ( "
                                   "`IdModePaiement` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                                   "`TypeModePaiement` TEXT );");

    //Places
    query.exec("CREATE TABLE IF NOT EXISTS Places ( "
                             "`IdPlace` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                             "`NumPlace` TEXT NOT NULL, "
                             "`NumPlacePlan` TEXT, "
                             "`Reserve` NUMERIC DEFAULT 0, "
                             "`IdSpectacleP` INTEGER, "
                             "FOREIGN KEY(`IdSpectacleP`) REFERENCES `Spectacles`(`IdSpectacle`) );");

    //Sièges
    query.exec("CREATE TABLE IF NOT EXISTS Sieges ( "
                             "`IdSiege` INTEGER NOT NULL, "
                             "`NumSiege` TEXT, PRIMARY KEY(`IdSiege`) );");

    //Spectacles
    query.exec("CREATE TABLE IF NOT EXISTS Spectacles ( "
                                 "`IdSpectacle` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                                 "`Spectacle` TEXT NOT NULL, "
                                 "`Date` TEXT NOT NULL, "
                                 "`Heure` NUMERIC NOT NULL, "
                                 "`JaugeSpectacle` INTEGER, "
                                 "`IdConfigSalle` INTEGER, FOREIGN KEY(`IdConfigSalle`) REFERENCES `ConfigSalle`(`IdConfigSalle`) );");

    //Tarifs
    query.exec("CREATE TABLE IF NOT EXISTS Tarifs ( "
                             "`IdTarif` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                             "`IntituleTarif` TEXT NOT NULL, "
                             "`Prix` REAL );");

    //Transactions
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

    //Utilisateurs
    query.exec("CREATE TABLE IF NOT EXISTS Utilisateurs ( "
                                   "`IdUtilisateur` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, "
                                   "`NomUtilisateur` TEXT NOT NULL, "
                                   "`PrenomUtilisateur` TEXT NOT NULL, "
                                   "`Administrateur` NUMERIC DEFAULT 0, "
                                   "`Username` TEXT NOT NULL, "
                                   "`Password` TEXT );");
 */

}

Accueil::~Accueil()
{
    delete ui;
}

//BOUTON Affecter les données à une TableView
void Accueil::on_aBtnSpectacles_clicked()
{
    Spectacles spectacles;
    spectacles.setModal(true);
    spectacles.exec();
}

void Accueil::on_aBtnClients_clicked()
{
    Clients clients;
    clients.setModal(true);
    clients.exec();
}

void Accueil::on_aBtnBilletterie_clicked()
{
    Billetterie billetterie;
    billetterie.setModal(true);
    billetterie.exec();
}

void Accueil::on_aBtnPlanDeSalle_clicked()
{
    PlanDeSalle planDeSalle;
    planDeSalle.setModal(true);
    planDeSalle.exec();
}

void Accueil::on_aBtnUtilisateur_clicked()
{
    Utilisateur utilisateur;
    utilisateur.setModal(true);
    utilisateur.exec();
}

void Accueil::on_aBtnAdministratioBillet_clicked()
{
    AdministrationBillet administrationBillet;
    administrationBillet.setModal(true);
    administrationBillet.exec();
}

void Accueil::on_aBtnFrequentation_clicked()
{
    Frequentation frequentation;
    frequentation.setModal(true);
    frequentation.exec();
}

void Accueil::on_aBtnQuitter_clicked()
{
    this->close();
}


