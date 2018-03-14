#include "clients.h"
#include "ui_clients.h"

#include "accueil.h"
#include "login.h"
#include <QtSql>
#include <QtDebug>
#include <QString>
#include <QMessageBox>



//***********
//*************
//***************   Modification: changer le label Civilité en combo ou radioButton
//****************
//********************
//**********************
//*************************



Clients::Clients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clients)
{
    ui->setupUi(this);

    //Affecter les données des clients dans la TableView

    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal

    connexion.openConnexion();

    //Requette pour remplir la TableView
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT * FROM Clients");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->cltTabV->setModel(modal);     //Envoyer les données dans la TableView

    //Redimentionner les colonne en fonction du contenu
    ui->cltTabV->resizeColumnsToContents();

    //fermeture de la connexion

    qDebug() << (modal->rowCount());


    //Requette pour remplir la ComboBox
    QSqlQueryModel * modal2 = new QSqlQueryModel();

    QSqlQuery* query2 = new QSqlQuery(connexion.maBaseDeDonnee);
    query2->prepare("SELECT * FROM Clients");
    query2->exec();
    modal2->setQuery(*query2);
    ui->cltCBoxIdSpectacle->setModel(modal2);

    //fermeture de la connexion
    connexion.closeConnexion();
    qDebug() << (modal2->rowCount());
}

Clients::~Clients()
{
    delete ui;
}

void Clients::on_cltBtnQuitter_clicked()
{
    this->close();
}

//Bouton ajouter nouveau client
void Clients::on_cltBtnAjouter_clicked()
{
    Login connexion;

    QString civilite;
    QString nom;
    QString prenom;
    QString adresse;
    QString cp;
    QString ville;
    QString email;
    QString tel;
    QString mob;
    QString abonne;

    civilite = ui->cltCBoxCivilite->currentText();
    nom = ui->cltTxtNom->text();
    prenom = ui->cltTxtPrenom->text();
    adresse = ui->cltTxtAdresse->text();
    cp = ui->cltTxtCp->text();
    ville = ui->cltTxtVille->text();
    email = ui->cltTxtEmail->text();
    tel = ui->cltTxtTel->text();
    mob = ui->cltTxtMob->text();
    abonne = ui->cltCBoxAbonne->currentText();

    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de la connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;
    query.prepare("INSERT INTO Clients (Civilite, NomClient, PrenomClient, AdresseClient, Cp, Ville, EmailClient, TelClient, MobClient, Abonne) "
                  "VALUES ('"+civilite+"','"+nom+"','"+prenom+"','"+adresse+"','"+cp+"','"+ville+"','"+email+"', '"+tel+"', '"+mob+"', '"+abonne+"')");	//requete insertion dans la bdd

    //Vider les champs



    if(query.exec())
    {
       //Affichage si ajouter ou pas dans un MessageBox
       QMessageBox::information(this,tr("Nouveau client"), tr("Nouveau client enregistré"));


       //*************************************
       //Réactualiser la TableView

       QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal


       QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
       query->prepare("SELECT * FROM Clients");

       query->exec();  //Execution de la requête
       modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
       ui->cltTabV->setModel(modal);     //Envoyer les données dans la TableView

       //fermeture de la connexion

       qDebug() << (modal->rowCount());
       //**************************************

       connexion.closeConnexion();  //Fermeture de la connexion

       //Vider les champs
       ui->cltCBoxCivilite->clear();
       ui->cltTxtNom->clear();
       ui->cltTxtPrenom->clear();
       ui->cltTxtAdresse->clear();
       ui->cltTxtCp->clear();
       ui->cltTxtVille->clear();
       ui->cltTxtEmail->clear();
       ui->cltTxtTel->clear();
       ui->cltTxtMob->clear();
       ui->cltCBoxAbonne->clear();
    }
    else
    {
        //en cas de non execution de la requete
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete

    }
}

//Bouton modifier client ====>>> Pb requete
void Clients::on_cltBtnModifier_clicked()
{
    Login connexion;

    QString civilite;
    QString nom;
    QString prenom;
    QString adresse;
    QString cp;
    QString ville;
    QString email;
    QString tel;
    QString mob;
    QString abonne;
    QString idClient;

    civilite = ui->cltCBoxCivilite->currentText();
    nom = ui->cltTxtNom->text();
    prenom = ui->cltTxtPrenom->text();
    adresse = ui->cltTxtAdresse->text();
    cp = ui->cltTxtCp->text();
    ville = ui->cltTxtVille->text();
    email = ui->cltTxtEmail->text();
    tel = ui->cltTxtTel->text();
    mob = ui->cltTxtMob->text();
    abonne = ui->cltCBoxAbonne->currentText();
    idClient = ui->cltLabelIdClient->text();

    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de la connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;
    //Requête de mise à jour
    query.prepare("UPDATE Clients SET "
                                        "Civilite ='"+civilite+"', NomClient ='"+nom+"',PrenomClient='"+prenom+"',"
                                        "AdresseClient ='"+adresse+"', Cp ='"+cp+"',Ville ='"+ville+"', EmailClient = '"+email+"', "
                                        "TelClient = '"+tel+"', MobClient = '"+mob+"', Abonne ='"+abonne+"'"
                  "WHERE IdClient ='"+idClient+"'");


    if(query.exec())
    {
        QMessageBox::information(this, tr("Modification client"), tr("Fiche client midifié avec succes"));

        //*************************************
        //Réactualiser la TableView

        QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal


        QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
        query->prepare("SELECT * FROM Clients");

        query->exec();  //Execution de la requête
        modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
        ui->cltTabV->setModel(modal);     //Envoyer les données dans la TableView

        //fermeture de la connexion

        qDebug() << (modal->rowCount());
        //**************************************

        connexion.closeConnexion(); //fermeture de la connexion

        //Vider les champs
        ui->cltCBoxCivilite->clear();
        ui->cltTxtNom->clear();
        ui->cltTxtPrenom->clear();
        ui->cltTxtAdresse->clear();
        ui->cltTxtCp->clear();
        ui->cltTxtVille->clear();
        ui->cltTxtEmail->clear();
        ui->cltTxtTel->clear();
        ui->cltTxtMob->clear();
        ui->cltCBoxAbonne->clear();
        ui->cltLabelIdClient->clear();
    }
    else
    {
        //en cas de non execution de la requete
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }
}

//Bouton supprimer
void Clients::on_cltBtnSupprimer_clicked()
{
    Login connexion;
    //Utiliser le nom pour supprimer l'enregistrement
    //QString nom;
    QString idClient;

    //nom = ui->cltTxtNom->text();
    idClient = ui->cltLabelIdClient->text();


    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;
    query.prepare("DELETE FROM Clients WHERE IdClient ='"+idClient+"'"); //requete suppression dans la bdd

    if(query.exec())
    {
        //Afficher l'info si la requete a été executé ou pas dans un messageBox
        //si ma requete est execté elle doit afficher le message suivant
        QMessageBox::information(this,tr("Suppression"), tr("Enregistrement supprimé")); 	//(Suppression) est le titre de le msgBox - (Enregistrement supprimé) est le message affiché dans le msgBox

        //*************************************
        //Réactualiser la TableView

        QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal


        QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
        query->prepare("SELECT * FROM Clients");

        query->exec();  //Execution de la requête
        modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
        ui->cltTabV->setModel(modal);     //Envoyer les données dans la TableView

        //fermeture de la connexion

        qDebug() << (modal->rowCount());
        //**************************************

        connexion.closeConnexion();  //Fermeture de la connexion


        //Vider les champs
        ui->cltCBoxCivilite->clear();
        ui->cltTxtNom->clear();
        ui->cltTxtPrenom->clear();
        ui->cltTxtAdresse->clear();
        ui->cltTxtCp->clear();
        ui->cltTxtVille->clear();
        ui->cltTxtEmail->clear();
        ui->cltTxtTel->clear();
        ui->cltTxtMob->clear();
        ui->cltCBoxAbonne->clear();
        ui->cltLabelIdClient->clear();
    }
    else
    {
        //en cas de non execution de la requete
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete

    }

}

//Affecté les données aux champs txt apartir de la tableView
void Clients::on_cltTabV_activated(const QModelIndex &index)
{
    QString valeurs;

    valeurs = ui->cltTabV->model()->data(index).toString();

    Login connexion;

    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de connexion";
        return;
    }

    connexion.openConnexion();
    QSqlQuery query;
    query.prepare("SELECT * FROM Clients WHERE IdClient = '"+valeurs+"'"
                                            "OR Civilite = '"+valeurs+"'"
                                            "OR NomClient = '"+valeurs+"'"
                                            "OR PrenomClient = '"+valeurs+"'"
                                            "OR AdresseClient = '"+valeurs+"'"
                                            "OR Cp = '"+valeurs+"'"
                                            "OR Ville = '"+valeurs+"'"
                                            "OR EmailClient = '"+valeurs+"'"
                                            "OR TelClient = '"+valeurs+"'"
                                            "OR MobClient = '"+valeurs+"'"
                                            "OR Abonne = '"+valeurs+"'");
    if(query.exec())
    {
        while (query.next())
        {
            ui->cltLabelIdClient->setText(query.value(0).toString());
            ui->cltCBoxCivilite->setCurrentText(query.value(1).toString());
            ui->cltTxtNom->setText(query.value(2).toString());
            ui->cltTxtPrenom->setText(query.value(3).toString());
            ui->cltTxtAdresse->setText(query.value(4).toString());
            ui->cltTxtCp->setText(query.value(5).toString());
            ui->cltTxtVille->setText(query.value(6).toString());
            ui->cltTxtEmail->setText(query.value(7).toString());
            ui->cltTxtTel->setText(query.value(8).toString());
            ui->cltTxtMob->setText(query.value(9).toString());
            ui->cltCBoxAbonne->setCurrentText(query.value(9).toString());



        }
        connexion.closeConnexion();
    }
    else
    {
            QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
    }
}

void Clients::on_cltBtnViderChamps_clicked()
{
    ui->cltLabelIdClient->clear();
    ui->cltCBoxCivilite->clear();
    ui->cltTxtNom->clear();
    ui->cltTxtPrenom->clear();
    ui->cltTxtAdresse->clear();
    ui->cltTxtEmail->clear();
    ui->cltTxtCp->clear();
    ui->cltTxtVille->clear();
    ui->cltTxtTel->clear();
    ui->cltTxtMob->clear();
    ui->cltCBoxAbonne->clear();
}
