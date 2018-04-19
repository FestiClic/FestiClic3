#include "frequentation.h"
#include "ui_frequentation.h"

#include "login.h"
#include "database.h"
#include <QDate>
#include <QMessageBox>
#include <QProgressBar>

Frequentation::Frequentation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Frequentation)
{
    ui->setupUi(this);

    Database connexion;
    connexion.openConnexion();

    //Rendre les champs inaccessible pour l'tilisateur
    ui->fTxtFrequentation->setEnabled(false);
    ui->fTxtFrequentation_2->setEnabled(false);
    ui->fTxtJaugeInitiale->setEnabled(false);
    ui->fTxtJaugeInitiale_2->setEnabled(false);
    ui->fTxtRemplissage->setEnabled(false);
    ui->fTxtRemplissage_2->setEnabled(false);

    //Requette pour remplir la ComboBox des spectacles cloturés
    AffecterSpectaclesCloturesDansCombo();

    //Requette pour remplir la ComboBox des spectacles programmés
    AffecterSpectaclesProgrammesDansCombo();

    //initialisation des comboBox
    ui->fCBoxSpectaclecloture->setCurrentIndex(-1);
    ui->fCBoxSpectacleProgramme->setCurrentIndex(-1);

    //***********************************************************************
    /*    //Affecter les données des utilisateurs dans la TableView

    QSqlQueryModel * modal2 = new QSqlQueryModel();

    QSqlQuery* queryTableV = new QSqlQuery(connexion.maBaseDeDonnee);
    queryTableV->prepare( "SELECT (IdSpectacle) AS 'Ref.', Spectacle, Date, "
                              "(JaugeSpectacle) AS 'Jauge intiale' , COUNT(NumPlace) AS 'Places vendus' "
                              "FROM Spectacles s, Places p "
                              "WHERE s.IdSpectacle = p.IdSpectacleP "
                              "AND Reserve  = 1 "
                              "ORDER BY IdSpectacleP ");
//Afficher uniquement le nombre total de siege reservés par spectacle et NON PAS SUR TTE LA TABLE

        queryTableV->exec();
        modal2->setQuery(*queryTableV);
        ui->fTabV->setModel(modal2);

        ui->fTabV->resizeColumnsToContents();

        qDebug() << (modal2->rowCount());
*/
}

void Frequentation::AffecterSpectaclesCloturesDansCombo()
{
    //Requette pour remplir la ComboBox des spectacles cloturés
    QDate aujourdhui;

    aujourdhui = QDate::currentDate();

    Database connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee);
    query->prepare("SELECT Spectacle FROM Spectacles WHERE Date < :aujourdhui");
    query->bindValue(":aujourdhui", aujourdhui);

    query->exec();
    modal->setQuery(*query);
    ui->fCBoxSpectaclecloture->setModel(modal);
}

void Frequentation::AffecterSpectaclesProgrammesDansCombo()
{
    //Requette pour remplir la ComboBox des spectacles programmés

    QDate aujourdhui;

    aujourdhui = QDate::currentDate();

    Database connexion;
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee);
    query->prepare("SELECT Spectacle FROM Spectacles WHERE Date > :aujourdhui");
    query->bindValue(":aujourdhui", aujourdhui);

    query->exec();
    modal->setQuery(*query);
    ui->fCBoxSpectacleProgramme->setModel(modal);

    qDebug() << (modal->rowCount());
}

Frequentation::~Frequentation()
{
    Database connexion;
    connexion.closeConnexion();

    delete ui;
}


void Frequentation::on_fCBoxSpectaclecloture_currentIndexChanged(const QString &arg1)
{
    QString spectacle;
    int idSpectale;

    spectacle = ui->fCBoxSpectaclecloture->currentText();

    QSqlQuery query;
    query.prepare("SELECT * FROM Spectacles WHERE Spectacle = :spectacle");
    query.bindValue(":spectacle", spectacle);

    if(query.exec())
    {
        while (query.next())
        {
            ui->fTxtJaugeInitiale->setText(query.value(4).toString());
            idSpectale = query.value(0).toInt();    //recuparation de l'IdSpectacle dans une variable

            //Reqete pour affecter la totalite des places réservées
            QSqlQuery query;
            query.prepare("SELECT COUNT(NumPlace) "
                          "FROM Places "
                          "WHERE IdSpectacleP = :idSpectacle "
                          "AND Reserve = 1 ");
            query.bindValue(":idSpectacle", idSpectale);
            query.exec();
            query.next();
            ui->fTxtRemplissage->setText(query.value(0).toString());

            //Calculer le pourcentage de la fréquentation du spectacle
            double pourcentage;
            double valeurRemplissage;
            double jauge;

            valeurRemplissage = std::stod(ui->fTxtRemplissage->text().toStdString());
            jauge = std::stod(ui->fTxtJaugeInitiale->text().toStdString());

            pourcentage = (100*valeurRemplissage/jauge);

            QString pourcentageRemplissage = QString::number(pourcentage);
            ui->fTxtFrequentation->setText(pourcentageRemplissage);

            //progresse bar
            ui->progressBar->setMaximum(100);
            ui->progressBar->setMinimum(0);
            ui->progressBar->setValue(pourcentage);
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }
}


void Frequentation::on_fCBoxSpectacleProgramme_currentIndexChanged(const QString &arg1)
{
    QString spectacle;
    int idSpectale;

    spectacle = ui->fCBoxSpectacleProgramme->currentText();

    //Requête de sélection
    QSqlQuery query;
    query.prepare("SELECT * FROM Spectacles WHERE Spectacle = :spectacle ");
    query.bindValue(":spectacle", spectacle);

    if(query.exec())
    {
        while (query.next())
        {
            ui->fTxtJaugeInitiale_2->setText(query.value(4).toString());
            idSpectale = query.value(0).toInt();    //recuparation de l'IdSpectacle dans une variable

            //Requête pour affecter la totalité des places réservées
            QSqlQuery query;
            query.prepare("SELECT COUNT(NumPlace) "
                          "FROM Places "
                          "WHERE IdSpectacleP = :idSpectacle "
                          "AND Reserve = 1 ");
            query.bindValue(":idSpectacle", idSpectale);
            query.exec();
            query.next();
            ui->fTxtRemplissage_2->setText(query.value(0).toString());

            //Calculer le pourcentage de la fréquentation du spectacle

            double pourcentage;
            double valeurRemplissage;
            double jauge;

            valeurRemplissage = std::stod(ui->fTxtRemplissage_2->text().toStdString());
            jauge = std::stod(ui->fTxtJaugeInitiale_2->text().toStdString());

            pourcentage = (100*valeurRemplissage/jauge);

            QString pourcentageRemplissage = QString::number(pourcentage);
            ui->fTxtFrequentation_2->setText(pourcentageRemplissage);

            //progress bar
            ui->progressBar_2->setMaximum(100);
            ui->progressBar_2->setMinimum(0);
            ui->progressBar_2->setValue(pourcentage);

        }
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }
}



void Frequentation::on_cltBtnQuitter_clicked()
{
    this->close();
}
