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
    query->prepare("SELECT (NomClient) AS NOM, (PrenomClient) AS PRENOM , Cp FROM Clients, Villes");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->cltTabV->setModel(modal);     //Envoyer les données dans la TableView

    //Requette pour remplir la ComboBox
    QSqlQueryModel * modal2 = new QSqlQueryModel();

    QSqlQuery* query2 = new QSqlQuery(connexion.maBaseDeDonnee);
    query2->prepare("SELECT Client FROM Clients");
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

    QString nom;
    QString prenom;
    QString adresse;
    QString email;
    QString tel;
    QString mob;

    nom = ui->cltTxtNom->text();
    prenom = ui->cltTxtPrenom->text();
    adresse = ui->cltTxtAdresse->text();
    email = ui->cltTxtEmail->text();
    tel = ui->cltTxtTel->text();
    mob = ui->cltTxtMob->text();

    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de la connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;
    query.prepare("INSERT INTO Clients (NomClient, PrenomClient, AdresseClient, EmailClient, TelClient, MobClient) "
                  "VALUES ('"+nom+"','"+prenom+"','"+adresse+"', '"+email+"', '"+tel+"', '"+mob+"')");	//requete insertion dans la bdd

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

    QString nom;
    QString prenom;
    QString adresse;
    QString email;
    QString tel;
    QString mob;
    QString idClient;

    nom = ui->cltTxtNom->text();
    prenom = ui->cltTxtPrenom->text();
    adresse = ui->cltTxtAdresse->text();
    email = ui->cltTxtEmail->text();
    tel = ui->cltTxtTel->text();
    mob = ui->cltTxtMob->text();
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
                                        "NomClient ='"+nom+"',PrenomClient='"+prenom+"',"
                                        "AdresseClient ='"+adresse+"', EmailClient = '"+email+"', "
                                        "TelClient = '"+tel+"', MobClient = '"+mob+"'"
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
    QString nom;

    nom = ui->cltTxtNom->text();

    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;
    query.prepare("DELETE FROM Clients WHERE NomClient ='"+nom+"'"); //requete suppression dans la bdd

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

        //Vider les champs de text
        ui->cltTxtNom->clear();
        ui->cltTxtPrenom->clear();
        ui->cltTxtAdresse->clear();
        ui->cltTxtEmail->clear();
        ui->cltTxtTel->clear();
        ui->cltTxtMob->clear();

    }
    else
    {
        //en cas de non execution de la requete
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete

    }

}

//Affecté les données aux chanps txt apartir de la tableView
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
                                            "OR NomClient = '"+valeurs+"'"
                                            "OR PrenomClient = '"+valeurs+"'"
                                            "OR AdresseClient = '"+valeurs+"'"
                                            "OR EmailClient = '"+valeurs+"'"
                                            "OR TelClient = '"+valeurs+"'"
                                            "OR MobClient = '"+valeurs+"'");
    if(query.exec())
    {
        while (query.next())
        {
            ui->cltLabelIdClient->setText(query.value(0).toString());
            //changer le champ en combo
            ui->cltLabelCivilite->setText(query.value(1).toString());
            ui->cltTxtNom->setText(query.value(2).toString());
            ui->cltTxtPrenom->setText(query.value(3).toString());
            ui->cltTxtAdresse->setText(query.value(4).toString());
            ui->cltTxtEmail->setText(query.value(5).toString());
            ui->cltTxtTel->setText(query.value(6).toString());
            ui->cltTxtMob->setText(query.value(7).toString());

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
    //changer le champ en combo
    ui->cltLabelCivilite->clear();
    ui->cltTxtNom->clear();
    ui->cltTxtPrenom->clear();
    ui->cltTxtAdresse->clear();
    ui->cltTxtEmail->clear();
    ui->cltTxtCp->clear();
    ui->cltTxtVille->clear();
    ui->cltTxtTel->clear();
    ui->cltTxtMob->clear();
}
