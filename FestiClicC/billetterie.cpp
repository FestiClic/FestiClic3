#include "billetterie.h"
#include "ui_billetterie.h"

#include "accueil.h"
#include "login.h"
#include "spectacles.h"
#include "modepaiement.h"
#include "plandesalle.h"
#include <QtSql>
#include <QtDebug>
#include <QString>
#include <QMessageBox>
#include "clients.h"

Billetterie::Billetterie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Billetterie)
{
    ui->setupUi(this);

    //ui->bCheckBPlacePlan->setChecked(true);
    ui->bRBtnPlacementPlan->setChecked(true);


//************************************************************************************************************************

// §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
    //Adévelopper
    //Mettre en place un checkBox sur chaque Groupe Box afin de rendre les boton et combobox clicables et charger les données
    //dans le comboBox en meme temp
// §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

    //Affecter les données des représentations au ComboBox

    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    connexion.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT Spectacle FROM Spectacles");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxRepresentations->setModel(modal);     //Envoyer les données en combo


    //fermeture de la connexion
    connexion.closeConnexion();
    qDebug() << (modal->rowCount());

//************************************************************************************************************************

    //Affecter le nomClient a la comboBox client
    Login connexion1;
    QSqlQueryModel * modal1 = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    connexion1.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query1 = new QSqlQuery(connexion1.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query1->prepare("SELECT NomClient FROM Clients");
    query1->exec();  //Execution de la requête
    modal1->setQuery(*query1);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxSpectacteur->setModel(modal1);     //Envoyer les données en combo


    //fermeture de la connexion
    connexion1.closeConnexion();
    qDebug() << (modal1->rowCount());


//************************************************************************************************************************

    //Affecter le tarif a la comboBox tarif
    Login connexion2;
    QSqlQueryModel * modal2 = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    connexion2.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query2 = new QSqlQuery(connexion2.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query2->prepare("SELECT IntituleTarif FROM Tarifs");
    query2->exec();  //Execution de la requête
    modal2->setQuery(*query2);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxTarif->setModel(modal2);     //Envoyer les données en combo

//************************************************************************************************************************

    //fermeture de la connexion
    connexion2.closeConnexion();
    qDebug() << (modal2->rowCount());

//************************************************************************************************************************
    // a supprimer plus tard
/*    //Initialisation des Labels
    ui->bLabelAdresse->clear();
    ui->bLabelDateRep->clear();
    ui->bLabelHeureRep->clear();
    ui->bLabelNomClt->clear();
    ui->bLabelPrenomClt->clear();
    ui->bLabelPrix->clear();
    ui->bLabelRepresentations->clear();
    ui->bLabelTotalPrix->clear();
*/
    //Initialisation des zones de text
    ui->bTxtDateEtHeure->clear();
    ui->bTxtInfosClient->clear();
    ui->bTxtNbPlaces->clear();
    ui->bTxtNomClient->clear();
    ui->bTxtPrix->clear();
    ui->bTxtPrixTotal->clear();
    ui->bTxtRepresentation->clear();
    ui->bCBoxNbPlaces->clear();




// §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
    //A supprimer ou adapter
// §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§



    //Masquer le bouton paiement tant que les champs sont vides
/*
    if(ui->bLabelAdresse->text().isEmpty() && ui->bLabelDateRep->text().isEmpty()
            && ui->bLabelHeureRep->text().isEmpty() && ui->bLabelNomClt->text().isEmpty()
            && ui->bLabelPrenomClt->text().isEmpty() && ui->bLabelPrix->text().isEmpty()
            && ui->bLabelRepresentations->text().isEmpty() && ui->bLabelTotalPrix->text().isEmpty())
    {
        ui->bBtnPaiement->hide();
        ui->bLabelNbPlaces->hide();
        ui->pBtnSuivant->hide();
        ui->bRBtnPlacementLibre->hide();
        ui->bRBtnPlacementPlan->hide();
    }
*/

}
//************************************************************************************************************************

Billetterie::~Billetterie()
{
    delete ui;
}

//************************************************************************************************************************

//Affecter les valeur ComboBox aux labels
void Billetterie::on_bCBoxRepresentations_currentIndexChanged(const QString &arg1)
{
    QString spectacle;
    spectacle = ui->bCBoxRepresentations->currentText();

    Login connexion;

    if(!connexion.openConnexion())
    {
        qDebug()<<"Echec de connexion";
        return;
    }

    connexion.openConnexion();

    //Je crée un objet requete de QSqlQuery
    QSqlQuery query;

    //Je prepare ma requete
    query.prepare("SELECT * FROM Spectacles WHERE Spectacle = '"+spectacle+"'");	//requete insertion de la valeur spectacle du combobox

    if(query.exec())
    {
        //tant que la requete reçoit des données je les affectes aux champs
        while (query.next())
        {
            /*
            ui->bLabelRepresentations->setText(query.value(1).toString());
            ui->bLabelDateRep->setText(query.value(2).toString());
            ui->bLabelHeureRep->setText(query.value(3).toString());
            */

            //Version avec des zones de text
            ui->bTxtRepresentation->setText(query.value(1).toString());
            ui->bTxtDateEtHeure->setText(query.value(2).toString() +" Heure de début "+ query.value(3).toString());


        }
        connexion.closeConnexion();
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }
/*
    //Affecter le nomClient a la comboBox client
    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    connexion.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT NomClient FROM Clients");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxSpectacteur->setModel(modal);     //Envoyer les données en combo


    //fermeture de la connexion
    connexion.closeConnexion();
    qDebug() << (modal->rowCount());
*/
}

//************************************************************************************************************************

void Billetterie::on_bCBoxSpectacteur_currentIndexChanged(const QString &arg1)
{
/*    //Affecter les tarifs => ConboBox Tarifs
    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    connexion.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT IntituleTarif FROM Tarifs");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxTarif->setModel(modal);     //Envoyer les données en combo

    //fermeture de la connexion
    connexion.closeConnexion();
    qDebug() << (modal->rowCount());

*/
    //***************************************
    QString spectateur;
    spectateur = ui->bCBoxSpectacteur->currentText();

    Login connexion;

    if(!connexion.openConnexion())
    {
        qDebug()<<"Echec de connexion";
        return;
    }

    connexion.openConnexion();

    //Je crée un objet requete de QSqlQuery
    QSqlQuery query;

    //Je prepare ma requete
    query.prepare("SELECT * FROM Clients WHERE NomClient = '"+spectateur+"'");	//requete insertion de la valeur spectacle du combobox

    if(query.exec())
    {
        //tant que la requete reçoit des données je les affectes aux champs
        while (query.next())
        {
            /*
            ui->bLabelNomClt->setText(query.value(2).toString());
            ui->bLabelPrenomClt->setText(query.value(3).toString());
            ui->bLabelAdresse->setText(query.value(4).toString());
            //Aficher le bouton de paiement
            //ui->bBtnPaiement->show();
            */

            //Version avec EditeLine civilite + nom + prenom
            ui->bTxtNomClient->setText(+" "+query.value(1).toString()+" "+query.value(2).toString()+" "+query.value(3).toString());


            //Zonne de text avec les infos client
            ui->bTxtInfosClient->setText(+" "+query.value(5).toString()+"\r "+query.value(6).toString()+" "+query.value(7).toString()
                                         +"\r Email : "+query.value(4).toString()+"\r Tel : "+query.value(8).toString()+"   Mob : "+query.value(9).toString()
                                         +"\r Statut spectateur : "+query.value(10).toString());
        }
        connexion.closeConnexion();
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }

}

//************************************************************************************************************************

//Bouton ajouter nouveau client Avant réservation
void Billetterie::on_bBtnAjouter_clicked()
{
    Clients clients;
    clients.setModal(true);
    clients.exec();

    this->close();

}

//************************************************************************************************************************

void Billetterie::on_bCBoxTarif_currentIndexChanged(const QString &arg1)
{
    QString tarif;
    tarif = ui->bCBoxTarif->currentText();

    Login connexion;

    if(!connexion.openConnexion())
    {
        qDebug()<<"Echec de connexion";
        return;
    }

    connexion.openConnexion();

    //Je crée un objet requete de QSqlQuery
    QSqlQuery query;

    //Je prepare ma requete
    query.prepare("SELECT * FROM Tarifs WHERE IntituleTarif = '"+tarif+"'");

    if(query.exec())
    {
        //tant que la requete reçoit des données je les affectes aux champs
        while (query.next())
        {
            //ui->bLabelPrix->setText(query.value(2).toString());

            //Version avec des zones de text
            ui->bTxtPrix->setText(query.value(2).toString());

            //Remplir combo nbPlaces
            for(int i = 1; i <=90; i++)
            {
                ui->bCBoxNbPlaces->addItem(QString::number(i));
            }

            //ui->bLabelAdresse(query.value(3).toString());
            //Aficher le bouton de paiement
            //ui->bBtnPaiement->show();

        }
        connexion.closeConnexion();


        /*
        ui->pBtnSuivant->show();
        ui->bLabelNbPlaces->show();
        ui->bRBtnPlacementLibre->show();
        ui->bRBtnPlacementPlan->show();
        */

    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }
}


void Billetterie::on_pBtnSuivant_clicked()
{
    //******************************************
    //Boite de message pour définir le nombre de place pour le spectacle
    //La message d'information dans la boucle apparait meme si la condition est remplie !!!!A coder!!!!
/*
    QVariant nbPlaces;
    do
        {
        nbPlaces = QInputDialog::getInt(this, "nbPlaces", "Entrez le nombre de places :", 0, 0, 99, 1);
        if(false)
        QMessageBox::information(this, "Info", "Vous devez choisir au minimum 1 place ");

        }
    while(nbPlaces.toInt()<1);

    QMessageBox::information(this, "Infos", "Vous avez choisi "+nbPlaces.toString()+" place(s)");
    ui->bBtnPaiement->show();
*/    //*************************************
/*
    //Test calcu de prix
    double prixTotal; //resultat

    double tarif;   //prix
    tarif = ui->bLabelPrix->text().toDouble(); //valeur a affecter
    double quantite = nbPlaces.toDouble();        //nbDeplaces
    prixTotal = (quantite * tarif);

    //prixTotal = (tarif);
    ui->bLabelNbPlaces->setText(QString::number(quantite));
    ui->bLabelTotalPrix->setText(QString::number(prixTotal));

    //Cacher le bouton
    ui->pBtnSuivant->hide();
*/
//***********************************************************************************************************************

//Calcule .....
    double prixTotal, prix, NbPlaces;

    prix = std::stod(ui->bTxtPrix->text().toStdString());
    ui->bTxtNbPlaces->setText(ui->bCBoxNbPlaces->currentText()+1); //TxtNbPlaces recupere la valeur du ComboBoxNbPlaces

    NbPlaces = std::stod(ui->bTxtNbPlaces->text().toStdString());

    prixTotal = (NbPlaces * prix);


    QString tarifTotal = QString::number(prixTotal);
    ui->bTxtPrixTotal->setText(tarifTotal);

//***********************************************************************************************************************
    //Ouverture plan de salle
    if(ui->bRBtnPlacementLibre->isChecked())
      {
        ModePaiement modePaiement;
        modePaiement.setModal(true);
        modePaiement.exec();
      }

      PlanDeSalle planDeSalle;
      planDeSalle.setModal(true);
      planDeSalle.exec();

      //Gestion de l'exception







}

void Billetterie::on_bBtnPaiement_clicked()
{
/*    if(ui->bRBtnPlacementLibre->isChecked())
    {
        ModePaiement modePaiement;
        modePaiement.setModal(true);
        modePaiement.exec();
    }

    PlanDeSalle planDeSalle;
    planDeSalle.setModal(true);
    planDeSalle.exec();

    //Gestion de l'exception
*/

}

void Billetterie::on_bBtnQuitter_clicked()
{
    this->close();
}


