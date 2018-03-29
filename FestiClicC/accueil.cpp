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

#include <QTabWidget>




Accueil::Accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);

    Login connexion;
    connexion.openConnexion();

    //ouverture de la page login
    Login login;
    login.setModal(true);
    if (login.exec() == QDialog::Accepted)
    {
        //Ok
        lanceApp=true;

        //-------------------------------------------------
        //Affecter le nom utilisateur au label accueil
        //Login connexion;

  /*      if(!connexion.openConnexion())
        {
            qDebug() << "Echec de connexion";
            return;
        }
  */
        QSqlQuery query;
        query.prepare("SELECT NomUtilisateur, PrenomUtilisateur, Administrateur FROM Utilisateurs ");
        if(query.exec())
        {
            while (query.next())
            {
                ui->aLabelNomUtilisateur->setText(query.value(1).toString() + ' ' + query.value(2).toString());
            }
          //  connexion.closeConnexion();
        }
    }
    else
    {
        //Echec
        lanceApp=false;
    }

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
  /*
    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal

    connexion.openConnexion();
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT * FROM Spectacles");

    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->sTabV->setModel(modal);     //Envoyer les données dans la TableView

    //fermeture de la connexion
    connexion.closeConnexion();
    qDebug() << (modal->rowCount());
*/
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
