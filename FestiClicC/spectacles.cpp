#include "spectacles.h"
#include "ui_spectacles.h"

#include "accueil.h"
#include "login.h"
#include <QtSql>
#include <QtDebug>
#include <QString>
#include <QMessageBox>
#include <QDate>
#include <QTime>


//***********
//*************
//***************
//****************
//********************
//**********************
//*************************

Spectacles::Spectacles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spectacles)
{
    ui->setupUi(this);

    MAJTableV();

    //Affecter les données des spectacles dans la TableView

    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal

    connexion.openConnexion();





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

    ViderLesChamps();
}

void Spectacles::ViderLesChamps()
{
    ui->sLabelIdSpectacle->clear();
    ui->sTxtSpectacle->clear();
    ui->sTxtJauge->clear();
    ui->sTxtIntituleConfig->clear();
    ui->sCBoxIdConfidSalle->setCurrentIndex(-1);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->timeEdit->setTime(QTime::currentTime());
}

void Spectacles::MAJTableV()
{
    //Affecter les données des spectacles dans la TableView
    Login connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal

    connexion.openConnexion();

    //Requette pour remplir la TableView
    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
    query->prepare("SELECT (IdSpectacle) AS 'Ref.', Spectacle, "
                   "Date, Heure, (IntituleConfigSalle) AS 'Type Spectacle',"
                   "(JaugeSpectacle) AS Jauge "
                   "FROM Spectacles s, ConfigSalle c "
                   "WHERE s.IdConfigSalle = c.IdConfigSalle");

    query->exec();  //Execution de la requête
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->sTabV->setModel(modal);     //Envoyer les données dans la TableView

    //Redimentionner les colonne en fonction du contenu
    ui->sTabV->resizeColumnsToContents();

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
    //Condition sur le comboBox *****A CODER*****
    //while (ui->sCBoxIdConfidSalle->currentText().isEmpty())


    Login connexion;

    QString spectacle;
    QString date;
    QString heure;
    int idConfigSalle;
    int jauge;


    spectacle = ui->sTxtSpectacle->text();

    date = ui->dateEdit->text();
    heure = ui->timeEdit->text();

    idConfigSalle = ui->sCBoxIdConfidSalle->currentText().toInt();

    jauge = ui->sTxtJauge->text().toInt();




//Pour la table dynamique
    QString seance;
    QString spec = "Spectacle_";
    //QString annee = "-A-";
    //QString tableSeanceDynamique;

    //idSpecatacle = ui->sLabelIdSpectacle->text();

    //seance contient les 4 premiers charactere du spectacle de gauche + l'année + et heure
    seance = (spec+spectacle.left(4)+'_'+date.right(4).append(heure.left(2)));
    qDebug() << seance;





        if(!connexion.openConnexion())
        {
            qDebug() << "Echec de la connexion";
            return;
        }

        QSqlQuery query;

        //La requete fonctionne sur SQLite mais pas depuis QT

        query.prepare("INSERT INTO Spectacles (Spectacle, Date, Heure, IdConfigSalle, JaugeSpectacle) "
                      "VALUES (:spectacle, :date, :heure, :idConfigSalle, :jaugeS)");
        query.bindValue(":spectacle", spectacle);
        query.bindValue(":date", date);
        query.bindValue(":heure", heure);
        query.bindValue(":idConfigSalle", idConfigSalle);
        query.bindValue(":jaugeS", jauge);

        if(query.exec())
        {
           QMessageBox::information(this,tr("Ajout spectacle"), tr("Spectacle ajouter au catalague"));

           //*************************************
           MAJTableV();
           //----------------------------------------------------
            ViderLesChamps();
           //----------------------------------------------------
//*************************************************************************************************************************************
        // Création de la table dynamique
            /*    Coder l'insertion dans une table Seance qui stockera le spectacle et la jauge (ici j'ai seance qui contient IdSpectacle
                    et IdConfigSalle

                    Etudier la possibilité d'utiliser une vue à la place d'une table supplémentaire ?????

                    //La requete est fonctionnelle sur le Browser
                        Insert into Seances (IdSpectacle, IdConfigSalle)
                                    values ((select max(IdSpectacle) from Spectacles),
                                    (select IdConfigSalle from Spectacles order by IdSpectacle desc ))
             */
/*
            connexion.openConnexion();


            //tableSeanceDynamique = QString("%1 %2 %3 %4").arg(seance).arg(idSpecatacle).arg(annee).arg(date);


            QSqlQuery query2;
            query2.prepare("CREATE TABLE Spectacle_Seance "
                                "(IdSeance INTEGER PRIMARY KEY NOT NULL, "
                                "NumPlace INTEGER , "
                                "Reserve INTEGER NOT NULL DEFAULT 0, ) ");
            //query.bindValue(":seance", seance);


            query2.exec();

            if(query2.exec())
                qDebug() << "requête fonctionnelle";
            else
                qDebug() << "requête plantée: " << query2.lastError();
*/
            //*************************************************************************************************************************************
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
    int jauge;

    int idConfigSalle;
    int idSpectacle;

    spectacle = ui->sTxtSpectacle->text();
    date = ui->dateEdit->text();
    heure = ui->timeEdit->text();
    jauge = ui->sTxtJauge->text().toInt();
    idConfigSalle = ui->sCBoxIdConfidSalle->currentText().toInt();

    idSpectacle = ui->sLabelIdSpectacle->text().toInt();


    if(!connexion.openConnexion())
    {
        qDebug() << "Echec de la connexion";
        return;
    }

    QSqlQuery query;
    //Requête de mise à jour
    query.prepare("UPDATE Spectacles SET "

                  "Spectacle = :spectacle, Date = :date, Heure = :heure,"
                  "IdConfigSalle = :idConfigSalle, JaugeSpectacle = :jaugeS "
                  "WHERE IdSpectacle = :idSpectacle ");
    query.bindValue(":spectacle", spectacle);
    query.bindValue(":date", date);
    query.bindValue(":heure", heure);
    query.bindValue(":idConfigSalle", idConfigSalle);
    query.bindValue(":idSpectacle", idSpectacle);
    query.bindValue(":jaugeS", jauge);




    if(query.exec())
    {
        QMessageBox::information(this, tr("Modification spectacle"), tr("Spectacle modifié avec succes"));

        MAJTableV();
        ViderLesChamps();


        connexion.closeConnexion(); //fermeture de la connexion

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

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Supprimer l'enregistrement ?", "La suppression des données est définitive, êtes vous sur ?",
                                   QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
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
        query.prepare("DELETE FROM Spectacles WHERE Spectacle = :spectacle"); //requete suppression dans la bdd
        query.bindValue(":spectacle", spectacle);

        if(query.exec())
        {
            //Afficher l'info si la requete a été executé ou pas dans un messageBox
            //si ma requete est execté elle doit afficher le message suivant
            QMessageBox::information(this,tr("Suppression"), tr("Enregistrement supprimé")); 	//(Suppression) est le titre de le msgBox - (Enregistrement supprimé) est le message affiché dans le msgBox


           //*************************************

            //*************************************


            MAJTableV();

            //----------------------------------------------------

             ViderLesChamps();


            //Redimentionner les colonne en fonction du contenu
            ui->sTabV->resizeColumnsToContents();

            //**************************************

            //----------------------------------------------------
            //**************************************


            connexion.closeConnexion();  //Fermeture de la connexion

            //Vider les champs de text
            ViderLesChamps();

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
        query.prepare("SELECT * FROM Spectacles "
                      "WHERE  IdSpectacle = '"+valeur+"'"
                                                "OR Spectacle = '"+valeur+"'"
                                                "OR Date = '"+valeur+"'"
                                                "OR Heure = '"+valeur+"'"
                                                "OR JaugeSpectacle = '"+valeur+"' ");
        if(query.exec())
        {
            while (query.next())
            {
                ui->sLabelIdSpectacle->setText(query.value(0).toString());
                ui->sTxtSpectacle->setText(query.value(1).toString());
                ui->dateEdit->setDate(query.value(2).toDate());
                ui->timeEdit->setTime(query.value(3).toTime());
                ui->sTxtJauge->setText(query.value(4).toString());
                ui->sCBoxIdConfidSalle->setCurrentText(query.value(5).toString());

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
    ViderLesChamps();
}
