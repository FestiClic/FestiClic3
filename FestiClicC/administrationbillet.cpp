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

    //Masquer les zones de text et les boutons
    MasquerLesChampsConfigSalle(); //ConfigSalle
    MasquerLesChampsTarif();
    MasquerLesChampsModePaiement();

    //Initialisation des champs text
    ViderLesChampsConfigSalle();
    ViderLesChampsTarif();
    ViderLesChampsModePaiemenet();
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

void AdministrationBillet::ViderLesChampsConfigSalle()
{
    ui->AdBTxtIntitule->clear();
    ui->AdBTxtNbPlaces->clear();
    //Masquer le label Alert
    ui->labelAlert->hide();
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

void AdministrationBillet::ViderLesChampsTarif()
{
    ui->AdBTxtTarif->clear();
    ui->AdBTxtPrix->clear();
    //Masquer le label Alert
    ui->labelAlert->hide();
}

void AdministrationBillet::MasquerLesChampsModePaiement()
{
    ui->AdBLabelMPaiement->hide();
    ui->AdBTxtIntituleMPaiement->hide();
    ui->AdBBtnAjouterMPaiement->hide();
    ui->AdBBtnSupprimerMPaiement->hide();
    ui->AdBBtnAnnulerMPaiement->hide();
}

void AdministrationBillet::AfficherLesChampsModePaiement()
{
    ui->AdBLabelMPaiement->show();
    ui->AdBTxtIntituleMPaiement->show();
    ui->AdBBtnAjouterMPaiement->show();
    ui->AdBBtnSupprimerMPaiement->show();
    ui->AdBBtnAnnulerMPaiement->show();
}

void AdministrationBillet::ViderLesChampsModePaiemenet()
{
    ui->AdBTxtIntituleMPaiement->clear();
    //Masquer le label Alert
    ui->labelAlert->hide();
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
    ViderLesChampsConfigSalle();
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
    ViderLesChampsTarif();
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
    ViderLesChampsModePaiemenet();
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

//Bouton ajouter nouvau enregistrement dans ConfigSalle
void AdministrationBillet::on_AdBBtnAjouter_clicked()
{
    QString configSalle;
    int jauge;

    configSalle = ui->AdBTxtIntitule->text();
    jauge = ui->AdBTxtNbPlaces->text().toInt();

    if(!ui->AdBTxtIntitule->text().isEmpty() && !ui->AdBTxtNbPlaces->text().isEmpty())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO ConfigSalle (IntituleConfigSalle, Jauge) "
                      "VALUES (:configSalle, :jauge)");
        query.bindValue(":configSalle", configSalle);;
        query.bindValue(":jauge", jauge);

        if(query.exec())
        {
           ViderLesChampsConfigSalle();

           QMessageBox::information(this,tr("Ajout nouvelle configuration de salle"), tr("Ajouté avec succès "));

           MAJTablesViewPage();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
        }
    }
    else
    {
        ui->labelAlert->show();
        ui->labelAlert->setStyleSheet("background-color:red; font-size: 15px;");
        ui->labelAlert->setText("Tous les champs sont obligatoires");
    }
}

//Bouton modifier un enregistrement dans ConfigSalle
void AdministrationBillet::on_AdBBtnModifier_clicked()
{
    QString configSalle;
    int jauge;

    configSalle = ui->AdBTxtIntitule->text();
    jauge = ui->AdBTxtNbPlaces->text().toInt();

    if(!ui->AdBTxtIntitule->text().isEmpty() && !ui->AdBTxtNbPlaces->text().isEmpty())
    {
        QSqlQuery query;
        query.prepare("UPDATE ConfigSalle "
                      "SET IntituleConfigSalle = :configSalle, Jauge = :jauge "
                      "WHERE IntituleConfigSalle = :configSalle");

        query.bindValue(":configSalle", configSalle);
        query.bindValue(":jauge", jauge);

        if(query.exec())
        {
            ViderLesChampsConfigSalle();

            QMessageBox::information(this, tr("Modification client"), tr("Fiche client midifié avec succes"));

            MAJTablesViewPage();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
        }
    }
    else
    {
        ui->labelAlert->show();
        ui->labelAlert->setStyleSheet("background-color:red; font-size: 15px;");
        ui->labelAlert->setText("La jauge est obligatoire !");
    }
}

//Bouton supprimer enregistrement dans Config Salle
void AdministrationBillet::on_AdBBtnSupprimer_clicked()
{
    QString configSalle;
    configSalle = ui->AdBTxtIntitule->text();

    QMessageBox msgBox;
    msgBox.setText("Voulez-vous vraiment supprimer "+configSalle+ " ?");
    QPushButton* pButtonYes = msgBox.addButton("Oui", QMessageBox::YesRole);
    msgBox.addButton("Non", QMessageBox::NoRole);

    msgBox.exec();
    if (msgBox.clickedButton()==(QAbstractButton*)pButtonYes)
    {

        QSqlQuery query;
        query.prepare("DELETE FROM ConfigSalle WHERE IntituleConfigSalle = :configSalle");
        query.bindValue(":configSalle", configSalle);

        if(query.exec())
        {
            QMessageBox::information(this,tr("Suppression"), tr("Enregistrement supprimé"));

            MAJTablesViewPage();
            ViderLesChampsConfigSalle();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
        }
    }
    else
    {
            qDebug() << "Non Annuler";
    }
}

//Bouton ajouter nouvau enregistrement dans Tarif
void AdministrationBillet::on_AdBBtnAjouterTarif_clicked()
{
    QString tarif;
    double prix;

    tarif = ui->AdBTxtTarif->text();
    prix = ui->AdBTxtPrix->text().toDouble();

    if(!ui->AdBTxtTarif->text().isEmpty() && !ui->AdBTxtPrix->text().isEmpty())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO Tarifs (IntituleTarif, Prix) "
                      "VALUES (:tarif, :prix)");
        query.bindValue(":tarif", tarif);;
        query.bindValue(":prix", prix);

        if(query.exec())
        {
           ViderLesChampsTarif();

           QMessageBox::information(this,tr("Ajout nouveau tarif "), tr("Ajouté avec succès "));

           MAJTablesViewPage();

        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
        }
    }
    else
    {
        ui->labelAlert->show();
        ui->labelAlert->setStyleSheet("background-color:red; font-size: 15px;");
        ui->labelAlert->setText("Tous les champs sont obligatoires");
    }
}

//Bouton modifier un enregistrement dans Tarif
void AdministrationBillet::on_AdBBtnModifierTarif_clicked()
{
    QString tarif;
    double prix;

    tarif = ui->AdBTxtTarif->text();
    prix = ui->AdBTxtPrix->text().toDouble();

    if(!ui->AdBTxtTarif->text().isEmpty() && !ui->AdBTxtPrix->text().isEmpty())
    {
        QSqlQuery query;
        query.prepare("UPDATE Tarifs "
                      "SET IntituleTarif = :tarif, Prix = :prix "
                      "WHERE IntituleTarif = :tarif");

        query.bindValue(":tarif", tarif);
        query.bindValue(":prix", prix);

        if(query.exec())
        {
            ViderLesChampsTarif();

            QMessageBox::information(this, tr("Modification client"), tr("Fiche client midifié avec succes"));

            MAJTablesViewPage();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
        }
    }
    else
    {
        ui->labelAlert->show();
        ui->labelAlert->setStyleSheet("background-color:red; font-size: 15px;");
        ui->labelAlert->setText("Le prix est obligatoire !");
    }
}

//Bouton supprimer enregistrement dans Tarif
void AdministrationBillet::on_AdBBtnSupprimerTarif_clicked()
{
    QString tarif;
    tarif = ui->AdBTxtTarif->text();

    QMessageBox msgBox;
    msgBox.setText("Voulez-vous vraiment supprimer "+tarif+ " ?");
    QPushButton* pButtonYes = msgBox.addButton("Oui", QMessageBox::YesRole);
    msgBox.addButton("Non", QMessageBox::NoRole);

    msgBox.exec();
    if (msgBox.clickedButton()==(QAbstractButton*)pButtonYes)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM Tarifs WHERE IntituleTarif = :tarif");
        query.bindValue(":tarif", tarif);

        if(query.exec())
        {
            QMessageBox::information(this,tr("Suppression"), tr("Enregistrement supprimé"));

            MAJTablesViewPage();
            ViderLesChampsTarif();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
        }
    }
    else
    {
            qDebug() << "Non Annuler";
    }
}

//Bouton ajouter nouvau enregistrement dans Mode de paiement
void AdministrationBillet::on_AdBBtnAjouterMPaiement_clicked()
{
    QString modePaiement;

    modePaiement = ui->AdBTxtIntituleMPaiement->text();

    if(!ui->AdBTxtIntituleMPaiement->text().isEmpty())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO ModePaiement (TypeModePaiement) "
                      "VALUES (:modePaiement)");
        query.bindValue(":modePaiement", modePaiement);

        if(query.exec())
        {
           ViderLesChampsModePaiemenet();

           QMessageBox::information(this,tr("Ajout nouveau mode de paiement"), tr("Ajouté avec succès "));

           MAJTablesViewPage();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());
        }
    }
    else
    {
        ui->labelAlert->show();
        ui->labelAlert->setStyleSheet("background-color:red; font-size: 15px;");
        ui->labelAlert->setText("Tous les champs sont obligatoires");
    }
}

//Bouton supprimer enregistrement dans Mode de paiement
void AdministrationBillet::on_AdBBtnSupprimerMPaiement_clicked()
{
    QString modePaiement;
    modePaiement = ui->AdBTxtIntituleMPaiement->text();

    QMessageBox msgBox;
    msgBox.setText("Voulez-vous vraiment supprimer "+modePaiement+ " ?");
    QPushButton* pButtonYes = msgBox.addButton("Oui", QMessageBox::YesRole);
    msgBox.addButton("Non", QMessageBox::NoRole);

    msgBox.exec();
    if (msgBox.clickedButton()==(QAbstractButton*)pButtonYes)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM ModePaiement WHERE TypeModePaiement = :modePaiement");
        query.bindValue(":modePaiement", modePaiement);

        if(query.exec())
        {
            QMessageBox::information(this,tr("Suppression"), tr("Enregistrement supprimé"));

            MAJTablesViewPage();
            ViderLesChampsModePaiemenet();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
        }
    }
    else
    {
            qDebug() << "Non Annuler";
    }
}
