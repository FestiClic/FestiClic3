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

    //Requette pour remplir la TableView
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT * FROM Spectacles");
    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->sTabV->setModel(modal);     //Envoyer les données dans la TableView

    //Redimentionner les colonne en fonction du contenu
    ui->sTabV->resizeColumnsToContents();


/*
    //Requette pour remplir la ComboBox
    QSqlQueryModel * modal2 = new QSqlQueryModel();

    QSqlQuery* query2 = new QSqlQuery(connexion.maBaseDeDonnee);
    query2->prepare("SELECT Spectacle FROM Spectacles");
    query2->exec();
    modal2->setQuery(*query2);
    ui->sCBoxIdSpectacle->setModel(modal2);
*/
    //fermeture de la connexion
    connexion.closeConnexion();
    qDebug() << (modal->rowCount());
    //qDebug() << (modal2->rowCount());
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
    QString jauge;

    spectacle = ui->sTxtSpectacle->text();
    date = ui->sTxtDate->text();
    heure = ui->sTxtHeure->text();
    jauge = ui->sTxtJauge->text();

    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de la connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;
    query.prepare("INSERT INTO Spectacles (Spectacle, Date, Heure, Jauge) "
                  "VALUES ('"+spectacle+"','"+date+"','"+heure+"', '"+jauge+"')");	//requete insertion dans la bdd

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

//Modification a corriger pb requete ajout ou non de champ ID
void Spectacles::on_sBtnModifier_clicked()
{
    Login connexion;

    QString spectacle;
    QString date;
    QString heure;
    QString jauge;
    QString idSpectacle;

    spectacle = ui->sTxtSpectacle->text();
    date = ui->sTxtDate->text();
    heure = ui->sTxtHeure->text();
    jauge = ui->sTxtJauge->text();

    //lable pour ID
    idSpectacle = ui->sLabelIdSpectacle->text();


    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de la connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;
    //Requête de mise à jour
    query.prepare("UPDATE Spectacles SET "
                  "Spectacle ='"+spectacle+"',Date='"+date+"', Heure ='"+heure+"', Jauge = '"+jauge+"'"
                  "WHERE IdSpectacle ='"+idSpectacle+"'");  //???? Acorriger


    if(query.exec())
    {
        //Afficher l'info si la requete a été executé ou pas dans un messageBox
        //si ma requete est execté elle doit afficher le message suivant

        QMessageBox::information(this, tr("Modification spectacle"), tr("Spectacle midifié avec succes"));

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

        connexion.closeConnexion(); //fermeture de la connexion

        //Vider l'ensemble des champs après la modification
        ui->sLabelIdSpectacle->clear();
        ui->sTxtSpectacle->clear();
        ui->sTxtDate->clear();
        ui->sTxtHeure->clear();
        ui->sTxtJauge->clear();
    }
    else
    {
        //en cas de non execution de la requete
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }

}


//Affecter les valeurs de la table apartir de la comboBox
//***** champ Jauge a rajouter
void Spectacles::on_sCBoxIdSpectacle_currentIndexChanged(const QString &arg1)
{
/*    QString spectacle;
    spectacle = ui->sCBoxIdSpectacle->currentText();

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
            ui->sLabelIdSpectacle->setText(query.value(0).toString());
            ui->sTxtSpectacle->setText(query.value(1).toString());
            ui->sTxtDate->setText(query.value(2).toString());
            ui->sTxtHeure->setText(query.value(3).toString());
            ui->sTxtJauge->setText(query.value(4).toString());
        }
        connexion.closeConnexion();
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }
*/
}

//Suppression d'un spactacle
//****Développement en cours****Afinaliser car pas opérationnelle
void Spectacles::on_sBtnSupprimer_clicked()
{

    Login connexion;
    //Utiliser le nom pour supprimer l'enregistrement
    QString spectacle;

    spectacle = ui->sTxtSpectacle->text();

    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de connexion";
        return;
    }

    connexion.openConnexion();

    QSqlQuery query;
    query.prepare("DELETE FROM Spectacles WHERE Spectacle ='"+spectacle+"'"); //requete suppression dans la bdd

    if(query.exec())
    {
        //Afficher l'info si la requete a été executé ou pas dans un messageBox
        //si ma requete est execté elle doit afficher le message suivant
        QMessageBox::information(this,tr("Suppression"), tr("Enregistrement supprimé")); 	//(Suppression) est le titre de le msgBox - (Enregistrement supprimé) est le message affiché dans le msgBox

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

        //Vider les champs de text
        ui->sTxtSpectacle->clear();
        ui->sTxtDate->clear();
        ui->sTxtHeure->clear();
        ui->sTxtJauge->clear();
        ui->sLabelIdSpectacle->clear();


    }
    else
    {
        //en cas de non execution de la requete
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete

    }

}



void Spectacles::on_sTabV_activated(const QModelIndex &index)
{
    //Affecté les données aux chanps txt apartir de la tableView

        QString valeurs;

        valeurs = ui->sTabV->model()->data(index).toString();

        Login connexion;

        if(!connexion.openConnexion())
        {
            qDebug() << "Echec de connexion";
            return;
        }

        connexion.openConnexion();
        QSqlQuery query;
        query.prepare("SELECT * FROM Spectacles WHERE IdSpectacle = '"+valeurs+"'"
                                                "OR Spectacle = '"+valeurs+"'"
                                                "OR Date = '"+valeurs+"'"
                                                "OR Heure = '"+valeurs+"'"
                                                "OR Jauge = '"+valeurs+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->sLabelIdSpectacle->setText(query.value(0).toString());
                ui->sTxtSpectacle->setText(query.value(1).toString());
                ui->sTxtDate->setText(query.value(2).toString());
                ui->sTxtHeure->setText(query.value(3).toString());
                ui->sTxtJauge->setText(query.value(4).toString());


            }
            connexion.closeConnexion();
        }
        else
        {
                QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
        }

}

void Spectacles::on_sBtnViderChamps_clicked()
{
    ui->sLabelIdSpectacle->clear();
    ui->sTxtSpectacle->clear();
    ui->sTxtDate->clear();
    ui->sTxtHeure->clear();
    ui->sTxtJauge->clear();
}
