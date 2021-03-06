#include "clients.h"
#include "ui_clients.h"

#include "accueil.h"
#include "database.h"
#include "login.h"
#include <QtSql>
#include <QtDebug>
#include <QString>
#include <QMessageBox>
#include "spectacles.h"

#include "billetterie.h"



Clients::Clients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clients)
{
    ui->setupUi(this);

    Database connexion;
    connexion.openConnexion();

    MAJTableV();
    ViderLesChamps();

    //Définir un masque pour encadrer la saisie utilisateur
    ui->cltTxtCp->setInputMask("00000");
    ui->cltTxtTel->setInputMask("0000000000");
    ui->cltTxtMob->setInputMask("0000000000");

    //Pour le champs mail déclarer une variable qui
    //ui->cltTxtEmail->setInputMask("@");


    /*
    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal

    connexion.openConnexion();

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
*/
}

void Clients::MAJTableV()
{
    //Affecter les données clinets dans la TableView
    Database connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal

    //Requette pour remplir la TableView
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT * FROM Clients ORDER BY NomClient");

    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->cltTabV->setModel(modal);     //Envoyer les données dans la TableView

    //Redimentionner les colonne en fonction du contenu
    ui->cltTabV->resizeColumnsToContents();

    //fermeture de la connexion
    // connexion.closeConnexion();
    qDebug() << (modal->rowCount());
}

void Clients::ViderLesChamps()
{
    ui->cltCBoxCivilite->setCurrentIndex(-1);
    ui->cltTxtNom->clear();
    ui->cltTxtPrenom->clear();
    ui->cltTxtAdresse->clear();
    ui->cltTxtCp->clear();
    ui->cltTxtVille->clear();
    ui->cltTxtEmail->clear();
    ui->cltTxtTel->clear();
    ui->cltTxtMob->clear();
    ui->cltCBoxAbonne->setCurrentIndex(-1);
    ui->cltLabelIdClient->clear();
    ui->cLabelAlerte->hide();

}

Clients::~Clients()
{
    Database connexion;
    connexion.closeConnexion();
    delete ui;
}

void Clients::on_cltBtnQuitter_clicked()
{
    this->close();
}

//Bouton ajouter nouveau client
void Clients::on_cltBtnAjouter_clicked()
{
    QString civilite;
    QString nom;
    QString prenom;
    QString adresse;
    QString cp;
    QString ville;
    QString email;
    int tel;
    int mob;
    QString abonne;

    civilite = ui->cltCBoxCivilite->currentText();
    nom = ui->cltTxtNom->text();
    prenom = ui->cltTxtPrenom->text();
    adresse = ui->cltTxtAdresse->text();
    cp = ui->cltTxtCp->text();
    ville = ui->cltTxtVille->text();
    email = ui->cltTxtEmail->text();
    tel = ui->cltTxtTel->text().toInt();
    mob = ui->cltTxtMob->text().toInt();
    abonne = ui->cltCBoxAbonne->currentText();

    if(!civilite.isEmpty() && !nom.isEmpty()
            && !prenom.isEmpty() && !abonne.isEmpty()
            && !email.isEmpty())
    {
        //Encadrer la saisie utilisateur dans le champ email (doit contenir @)
        if (email.contains("@"))
        {
            //Ne pas créer de client à partir d'un client existant
            if(ui->cltLabelIdClient->text().isEmpty())
            {
                QSqlQuery query;

                query.prepare("INSERT INTO Clients (Civilite, NomClient, "
                              "PrenomClient, AdresseClient, Cp, Ville, "
                              "EmailClient, TelClient, MobClient, Abonne) "
                              "VALUES (:civilite, :nom, :prenom, :adresse, "
                              ":cp, :ville, :email, :tel, :mob, :abonne)");

                query.bindValue(":civilite", civilite);
                query.bindValue(":nom", nom);
                query.bindValue(":prenom", prenom);
                query.bindValue(":adresse", adresse);
                query.bindValue(":cp", cp);
                query.bindValue(":ville", ville);
                query.bindValue(":email", email);
                query.bindValue(":tel", tel);
                query.bindValue(":mob", mob);
                query.bindValue(":abonne", abonne);

                if(query.exec())
                {
                    ViderLesChamps();

                    //Affichage si ajouter ou pas dans un MessageBox
                    QMessageBox::information(this,tr("Nouveau client"), tr("Nouveau client enregistré"));

                    MAJTableV();
                }
                else
                {
                    //en cas de non execution de la requete
                    QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
                }
            }
            else
            {
                ui->cLabelAlerte->show();
                ui->cLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
                ui->cLabelAlerte->setText("Impossible de créer un nouveau client à partir d'un client existant !");
            }
        }
        else
        {
            ui->cLabelAlerte->show();
            ui->cLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
            ui->cLabelAlerte->setText("Le format de l'adresse mail n'est pas correct");
        }
    }
    else
    {
        ui->cLabelAlerte->show();
        ui->cLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
        ui->cLabelAlerte->setText("Les champs Civilité - Nom - Prénom - Adresse Email et Abonnement sont obligatoires");
    }
}

//Bouton modifier client
void Clients::on_cltBtnModifier_clicked()
{
    QString civilite;
    QString nom;
    QString prenom;
    QString adresse;
    QString cp;
    QString ville;
    QString email;
    int tel;
    int mob;
    QString abonne;
    int idClient;

    civilite = ui->cltCBoxCivilite->currentText();
    nom = ui->cltTxtNom->text();
    prenom = ui->cltTxtPrenom->text();
    email = ui->cltTxtEmail->text();
    adresse = ui->cltTxtAdresse->text();
    cp = ui->cltTxtCp->text();
    ville = ui->cltTxtVille->text();
    tel = ui->cltTxtTel->text().toInt();
    mob = ui->cltTxtMob->text().toInt();
    abonne = ui->cltCBoxAbonne->currentText();
    idClient = ui->cltLabelIdClient->text().toInt();

    if(!civilite.isEmpty() && !nom.isEmpty()
            && !prenom.isEmpty() && !abonne.isEmpty()
            && !email.isEmpty())
    {
        //Encadrer la saisie utilisateur dans le champ mail
        if (email.contains("@"))
        {
            QSqlQuery query;
            //Requête de mise à jour
            query.prepare("UPDATE Clients SET Civilite = :civilite, "
                          "NomClient = :nom, "
                          "PrenomClient = :prenom, "
                          "EmailClient = :email, "
                          "AdresseClient = :adresse, "
                          "Cp = :cp, Ville = :ville, "
                          "TelClient = :tel, "
                          "MobClient = :mob, "
                          "Abonne = :abonne "
                          "WHERE IdClient = :idClient");

            query.bindValue(":civilite", civilite);
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prenom);
            query.bindValue(":email", email);
            query.bindValue(":adresse", adresse);
            query.bindValue(":cp", cp);
            query.bindValue(":ville", ville);
            query.bindValue(":tel", tel);
            query.bindValue(":mob", mob);
            query.bindValue(":abonne", abonne);
            query.bindValue(":idClient", idClient);

            if(query.exec())
            {
                ViderLesChamps();
                QMessageBox::information(this, tr("Modification client"), tr("Fiche client midifié avec succes"));
                MAJTableV();
            }
            else
            {
                //en cas de non execution de la requete
                QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
            }
        }
        else
        {
            ui->cLabelAlerte->show();
            ui->cLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
            ui->cLabelAlerte->setText("Le format de l'adresse mail n'est pas correct");
        }
    }
    else
    {
        ui->cLabelAlerte->show();
        ui->cLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
        ui->cLabelAlerte->setText("Les champs Civilité - Nom - Prénom - Adresse Email et Abonnement sont obligatoires");
    }
}

//Bouton supprimer
void Clients::on_cltBtnSupprimer_clicked()
{
    QString nomClient;
    QString prenomClient;
    nomClient = ui->cltTxtNom->text();
    prenomClient = ui->cltTxtPrenom->text();

    if(!ui->cltCBoxCivilite->currentText().isEmpty() && !nomClient.isEmpty()
            && !prenomClient.isEmpty() && !ui->cltCBoxAbonne->currentText().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Voulez-vous vraiment supprimer "+nomClient+ " "+prenomClient+ " ?");
        QPushButton* pButtonYes = msgBox.addButton("Oui", QMessageBox::YesRole);
        msgBox.addButton("Non", QMessageBox::NoRole);

        msgBox.exec();
        if (msgBox.clickedButton()==(QAbstractButton*)pButtonYes)
        {
            int idClient;

            idClient = ui->cltLabelIdClient->text().toInt();

            QSqlQuery query;
            query.prepare("DELETE FROM Clients WHERE IdClient = :idClient"); //requete suppression dans la bdd
            query.bindValue(":idClient", idClient);

            if(query.exec())
            {
                ViderLesChamps();
                QMessageBox::information(this,tr("Suppression"), tr("Enregistrement supprimé")); 	//(Suppression) est le titre de le msgBox - (Enregistrement supprimé) est le message affiché dans le msgBox
                MAJTableV();
            }
            else
            {
                //en cas de non execution de la requete
                QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
            }
        }
        else
        {
            qDebug() << "Non Annuler";
            ViderLesChamps();
        }
    }
    else
    {
        ui->cLabelAlerte->show();
        ui->cLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
        ui->cLabelAlerte->setText("Sélectionner un enregistrement ");
    }
}

//Affecté les données aux champs txt à partir de la tableView
void Clients::on_cltTabV_activated(const QModelIndex &index)
{
    QString valeurs;

    valeurs = ui->cltTabV->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM Clients WHERE IdClient = :valeurs "
                  "OR Civilite = :valeurs "
                  "OR NomClient = :valeurs "
                  "OR PrenomClient = :valeurs "
                  "OR AdresseClient = :valeurs "
                  "OR Cp = :valeurs "
                  "OR Ville = :valeurs "
                  "OR EmailClient = :valeurs "
                  "OR TelClient = :valeurs "
                  "OR MobClient = :valeurs "
                  "OR Abonne = :valeurs ");
    query.bindValue(":valeurs", valeurs);

    if(query.exec())
    {
        while (query.next())
        {
            ui->cltLabelIdClient->setText(query.value(0).toString());
            ui->cltCBoxCivilite->setCurrentText(query.value(1).toString());
            ui->cltTxtNom->setText(query.value(2).toString());
            ui->cltTxtPrenom->setText(query.value(3).toString());
            ui->cltTxtAdresse->setText(query.value(5).toString());
            ui->cltTxtCp->setText(query.value(6).toString());
            ui->cltTxtVille->setText(query.value(7).toString());
            ui->cltTxtEmail->setText(query.value(4).toString());
            ui->cltTxtTel->setText(query.value(8).toString());
            ui->cltTxtMob->setText(query.value(9).toString());
            ui->cltCBoxAbonne->setCurrentText(query.value(10).toString());
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
    }
}

void Clients::on_cltBtnViderChamps_clicked()
{
    ViderLesChamps();
}
