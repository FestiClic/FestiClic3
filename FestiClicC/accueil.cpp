#include "accueil.h"
#include "ui_accueil.h"

#include "login.h"
#include "database.h"
#include "spectacles.h"
#include "clients.h"
#include "billetterie.h"
#include "plandesalle.h"

#include <QTabWidget>




Accueil::Accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);

    //ouverture de la page login
    Login login;
    login.setModal(true);
    if (login.exec() == QDialog::Accepted)
    {
        //Ok
        lanceApp=true;
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
