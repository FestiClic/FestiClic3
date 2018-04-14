#include "utilisateur.h"
#include "ui_utilisateur.h"

#include "database.h"
#include "login.h"
#include "accueil.h"
#include <QtSql>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QByteArray>

Utilisateur::Utilisateur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Utilisateur)
{
    ui->setupUi(this);

    //Ouverture de la connexion
    Database connexion;
    connexion.openConnexion();

    //Mise à jour de la tableView
    MAJTableV();

    //Initialisation de l'ensemble des champs de la page
    ViderLesChamps();

    //Masquer les champs administrateur
    //Champs nécessaires pour la mise en place d'une gestion de droits
    ui->uCBoxAdministrateur->hide();
    ui->uLabelAdministrateur->hide();
}

void Utilisateur::MAJTableV()
{
    //Affecter les données des utilisateurs dans la TableView
    Database connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();

    //Requête
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee);
    query->prepare("SELECT (IdUtilisateur) AS 'Ref.', (NomUtilisateur) AS 'Nom utilisateur', "
                   "(PrenomUtilisateur) AS 'Prénom Utilisateur' "
                   "FROM Utilisateurs ");

    //Exécution de la requête
    query->exec();
    modal->setQuery(*query);
    ui->uTabV->setModel(modal);

    //Redimensionner les colonne en fonction du contenu
    ui->uTabV->resizeColumnsToContents();

    qDebug() << (modal->rowCount());
}

//Initialisation de l'ensemble des champs et labels de la page
//Ne rien afficher dans le comboBox (index -1)
void Utilisateur::ViderLesChamps()
{
    ui->uTxtNom->clear();
    ui->uTxtPrenom->clear();
    ui->uTxtUsername->clear();
    ui->uTxtPassword->clear();
    ui->uLabelIditUtilisateur->clear();
    ui->uCBoxAdministrateur->setCurrentIndex(-1);
    ui->uLabelAlerte->hide();
}

//Rendre les champs cliquables
void Utilisateur::RendreLesChampsUserNameEtPassWordCliquables()
{

    ui->uTxtUsername->setEnabled(true);
    ui->uTxtPassword->setEnabled(true);
}

Utilisateur::~Utilisateur()
{
    //Fermeture de la connexion
    Database connexion;
    connexion.closeConnexion();

    delete ui;
}

/* Methode Nécessaire pour le développement futur de l'Application
 * //Methode cryptage de mdp openClasseRoom

    QString chaine=user.GetMotDePasse();
    QByteArray motDePasseCrypte = QCryptographicHash::hash(chaine.toUtf8(), QCryptographicHash::Sha1);
*/

//Création d'un nouveau compte utilisateur
void Utilisateur::on_uBtnAjouter_clicked()
{
    QString nomUtilisateur;
    QString prenomUtilisateur;
    QString username;
    QString password;
    int administrateurGroupe;

    //Affectation des valeurs des champs aux variables
    nomUtilisateur = ui->uTxtNom->text();
    prenomUtilisateur = ui->uTxtPrenom->text();
    username = ui->uTxtUsername->text();
    password = ui->uTxtPassword->text();
    administrateurGroupe = ui->uCBoxAdministrateur->currentText().toInt();

    //Verifier si les champs ne sont pas vide (tous les champs sont obligatoires)
    if(!nomUtilisateur.isEmpty() && !prenomUtilisateur.isEmpty()
            && !username.isEmpty() && !password.isEmpty())
    {
        //Ne pas créer d'utilisateur à partir d'un utilisateur existant
        if(ui->uLabelIditUtilisateur->text().isEmpty())
        {
            //Requête d'insertion dans la table Utilisateur
            QSqlQuery query;

            query.prepare("INSERT INTO Utilisateurs (NomUtilisateur, PrenomUtilisateur, Username, Password, Administrateur) "
                          "VALUES (:nomUtilisateur, :prenomUtilisateur, :username, :passeword, :adminGroup)");
            query.bindValue(":nomUtilisateur", nomUtilisateur);
            query.bindValue(":prenomUtilisateur", prenomUtilisateur);
            query.bindValue(":username", username);
            query.bindValue(":passeword", password);
            query.bindValue(":adminGroup", administrateurGroupe);   //le statut utilisateur sera nécessaire pour la gestion des droits

            //A développer ...
            //Il est également nécessaire de mettre en place une fonction qui permet à l'utilisateur de modifier son mot de passe
            //lors de première connexion à l'application

            //En cas de succès
            if(query.exec())
            {
                ViderLesChamps();

                //Pour une meilleure expérience utilisateur: remplacer le QMessageBox par un simple message dans le label Alert
                QMessageBox::information(this,tr("Ajout utilisateur"), tr("Utilisateur ajouter avec succès"));

                MAJTableV();

                RendreLesChampsUserNameEtPassWordCliquables();

                //Redimensionner les colonne en fonction du contenu
                ui->uTabV->resizeColumnsToContents();
            }
            //En cas d'échec
            else
            {
                QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
            }
        }
        //Si tentative de créer un nouveau compte utilisateur à partir d'un utilisateur existant
        //Message d'avertissement
        else
        {
            ui->uLabelAlerte->show();
            ui->uLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
            ui->uLabelAlerte->setText("Impossible de créer un nouveau compte utilisateur à partir d'un compte existant !");
        }
    }
    //Si un des champs de saisi est vide
    else
    {
        ui->uLabelAlerte->show();
        ui->uLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
        ui->uLabelAlerte->setText("Tous les champs sont obligatoires");
    }
}

//Modification d'un compte Utilisateur
void Utilisateur::on_uBtnModifier_clicked()
{
    QString nomUtilisateur;
    QString prenomUtilisateur;
    QString username;
    QString password;
    int administrateurGroupe;
    int idUtilisateur;

    //Affectation des valeurs des champs aux variables
    nomUtilisateur = ui->uTxtNom->text();
    prenomUtilisateur = ui->uTxtPrenom->text();
    username = ui->uTxtUsername->text();
    password = ui->uTxtPassword->text();
    administrateurGroupe = ui->uCBoxAdministrateur->currentText().toInt();
    idUtilisateur = ui->uLabelIditUtilisateur->text().toInt();

    //Verifier si les champs ne sont pas vide (ici uniquement le nom et le prénom)
    if(!nomUtilisateur.isEmpty() && !prenomUtilisateur.isEmpty())
    {
        //La requête de modification de la table Utilisateur
        QSqlQuery query;

        query.prepare("UPDATE Utilisateurs SET "

                      "NomUtilisateur = :nomUtilisateur, "
                      "PrenomUtilisateur = :prenomUtilisateur, "
                      "Administrateur = :adminGroup "
                      "WHERE IdUtilisateur = :idUtilisateur ");

        query.bindValue(":nomUtilisateur", nomUtilisateur);
        query.bindValue(":prenomUtilisateur", prenomUtilisateur);
        query.bindValue(":adminGroup", administrateurGroupe);
        query.bindValue(":idUtilisateur", idUtilisateur);

        //En cas de succès
        if(query.exec())
        {
            ViderLesChamps();

            //Pour une meilleure expérience utilisateur: remplacer le QMessageBox par un simple message dans le label Alert
            QMessageBox::information(this,tr("Modification utilisateur"), tr("La fiche utilisateur à été modifié avec succès"));

            MAJTableV();

            RendreLesChampsUserNameEtPassWordCliquables();

            //Redimensionner les colonne en fonction du contenu
            ui->uTabV->resizeColumnsToContents();
        }
        //En cas d'échec
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
        }
    }
    //Si un des champs de saisi est vide
    else
    {
        ui->uLabelAlerte->show();
        ui->uLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
        ui->uLabelAlerte->setText("Les champs Nom - Prénom sont obligatoires");
    }
}

//Supprimer un compte utilisateur
void Utilisateur::on_uBtnSupprimer_clicked()
{
    QString nomUtilisateur;
    QString prenomUtilisateur;

    //Affectation des valeurs des champs aux variables
    nomUtilisateur = ui->uTxtNom->text();
    prenomUtilisateur= ui->uTxtPrenom->text();

    //Verifier si les champs ne sont pas vide (ici uniquement le nom et le prénom)
    if(!nomUtilisateur.isEmpty() && !prenomUtilisateur.isEmpty())
    {
        //Message de confirmation avec l'execution de la suppression (QMessage Yes/No)
        QMessageBox msgBox;
        msgBox.setText("Voulez-vous vraiment supprimer "+nomUtilisateur+ " "+prenomUtilisateur+ " ?");
        QPushButton* pButtonYes = msgBox.addButton("Oui", QMessageBox::YesRole);
        msgBox.addButton("Non", QMessageBox::NoRole);

        msgBox.exec();

        //Si le clic est sur oui - Supprimer l'utilisateur de la BDD
        if (msgBox.clickedButton()==(QAbstractButton*)pButtonYes)
        {
            //qDebug
            qDebug() << "ok";

            int idUtilisateur;

            idUtilisateur = ui->uLabelIditUtilisateur->text().toInt();

            //Requête de suppression de la table Utilisateur
            QSqlQuery query;
            query.prepare("DELETE FROM Utilisateurs WHERE IdUtilisateur = :idUtilisateur");
            query.bindValue(":idUtilisateur", idUtilisateur);

            //En cas de succès
            if(query.exec())
            {
                ViderLesChamps();

                //Pour une meilleure expérience utilisateur: remplacer le QMessageBox par un simple message dans le label Alert
                QMessageBox::information(this,tr("Suppression"), tr("Enregistrement supprimé "));

                MAJTableV();

                RendreLesChampsUserNameEtPassWordCliquables();

                //Redimensionner les colonne en fonction du contenu
                ui->uTabV->resizeColumnsToContents();
            }
            //En cas d'échec
            else
            {
                QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
            }
        }
        //Si le clic est sur - Ne rien faire
        else
        {
            //qDebug
            qDebug() << "Non Annuler";

            ViderLesChamps();

            RendreLesChampsUserNameEtPassWordCliquables();
        }
    }
    //Si un des champs de saisi est vide
    else
    {
        ui->uLabelAlerte->show();
        ui->uLabelAlerte->setStyleSheet("background-color: rgb(255, 99, 71); font-size: 15px;");
        ui->uLabelAlerte->setText("Les champs Nom - Prénom sont obligatoires");
    }
}

//Affecté les données aux champs text à partir d'un double clic sur l'ID Utilisateur dans la tableView
void Utilisateur::on_uTabV_activated(const QModelIndex &index)
{
    QString valeur;

    valeur = ui->uTabV->model()->data(index).toString();

    //Requête - récupérer les données à partir d'un double clic sur l'IdUtilisateur
    QSqlQuery query;
    query.prepare("SELECT IdUtilisateur, NomUtilisateur, PrenomUtilisateur, Administrateur FROM Utilisateurs "
                  "WHERE  IdUtilisateur = :valeur ");
    query.bindValue(":valeur", valeur);

    //En cas de succès
    if(query.exec())
    {
        //Affecter les données en provenance de la requête aux champs de text appropriées
        while (query.next())
        {
            ui->uLabelIditUtilisateur->setText(query.value(0).toString());
            ui->uTxtNom->setText(query.value(1).toString());
            ui->uTxtPrenom->setText(query.value(2).toString());
            ui->uCBoxAdministrateur->setCurrentText(query.value(3).toString());
        }

        //Rendre les champs inaccessibles car uniquement l'utilisateur a le droit de modifier ses données d'accès
        ui->uTxtUsername->setEnabled(false);
        ui->uTxtPassword->setEnabled(false);
    }
    //En cas d'échec
    else
    {
        QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
    }
}


void Utilisateur::on_uBtnViderChamps_clicked()
{
    ViderLesChamps();

    RendreLesChampsUserNameEtPassWordCliquables();
}

//Quitter la fiche utilisateur
void Utilisateur::on_uBtnQuitter_clicked()
{
    this->close();
}
