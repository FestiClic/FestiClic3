#include "utilisateur.h"
#include "ui_utilisateur.h"
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

    Login connexion;
    connexion.openConnexion();

    MAJTableV();
    ViderLesChamps();
}

void Utilisateur::MAJTableV()
{
    //Affecter les données des utilisateurs dans la TableView
    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();

    //connexion.openConnexion();

    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee);
    query->prepare("SELECT (IdUtilisateur) AS 'Ref.', NomUtilisateur, "
                   "PrenomUtilisateur "
                   "FROM Utilisateurs ");

    query->exec();
    modal->setQuery(*query);
    ui->uTabV->setModel(modal);

    ui->uTabV->resizeColumnsToContents();

    //connexion.closeConnexion();
    qDebug() << (modal->rowCount());
}

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

Utilisateur::~Utilisateur()
{
    Login connexion;
    connexion.closeConnexion();
    delete ui;
}

/*
 * //Methode cryptage de mdp openClasseRoom
    QString chaine=user.GetMotDePasse();
    QByteArray motDePasseCrypte = QCryptographicHash::hash(chaine.toUtf8(), QCryptographicHash::Sha1);

*/

void Utilisateur::on_uBtnAjouter_clicked()
{
    QString nomUtilisateur;
    QString prenomUtilisateur;
    QString username;
    QString password;
    int administrateurGroupe;

    nomUtilisateur = ui->uTxtNom->text();
    prenomUtilisateur = ui->uTxtPrenom->text();
    username = ui->uTxtUsername->text();
    password = ui->uTxtPassword->text();
    administrateurGroupe = ui->uCBoxAdministrateur->currentText().toInt();

    if(!ui->uTxtNom->text().isEmpty() && !ui->uTxtPrenom->text().isEmpty()
            && !ui->uTxtUsername->text().isEmpty() && !ui->uTxtPassword->text().isEmpty())
    {
        QSqlQuery query;

        query.prepare("INSERT INTO Utilisateurs (NomUtilisateur, PrenomUtilisateur, Username, Password, Administrateur) "
                      "VALUES (:nomUtilisateur, :prenomUtilisateur, :username, :passeword, :adminGroup)");
        query.bindValue(":nomUtilisateur", nomUtilisateur);
        query.bindValue(":prenomUtilisateur", prenomUtilisateur);
        query.bindValue(":username", username);
        query.bindValue(":passeword", password);
        query.bindValue(":adminGroup", administrateurGroupe);

        if(query.exec())
        {
           ViderLesChamps();

           QMessageBox::information(this,tr("Ajout utilisateur"), tr("Utilisateur ajouter avec succès"));

           MAJTableV();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
        }
    }
    else
    {
        ui->uLabelAlerte->show();
        ui->uLabelAlerte->setStyleSheet("background-color:red; font-size: 15px;");
        ui->uLabelAlerte->setText("Tous les champs sont obligatoires");
    }
}

void Utilisateur::on_uBtnQuitter_clicked()
{
    this->close();
}

void Utilisateur::on_uBtnModifier_clicked()
{
    QString nomUtilisateur;
    QString prenomUtilisateur;
    QString username;
    QString password;
    int administrateurGroupe;
    int idUtilisateur;


    nomUtilisateur = ui->uTxtNom->text();
    prenomUtilisateur = ui->uTxtPrenom->text();
    username = ui->uTxtUsername->text();
    password = ui->uTxtPassword->text();
    administrateurGroupe = ui->uCBoxAdministrateur->currentText().toInt();
    idUtilisateur = ui->uLabelIditUtilisateur->text().toInt();

    if(!ui->uTxtNom->text().isEmpty() && !ui->uTxtPrenom->text().isEmpty())
    {
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

        if(query.exec())
        {
           ViderLesChamps();

           QMessageBox::information(this,tr("Modification utilisateur"), tr("La fiche utilisateur à été modifié avec succès"));

           MAJTableV();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
        }
    }
    else
    {
        ui->uLabelAlerte->show();
        ui->uLabelAlerte->setStyleSheet("background-color:red; font-size: 15px;");
        ui->uLabelAlerte->setText("Les champs Nom - Prénom sont obligatoires");
    }
}

void Utilisateur::on_uBtnSupprimer_clicked()
{
    QString nomUtilisateur;
    QString prenomUtilisateur;

    nomUtilisateur = ui->uTxtNom->text();
    prenomUtilisateur= ui->uTxtPrenom->text();

    if(!ui->uTxtNom->text().isEmpty() && !ui->uTxtPrenom->text().isEmpty())
    {

        QMessageBox msgBox;
        msgBox.setText("Voulez-vous vraiment supprimer "+nomUtilisateur+ " "+prenomUtilisateur+ " ?");
        QPushButton* pButtonYes = msgBox.addButton("Oui", QMessageBox::YesRole);
        msgBox.addButton("Non", QMessageBox::NoRole);

        msgBox.exec();
        if (msgBox.clickedButton()==(QAbstractButton*)pButtonYes)
        {
            //QDEBUG
            qDebug() << "ok";

            int idUtilisateur;

            idUtilisateur = ui->uLabelIditUtilisateur->text().toInt();

            QSqlQuery query;
            query.prepare("DELETE FROM Utilisateurs WHERE IdUtilisateur = :idUtilisateur");
            query.bindValue(":idUtilisateur", idUtilisateur);

            if(query.exec())
            {
                ViderLesChamps();

                QMessageBox::information(this,tr("Suppression"), tr("Enregistrement supprimé "));

                MAJTableV();

                ui->uTabV->resizeColumnsToContents();
            }
            else
            {
                QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
            }
        }
        else
        {
            //QDEBUG
            qDebug() << "Non Annuler";
            ViderLesChamps();
        }
    }
    else
    {
        ui->uLabelAlerte->show();
        ui->uLabelAlerte->setStyleSheet("background-color:red; font-size: 15px;");
        ui->uLabelAlerte->setText("Les champs Nom - Prénom sont obligatoires");
    }
}

//Affecté les données aux chanps txt apartir de la tableView
void Utilisateur::on_uTabV_activated(const QModelIndex &index)
{
        QString valeur;

        valeur = ui->uTabV->model()->data(index).toString();

        QSqlQuery query;
        query.prepare("SELECT IdUtilisateur, NomUtilisateur, PrenomUtilisateur, Administrateur FROM Utilisateurs "
                      "WHERE  IdUtilisateur = :valeur "
                                                "OR NomUtilisateur = :valeur "
                                                "OR PrenomUtilisateur = :valeur "
                                                "OR Administrateur = :valeur ");
        query.bindValue(":valeur", valeur);

        if(query.exec())
        {
            while (query.next())
            {
                ui->uLabelIditUtilisateur->setText(query.value(0).toString());
                ui->uTxtNom->setText(query.value(1).toString());
                ui->uTxtPrenom->setText(query.value(2).toString());
                ui->uCBoxAdministrateur->setCurrentText(query.value(3).toString());
            }
        }
        else
        {
                QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
        }
}

void Utilisateur::on_uBtnViderChamps_clicked()
{
    ViderLesChamps();
}
