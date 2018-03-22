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
    query->prepare("SELECT IdSpectacle, Spectacle, Date, Heure, IntituleConfigSalle, Jauge "
                   "FROM Spectacles s, ConfigSalle c "
                   "WHERE s.IdConfigSalle = c.IdConfigSalle");

    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->sTabV->setModel(modal);     //Envoyer les données dans la TableView

    //Redimentionner les colonne en fonction du contenu
    ui->sTabV->resizeColumnsToContents();



    //Requette pour remplir le ComboBox
    QSqlQueryModel * modal2 = new QSqlQueryModel();

    QSqlQuery* query2 = new QSqlQuery(connexion.maBaseDeDonnee);
    query2->prepare("SELECT IdConfigSalle FROM ConfigSalle");
    query2->exec();
    modal2->setQuery(*query2);
    ui->sCBoxIdConfidSalle->setModel(modal2);
    ui->sCBoxIdConfidSalle->setCurrentIndex(-1);

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
    int idConfigSalle;


    spectacle = ui->sTxtSpectacle->text();
    date = ui->sTxtDate->text();
    heure = ui->sTxtHeure->text();
    idConfigSalle = ui->sCBoxIdConfidSalle->currentText().toInt();


    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de la connexion";
        return;
    }

    QSqlQuery query;

    //La requete fonctionne sur SQLite mais pas depuis QT

    query.prepare("INSERT INTO Spectacles (Spectacle, Date, Heure, IdConfigSalle) "
                  "VALUES ('"+spectacle+"','"+date+"','"+heure+"', :IdSalle)");
    query.bindValue(":IdSalle", idConfigSalle);



    if(query.exec())
    {
       QMessageBox::information(this,tr("Ajout spectacle"), tr("Spectacle ajouter au catalague"));

       //*************************************
       //Réactualiser la TableView
       // trouver un moyen de réactualiser au lieu de réexécuter la requête d'affichage


       QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal


       QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
        query->prepare("SELECT IdSpectacle, Spectacle, Date, Heure, IntituleConfigSalle, Jauge "
                       "FROM Spectacles s, ConfigSalle c "
                       "WHERE s.IdConfigSalle = c.IdConfigSalle");

       query->exec();  //Execution de la requête
       modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
       ui->sTabV->setModel(modal);     //Envoyer les données dans la TableView

       //Redimentionner les colonne en fonction du contenu
       ui->sTabV->resizeColumnsToContents();    //Envoyer les données dans la TableView

       //fermeture de la connexion

       qDebug() << (modal->rowCount());

       //----------------------------------------------------
       //Vider les champs
       ui->sLabelIdSpectacle->clear();
       ui->sTxtSpectacle->clear();
       ui->sTxtDate->clear();
       ui->sTxtHeure->clear();
       ui->sTxtJauge->clear();
       ui->sTxtIntituleConfig->clear();
       ui->sCBoxIdConfidSalle->setCurrentIndex(-1);

       //----------------------------------------------------
       //**************************************

       connexion.closeConnexion();
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
    }
}

//Modification a corriger pb requete ajout ou non de champ ID
void Spectacles::on_sBtnModifier_clicked()
{
    Login connexion;

    QString spectacle;
    QString date;
    QString heure;
    QString idConfifSalle;
    QString idSpectacle;

    spectacle = ui->sTxtSpectacle->text();
    date = ui->sTxtDate->text();
    heure = ui->sTxtHeure->text();
    //jauge = ui->sTxtJauge->text();
    idConfifSalle = ui->sCBoxIdConfidSalle->currentText();

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
                  "Spectacle ='"+spectacle+"',Date='"+date+"', Heure ='"+heure+"', IdConfifSalle = '"+idConfifSalle+"'"
                  "WHERE IdSpectacle ='"+idSpectacle+"'");



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
        query->prepare("SELECT IdSpectacle, Spectacle, Date, Heure, IntituleConfigSalle, Jauge "
                       "FROM Spectacles s, ConfigSalle c "
                       "WHERE s.IdConfigSalle = c.IdConfigSalle");

       query->exec();  //Execution de la requête
       modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
       ui->sTabV->setModel(modal);     //Envoyer les données dans la TableView

       //Redimentionner les colonne en fonction du contenu
       ui->sTabV->resizeColumnsToContents();    //Envoyer les données dans la TableView

       //fermeture de la connexion

       qDebug() << (modal->rowCount());

       //----------------------------------------------------
       //Vider les champs
       ui->sLabelIdSpectacle->clear();
       ui->sTxtSpectacle->clear();
       ui->sTxtDate->clear();
       ui->sTxtHeure->clear();
       ui->sTxtJauge->clear();
       ui->sTxtIntituleConfig->clear();
       ui->sCBoxIdConfidSalle->setCurrentIndex(-1);

       //----------------------------------------------------
       //**************************************

        connexion.closeConnexion(); //fermeture de la connexion

        //Vider l'ensemble des champs après la modification
        ui->sLabelIdSpectacle->clear();
        ui->sTxtSpectacle->clear();
        ui->sTxtDate->clear();
        ui->sTxtHeure->clear();
        ui->sTxtJauge->clear();
        ui->sCBoxIdConfidSalle->clear();
    }
    else
    {
        //en cas de non execution de la requete
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }

}


//Affecter la jauge a partir des donnee conbobox

void Spectacles::on_sCBoxIdConfidSalle_currentIndexChanged(const QString &arg1)
{
    QString intituleConfig;
    intituleConfig = ui->sCBoxIdConfidSalle->currentText();

    Login connexion;

    if(!connexion.openConnexion())
    {
        qDebug()<<"Echec de connexion";
        return;
    }
    QSqlQuery query;

    //Je prepare ma requete
    query.prepare("SELECT * FROM ConfigSalle WHERE IdConfigSalle = '"+intituleConfig+"'");

    if(query.exec())
    {
        //tant que la requete reçoit des données je les affectes aux champs
        while (query.next())
        {
            ui->sTxtIntituleConfig->setText(query.value(1).toString());
            ui->sTxtJauge->setText(query.value(2).toString());
        }
        connexion.closeConnexion();
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }
}

//Suppression d'un spactacle
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
         query->prepare("SELECT IdSpectacle, Spectacle, Date, Heure, IntituleConfigSalle, Jauge "
                        "FROM Spectacles s, ConfigSalle c "
                        "WHERE s.IdConfigSalle = c.IdConfigSalle");

        query->exec();  //Execution de la requête
        modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
        ui->sTabV->setModel(modal);     //Envoyer les données dans la TableView

        //Redimentionner les colonne en fonction du contenu
        ui->sTabV->resizeColumnsToContents();    //Envoyer les données dans la TableView

        //fermeture de la connexion

        qDebug() << (modal->rowCount());

        //----------------------------------------------------
        //Vider les champs
        ui->sLabelIdSpectacle->clear();
        ui->sTxtSpectacle->clear();
        ui->sTxtDate->clear();
        ui->sTxtHeure->clear();
        ui->sTxtJauge->clear();
        ui->sTxtIntituleConfig->clear();
        ui->sCBoxIdConfidSalle->setCurrentIndex(-1);

        //----------------------------------------------------
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

        QString valeur;

        valeur = ui->sTabV->model()->data(index).toString();

        Login connexion;

        if(!connexion.openConnexion())
        {
            qDebug() << "Echec de connexion";
            return;
        }

        connexion.openConnexion();
        QSqlQuery query;
        query.prepare("SELECT IdSpectacle, Spectacle, Date, Heure, IdConfigSalle FROM Spectacles "
                      "WHERE  IdSpectacle = '"+valeur+"'"
                                                "OR Spectacle = '"+valeur+"'"
                                                "OR Date = '"+valeur+"'"
                                                "OR Heure = '"+valeur+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->sLabelIdSpectacle->setText(query.value(0).toString());
                ui->sTxtSpectacle->setText(query.value(1).toString());
                ui->sTxtDate->setText(query.value(2).toString());
                ui->sTxtHeure->setText(query.value(3).toString());
                ui->sCBoxIdConfidSalle->clear();
                ui->sTxtJauge->clear();
            }
            //-------------------------------------------------------------------------------------

            //-------------------------------------------------------------------------------------

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
    ui->sTxtIntituleConfig->clear();
    ui->sCBoxIdConfidSalle->setCurrentIndex(-1);
}
