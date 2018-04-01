#include "administrationbillet.h"
#include "ui_administrationbillet.h"

#include "login.h"
#include <QMessageBox>

AdministrationBillet::AdministrationBillet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministrationBillet)
{
    ui->setupUi(this);
    Login connexion;
    connexion.openConnexion();

    MAJTablesViewPage();


    //Cacher les zones de text et les boutons
    MasquerLesChampsConfigSalle(); //ConfigSalle
    MasquerLesChampsTarif();
    MasquerLesChampsModePaiement();

}

void AdministrationBillet::MAJTablesViewPage()
{
    Login connexion;
    //Affecter les données des configurations Salle dans la colomnView
        QSqlQueryModel * modelConfigSalle = new QSqlQueryModel();  //Model de connexion pointeur modal

        //Affecter les données Tarifs dans la colomnView
            QSqlQueryModel * modelTarif = new QSqlQueryModel();  //Model de connexion pointeur modal

            //Affecter les données Mode de paiement dans la colomnView
                QSqlQueryModel * modelPaiementMode = new QSqlQueryModel();  //Model de connexion pointeur modal

        // ////////////////////////////////////////////////////////////////////////////////////////////////////

        QSqlQuery* queryConfigSalle = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
        queryConfigSalle->prepare("SELECT (IntituleConfigSalle) AS ' Configuration des salles ', (Jauge) AS ' Nombre de places ' "
                       "FROM ConfigSalle ");
        // /////////////
        QSqlQuery* queryTarif = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
        queryTarif->prepare("SELECT (IntituleTarif) AS '  Intitulé Tarif  ', (Prix) AS 'Prix en euro' "
                       "FROM Tarifs ");
        // /////////////
        QSqlQuery* queryModePaiement = new QSqlQuery(connexion.maBaseDeDonnee); //Création de la variable query qui pointe sur QSqlquery
        queryModePaiement->prepare("SELECT (TypeModePaiement) AS '  Modes de paiement acceptés  ' "
                       "FROM ModePaiement ");
        // /////////////

        queryConfigSalle->exec();  //Execution de la requête
        modelConfigSalle->setQuery(*queryConfigSalle);    //Récuperation des valeurs pointeur de requete
        ui->TabVConfigSalle->setModel(modelConfigSalle);     //Envoyer les données dans la TabView
        //Redimentionner les colonnes en fonction du contenu
        ui->TabVConfigSalle->resizeColumnsToContents();
        qDebug() << (modelConfigSalle->rowCount());

        // //////////

        queryTarif->exec();  //Execution de la requête
        modelTarif->setQuery(*queryTarif);    //Récuperation des valeurs pointeur de requete
        ui->TabVTarif->setModel(modelTarif);     //Envoyer les données dans la TabView
        //Redimentionner les colonnes en fonction du contenu
        ui->TabVTarif->resizeColumnsToContents();
        qDebug() << (modelTarif->rowCount());

        // //////////

        queryModePaiement->exec();  //Execution de la requête
        modelPaiementMode->setQuery(*queryModePaiement);    //Récuperation des valeurs pointeur de requete
        ui->TabVMPaiement->setModel(modelPaiementMode);     //Envoyer les données dans la TabView
        //Redimentionner les colonnes en fonction du contenu
        ui->TabVMPaiement->resizeColumnsToContents();
        qDebug() << (modelPaiementMode->rowCount());
}

void AdministrationBillet::MasquerLesChampsConfigSalle()
{
    ui->AdBLabelIntitule->hide();
    ui->AdBTxtIntitule->hide();
    ui->AdBLabelJauge->hide();
    ui->AdBTxtNbPlaces->hide();
    ui->AdBBtnAjouter->hide();
    ui->AdBBtnModifier->hide();
    ui->AdBBtnSupprimer->hide();
    ui->AdBBtnAnnuler->hide();
}

void AdministrationBillet::AfficherLesChampsConfigSalle()
{
    ui->AdBLabelIntitule->show();
    ui->AdBTxtIntitule->show();
    ui->AdBLabelJauge->show();
    ui->AdBTxtNbPlaces->show();
    ui->AdBBtnAjouter->show();
    ui->AdBBtnModifier->show();
    ui->AdBBtnSupprimer->show();
    ui->AdBBtnAnnuler->show();
}

void AdministrationBillet::MasquerLesChampsTarif()
{
    ui->AdBLabelTarif->hide();
    ui->AdBTxtTarif->hide();
    ui->AdBLabelPrix->hide();
    ui->AdBTxtPrix->hide();
    ui->AdBBtnAjouterTarif->hide();
    ui->AdBBtnModifierTarif->hide();
    ui->AdBBtnSupprimerTarif->hide();
    ui->AdBBtnAnnulerTarif->hide();
}

void AdministrationBillet::AfficherLesChampsTarif()
{
    ui->AdBLabelTarif->show();
    ui->AdBTxtTarif->show();
    ui->AdBLabelPrix->show();
    ui->AdBTxtPrix->show();
    ui->AdBBtnAjouterTarif->show();
    ui->AdBBtnModifierTarif->show();
    ui->AdBBtnSupprimerTarif->show();
    ui->AdBBtnAnnulerTarif->show();
}

void AdministrationBillet::MasquerLesChampsModePaiement()
{
    ui->AdBLabelMPaiement->hide();
    ui->AdBTxtIntituleMPaiement->hide();
    ui->AdBBtnAjouterMPaiement->hide();
    ui->AdBBtnModifierMPaiement->hide();
    ui->AdBBtnSupprimerMPaiement->hide();
    ui->AdBBtnAnnulerMPaiement->hide();
}

void AdministrationBillet::AfficherLesChampsModePaiement()
{
    ui->AdBLabelMPaiement->show();
    ui->AdBTxtIntituleMPaiement->show();
    ui->AdBBtnAjouterMPaiement->show();
    ui->AdBBtnModifierMPaiement->show();
    ui->AdBBtnSupprimerMPaiement->show();
    ui->AdBBtnAnnulerMPaiement->show();
}

AdministrationBillet::~AdministrationBillet()
{
    Login connexion;
    connexion.closeConnexion();
    delete ui;
}

void AdministrationBillet::on_AdBBtnModifierFiche_clicked()
{
    AfficherLesChampsConfigSalle();
    ui->AdBBtnModifierFiche->hide();
}

void AdministrationBillet::on_AdBBtnAnnuler_clicked()
{
    MasquerLesChampsConfigSalle();
    ui->AdBBtnModifierFiche->show();

}

void AdministrationBillet::on_AdBBtnModifierFicheTarif_clicked()
{
    AfficherLesChampsTarif();
    ui->AdBBtnModifierFicheTarif->hide();
}

void AdministrationBillet::on_AdBBtnAnnulerTarif_clicked()
{
    MasquerLesChampsTarif();
    ui->AdBBtnModifierFicheTarif->show();
}

void AdministrationBillet::on_AdBBtnModifierFicheMPaiement_clicked()
{
    AfficherLesChampsModePaiement();
    ui->AdBBtnModifierFicheMPaiement->hide();
}

void AdministrationBillet::on_AdBBtnAnnulerMPaiement_clicked()
{
    MasquerLesChampsModePaiement();
    ui->AdBBtnModifierFicheMPaiement->show();
}

//Affecté les données aux chanps txt apartir de la tableView ConfigSalle
void AdministrationBillet::on_TabVConfigSalle_activated(const QModelIndex &index)
{
        QString valeur;
        valeur = ui->TabVConfigSalle->model()->data(index).toString();

        QSqlQuery query;
        query.prepare("SELECT * FROM ConfigSalle "
                      "WHERE  IntituleConfigSalle = :valeur "
                      "OR Jauge = :valeur ");
        query.bindValue(":valeur", valeur);
        if(query.exec())
        {
            while (query.next())
            {
                ui->AdBTxtIntitule->setText(query.value(1).toString());
                ui->AdBTxtNbPlaces->setText(query.value(2).toString());

                //Afficher les champs qui recoivent les données de la requête
                AfficherLesChampsConfigSalle();
                ui->AdBBtnModifierFiche->hide();
            }
        }
        else
        {
                QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
        }
}

//Affecté les données aux chanps txt apartir de la tableView Tarif
void AdministrationBillet::on_TabVTarif_activated(const QModelIndex &index)
{
    QString valeur;
    valeur = ui->TabVTarif->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM Tarifs "
                  "WHERE IntituleTarif = :valeur "
                  "OR Prix = :valeur ");
    query.bindValue(":valeur", valeur);
    if(query.exec())
    {
        while (query.next())
        {
            ui->AdBTxtTarif->setText(query.value(1).toString());
            ui->AdBTxtPrix->setText(query.value(2).toString());

            //Afficher les champs qui recoivent les données de la requête
            AfficherLesChampsTarif();
            ui->AdBBtnModifierFicheTarif->hide();
        }
    }
    else
    {
            QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
    }
}

//Affecté les données aux chanps txt apartir de la tableView Mode de paiement
void AdministrationBillet::on_TabVMPaiement_activated(const QModelIndex &index)
{
    QString valeur;
    valeur = ui->TabVMPaiement->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM ModePaiement "
                  "WHERE  TypeModePaiement = :valeur ");
    query.bindValue(":valeur", valeur);
    if(query.exec())
    {
        query.next();
        ui->AdBTxtIntituleMPaiement->setText(query.value(1).toString());

        //Afficher les champs qui recoivent les données de la requête
        AfficherLesChampsModePaiement();
        ui->AdBBtnModifierFicheMPaiement->hide();

    }
    else
    {
            QMessageBox::warning(this, tr("Erreur:"), query.lastError().text());
    }
}
