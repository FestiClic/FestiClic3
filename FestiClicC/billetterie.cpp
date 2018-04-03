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
#include <QList>
#include <QButtonGroup>




Billetterie::Billetterie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Billetterie)
{
    ui->setupUi(this);

    Login connexion;
    connexion.openConnexion();
//Masquer les deux listes des numSienges
    ui->bListVNumSiege->hide();
    ui->listWidget->hide();
    ui->bBtnClearList->hide();

    ui->bRBtnPlacementPlan->setChecked(true);



    //cacher le label billet
    ui->scrollArea->hide();



    //Affecter les données des représentations au ComboBox

//    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    //connexion.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT Spectacle FROM Spectacles");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxRepresentations->setModel(modal);     //Envoyer les données en combo


    //fermeture de la connexion
    //connexion.closeConnexion();
    qDebug() << (modal->rowCount());

    ui->bCBoxRepresentations->setCurrentIndex(-1);

//************************************************************************************************************************

    //Affecter le nomClient a la comboBox client
    //Login connexion1;
    QSqlQueryModel * modal1 = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    //connexion1.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query1 = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query1->prepare("SELECT NomClient FROM Clients");
    query1->exec();  //Execution de la requête
    modal1->setQuery(*query1);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxSpectacteur->setModel(modal1);     //Envoyer les données en combo


    //fermeture de la connexion
   // connexion1.closeConnexion();
    qDebug() << (modal1->rowCount());

    ui->bCBoxSpectacteur->setCurrentIndex(-1);


//************************************************************************************************************************

    //Affecter le tarif a la comboBox tarif
    //Login connexion2;
    QSqlQueryModel * modal2 = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    //connexion2.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query2 = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query2->prepare("SELECT IntituleTarif FROM Tarifs");
    query2->exec();  //Execution de la requête
    modal2->setQuery(*query2);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxTarif->setModel(modal2);     //Envoyer les données en combo

    ui->bCBoxTarif->setCurrentIndex(-1);

//************************************************************************************************************************

    //Affecter les num sieges a la comboBox numSiege
    //Login connexion3;
    QSqlQueryModel * modal3 = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    //connexion3.openConnexion();

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query3 = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query3->prepare("SELECT NumPlace FROM Places");
    query3->exec();  //Execution de la requête
    modal3->setQuery(*query3);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxNumSiege->setModel(modal3);     //Envoyer les données en combo
//************************************************************************************************************************
    //Affecter les modes de paiement a la comboBox
    QSqlQueryModel * modalModePaiement = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    QSqlQuery* queryModePaiement = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    queryModePaiement->prepare("SELECT TypeModePaiement FROM ModePaiement ");
    queryModePaiement->exec();  //Execution de la requête
    modalModePaiement->setQuery(*queryModePaiement);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxModePaiement->setModel(modalModePaiement);     //Envoyer les données en combo

    qDebug() << (modalModePaiement->rowCount());
//************************************************************************************************************************

    qDebug() << (modal2->rowCount());

//************************************************************************************************************************

    //Initialisation des EditLine
    ui->bTxtInfosClient->clear();
    ui->bTxtDateEtHeure->clear();
    ui->bCBoxNbPlaces->clear();

    //ui->bTxtCb->clear();

    //Initialisation des Label
    ui->bLabelRepresentation->clear();
    ui->bLabelIdClient->clear();
    ui->bLabelNomClient->clear();
    ui->bLabelPrix->clear();
    ui->bLabelIdClient->clear();
    ui->bLabelIdSpectacle->clear();


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
    MAJListeDesSieges();




    qDebug() << (modal->rowCount());

}

void Billetterie::MAJListeDesSieges()
{
    Login connexion;
    QSqlQueryModel * modal4 = new QSqlQueryModel();
    QString spectacle;
    int idSpectacle;

    spectacle = ui->bLabelIdSpectacle->text();
    idSpectacle = ui->bLabelIdSpectacle->text().toInt();

   // connexion.openConnexion();

    QSqlQuery* query4 = new QSqlQuery(connexion.maBaseDeDonnee);
    query4->prepare("SELECT NumPlace FROM Places WHERE Reserve = 0 "
                    "AND IdSpectacleP = :idSpectacle");
    query4->bindValue(":idSpectacle", idSpectacle);
    query4->exec();
    modal4->setQuery(*query4);
    ui->bListVNumSiege->setModel(modal4);
}


Billetterie::~Billetterie()
{
    Login connexion;
    connexion.closeConnexion();
    delete ui;
}

//************************************************************************************************************************

//Affecter les valeur ComboBox aux labels
void Billetterie::on_bCBoxRepresentations_currentIndexChanged(const QString &arg1)
{
    QString spectacle;
    spectacle = ui->bCBoxRepresentations->currentText();

    //Login connexion;
/*
    if(!connexion.openConnexion())
    {
        qDebug()<<"Echec de connexion";
        return;
    }
*/
 //   connexion.openConnexion();

    //Je crée un objet requete de QSqlQuery
    QSqlQuery query;

    //Je prepare ma requete
    query.prepare("SELECT * FROM Spectacles WHERE Spectacle = '"+spectacle+"'");	//requete insertion de la valeur spectacle du combobox

    if(query.exec())
    {
        //tant que la requete reçoit des données je les affectes aux champs
        while (query.next())
        {
            ui->bLabelIdSpectacle->setText(query.value(0).toString());
            ui->bLabelRepresentation->setText(query.value(1).toString());

            //Version avec des zones de text

            ui->bTxtDateEtHeure->setText(query.value(2).toString() +" Heure de début "+ query.value(3).toString());


        }

        MAJListeDesSieges();

  //-------------------------------------------------------------------------------------------------------------
 /*       //Requete modification couleur Siege
        //Scaner la table si le numSiege est present WHERE idSpectacle==> SetStyleSheet BTN else Rien faire

        while(ui->bLabelIdSpectacle->text = )
        QSqlQuery query2;
        query2.prepare("SELECT * FROM SiegeSpectacleClient")

  */
  //-------------------------------------------------------------------------------------------------------------
    //    connexion.closeConnexion();
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

 //   Login connexion;

/*    if(!connexion.openConnexion())
    {
        qDebug()<<"Echec de connexion";
        return;
    }
*/
 //   connexion.openConnexion();

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
  //      connexion.closeConnexion();
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

//    Login connexion;

/*    if(!connexion.openConnexion())
    {
        qDebug()<<"Echec de connexion";
        return;
    }
*/
 //   connexion.openConnexion();

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
            for(int i = 0; i <=90; i++)
            {
                ui->bCBoxNbPlaces->addItem(QString::number(i));
            }

            //ui->bLabelAdresse(query.value(3).toString());
            //Aficher le bouton de paiement
            //ui->bBtnPaiement->show();

        }
  //      connexion.closeConnexion();
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


    //changer la valeur d'index de la comboNbPlace pour
    if(ui->listWidget->count() != 0)
    {
        ui->bCBoxNbPlaces->setCurrentIndex(ui->listWidget->count());
    }

        //Calcule total prix
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
        //Ne pas passer à la suite si le nombre de place est à 0 et la listeW aussi
        if(ui->bCBoxNbPlaces->currentText().toInt() == 0)
        {
            QMessageBox::information(this, "Info", "Vous devez choisir au minimum 1 place ");
        }
        else
        {
            // Afficher le groupeBox modede paiment
            ui->bGBoxModePaiement->show();
            ui->bGBoxPlanSalle->hide();
            ui->widgetPartieGauche->hide();
        }
    }

//***********************************************************************************************************************



//***********************************************************************************************************************

}

void Billetterie::on_bBtnPaiement_clicked()
{
//    Login connexion;

    int spectacle;
    QString client;
    QString tarif;
    int nbPlaces;

    nbPlaces = ui->listWidget->count();
    spectacle = ui->bLabelIdSpectacle->text().toInt();
    client = ui->bLabelIdClient->text();
    tarif = ui->bCBoxTarif->currentText();


    //Récuperation date systeme pour l'inclure dans le billet
    //QDateTime dateSys = QDateTime::currentDateTime();
    //QString dateSysA = dateSys.toString();

    QVector <QString> siegesCommande;
    QString numPlace;


 /*   if(!connexion.openConnexion())
    {
        qDebug()<<"Echec de connexion";
        return;
    }
*/

   //**********************************************************************************************************************
  // Ouverture de du billet en html avec les information:
   // Nom spectacle - date - heure - tarif - NumSiege - ConfigSalle + infos légales


   //***********************************************************************************************************************

/*    // §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

    // Requete ok pour recupérer données pour generation billet
                SELECT IdBillet, NomClient, Spectacle, Prix
                FROM Billets b, Clients c, Spectacles s, Tarifs t
                Where b.IdClient = c.IdClient
                and b.IdSpectacle = s.IdSpectacle
                and b.IdTarif = t.IdTarif
                and IdBillet = 7
*/    // §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§


     // §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
     // A coder
     //Stocker la liste de resaPlaces dans un Vector
     // §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

     //***OK**
     // Récupération des éléments de la QlisteWidger
     //utiliser cette liste pour la décrémentation du nbplace / spectacle

// A finir !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

     for(int i = 0; i < ui->listWidget->count(); ++i)
     {
         siegesCommande.push_back(ui->listWidget->item(i)->text());
     }

         for (int j = 0; j < siegesCommande.length(); j++)
         {
             numPlace = siegesCommande[j];

             qDebug() << numPlace;


             QSqlQuery query3;
//Requete pour passer le siege en réservé
             query3.prepare( "UPDATE Places SET Reserve = 1 "
                             "WHERE NumPlace = :numPlace "
                             "AND IdSpectacleP = :idSpectacle ");

             query3.bindValue(":numPlace", numPlace);
             query3.bindValue(":idSpectacle", spectacle);

             if(query3.exec())
                 qDebug() << "requête fonctionnelle";
             else
                 qDebug() << "requête plantée: " << query3.lastError();


             //******************************************************************************
                      QSqlQuery query;

//Requete insertion données dans la table billet

                      query.prepare("INSERT INTO Billets (NumBillet, IdClient, IdSpectacle, IdTarif, IdPlace) "
                                    "VALUES ( (SELECT MAX(NumBillet+1) FROM Billets), "
                                            "(SELECT IdClient FROM Clients WHERE IdClient = :client), "
                                            "(SELECT IdSpectacle FROM Spectacles WHERE IdSpectacle = :spectacle), "
                                            "(SELECT IdTarif FROM Tarifs WHERE IntituleTarif = :tarif), "
                                            "(SELECT IdPlace FROM Places WHERE NumPlace = :siege) ) ");

                      query.bindValue(":client", client);
                      query.bindValue(":spectacle", spectacle);
                      query.bindValue(":tarif", tarif);
                      query.bindValue(":siege", numPlace);

                      query.exec();

              //******************************************************************************


   /*                   for(int k = 0; k<ui->bCBoxNbPlaces->currentText().toInt(); k++)
                      {
                          QSqlQuery queryInserrtInSiegeSpectacleClient;

                          //Requete insertion données dans la table SiegeSpectacleClient

                          queryInserrtInSiegeSpectacleClient.prepare("INSERT INTO SiegeSpectacleClient (IdSpectacle, IdClient, IdSiege) "
                                        "VALUES ( (SELECT IdSpectacle FROM Spectacles WHERE IdSpectacle = :spectacle ), "
                                                "(SELECT IdClient FROM Clients WHERE IdClient = :client), "
                                                "(SELECT IdPlace FROM Places WHERE NumPlace = :siege) ) ");
                          queryInserrtInSiegeSpectacleClient.bindValue(":spectacle", spectacle);
                          queryInserrtInSiegeSpectacleClient.bindValue(":client", client);
                          queryInserrtInSiegeSpectacleClient.bindValue(":siege", numPlace);


                          queryInserrtInSiegeSpectacleClient.exec();
                          }
*/
              //******************************************************************************

// Requête décrémentation Jauge spectacle dans la table Spectacle BDD ***OK***
                     QSqlQuery queryDecrementationJauge;
                     queryDecrementationJauge.prepare("UPDATE Spectacles SET JaugeSpectacle = (JaugeSpectacle - :nbPlaces)"
                                    "WHERE IdSpectacle = :spectacle ");
                     queryDecrementationJauge.bindValue(":nbPlaces", nbPlaces);
                     queryDecrementationJauge.bindValue(":spectacle", spectacle);

                     queryDecrementationJauge.exec();

                     qDebug() << nbPlaces;


         }
         //********************************************************************************
                  //Faire requet pour insertion dans table Mode Paiement
        //********************************************************************************
        //Requete insertion données dans la table Transaction

         QString modePaiement;
         int nombreDePlaces;

         modePaiement = ui->bCBoxModePaiement->currentText();
         nombreDePlaces = siegesCommande.count();

         QSqlQuery queryTransaction;



         queryTransaction.prepare("INSERT INTO Transactions (IdClient, IdSpectacle, IdTarif, IdModePaiement, NombreDePlaces ) "
                       "VALUES ( (SELECT IdClient FROM Clients WHERE IdClient = :client ), "
                       "(SELECT IdSpectacle FROM Spectacles WHERE IdSpectacle = :spectacle), "
                       "(SELECT IdTarif FROM Tarifs WHERE IntituleTarif = :tarif), "
                       "(SELECT IdModePaiement FROM ModePaiement WHERE TypeModePaiement = :modePaiement), "
                       ":nombreDePlaces ) ");

         queryTransaction.bindValue(":client", client);
         queryTransaction.bindValue(":spectacle", spectacle);
         queryTransaction.bindValue(":tarif", tarif);
         queryTransaction.bindValue(":modePaiement", modePaiement);
         queryTransaction.bindValue(":nombreDePlaces", nombreDePlaces);

         queryTransaction.exec();

         qDebug() << "Nombre de siege"<< siegesCommande.count();

         siegesCommande.pop_back();







         /*    // §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

             // Requete ok pour recupérer données pour generation billet
                         SELECT IdBillet, NomClient, Spectacle, Prix
                         FROM Billets b, Clients c, Spectacles s, Tarifs t
                         Where b.IdClient = c.IdClient
                         and b.IdSpectacle = s.IdSpectacle
                         and b.IdTarif = t.IdTarif
                         and IdBillet = 7
         */    // §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

         ui->scrollArea->show();

//Requete pour données billet

         QSqlQuery queryDonneesBillet;
         queryDonneesBillet.prepare("SELECT IdTransaction, IdBillet, Civilite, NomClient, PrenomClient, Spectacle, Prix, NumPlace "
                                    "FROM Transactions tr , Billets b, Clients c, Spectacles s, Tarifs t, Places p "
                                    "Where b.IdClient = c.IdClient "
                                    "AND b.IdSpectacle = s.IdSpectacle "
                                    "AND b.IdTarif = t.IdTarif "
                                    "AND b.IdPlace = p.IdPlace "
                                    "AND tr.IdSpectacle = s.IdSpectacle "
                                    "group by NumPlace ");


         // Ajouter total a payer prix*nbPlaces




         queryDonneesBillet.exec();

         if(queryDonneesBillet.next())
         {
             ui->LabelNomSurBillet->setText("Billet no: " + queryDonneesBillet.value(1).toString());
             ui->LabelNomSurBillet_2->setText(queryDonneesBillet.value(2).toString() +" "+ queryDonneesBillet.value(3).toString() +" "+ queryDonneesBillet.value(4).toString() );
             ui->LabelNomSurBillet_3->setText(ui->bTxtCb->text()  +" € ");
             ui->LabelNomSurBillet_4->setText(queryDonneesBillet.value(5).toString());
             ui->LabelNomSurBillet_5->setText("Siége(s) no : "+ queryDonneesBillet.value(7).toString());
             ui->LabelNomSurBillet_6->setText("Transaction no : "+ queryDonneesBillet.value(0).toString());
             //ui->LabelNomSurBillet_7->setText("Transaction no : "+ queryDonneesBillet.value(8).toString() + queryDonneesBillet.value(9).toString()+ queryDonneesBillet.value(10).toString());

             ui->LabelNomSurBillet->setStyleSheet("color:white; front-size: 20px; background-image: none;");
             ui->LabelNomSurBillet_2->setStyleSheet("color:white; front-size: 20px");
             ui->LabelNomSurBillet_3->setStyleSheet("color:white; front-size: 20px");
             ui->LabelNomSurBillet_4->setStyleSheet("color:white; front-size: 20px");
             ui->LabelNomSurBillet_5->setStyleSheet("color:white; front-size: 20px");
             ui->LabelNomSurBillet_6->setStyleSheet("color:white; front-size: 20px");
             ui->LabelNomSurBillet_7->setStyleSheet("color:white; front-size: 20px, background-image: none;");
         }

         qDebug() << nbPlaces;
         //qDebug() << "Donnéses billet " << ui->bLabelBillet->text();


         //ui->bLabelBillet->setText("<html><b><u>+spectacle+<br>+tarif+<br>+numPlace+<br>+client+</u></b></html>");


    //Changer l'apparence siege sur plan

    //ui->S_8-setStyleSheet("background-image:url(:BtnRed.png); background-color: cornflowerblue;");

    //***********************************************************************************************************************


         MAJListeDesSieges();

}

//******************************************************************************************
void Billetterie::on_bBtnQuitter_clicked()
{
    this->close();
}


void Billetterie::on_bListVNumSiege_activated(const QModelIndex &index)
{
    QString valeurs;

    valeurs = ui->bListVNumSiege->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM Places WHERE NumPlace = :valeurs ");
    query.bindValue(":valeurs", valeurs);

    if (query.exec())
    {
        query.next();

        ui->listWidget->addItem(query.value(1).toString());

    }
    else
    {
            QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
    }

}

void Billetterie::on_bBtnSuivantPlan_2_clicked()
{
    // Initialiser les champs
    ui->bTxtCb->clear();

    if(ui->listWidget->count() != 0)
    {
        ui->bCBoxNbPlaces->setCurrentIndex(ui->listWidget->count());
    }

//Calcule .....
    double prixTotal, prix, NbPlaces;

    prix = std::stod(ui->bLabelPrix->text().toStdString());

    NbPlaces = std::stod(ui->bCBoxNbPlaces->currentText().toStdString());

    prixTotal = (NbPlaces * prix);

    QString tarifTotal = QString::number(prixTotal);
    ui->bTxtCb->setText(tarifTotal);

    // Afficher le groupeBox modede paiment
    ui->bGBoxModePaiement->show();
    ui->bGBoxPlanSalle->hide();
    ui->widgetPartieGauche->hide();
}

void Billetterie::on_bBtnClientConcert_clicked()
{
    ui->bLabelNomClient->setText("Flow");
    ui->bLabelIdClient->setText("21");
    ui->bTxtInfosClient->setText("Flow Billet <br> Billetterie concerts et festivals  ");
}

void Billetterie::on_bRBtnPlacementLibre_clicked()
{
    ui->bListVNumSiege->show();
    ui->listWidget->show();
    ui->bBtnClearList->show();
    ui->bGBoxPlanSalle->hide();
}

void Billetterie::on_bRBtnPlacementPlan_clicked()
{
    ui->bListVNumSiege->hide();
    ui->listWidget->hide();
    ui->bBtnClearList->hide();
    ui->bGBoxModePaiement->hide();
}

void Billetterie::on_bBtnAnnulerPaiement_2_clicked()
{
    ui->widgetPartieGauche->show();
    ui->bGBoxModePaiement->hide();
}

//***************************************************************************************
// A finir !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Coder le slot pour les btn plan de salle
Billetterie::AddSlotsToGroupe()
{
/*    QString valeur;
    QButtonGroup* groupe = new QButtonGroup();
    groupe->addButton(ui->PA1);
    groupe->addButton(ui->PA2);
    groupe->addButton(ui->PA3);
    groupe->addButton(ui->PA4);
    groupe->addButton(ui->PA5);
    groupe->addButton(ui->PA6);
    groupe->addButton(ui->PA7);
    groupe->addButton(ui->PA8);
    groupe->addButton(ui->PA9);
    groupe->addButton(ui->PA10);

    connect(groupe,SIGNAL(buttonClicked(int)), this, SLOT(on_bBtnSuivant_clicked()));
*/
}

//Les boutons du plan de salle

void Billetterie::on_PA1_clicked()
{
    ui->listWidget->addItem("PA1");
    ui->PA1->setStyleSheet("background-image:url(:UserMenRed.png); background-color: cornflowerblue;");
}

void Billetterie::on_PA2_clicked()
{
    ui->listWidget->addItem("PA2");
    ui->PA1->setStyleSheet("background-image:url(:UserMenRed.png); background-color: cornflowerblue;");
}

