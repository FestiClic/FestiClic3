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

    Database connexion;
    connexion.openConnexion();

    //ouverture de la page login
    Login login;
    login.setModal(true);

    if (login.exec() == QDialog::Accepted)
    {
        //Ok
        lanceApp=true;

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
          //  connexion.closeConnexion();
        }
    }
    else
    {
        //Echec
        lanceApp=false;
    }
    //Labels
   // ui->aLabelHello->setStyleSheet("background-color:white; font-size: 15px; color: orange;");
    ui->aLabelHello->setStyleSheet("color: white;");
    ui->aLabelHello->setText("HELLO");

    ui->aLabelNomUtilisateur->setStyleSheet("color: white;");
    //ui->aLabelNomUtilisateur->setText("Connexion Monoposte \n Saison 2017 / 2018");

    ui->aLabelDate->setStyleSheet("color: white;");
    ui->aLabelDate->setText(QDate::currentDate().toString("dd - MM - yyyy"));




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


