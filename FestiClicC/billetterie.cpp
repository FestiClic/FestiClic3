#include "billetterie.h"
#include "ui_billetterie.h"

#include "accueil.h"
#include "database.h"
#include "clients.h"
#include "spectacles.h"
#include "modepaiement.h"
#include "plandesalle.h"
#include <QtSql>
#include <QtDebug>
#include <QString>
#include <QMessageBox>
#include <QDateTime>
#include <QVector>
#include <QList>
#include <QButtonGroup>




Billetterie::Billetterie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Billetterie)
{
    ui->setupUi(this);

    Database connexion;
    connexion.openConnexion();

    //Radio bouton placement libre au chargement de la page
    ui->bRBtnPlacementLibre->setChecked(true);

    //Rendre les zones de text inaccessible
    ui->bTxtDateEtHeure->setEnabled(false);
    ui->bTxtInfosClient->setEnabled(false);

    //cacher le label billet
    ui->scrollArea->hide();

    //Affecter les données des représentations au ComboBox
    AffecterDonneesRepresentation();

    //Affecter le nomClient a la comboBox client
    AffecterLesNomsClients();

    //Affecter le tarif a la comboBox tarif
    AffecterLesTarifs();

    //Affecter les num sieges a la comboBox numSiege
    //Nécessaire pour le développement futur de l'application
    //AffecterLesNumerosDesSieges();

    //Affecter les modes de paiement a la comboBox
    AffecterLesModesDePaiement();

    //Initialisation des EditLine
    //Le choix de text line edite à la place des Labels est dans le but de dévelepper ultérieurement
    //une fonction de mise à jour des fiches clients et spectacles directement depuis la billetterie
    ui->bTxtInfosClient->clear();
    ui->bTxtDateEtHeure->clear();
    ui->bCBoxNbPlaces->clear();

    //Initialisation des Labels
    ui->bLabelRepresentation->clear();
    ui->bLabelIdClient->clear();
    ui->bLabelNomClient->clear();
    ui->bLabelPrix->clear();
    ui->bLabelIdClient->clear();
    ui->bLabelIdSpectacle->clear();
    ui->bLabelAlerte->clear();

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

    //Affecter liste numero de sieges a la ListView
    MAJListeDesSieges();

    //chanp text pour afficher le prix total avant paiement
    ui->bTxtCb->setEnabled(false);
    ui->bTxtCb->setStyleSheet("color: green; font-size: 15px;");

    //Changer la couleur du text du champs total a payer
    ui->bLabelEuro_2->setStyleSheet("color: green;");

    //Masquer le combo NbPlace - sera utilisé pour le développement future de l'appli
    //Le combo est nécessaire dans cette version car il stock le nombre total de places dans la liste widget
    ui->bCBoxNbPlaces->hide();
    ui->bCBoxNumSiege->hide();
}

//Affecter les données des représentations au ComboBox
void Billetterie::AffecterDonneesRepresentation()
{
    Database connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT Spectacle FROM Spectacles");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxRepresentations->setModel(modal);     //Envoyer les données dans le combo

    qDebug() << (modal->rowCount());

    //Mettre le combo sur l'index -1 pour ne rien afficher au chargement de la page
    ui->bCBoxRepresentations->setCurrentIndex(-1);
}

//Affecter le nomClient au comboBox client
void Billetterie::AffecterLesNomsClients()
{
    Database connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal (Client)

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query1 = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query1->prepare("SELECT NomClient FROM Clients");
    query1->exec();  //Execution de la requête
    modal->setQuery(*query1);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxSpectacteur->setModel(modal);     //Envoyer les données dans le combo

    qDebug() << (modal->rowCount());

    //Mettre le combo sur l'index -1 pour ne rien afficher au chargement de la page
    ui->bCBoxSpectacteur->setCurrentIndex(-1);
}

//Affecter le tarif au comboBox tarif
void Billetterie::AffecterLesTarifs()
{
    Database connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal (Tarif)

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT IntituleTarif FROM Tarifs");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxTarif->setModel(modal);     //Envoyer les données dans le combo

    qDebug() << (modal->rowCount());

    //Mettre le combo sur l'index -1 pour ne rien afficher au chargement de la page
    ui->bCBoxTarif->setCurrentIndex(-1);
}


//Affecter les num sieges au comboBox numSiege
//Nécessaire pour le développement futur de l'application
//---------------------------------------------------------------------------------------------------------------------
/*
void Billetterie::AffecterLesNumerosDesSieges()
{
    Database connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)

    //Requette pour remplir Combo Spectacles
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT NumPlace FROM Places");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxNumSiege->setModel(modal);     //Envoyer les données en combo
    qDebug() << (modal->rowCount());
}
*/
//---------------------------------------------------------------------------------------------------------------------

//Affecter les modes de paiement au comboBox
void Billetterie::AffecterLesModesDePaiement()
{
    Database connexion;
    QSqlQueryModel * modalModePaiement = new QSqlQueryModel();  //Model de connexion pointeur modal

    QSqlQuery* queryModePaiement = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    queryModePaiement->prepare("SELECT TypeModePaiement FROM ModePaiement ");
    queryModePaiement->exec();  //Execution de la requête
    modalModePaiement->setQuery(*queryModePaiement);    //Récuperation des valeurs pointeur de requete
    ui->bCBoxModePaiement->setModel(modalModePaiement);     //Envoyer les données dans le combo

    qDebug() << (modalModePaiement->rowCount());
}

//Affecter les numéro de sièges non réservés à la liste des sieges (QListView)
void Billetterie::MAJListeDesSieges()
{
    Database connexion;

    QString spectacle;
    int idSpectacle;

    QSqlQueryModel * modal = new QSqlQueryModel();

    //spectacle = ui->bLabelIdSpectacle->text();
    idSpectacle = ui->bLabelIdSpectacle->text().toInt();

    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee);
    query->prepare("SELECT NumPlace FROM Places WHERE Reserve = 0 "
                    "AND IdSpectacleP = :idSpectacle");
    query->bindValue(":idSpectacle", idSpectacle);
    query->exec();
    modal->setQuery(*query);
    ui->bListVNumSiege->setModel(modal);

    //Vérifier l'état de chaque siège
    VerifierSiReserve();
}


Billetterie::~Billetterie()
{
    Database connexion;
    connexion.closeConnexion();
    delete ui;
}


//Affecter les données spectacle depuis le ComboBox vers les labels
void Billetterie::on_bCBoxRepresentations_currentIndexChanged(const QString &arg1)
{
    QString spectacle;
    int jauge;
    spectacle = ui->bCBoxRepresentations->currentText();

    //Je crée un objet requete de QSqlQuery
    QSqlQuery query;

    //Je prepare ma requete
    query.prepare("SELECT * FROM Spectacles WHERE Spectacle = :spectacle ");	//requete insertion de la valeur spectacle du combobox
    query.bindValue(":spectacle", spectacle);

    if(query.exec())
    {
        //tant que la requete reçoit des données je les affectes aux champs
        while (query.next())
        {
            ui->bLabelIdSpectacle->setText(query.value(0).toString());
            ui->bLabelRepresentation->setText(query.value(1).toString());

            //Version avec des zones de text
            ui->bTxtDateEtHeure->setText(query.value(2).toString() +" Heure de début "+ query.value(3).toString());

            //Affecter la jauh*ge du spectectacle à la variable jauge
            jauge = query.value(4).toInt();
        }
        MAJListeDesSieges();

        //masquer le label alert
        ui->bLabelAlerte->hide();

        //Le choix des places sur le plan est accessible uniquement si la jauge est inférieur ou égal à 50
        if(jauge > 50)
        {
            ui->bRBtnPlacementPlan->setEnabled(false);
        }
        else
        {
            ui->bRBtnPlacementPlan->setEnabled(true);
        }
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
}

//Affecter les données spectateur depuis le ComboBox vers les labels
void Billetterie::on_bCBoxSpectacteur_currentIndexChanged(const QString &arg1)
{

    QString spectateur;
    spectateur = ui->bCBoxSpectacteur->currentText();

    //requete insertion de la valeur spectacle du combobox
    QSqlQuery query;

    //Je prepare ma requete
    query.prepare("SELECT * FROM Clients WHERE NomClient = :spectateur ");
    query.bindValue(":spectateur", spectateur);

    if(query.exec())
    {
        //tant que la requete reçoit des données je les affectes aux champs
        while (query.next())
        {
            //Afficher les données du client
            ui->bLabelNomClient->setText(+" "+query.value(1).toString()+
                                         " "+query.value(2).toString()+
                                         " "+query.value(3).toString());
            ui->bLabelIdClient->setText(query.value(0).toString());

            //Zonne de text avec les infos client
            ui->bTxtInfosClient->setText(+" "+query.value(5).toString()+"\r "
                                         +query.value(6).toString()+" "
                                         +query.value(7).toString()
                                         +"\r Email : "+query.value(4).toString()
                                         +"\r Tel : "+query.value(8).toString()
                                         +"   Mob : "+query.value(9).toString()
                                         +"\r Statut spectateur : "+query.value(10).toString());
        }
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
//Trouver un moyen d'update le combo ou supprimer le bouton !
//Bouton ajouter nouveau client Avant réservation
void Billetterie::on_bBtnAjouter_clicked()
{
    Clients clients;
    clients.setModal(true);
    clients.exec();
}

//************************************************************************************************************************

//Affecter les données tarif depuis le ComboBox vers les labels
void Billetterie::on_bCBoxTarif_currentIndexChanged(const QString &arg1)
{

    QString tarif;
    tarif = ui->bCBoxTarif->currentText();

    //Je crée un objet requete de QSqlQuery
    QSqlQuery query;

    //Je prepare ma requete
    query.prepare("SELECT * FROM Tarifs WHERE IntituleTarif = :tarif ");
    query.bindValue(":tarif", tarif);

    if(query.exec())
    {
        //tant que la requete reçoit des données je les affectes aux champs
        while (query.next())
        {
            //Prix dans Label
            ui->bLabelPrix->setText(query.value(2).toString());

            //Remplir combo nbPlaces
            for(int i = 0; i <=90; i++)
            {
                ui->bCBoxNbPlaces->addItem(QString::number(i));
            }
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }

    // Tester les Labels pour afficher le BtnSuivant
    if(!ui->bLabelRepresentation->text().isEmpty() && !ui->bLabelNomClient->text().isEmpty())
    {
        ui->bBtnSuivant->show();

/*        //Afficher les deux listes des numSienges
        ui->bListVNumSiege->show();
        ui->listWidget->show();
        ui->bBtnClearList->show();
*/
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

    // Initialiser le champs
    ui->bTxtCb->clear();

    //changer la valeur d'index du comboNbPlace
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
        //Ne pas passer à la suite si le nombre de place est de 0 et la listeW aussi
        if(ui->bCBoxNbPlaces->currentText().toInt() == 0)
        {
            //masquer l'Alert
            ui->bLabelAlerte->show();
            ui->bLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
            ui->bLabelAlerte->setText("Vous devez choisir au minimum 1 place !");
            //QMessageBox::information(this, "Info", "Vous devez choisir au minimum 1 place ");
        }
        else
        {
            // Afficher le groupeBox mode de paiment
            ui->bGBoxModePaiement->show();
            ui->bGBoxPlanSalle->hide();
            ui->widgetPartieGauche->hide();
        }
    }

}

void Billetterie::on_bBtnPaiement_clicked()
{
        int spectacle;
        QString client;
        QString tarif;
        int nbPlaces;

        nbPlaces = ui->listWidget->count();
        spectacle = ui->bLabelIdSpectacle->text().toInt();
        client = ui->bLabelIdClient->text();
        tarif = ui->bCBoxTarif->currentText();

        //Desactiver le groupe box Paiemement
        ui->bGBoxModePaiement->setEnabled(false);


        //Récuperation date systeme pour l'inclure dans le billet
        //QDateTime dateSys = QDateTime::currentDateTime();
        //QString dateSysA = dateSys.toString();

        QVector <QString> siegesCommande;
        QString numPlace;

         //Stocker le nombre de sieges de la listeWidget dans un vecteur
         for(int i = 0; i < ui->listWidget->count(); ++i)
         {
             siegesCommande.push_back(ui->listWidget->item(i)->text());
         }

         for (int j = 0; j < siegesCommande.length(); j++)
         {
            numPlace = siegesCommande[j];
            qDebug() << numPlace;


    //Requete pour changer le statut du siege dans la BDD (le passer à réservé)
            QSqlQuery query3;
            query3.prepare( "UPDATE Places SET Reserve = 1 "
                                 "WHERE NumPlace = :numPlace "
                                 "AND IdSpectacleP = :idSpectacle ");

            query3.bindValue(":numPlace", numPlace);
            query3.bindValue(":idSpectacle", spectacle);

            if(query3.exec())
                qDebug() << "requête fonctionnelle";
            else
                qDebug() << "requête plantée: " << query3.lastError();


    //Requete insertion des données dans la table billet
            QSqlQuery query;
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

    // Requête décrémentation Jauge spectacle dans la table Spectacle BDD

            QSqlQuery queryDecrementationJauge;
            queryDecrementationJauge.prepare("UPDATE Spectacles SET JaugeSpectacle = (JaugeSpectacle - :nbPlaces)"
                                                                "WHERE IdSpectacle = :spectacle ");
            queryDecrementationJauge.bindValue(":nbPlaces", nbPlaces);
            queryDecrementationJauge.bindValue(":spectacle", spectacle);

            queryDecrementationJauge.exec();

            qDebug() << nbPlaces;
         }
             //********************************************************************************
                      //Coder une requet pour insertion dans table Mode Paiement
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

             //Afficher le billet
             ui->scrollArea->show();

    //Requete pour données à afficher sur le billet

             QSqlQuery queryDonneesBillet;
             queryDonneesBillet.prepare("SELECT MAX(IdTransaction), MAX(IdBillet), Civilite, NomClient, PrenomClient, Spectacle, Prix, NumPlace "
                                        "FROM Transactions tr , Billets b, Clients c, Spectacles s, Tarifs t, Places p "
                                        "Where b.IdClient = c.IdClient "
                                        "AND b.IdSpectacle = s.IdSpectacle "
                                        "AND b.IdTarif = t.IdTarif "
                                        "AND b.IdPlace = p.IdPlace "
                                        "AND tr.IdSpectacle = s.IdSpectacle ");

             queryDonneesBillet.exec();

    //Affecter les données au billet
             if(queryDonneesBillet.next())
             {
                 ui->LabelNomSurBillet->setText("Billet no: " + queryDonneesBillet.value(1).toString());
                 ui->LabelNomSurBillet_2->setText(ui->bLabelNomClient->text()); //queryDonneesBillet.value(2).toString() +" "+ queryDonneesBillet.value(3).toString() +" "+ queryDonneesBillet.value(4).toString() );
                 ui->LabelNomSurBillet_3->setText(ui->bTxtCb->text()  +" € ");
                 ui->LabelNomSurBillet_4->setText(ui->bLabelRepresentation->text());//queryDonneesBillet.value(5).toString());
                 ui->LabelNomSurBillet_5->setText("Siége(s) no : "+ queryDonneesBillet.value(7).toString() );
                 ui->LabelNomSurBillet_6->setText("Transaction no : "+ queryDonneesBillet.value(0).toString());
                 ui->LabelNomSurBillet_8->setText(ui->bTxtDateEtHeure->text());


                 ui->LabelNomSurBillet->setStyleSheet("color:white; font-size: 15px; font-weight: bold;");
                 ui->LabelNomSurBillet_2->setStyleSheet("color:white; font-size: 15px; font-weight: bold;");
                 ui->LabelNomSurBillet_3->setStyleSheet("color:white; font-size: 15px; font-weight: bold;");
                 ui->LabelNomSurBillet_4->setStyleSheet("color:white; font-size: 15px; font-weight: bold;");
                 ui->LabelNomSurBillet_5->setStyleSheet("color:white; font-size: 15px; font-weight: bold;");
                 ui->LabelNomSurBillet_6->setStyleSheet("color:white; font-size: 15px; font-weight: bold;");
                //ui->LabelNomSurBillet_7->setStyleSheet(" border-image: url(:CodeBarre.jpg);");
                 ui->LabelNomSurBillet_8->setStyleSheet("color:white; font-size: 15px; font-weight: bold;");
             }

             qDebug() << nbPlaces;

             MAJListeDesSieges();
}

void Billetterie::on_bBtnQuitter_clicked()
{
    this->close();
}


void Billetterie::on_bListVNumSiege_activated(const QModelIndex &index)
{
    //Affecter les numéros de sièges à la listeView
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
    //masquer l'Alert
    ui->bLabelAlerte->hide();

}

void Billetterie::on_bBtnSuivantPlan_2_clicked()
{
    // Initialiser les champs
    ui->bTxtCb->clear();

    if(ui->listWidget->count() != 0)
    {
        ui->bCBoxNbPlaces->setCurrentIndex(ui->listWidget->count());
    }

//Calcule du prix total
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
    //Ajouter des données fixes d'un client fectif pour l'impression de billets concert à l'avance
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


void Billetterie::on_bBtnAnnulerPaiement_clicked()
{
    ui->widgetPartieGauche->show();
    ui->bGBoxModePaiement->hide();
}

//Bouton annuler du plan
void Billetterie::on_bBtnAnnulerPlan_clicked()
{
    InitialisationEtatDesSieges();
    ui->bGBoxPlanSalle->hide();
}
// §§§§§§§§§§§§ Plan a finir §§§§§§§§§§§§§§§
//Identifier les sièges réservés sur le plan
void Billetterie::VerifierSiReserve()
{
    int idSpectacle;
    QString siege;

    idSpectacle = ui->bLabelIdSpectacle->text().toInt();

    // Requête pour tester le statut des sièges
    QSqlQuery query;
    query.prepare("SELECT * FROM Places WHERE IdSpectacleP = :idSpectacle AND Reserve = 1 ");
    query.bindValue(":idSpectacle", idSpectacle);

    if(query.exec())
    {
       InitialisationEtatDesSieges();
        bool trouver = false;

        while(query.next())
        {
            siege = query.value(1).toString();
            qDebug() << "siege : " << siege;

            trouver = true;

            // Si la requete revoie des données
            if(trouver)
            {
                // la variable reserve recoit le resultat boolean de la requête(statut du siège)
                int reserve;
                reserve = query.value(3).toInt();

                // Si réservé
                if(reserve == 1)
                {
                    if(siege == "PA1")
                    {
                        ui->P1->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P1->setEnabled(false);
                    }
                    if(siege == "PA2")
                    {
                        ui->P2->setStyleSheet("border-image: url(:wheelchairCircRouge.png);");
                        ui->P2->setEnabled(false);
                    }
                    if(siege == "PA3")
                    {
                        ui->P3->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P3->setEnabled(false);
                    }
                    if(siege == "PA4")
                    {
                        ui->P4->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P4->setEnabled(false);
                    }
                    if(siege == "PA5")
                    {
                        ui->P5->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P5->setEnabled(false);
                    }
                    if(siege == "PA6")
                    {
                        ui->P6->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P6->setEnabled(false);
                    }
                    if(siege == "PA7")
                    {
                        ui->P7->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P7->setEnabled(false);
                    }
                    if(siege == "PA8")
                    {
                        ui->P8->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P8->setEnabled(false);
                    }
                    if(siege == "PA9")
                    {
                        ui->P9->setStyleSheet("border-image: url(:wheelchairCircRouge.png);");
                        ui->P9->setEnabled(false);
                    }
                    if(siege == "PA10")
                    {
                        ui->P10->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P10->setEnabled(false);
                    }
                    if(siege == "PA11")
                    {
                        ui->P11->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P11->setEnabled(false);
                    }
                    if(siege == "PA12")
                    {
                        ui->P12->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P12->setEnabled(false);
                    }
                    if(siege == "PA13")
                    {
                        ui->P13->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P13->setEnabled(false);
                    }
                    if(siege == "PA14")
                    {
                        ui->P14->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P14->setEnabled(false);
                    }
                    if(siege == "PA15")
                    {
                        ui->P15->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P15->setEnabled(false);
                    }
                    if(siege == "PA16")
                    {
                        ui->P16->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P16->setEnabled(false);
                    }
                    if(siege == "PA17")
                    {
                        ui->P17->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P17->setEnabled(false);
                    }
                    if(siege == "PA18")
                    {
                        ui->P18->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P18->setEnabled(false);
                    }
                    if(siege == "PA19")
                    {
                        ui->P19->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P19->setEnabled(false);
                    }
                    if(siege == "PA20")
                    {
                        ui->P20->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P20->setEnabled(false);
                    }
                    if(siege == "PA21")
                    {
                        ui->P21->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P21->setEnabled(false);
                    }
                    if(siege == "PA22")
                    {
                        ui->P22->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P22->setEnabled(false);
                    }
                    if(siege == "PA23")
                    {
                        ui->P23->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P23->setEnabled(false);
                    }
                    if(siege == "PA24")
                    {
                        ui->P24->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P24->setEnabled(false);
                    }
                    if(siege == "PA25")
                    {
                        ui->P25->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P25->setEnabled(false);
                    }
                    if(siege == "PA26")
                    {
                        ui->P26->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P26->setEnabled(false);
                    }
                    if(siege == "PA27")
                    {
                        ui->P27->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P27->setEnabled(false);
                    }
                    if(siege == "PA28")
                    {
                        ui->P28->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P28->setEnabled(false);
                    }
                    if(siege == "PA29")
                    {
                        ui->P29->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P29->setEnabled(false);
                    }
                    if(siege == "PA30")
                    {
                        ui->P30->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P30->setEnabled(false);
                    }
                    if(siege == "PA31")
                    {
                        ui->P31->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P31->setEnabled(false);
                    }
                    if(siege == "PA32")
                    {
                        ui->P32->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P32->setEnabled(false);
                    }
                    if(siege == "PA33")
                    {
                        ui->P33->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P33->setEnabled(false);
                    }
                    if(siege == "PA34")
                    {
                        ui->P34->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P34->setEnabled(false);
                    }
                    if(siege == "PA35")
                    {
                        ui->P35->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P35->setEnabled(false);
                    }
                    if(siege == "PA36")
                    {
                        ui->P36->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P36->setEnabled(false);
                    }
                    if(siege == "PA37")
                    {
                        ui->P37->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P37->setEnabled(false);
                    }
                    if(siege == "PA38")
                    {
                        ui->P38->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P38->setEnabled(false);
                    }
                    if(siege == "PA39")
                    {
                        ui->P39->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P39->setEnabled(false);
                    }
                    if(siege == "PA40")
                    {
                        ui->P40->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P40->setEnabled(false);
                    }
                    if(siege == "PA41")
                    {
                        ui->P41->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P41->setEnabled(false);
                    }
                    if(siege == "PA42")
                    {
                        ui->P42->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P42->setEnabled(false);
                    }
                    if(siege == "PA43")
                    {
                        ui->P43->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P43->setEnabled(false);
                    }
                    if(siege == "PA44")
                    {
                        ui->P44->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P44->setEnabled(false);
                    }
                    if(siege == "PA45")
                    {
                        ui->P45->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P45->setEnabled(false);
                    }
                    if(siege == "PA46")
                    {
                        ui->P46->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P46->setEnabled(false);
                    }
                    if(siege == "PA47")
                    {
                        ui->P47->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P47->setEnabled(false);
                    }
                    if(siege == "PA48")
                    {
                        ui->P48->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P48->setEnabled(false);
                    }
                    if(siege == "PA49")
                    {
                        ui->P49->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P49->setEnabled(false);
                    }
                    if(siege == "PA50")
                    {
                        ui->P50->setStyleSheet("border-image: url(:UserMenRed.png);");
                        ui->P50->setEnabled(false);
                    }

                }
            }
        }
    }
}

//Initialisation etat des siéges
void Billetterie::InitialisationEtatDesSieges()
{
    ui->P1->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P2->setStyleSheet("border-image: url(:wheelchairVert.png);");   //Fauteuil handicapé
    ui->P3->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P4->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P5->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P6->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P7->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P8->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P9->setStyleSheet("border-image: url(:wheelchairVert.png);");   //Fauteuil handicapé
    ui->P10->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P11->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P12->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P13->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P14->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P15->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P16->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P17->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P18->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P19->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P20->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P21->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P22->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P23->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P24->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P25->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P26->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P27->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P28->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P29->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P30->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P31->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P31->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P32->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P33->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P34->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P35->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P36->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P37->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P38->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P39->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P40->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P41->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P42->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P43->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P44->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P45->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P46->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P47->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P48->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P49->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P50->setStyleSheet("border-image: url(:CircPlusGreen.png);");

    ui->P1->setEnabled(true);
    ui->P2->setEnabled(true);
    ui->P3->setEnabled(true);
    ui->P4->setEnabled(true);
    ui->P5->setEnabled(true);
    ui->P6->setEnabled(true);
    ui->P7->setEnabled(true);
    ui->P8->setEnabled(true);
    ui->P9->setEnabled(true);
    ui->P10->setEnabled(true);
    ui->P11->setEnabled(true);
    ui->P12->setEnabled(true);
    ui->P13->setEnabled(true);
    ui->P14->setEnabled(true);
    ui->P15->setEnabled(true);
    ui->P16->setEnabled(true);
    ui->P17->setEnabled(true);
    ui->P18->setEnabled(true);
    ui->P19->setEnabled(true);
    ui->P20->setEnabled(true);
    ui->P21->setEnabled(true);
    ui->P22->setEnabled(true);
    ui->P23->setEnabled(true);
    ui->P24->setEnabled(true);
    ui->P25->setEnabled(true);
    ui->P26->setEnabled(true);
    ui->P27->setEnabled(true);
    ui->P28->setEnabled(true);
    ui->P29->setEnabled(true);
    ui->P30->setEnabled(true);
    ui->P31->setEnabled(true);
    ui->P32->setEnabled(true);
    ui->P33->setEnabled(true);
    ui->P34->setEnabled(true);
    ui->P35->setEnabled(true);
    ui->P36->setEnabled(true);
    ui->P37->setEnabled(true);
    ui->P38->setEnabled(true);
    ui->P39->setEnabled(true);
    ui->P40->setEnabled(true);
    ui->P41->setEnabled(true);
    ui->P42->setEnabled(true);
    ui->P43->setEnabled(true);
    ui->P44->setEnabled(true);
    ui->P45->setEnabled(true);
    ui->P46->setEnabled(true);
    ui->P47->setEnabled(true);
    ui->P48->setEnabled(true);
    ui->P49->setEnabled(true);
    ui->P50->setEnabled(true);
}

//Les boutons du plan
void Billetterie::on_P1_clicked()
{
    ui->listWidget->addItem("PA1");
    ui->P1->setStyleSheet("border-image:url(:plus.png);");
}

void Billetterie::on_P2_clicked()
{
    ui->listWidget->addItem("PA2");
    ui->P2->setStyleSheet("border-image:url(:plus.png);");
}

void Billetterie::on_P3_clicked()
{
    ui->listWidget->addItem("PA3");
    ui->P3->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P4_clicked()
{
    ui->listWidget->addItem("PA4");
    ui->P4->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P5_clicked()
{
    ui->listWidget->addItem("PA5");
    ui->P5->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P6_clicked()
{
    ui->listWidget->addItem("PA6");
    ui->P6->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P7_clicked()
{
    ui->listWidget->addItem("PA7");
    ui->P7->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P8_clicked()
{
    ui->listWidget->addItem("PA8");
    ui->P8->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P9_clicked()
{
    ui->listWidget->addItem("PA9");
    ui->P9->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P10_clicked()
{
    ui->listWidget->addItem("PA10");
    ui->P10->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P11_clicked()
{
    ui->listWidget->addItem("PA11");
    ui->P11->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P12_clicked()
{
    ui->listWidget->addItem("PA12");
    ui->P12->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P13_clicked()
{
    ui->listWidget->addItem("PA13");
    ui->P13->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P14_clicked()
{
    ui->listWidget->addItem("PA14");
    ui->P14->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P15_clicked()
{
    ui->listWidget->addItem("PA15");
    ui->P15->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P16_clicked()
{
    ui->listWidget->addItem("PA16");
    ui->P16->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P17_clicked()
{
    ui->listWidget->addItem("PA17");
    ui->P17->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P18_clicked()
{
    ui->listWidget->addItem("PA18");
    ui->P18->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P19_clicked()
{
    ui->listWidget->addItem("PA19");
    ui->P19->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P20_clicked()
{
    ui->listWidget->addItem("PA20");
    ui->P20->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P21_clicked()
{
    ui->listWidget->addItem("PA21");
    ui->P21->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P22_clicked()
{
    ui->listWidget->addItem("PA22");
    ui->P22->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P23_clicked()
{
    ui->listWidget->addItem("PA23");
    ui->P23->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P24_clicked()
{
    ui->listWidget->addItem("PA24");
    ui->P24->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P25_clicked()
{
    ui->listWidget->addItem("PA25");
    ui->P25->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P26_clicked()
{
    ui->listWidget->addItem("PA26");
    ui->P26->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P27_clicked()
{
    ui->listWidget->addItem("PA27");
    ui->P27->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P28_clicked()
{
    ui->listWidget->addItem("PA28");
    ui->P28->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P29_clicked()
{
    ui->listWidget->addItem("PA29");
    ui->P29->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P30_clicked()
{
    ui->listWidget->addItem("PA30");
    ui->P30->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P31_clicked()
{
    ui->listWidget->addItem("PA31");
    ui->P31->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P32_clicked()
{
    ui->listWidget->addItem("PA32");
    ui->P32->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P33_clicked()
{
    ui->listWidget->addItem("PA33");
    ui->P33->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P34_clicked()
{
    ui->listWidget->addItem("PA34");
    ui->P34->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P35_clicked()
{
    ui->listWidget->addItem("PA35");
    ui->P35->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P36_clicked()
{
    ui->listWidget->addItem("PA36");
    ui->P36->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P37_clicked()
{
    ui->listWidget->addItem("PA37");
    ui->P37->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P38_clicked()
{
    ui->listWidget->addItem("PA38");
    ui->P38->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P39_clicked()
{
    ui->listWidget->addItem("PA39");
    ui->P39->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P40_clicked()
{
    ui->listWidget->addItem("PA40");
    ui->P40->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P41_clicked()
{
    ui->listWidget->addItem("PA41");
    ui->P41->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P42_clicked()
{
    ui->listWidget->addItem("PA42");
    ui->P42->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P43_clicked()
{
    ui->listWidget->addItem("PA43");
    ui->P43->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P44_clicked()
{
    ui->listWidget->addItem("PA44");
    ui->P44->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P45_clicked()
{
    ui->listWidget->addItem("PA45");
    ui->P45->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P46_clicked()
{
    ui->listWidget->addItem("PA46");
    ui->P46->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P47_clicked()
{
    ui->listWidget->addItem("PA47");
    ui->P47->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P48_clicked()
{
    ui->listWidget->addItem("PA48");
    ui->P48->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P49_clicked()
{
    ui->listWidget->addItem("PA49");
    ui->P49->setStyleSheet("border-image:url(:plus.png); ");
}

void Billetterie::on_P50_clicked()
{
    ui->listWidget->addItem("PA50");
    ui->P50->setStyleSheet("border-image:url(:plusplus.png); ");
}


