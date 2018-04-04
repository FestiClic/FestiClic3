#include "plandesalle.h"
#include "ui_plandesalle.h"

#include "accueil.h"
#include "login.h"
#include <QtSql>
#include <QSqlQuery>
#include <QButtonGroup>
#include <QAbstractButton>
#include <QVector>




PlanDeSalle::PlanDeSalle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanDeSalle)
{
    Login connexion;
    connexion.openConnexion();
    ui->setupUi(this);

    VerifierSiReserve();
/*
//Vecteur pour stocker mes sieges
    QVector <int> numeroPlace;
    QVector <QString> listeSieges;


    int numSiege = 10;

    QString nomSiege = "PA_";
    QString intituleSiege;


    // remplir le vecteur
    for(int i = 1; i <= numSiege; i++)
    {
        numeroPlace.push_back(i);
        qDebug() << numeroPlace;
        intituleSiege = nomSiege + (i);
        qDebug() << "intituleSiege: "<< intituleSiege;




        qDebug() << listeSieges;




*/
/*        qDebug() << "valeur de i" << i;
        intituleSiege = ((nomSiege.right(4)=i )+numeroPlace.value(i));
        qDebug() << "valeur intitule siege" << intituleSiege;
*/

 /*

        // Affecter les num sièges au vector tant que les dernier 4 caractères correspon,dent à i.
        QString nomPlace;
        nomPlace = (nomSiege.right(4).toInt() = [i]);

        if (nomPlace)
        {
            numeroPlace.push_back(nomPlace);
        }


            qDebug () << numeroPlace;

    }
   ui->buttonGroup->connect(ui->buttonGroup, SIGNAL(buttonClicked(QAbstractButton* )),
                             this, SLOT(ChangerStatutSiege(QAbstractButton* )));


    }
*/
//Requette pour remplir Combo Spectacles
    QSqlQueryModel * modal = new QSqlQueryModel();  //Model de connexion pointeur modal (Spectacle)


    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee);
    query->prepare("SELECT IdSpectacle FROM Spectacles");
    query->exec();
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->pCBoxSpectacle->setModel(modal);     //Envoyer les données en combo


    //fermeture de la connexion
    //connexion.closeConnexion();
    qDebug() << (modal->rowCount());

    ui->pCBoxSpectacle->setCurrentIndex(-1);
}

//changer aspect btn
void PlanDeSalle::ChangerStatutSiege()
{
//    QVector <QString> NomPlace;
//    NomPlace.push_back(ui->buttonGroup->objectName());
//    qDebug() <<"Sieges dans vector" << NomPlace;
}

void PlanDeSalle::InitialisationEtatDesSieges()
{
    ui->P_001->setStyleSheet("background-color: none;");
    ui->P_002->setStyleSheet("background-color: none;");
    ui->P_003->setStyleSheet("background-color: none;");
    ui->P_004->setStyleSheet("background-color: none;");
    ui->P_005->setStyleSheet("background-color: none;");
    ui->P_006->setStyleSheet("background-color: none;");
    ui->P_007->setStyleSheet("background-color: none;");
    ui->P_008->setStyleSheet("background-color: none;");
    ui->P_009->setStyleSheet("background-color: none;");
    ui->P_010->setStyleSheet("background-color: none;");
}

void PlanDeSalle::VerifierSiReserve()
{
    int idSpectacle;

    idSpectacle = ui->pCBoxSpectacle->currentText().toInt();

    QVector <int> numeroPlace;
    QVector <QString> listeSieges;
    int numSiege = 10;
    QString siege;


    for(int i = 1; i <= numSiege; i++)
    {
        numeroPlace.push_back(i);
        qDebug() << numeroPlace;

        QSqlQuery query;
        query.prepare("SELECT * FROM Places WHERE IdSpectacleP = :idSpectacle AND Reserve = 1 ");

        query.bindValue(":idSpectacle", idSpectacle);
        //query.bindValue(":siege", siege);

        //int j = 0;

        if(query.exec())
        {
            int trouver = 0;
            while(query.next())
            {
                siege = query.value(1).toString();


                qDebug() << "siege : " << siege;
                trouver++;

            if(trouver!=0)
            {
                int reserve;
                reserve = query.value(3).toInt();


                //for(int j = 0; j == i; j++)
                //{

                    if(reserve == 1)
                    {
                        if(siege == "PA1")
                        {
                            ui->P_001->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_001->setEnabled(false);
                        }
                        if(siege == "PA2")
                        {
                            ui->P_002->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_002->setEnabled(false);
                        }
                        if(siege == "PA3")
                        {
                            ui->P_003->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_003->setEnabled(false);
                        }
                        if(siege == "PA4")
                        {
                            ui->P_004->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_004->setEnabled(false);
                        }
                        if(siege == "PA5")
                        {
                            ui->P_005->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_005->setEnabled(false);
                        }
                        if(siege == "PA6")
                        {
                            ui->P_006->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_006->setEnabled(false);
                        }
                        if(siege == "PA7")
                        {
                            ui->P_007->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_007->setEnabled(false);
                        }
                        if(siege == "PA8")
                        {
                            ui->P_008->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_008->setEnabled(false);
                        }
                        if(siege == "PA9")
                        {
                            ui->P_009->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_009->setEnabled(false);
                        }
                        if(siege == "PA10")
                        {
                            ui->P_010->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_010->setEnabled(false);
                        }
                    }
                    if(reserve == 0)
                    {
                        if(siege == "PA1")
                        {
                            ui->P_001->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA2")
                        {
                            ui->P_002->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA3")
                        {
                            ui->P_003->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA4")
                        {
                            ui->P_004->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA5")
                        {
                            ui->P_005->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA6")
                        {
                            ui->P_006->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA7")
                        {
                            ui->P_007->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA8")
                        {
                            ui->P_008->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA9")
                        {
                            ui->P_009->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA10")
                        {
                            ui->P_010->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                   }

                    //}
            }
           }  //j++;
        }
    }

}

PlanDeSalle::~PlanDeSalle()
{
    Login connexion;
    connexion.closeConnexion();
    delete ui;
    //NbSieges places 666
}



void PlanDeSalle::on_P_001_clicked()
{

}

void PlanDeSalle::on_pBtnVisualiser_clicked()
{
    InitialisationEtatDesSieges();
    VerifierSiReserve();
}

void PlanDeSalle::on_pCBoxSpectacle_currentIndexChanged(const QString &arg1)
{
    InitialisationEtatDesSieges();
    VerifierSiReserve();
}
