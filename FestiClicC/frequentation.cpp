#include "frequentation.h"
#include "ui_frequentation.h"

#include "login.h"
#include <QDate>
#include <QMessageBox>

Frequentation::Frequentation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Frequentation)
{
    ui->setupUi(this);

    Login connexion;
    connexion.openConnexion();

    //initialisation des comboBox
    ui->fCBoxSpectaclecloture->setCurrentIndex(-1);
    ui->fCBoxSpectacleProgramme->setCurrentIndex(-1);

    QDate aujourdhui;

    aujourdhui = QDate::currentDate();

    //Requette pour remplir la ComboBox des spectacles cloturés
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* querySpectaclecloture = new QSqlQuery(connexion.maBaseDeDonnee);
    querySpectaclecloture->prepare("SELECT Spectacle FROM Spectacles WHERE Date > :aujourdhui");
    querySpectaclecloture->bindValue(":aujourdhui", aujourdhui);

    querySpectaclecloture->exec();
    modal->setQuery(*querySpectaclecloture);
    ui->fCBoxSpectaclecloture->setModel(modal);

    //Requette pour remplir la ComboBox des spectacles programmés
    QSqlQueryModel * modal1 = new QSqlQueryModel();

    QSqlQuery* querySpectacleProgramme = new QSqlQuery(connexion.maBaseDeDonnee);
    querySpectacleProgramme->prepare("SELECT Spectacle FROM Spectacles WHERE Date < :aujourdhui");
    querySpectacleProgramme->bindValue(":aujourdhui", aujourdhui);

    querySpectacleProgramme->exec();
    modal1->setQuery(*querySpectacleProgramme);
    ui->fCBoxSpectacleProgramme->setModel(modal1);

    qDebug() << (modal->rowCount());

    //***********************************************************************
    //Affecter les données des utilisateurs dans la TableView

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
}



Frequentation::~Frequentation()
{
    Login connexion;
    connexion.closeConnexion();

    delete ui;
}

void Frequentation::on_fCBoxSpectaclecloture_currentIndexChanged(int index)
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

        }
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }

}

void Frequentation::on_fCBoxSpectacleProgramme_currentIndexChanged(int index)
{
    QString spectacle;
    int idSpectale;

    spectacle = ui->fCBoxSpectacleProgramme->currentText();

    QSqlQuery query;
    query.prepare("SELECT * FROM Spectacles WHERE Spectacle = :spectacle");
    query.bindValue(":spectacle", spectacle);

    if(query.exec())
    {
        while (query.next())
        {
            ui->fTxtJaugeInitiale_2->setText(query.value(4).toString());
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

        }
    }
    else
    {
        QMessageBox::warning(this,tr("Erreur:"),query.lastError().text());	//msgBox avec comme titre erreur et le text de l'erreur generé par la requete
    }
}
