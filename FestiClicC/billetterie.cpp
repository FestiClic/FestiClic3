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
#include <QDateTime>
#include <QVector>


Billetterie::Billetterie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Billetterie)
{
    ui->setupUi(this);

    ui->bRBtnPlacementPlan->setChecked(true);


//************************************************************************************************************************

    //§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

    // Amélioration du code ===  Executer l'ensemble des requetes dans la même connexion a la bdd

    //§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

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

    //Affecter les num sieges a la comboBox numSiege
    Login connexion3;
    QSqlQueryModel * modal3 = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    connexion3.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query3 = new QSqlQuery(connexion3.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query3->prepare("SELECT NumPlace FROM Places");
    query3->exec();  //Execution de la requête
    modal3->setQuery(*query3);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxNumSiege->setModel(modal3);     //Envoyer les données en combo

//************************************************************************************************************************

    //fermeture de la connexion
    connexion2.closeConnexion();
    qDebug() << (modal2->rowCount());

//************************************************************************************************************************

    //Initialisation des EditLine
    ui->bTxtInfosClient->clear();
    ui->bTxtDateEtHeure->clear();
    ui->bCBoxNbPlaces->clear();

    //ui->bTxtCb->clear();

    //Initialisation des Label
    ui->bLabelRepresentation->clear();
    ui->bLabelNomClient->clear();
    ui->bLabelPrix->clear();
    ui->bLabelIdClient->clear();
//************************************************************************************************************************

    //Masquer le bouton suivant tant que les champs sont vides

    if(ui->bLabelNomClient->text().isEmpty()
            && ui->bLabelRepresentation->text().isEmpty()
            && ui->bLabelPrix->text().isEmpty())
    {
        ui->bBtnSuivant->hide();
    }

    //Masquer le grpoupeBox Mode paiement a l'ouverture de la billet
    ui->bGBoxModePaiement->hide();

    //Masquer le grpoupeBox Plan de salle a l'ouverture de la billet
    ui->bGBoxPlanSalle->hide();
//************************************************************************************************************************
    //Affecter liste numero de sieges a la ListView
    Login connexion4;
    QSqlQueryModel * modal4 = new QSqlQueryModel();
    QString spectacle;

    spectacle = ui->bLabelRepresentation->text();

    connexion4.openConnexion();

    QSqlQuery* query4 = new QSqlQuery(connexion.maBaseDeDonnee);
    query4->prepare("SELECT NumPlace FROM Places WHERE Reserve = 0  ");
    query4->exec();
    modal4->setQuery(*query4);
    ui->bListVNumSiege->setModel(modal4);

    //fermeture de la connexion
    connexion.closeConnexion();

    qDebug() << (modal->rowCount());
}


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

            ui->bLabelRepresentation->setText(query.value(1).toString());
            /*ui->bLabelDateRep->setText(query.value(2).toString());
            ui->bLabelHeureRep->setText(query.value(3).toString());
            */

            //Version avec des zones de text

            ui->bTxtDateEtHeure->setText(query.value(2).toString() +" Heure de début "+ query.value(3).toString());


        }
        connexion.closeConnexion();
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }

    // Tester les Labels pour afficher le BtnSuivant
    if(!ui->bLabelPrix->text().isEmpty() && !ui->bLabelPrix->text().isEmpty())
    {
        ui->bBtnSuivant->show();
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
            //Version avec Label civilite + nom + prenom


            ui->bLabelNomClient->setText(+" "+query.value(1).toString()+" "+query.value(2).toString()+" "+query.value(3).toString());

            ui->bLabelIdClient->setText(query.value(0).toString());

            //Version avec EditeLine civilite + nom + prenom
            //ui->bTxtNomClient->setText(+" "+query.value(1).toString()+" "+query.value(2).toString()+" "+query.value(3).toString());


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

    // Tester les Labels pour afficher le BtnSuivant
    if(!ui->bLabelRepresentation->text().isEmpty() && !ui->bLabelPrix->text().isEmpty())
    {
        ui->bBtnSuivant->show();
    }

}

//************************************************************************************************************************

//Bouton ajouter nouveau client Avant réservation
void Billetterie::on_bBtnAjouter_clicked()
{
    Clients clients;
    clients.setModal(true);
    clients.exec();
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
            //Prix dans Label
            ui->bLabelPrix->setText(query.value(2).toString());

            //Version avec des zones de text
            //ui->bTxtPrix->setText(query.value(2).toString());

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
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }

    // Tester les Labels pour afficher le BtnSuivant
    if(!ui->bLabelRepresentation->text().isEmpty() && !ui->bLabelNomClient->text().isEmpty())
    {
        ui->bBtnSuivant->show();
    }
}


void Billetterie::on_bBtnSuivant_clicked()
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
    ui->bBtnSuivant->hide();
*/
//***********************************************************************************************************************

    // Initialiser les champs
    ui->bTxtCb->clear();
    ui->bTxtChCulture->clear();
    ui->bTxtCheque->clear();
    ui->bTxtChVacances->clear();
    ui->bTxtEspeces->clear();
    ui->bTxtVInternet->clear();

//Calcule .....
    double prixTotal, prix, NbPlaces;

    prix = std::stod(ui->bLabelPrix->text().toStdString());

    //ui->bTxtNbPlaces->setText(ui->bCBoxNbPlaces->currentText()+1); //TxtNbPlaces recupere la valeur du ComboBoxNbPlaces

    NbPlaces = std::stod(ui->bCBoxNbPlaces->currentText().toStdString());

    prixTotal = (NbPlaces * prix);


    QString tarifTotal = QString::number(prixTotal);
    ui->bTxtCb->setText(tarifTotal);

    //******************************************


//***********************************************************************************************************************
    //Ouverture plan de salle
    if(ui->bRBtnPlacementPlan->isChecked())
      {
        // Afficher le groupeBox plan de salle
        ui->bGBoxPlanSalle->show();
        ui->bGBoxModePaiement->hide();
      }
    else if(ui->bRBtnPlacementLibre->isChecked())
    {
        // Afficher le groupeBox modede paiment
        ui->bGBoxModePaiement->show();
        ui->bGBoxPlanSalle->hide();
    }

//***********************************************************************************************************************



//***********************************************************************************************************************

}

void Billetterie::on_bBtnPaiement_clicked()
{
    Login connexion;

    QString spectacle;
    QString client;
    QString tarif;
    QString siege;

    spectacle = ui->bLabelRepresentation->text();
    client = ui->bLabelIdClient->text();
    tarif = ui->bCBoxTarif->currentText();
    siege = ui->bCBoxNumSiege->currentText();

    //Récuperation date systeme pour l'inclure dans le billet
    //QDateTime dateSys = QDateTime::currentDateTime();
    //QString dateSysA = dateSys.toString();

    if(!connexion.openConnexion())
    {
        qDebug()<<"Echec de connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;


    //Requete insertion données dans la table billet

    query.prepare("INSERT INTO Billets (NumBillet, IdClient, IdSpectacle, IdTarif, IdPlace) "
                  "VALUES ( (SELECT MAX(NumBillet)+1 FROM Billets), "
                          "(SELECT IdClient FROM Clients WHERE NomClient = '"+client+"'), "
                          "(SELECT IdSpectacle FROM Spectacles WHERE Spectacle = '"+spectacle+"'), "
                          "(SELECT IdTarif FROM Tarifs WHERE IntituleTarif = '"+tarif+"'), "
                          "(SELECT IdPlace FROM Places WHERE NumPlace = '"+siege+"') ) ");
     query.exec();

     // Requête décrémentation Jauge spectacle dans la table Spectacle BDD
     QSqlQuery query2;

    query2.prepare("UPDATE Spectacles SET Jauge = Jauge-'"+ui->bCBoxNbPlaces->currentText()+"' "
                   "WHERE Spectacle = '"+ui->bCBoxRepresentations->currentText()+"' ");

    query2.exec();


    //***********************************************************************************************************************
    // §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
    // A coder
    //Stocker la liste de resaPlaces dans un Vector
    // §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§


    // Récupération des éléments de la QlisteWidger
    //utiliser cette liste pour la décrémentation du nbplace / spectacle


    QVector <QString> siegesCommande;
    for(int i = 0; i < ui->listWidget->count(); ++i)
    {
        siegesCommande.push_back(ui->listWidget->item(i)->text());

        qDebug() << siegesCommande; //pour controler l'ajout au vector
    }

    //Changer l'apparence siege sur plan

    //ui->S_8-setStyleSheet("background-image:url(:BtnRed.png); background-color: cornflowerblue;");

    //***********************************************************************************************************************

    connexion.closeConnexion();

}

void Billetterie::on_bBtnQuitter_clicked()
{
    this->close();
}

void Billetterie::on_bBtnEspeces_clicked()
{
    //Passer la valeur du champ prix total au champ Especes
    QString montant = ui->bTxtCb->text();
    ui->bTxtEspeces->setText(montant);
    ui->bTxtCb->clear();
}

void Billetterie::on_bBtnCheque_clicked()
{
    QString montant = ui->bTxtCb->text();
    ui->bTxtCheque->setText(montant);
    ui->bTxtCb->clear();

/*  //Teter l'ensemble des champs pour recuperer la valeur dans le bon champ
    if (!ui->bTxtCb->text().isEmpty())
    {
        ui->bTxtCheque->setText(montant);
        ui->bTxtCb->clear();
    }

    else if (!ui->bTxtEspeces->text().isEmpty())
    {
        ui->bTxtCheque->setText(montant);
        ui->bTxtEspeces->clear();
    }

    else if (!ui->bTxtChVacances->text().isEmpty())
    {
        ui->bTxtCheque->setText(montant);
        ui->bTxtChVacances->clear();
    }

    else if (!ui->bTxtChCulture->text().isEmpty())
    {
        ui->bTxtCheque->setText(montant);
        ui->bTxtChCulture->clear();
    }
*/

}

void Billetterie::on_bBtnChVacances_clicked()
{
    QString montant = ui->bTxtCb->text();
    ui->bTxtChVacances->setText(montant);
    ui->bTxtCb->clear();
}

void Billetterie::on_bBtnChCulture_clicked()
{
    QString montant = ui->bTxtCb->text();
    ui->bTxtChCulture->setText(montant);
    ui->bTxtCb->clear();

}




void Billetterie::on_bBtnCb_clicked()
{

}

void Billetterie::on_bListVNumSiege_activated(const QModelIndex &index)
{
    QString valeurs;

    valeurs = ui->bListVNumSiege->model()->data(index).toString();

    Login connexion;

    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de la connexion";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Places WHERE NumPlace = '"+valeurs+"' ");

    if (query.exec())
    {
        while (query.next())
        {
            ui->listWidget->addItem(query.value(1).toString());
        }

        connexion.closeConnexion();
    }
    else
    {
            QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
    }

}
