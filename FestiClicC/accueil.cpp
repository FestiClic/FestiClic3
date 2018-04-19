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
#include <QVector>
#include <QDebug>

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

    //ouverture de la page login au lancement de l'application
    Login login;
    login.setModal(true);

    //Vérification si la connexion est acceptée
    if (login.exec() == QDialog::Accepted)
    {
        //Ok
        lanceApp=true;

        //*//////////////////////////////////////////////////////////////////////////////////////////////////////////

        /*     //Recupérer les données utilisateur pour les affecter au label NomUtilisateur
       //Affectation nom et prenom utilisateur

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

        //*//////////////////////////////////////////////////////////////////////////////////////////////////////////
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

    //Affectation de la date du jour dans le labelDate
    ui->aLabelDate->setStyleSheet("color: white;");
    ui->aLabelDate->setText(QDate::currentDate().toString("dd - MM - yyyy"));
}

void Accueil::InsererDonneesDansBDD()
{
    //Données fixes nécessaires pour la démonstration de l'application

    QSqlQuery query;

    //Requête pour insérer un compte utilisateur de démonstartion
    query.exec("INSERT INTO Utilisateurs (IdUtilisateur, NomUtilisateur, PrenomUtilisateur, Username, Password) "
               "VALUES (1, 'CompteDemonstration', 'Demonstation', 'demo', 'demo')");


    //Insérer des données pour le compte de démonstration

    //Requête pour la table Billets
    query.exec("INSERT INTO Billets (`IdBillet`, `NumBillet`) "
               "VALUES (1, 1) ");

    //Requête pour la table Clients
    query.exec("INSERT INTO Clients (`IdClient`, `Civilite`, `NomClient`, `PrenomClient`, `EmailClient`, "
               "`AdresseClient`, `Cp`,`Ville`, `TelClient`, `MobClient`, `Abonne` )"
               "VALUES (1, 'Mme', 'ADNET', 'Francoise', 'adnet.francoise@yahoo.fr',"
               "'Route de Scherwiller', '67600', 'Sélestat', '0301234567', '0601234567', 'Abonné(e)' ), "
               "(2, 'Mme', 'ADNES', 'Emmanuelle', 'addes.emmanuelle@yahoo.fr',"
               "'Route des Blés', '68000', 'Colmar', '0381234568', '0681234569', 'Non abonné(e)' ), "
               "(3, 'Mr', 'PIGNON', 'François', 'ddc@lediner.fr',"
               "'Route George Van Brugel', '67000', 'Strasbourg', '0388234568', '0681234569', 'Abonné(e)' ) ");


    //Requête pour la table Configuration des salles
    query.exec("INSERT INTO ConfigSalle (`IdConfigSalle`, `IntituleConfigSalle`, `Jauge` )"
               "VALUES (1, 'Placement numérotée', '50' ), "
               "(2, 'Placement libre', '50' ) ");

    //Requête pour la table Modes de paiement
    query.exec("INSERT INTO ModePaiement (`IdModePaiement`, `TypeModePaiement` )"
               "VALUES (1, 'Carte bancaire' ), "
               "(2, 'Espèces' ), "
               "(3, 'Chèque' ), "
               "(4, 'Chèque culture' ), "
               "(5, 'Chèque cadeau' ) ");

    //Requête pour la table Transactions
    query.exec("INSERT INTO Transactions (`IdTransaction` )"
                              "VALUES (100 )");

    //Requête pour la table Tarifs
    query.exec("INSERT INTO Tarifs (`IdTarif`, `IntituleTarif`, `Prix` )"
               "VALUES (1, 'Plein Tarif', '21.00' ),"
               "(2, 'Tarif Réduit', '12.60' ), "
               "(3, 'Carte Culture', '6.00' ), "
               "(4, 'Carte VitaCulture', '5.50' ), "
               "(5, 'Les scolaires', '4.50' ), "
               "(6, 'Invité Cie', '0.00' ), "
               "(7, 'Presse', '0.00' ) ");

    //Requête pour la table Sièges
    query.exec("INSERT INTO Sieges (`IdSiege`, `NumSiege` )"
               "VALUES (1 , 'PA1' ), "
               "(2 , 'PA2' ), "
               "(3 , 'PA3' ), "
               "(4 , 'PA4' ), "
               "(5 , 'PA5' ), "
               "(6 , 'PA6' ), "
               "(7 , 'PA7' ), "
               "(8 , 'PA8' ), "
               "(9 , 'PA9' ), "
               "(10 , 'PA10' ), "
               "(11 , 'PA11' ), "
               "(12 , 'PA12' ), "
               "(13 , 'PA13' ), "
               "(14 , 'PA14' ), "
               "(15 , 'PA15' ), "
               "(16 , 'PA16' ), "
               "(17 , 'PA17' ), "
               "(18 , 'PA18' ), "
               "(19 , 'PA19' ), "
               "(20 , 'PA20' ), "
               "(21 , 'PA21' ), "
               "(22 , 'PA22' ), "
               "(23 , 'PA23' ), "
               "(24 , 'PA24' ), "
               "(25 , 'PA25' ), "
               "(26 , 'PA26' ), "
               "(27 , 'PA27' ), "
               "(28 , 'PA28' ), "
               "(29 , 'PA29' ), "
               "(30 , 'PA30' ), "
               "(31 , 'PA31' ), "
               "(32 , 'PA32' ), "
               "(33 , 'PA33' ), "
               "(34 , 'PA34' ), "
               "(35 , 'PA35' ), "
               "(36 , 'PA36' ), "
               "(37 , 'PA37' ), "
               "(38 , 'PA38' ), "
               "(39 , 'PA39' ), "
               "(40 , 'PA40' ), "
               "(41 , 'PA41' ), "
               "(42 , 'PA42' ), "
               "(43 , 'PA43' ), "
               "(44 , 'PA44' ), "
               "(45 , 'PA45' ), "
               "(46 , 'PA46' ), "
               "(47 , 'PA47' ), "
               "(48 , 'PA48' ), "
               "(49 , 'PA49' ), "
               "(50 , 'PA50' ) ");

    //Requête pour la table Spectacles
    query.exec("INSERT INTO Spectacles (IdSpectacle, Spectacle, Date, Heure, IdConfigSalle, JaugeSpectacle) "
               "VALUES (1, 'INFERNO', '12/05/2016', '16:00', 1, 50), "
               "(2, 'CEUX QUI ERRENT NE SE TROMPENT PAS', '15/05/2016', '20:00', 2, 50 ) ");
}

Accueil::~Accueil()
{
    delete ui;
}

//Ouverture de la fiche Spectacles
void Accueil::on_aBtnSpectacles_clicked()
{
    Spectacles spectacles;
    spectacles.setModal(true);
    spectacles.exec();
}

//Ouverture de la fiche Clients
void Accueil::on_aBtnClients_clicked()
{
    Clients clients;
    clients.setModal(true);
    clients.exec();
}

//Ouverture de la fiche Billetterie
void Accueil::on_aBtnBilletterie_clicked()
{
    Billetterie billetterie;
    billetterie.setModal(true);
    billetterie.exec();
}

//Ouverture de la fiche Plan de Salle
void Accueil::on_aBtnPlanDeSalle_clicked()
{
    PlanDeSalle planDeSalle;
    planDeSalle.setModal(true);
    planDeSalle.exec();
}

//Ouverture de la fiche Utilisateurs
void Accueil::on_aBtnUtilisateur_clicked()
{
    Utilisateur utilisateur;
    utilisateur.setModal(true);
    utilisateur.exec();
}

//Ouverture de la fiche Administration des billet
void Accueil::on_aBtnAdministratioBillet_clicked()
{
    AdministrationBillet administrationBillet;
    administrationBillet.setModal(true);
    administrationBillet.exec();
}

//Ouverture de la fiche des Fréquentations
void Accueil::on_aBtnFrequentation_clicked()
{
    Frequentation frequentation;
    frequentation.setModal(true);
    frequentation.exec();
}

//Quitter l'application
void Accueil::on_aBtnQuitter_clicked()
{
    this->close();
}


