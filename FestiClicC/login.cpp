#include "login.h"
#include "ui_login.h"
#include "accueil.h"
#include "database.h"
#include <QtSql>



Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    //Ouverture de la connexion
    Database connexion;
    connexion.openConnexion();

    //Changement du text et da sa couleur en fonction de l'état de la connexion
    if(connexion.openConnexion())
    {
        ui->lLabConnexion->setText("Connexion Billetterie principale");
        ui->lLabConnexion->setStyleSheet("color: green;");
    }
    else
    {
        ui->lLabConnexion->setText("Connexion non établie !");
        ui->lLabConnexion->setStyleSheet("color: rgb(255, 99, 71);");
    }
}


Login::~Login()
{
    delete ui;
}

void Login::on_lBtnSeConnecter_2_clicked()
{
    QString nomUtilisateur;
    QString motDePasse;

    nomUtilisateur = ui->lTxtNomUtilisateur_2->text();
    motDePasse = ui->lTxtMotDePasse_2->text();

    if(nomUtilisateur.isEmpty() && motDePasse.isEmpty())
    {
        ui->lLabConnexion->setText("Veuillez saisir le nom d'utilisateur et le mot de passe !");
        ui->lLabConnexion->setStyleSheet("color: rgb(255, 99, 71);");
    }
    else
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM Utilisateurs WHERE Username = :nomUtilisateur AND Password = :motDePasse");
        query.bindValue(":nomUtilisateur", nomUtilisateur);
        query.bindValue(":motDePasse", motDePasse);

        if(query.exec())
        {
            int compteur = 0;
            while(query.next())
            {
                compteur++;
            }
            if(compteur==1)
            {
                ui->lLabConnexion->setText("Acces accepté");

                this->accept();
                this->close();
            }
            else
            {
                ui->lLabConnexion->setText("Le nom d'tilisateur et / ou le mot de passe ne sont pas corrects");
                ui->lLabConnexion->setStyleSheet("color: rgb(255, 99, 71);");
            }
        }
    }
}

void Login::on_lBtnAnnuler_2_clicked()
{
    this->reject();
    this->close();
}
