#include "spectacles.h"
#include "ui_spectacles.h"
#include "accueil.h"
#include "login.h"
#include <QtSql>
#include <QtDebug>
#include <QString>
#include <QMessageBox>

Spectacles::Spectacles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spectacles)
{
    ui->setupUi(this);


    //Affecter les données des spectacles dans la TableView

    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal

    connexion.openConnexion();
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT * FROM Spectacles");

    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->sTabV->setModel(modal);     //Envoyer les données dans la TableView

    //fermeture de la connexion
    connexion.closeConnexion();
    qDebug() << (modal->rowCount());
}

Spectacles::~Spectacles()
{
    delete ui;
}

void Spectacles::on_sBtnQuitter_clicked()
{
    this->close();
}

//Inserer des données en base de données - bouton ajouter
void Spectacles::on_sBtnAjouter_clicked()
{
    Login connexion;

    QString spectacle;
    QString date;
    QString heure;

    spectacle = ui->sTxtSpectacle->text();
    date = ui->sTxtDate->text();
    heure = ui->sTxtHeure->text();

    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de la connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;
    query.prepare("INSERT INTO Spectacles (Spectacle, Date, Heure) "
                  "VALUES ('"+spectacle+"','"+date+"','"+heure+"')");	//requete insertion dans la bdd

    if(query.exec())
    {
       //Affichage si ajouter ou pas dans un MessageBox
       QMessageBox::information(this,tr("Ajout spectacle"), tr("Spectacle ajouter au catalague"));


       //*************************************
       //Réactualiser la TableView
       // trouver un moyen de réactualiser au lieu de réexécuter la requête d'affichage


       QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal


       QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
       query->prepare("SELECT * FROM Spectacles");

       query->exec();  //Execution de la requête
       modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
       ui->sTabV->setModel(modal);     //Envoyer les données dans la TableView

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
