#include "plandesalle.h"
#include "ui_plandesalle.h"

#include "accueil.h"
#include "database.h"
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
    Database connexion;
    connexion.openConnexion();
    ui->setupUi(this);

    VerifierSiReserve();
/*
//Vecteur pour stocker mes sieges
    QVector <int*> *numeroPlace = new QVector <int*>;
    int* adresseS = new int;
    QVector <QString> listeSieges;


    int numSiege = 10;

    QString nomSiege = "PA_";
    QString intituleSiege;


    // remplir le vecteur
    for(int i = 1; i <= numSiege; i++)
    {
        numeroPlace->push_back(adresseS);
        qDebug() << "numeroPlace "<<numeroPlace;
        //intituleSiege = nomSiege + (numeroPlace)[i];
        qDebug() << "adresseS " << adresseS;




        qDebug() << listeSieges;


        delete numeroPlace;
        delete adresseS;

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

    ui->P_001->setEnabled(true);
    ui->P_002->setEnabled(true);
    ui->P_003->setEnabled(true);
    ui->P_004->setEnabled(true);
    ui->P_005->setEnabled(true);
    ui->P_006->setEnabled(true);
    ui->P_007->setEnabled(true);
    ui->P_008->setEnabled(true);
    ui->P_009->setEnabled(true);
    ui->P_010->setEnabled(true);
}

void PlanDeSalle::VerifierSiReserve()
{
    int idSpectacle;

    idSpectacle = ui->pCBoxSpectacle->currentText().toInt();

    QVector <int> numeroPlace;
    //QVector <QString> listeSieges;
    int numSiege = 10;
    QString siege;
    QString prefixNomSiege = "PA";
    QString intituleSiege;


    //Remplir le vecteur
    for(int i = 1; i <= numSiege; i++)
    {
        numeroPlace.push_back(i);
        qDebug() << "numeroPlace : " << numeroPlace;
        QString siegeNum = QString::number(i);

        //Affcter la concatenation du prefex et i eme élement à la variable intituleSiege
        intituleSiege = prefixNomSiege+siegeNum;

        qDebug() << "siege : " << siegeNum;
        qDebug() << "intituleSiege : " << intituleSiege;


        QSqlQuery query;
        query.prepare("SELECT * FROM Places WHERE IdSpectacleP = :idSpectacle AND Reserve = 1 ");

        query.bindValue(":idSpectacle", idSpectacle);
        //query.bindValue(":siege", siege);

        //int j = 0;

        if(query.exec())
        {
            bool trouver = false;
            while(query.next())
            {
                siege = query.value(1).toString();


                qDebug() << "siege : " << siege;
                trouver = true;

            if(trouver)
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
                        // //////////////////////////////////////////////////////////////
                        if(siege == "PA11")
                        {
                            ui->P_011->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_011->setEnabled(false);
                        }
                        if(siege == "PA12")
                        {
                            ui->P_012->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_012->setEnabled(false);
                        }
                        if(siege == "PA13")
                        {
                            ui->P_013->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_013->setEnabled(false);
                        }
                        if(siege == "PA14")
                        {
                            ui->P_014->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_014->setEnabled(false);
                        }
                        if(siege == "PA15")
                        {
                            ui->P_015->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_015->setEnabled(false);
                        }
                        if(siege == "PA16")
                        {
                            ui->P_016->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_016->setEnabled(false);
                        }
                        if(siege == "PA17")
                        {
                            ui->P_017->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_017->setEnabled(false);
                        }
                        if(siege == "PA18")
                        {
                            ui->P_018->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_018->setEnabled(false);
                        }
                        if(siege == "PA19")
                        {
                            ui->P_019->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_019->setEnabled(false);
                        }
                        if(siege == "PA20")
                        {
                            ui->P_020->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_020->setEnabled(false);
                        }
                        if(siege == "PA21")
                        {
                            ui->P_021->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_021->setEnabled(false);
                        }
                        if(siege == "PA22")
                        {
                            ui->P_022->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_022->setEnabled(false);
                        }
                        if(siege == "PA23")
                        {
                            ui->P_023->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_023->setEnabled(false);
                        }
                        if(siege == "PA24")
                        {
                            ui->P_024->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_024->setEnabled(false);
                        }
                        if(siege == "PA25")
                        {
                            ui->P_025->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_025->setEnabled(false);
                        }
                        if(siege == "PA26")
                        {
                            ui->P_026->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_026->setEnabled(false);
                        }
                        if(siege == "PA27")
                        {
                            ui->P_027->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_027->setEnabled(false);
                        }
                        if(siege == "PA28")
                        {
                            ui->P_028->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P_028->setEnabled(false);
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
                        // ///////////////////////////////////////////////////////////////////
                        if(siege == "PA11")
                        {
                            ui->P_011->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA12")
                        {
                            ui->P_012->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA13")
                        {
                            ui->P_013->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA14")
                        {
                            ui->P_014->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA15")
                        {
                            ui->P_015->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA16")
                        {
                            ui->P_016->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA17")
                        {
                            ui->P_017->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA18")
                        {
                            ui->P_018->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA19")
                        {
                            ui->P_019->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA20")
                        {
                            ui->P_020->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA21")
                        {
                            ui->P_021->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA22")
                        {
                            ui->P_022->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA23")
                        {
                            ui->P_023->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA24")
                        {
                            ui->P_024->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA25")
                        {
                            ui->P_025->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA26")
                        {
                            ui->P_026->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA27")
                        {
                            ui->P_027->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA28")
                        {
                            ui->P_018->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                   }
                    //}
            }
           }
        }
    }

}

PlanDeSalle::~PlanDeSalle()
{


    Database connexion;
    connexion.closeConnexion();
    delete ui;
    //NbSieges places 666
}



void PlanDeSalle::on_P_001_clicked()
{
    //Créer un methode dans laquelle je déclare mon Qvector
    //Appeler la methode

    //si mon élément = 0 fait ce qui suit(btn setStyleSheet = Green)
    ui->P_010->setStyleSheet("background-color: rgb(20, 100, 20);");

    //Sinon change la couleur en gris


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

void PlanDeSalle::on_pBtnValider_clicked()
{

}
