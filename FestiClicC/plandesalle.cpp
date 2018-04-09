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
#include <QList>
#include <iostream>




PlanDeSalle::PlanDeSalle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanDeSalle)
{
    Database connexion;
    connexion.openConnexion();

    ui->setupUi(this);

    VerifierSiReserve();
// ////////////////////
/*    QButtonGroup* group = new QButtonGroup(this);
       group->addButton(ui->PA1);
       group->addButton(ui->PA2);
       group->addButton(ui->PA3);
       group->addButton(ui->PA4);

       group->connect(group, SIGNAL(buttonClicked(QAbstractButton*)),
                                    this, SLOT(steelChange(int)));
*/
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
    query->prepare("SELECT Spectacle FROM Spectacles");
    query->exec();
    modal->setQuery(*query);    //Récuperation des valeurs pointeur de requete
    ui->pCBoxSpectacle->setModel(modal);     //Envoyer les données en combo

    //fermeture de la connexion
    //connexion.closeConnexion();
    qDebug() << (modal->rowCount());

    ui->pCBoxSpectacle->setCurrentIndex(-1);
    ui->pLabelIdSpectacle->clear();

// ////////////////////////////////////////////
}

void PlanDeSalle::steelChange(int buttonID)
{
/*    qDebug() << "buttonID : " << buttonID;
    QButtonGroup* group = new QButtonGroup(this);
    (this)->setStyleSheet("background-color: rgb(255, 99, 71);");


    //QButtonGroup::buttonClicked(objectName());

*/    //objectName(buttonID)
/*
    QList<QPushButton *> allWidgets = PlanDeSalle().findChildren<QPushButton *>("");
    QList<QPushButton*>::iterator it;
    for (it = allWidgets.begin(); it != allWidgets.end(); it++) {
        if ((*it)->objectName() == "PA1")  // here, objectName is not working!!
        {
            qDebug()<< "allWidgets : " << allWidgets;
            (*it)->setStyleSheet("background-color: rgb(255, 99, 71);");
            (*it)->setEnabled(false);

        }
    }

*/



    //setEnabled(false);
    //;
    //qDebug() << "ca marche : : : ";
}

// //////////////////////////////////////////////

//changer aspect btn
void PlanDeSalle::ChangerStatutSiege()
{
//    QVector <QString> NomPlace;
//    NomPlace.push_back(ui->buttonGroup->objectName());
//    qDebug() <<"Sieges dans vector" << NomPlace;
}

void PlanDeSalle::SetSiege()
{
/*    ui->PA1->setStyleSheet("background-color: rgb(255, 99, 71);");
    ui->PA1->setEnabled(false);

    ui->PA2->setStyleSheet("background-color: rgb(255, 99, 71);");
    ui->PA2->setEnabled(false);
*/
}

void PlanDeSalle::InitialisationEtatDesSieges()
{
    ui->P1->setStyleSheet("background-color: none;");
    ui->P2->setStyleSheet("background-color: none;");
    ui->P3->setStyleSheet("background-color: none;");
    ui->P4->setStyleSheet("background-color: none;");
    ui->P5->setStyleSheet("background-color: none;");
    ui->P6->setStyleSheet("background-color: none;");
    ui->P7->setStyleSheet("background-color: none;");
    ui->P8->setStyleSheet("background-color: none;");
    ui->P9->setStyleSheet("background-color: none;");
    ui->P10->setStyleSheet("background-color: none;");

    ui->P11->setStyleSheet("background-color: none;");
    ui->P12->setStyleSheet("background-color: none;");
    ui->P13->setStyleSheet("background-color: none;");
    ui->P14->setStyleSheet("background-color: none;");
    ui->P15->setStyleSheet("background-color: none;");
    ui->P16->setStyleSheet("background-color: none;");
    ui->P17->setStyleSheet("background-color: none;");
    ui->P18->setStyleSheet("background-color: none;");
    ui->P19->setStyleSheet("background-color: none;");
    ui->P20->setStyleSheet("background-color: none;");

    ui->P21->setStyleSheet("background-color: none;");
    ui->P22->setStyleSheet("background-color: none;");
    ui->P23->setStyleSheet("background-color: none;");
    ui->P24->setStyleSheet("background-color: none;");
    ui->P25->setStyleSheet("background-color: none;");
    ui->P26->setStyleSheet("background-color: none;");
    ui->P27->setStyleSheet("background-color: none;");
    ui->P28->setStyleSheet("background-color: none;");


    ui->P1->setEnabled(true);
    ui->P2->setEnabled(true);
    ui->P3->setEnabled(true);
    ui->P4->setEnabled(true);
    ui->P5->setEnabled(true);
    ui->P6->setEnabled(true);
    ui->P7->setEnabled(true);
    ui->P8->setEnabled(true);
    ui->P9->setEnabled(true);
    ui->P10->setEnabled(true);
    ui->P11->setEnabled(true);
    ui->P12->setEnabled(true);
    ui->P13->setEnabled(true);
    ui->P14->setEnabled(true);
    ui->P15->setEnabled(true);
    ui->P16->setEnabled(true);
    ui->P17->setEnabled(true);
    ui->P18->setEnabled(true);
    ui->P19->setEnabled(true);
    ui->P20->setEnabled(true);
    ui->P21->setEnabled(true);
    ui->P22->setEnabled(true);
    ui->P23->setEnabled(true);
    ui->P24->setEnabled(true);
    ui->P25->setEnabled(true);
    ui->P26->setEnabled(true);
    ui->P27->setEnabled(true);
    ui->P28->setEnabled(true);

}

void PlanDeSalle::VerifierSiReserve()
{
    int idSpectacle;

    idSpectacle = ui->pLabelIdSpectacle->text().toInt();

    QVector <int> numeroPlace;
    //QVector <QString> listeSieges;
    int numSiege = 10;
    QString siege;
    QString prefixNomSiege = "PA";
    QString intituleSiege;

    // TEST OBJECT NAME ////////////////////////////////////////////////////////////////////////////////////


                           // QList<QButtonGroup> tousLesBoutons = PlanDeSalle().findChildren<QButtonGroup>("");
                            //QList<QButtonGroup>::iterator it;



                            //qDebug() << "tousLesBoutons : " << tousLesBoutons;

    //Remplir le vecteur
    for(int i = 1; i <= numSiege; i++)
    {
        numeroPlace.push_back(i);
        qDebug() << "numeroPlace : " << numeroPlace;
        QString siegeNum = QString::number(i);

        //Affecter la concatenation du prefex et i eme élement à la variable intituleSiege
        intituleSiege = prefixNomSiege+siegeNum;

        qDebug() << "siegeNum : " << siegeNum;
        qDebug() << "intituleSiege : " << intituleSiege;


// //////////////////////

/*        for (it = tousLesBoutons.begin(); it != tousLesBoutons.end(); it++) {

            if(siege == intituleSiege)
            {
            //(it)->setStyleSheet("background-color: rgb(255, 99, 71);");;
            //(it)->setEnabled(false);
            }

        }

*/


        // Requête pour tester le statut des sièges
        QSqlQuery query;
        query.prepare("SELECT * FROM Places WHERE IdSpectacleP = :idSpectacle AND Reserve = 1 ");
        query.bindValue(":idSpectacle", idSpectacle);
        if(query.exec())
        {


            InitialisationEtatDesSieges();
            bool trouver = false;
            while(query.next())
            {
                siege = query.value(1).toString();
                qDebug() << "siege : " << siege;


                trouver = true;
            // Si le statut du siège est Réservé
            if(trouver)
            {
                // la variable reserve recoit le resultat boolean de la requête(statut du siège)
                int reserve;
                reserve = query.value(3).toInt();

                    // Si réservé
                    if(reserve == 1)
                    {


                        //si nom d'objet = intituleSiege
                     //  if (objectName() == intituleSiege)
                       //{

                     //    QPushButton *bouton = new QPushButton;
                     //    bouton->setObjectName(intituleSiege.tos);


                        if(siege == "PA1")
                        {
                            ui->P1->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P1->setEnabled(false);
                        }
                        if(siege == "PA2")
                        {
                            ui->P2->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P2->setEnabled(false);
                        }
                        if(siege == "PA3")
                        {
                            ui->P3->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P3->setEnabled(false);
                        }
                        if(siege == "PA4")
                        {
                            ui->P4->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P4->setEnabled(false);
                        }
                        if(siege == "PA5")
                        {
                            ui->P5->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P5->setEnabled(false);
                        }
                        if(siege == "PA6")
                        {
                            ui->P6->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P6->setEnabled(false);
                        }
                        if(siege == "PA7")
                        {
                            ui->P7->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P7->setEnabled(false);
                        }
                        if(siege == "PA8")
                        {
                            ui->P8->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P8->setEnabled(false);
                        }
                        if(siege == "PA9")
                        {
                            ui->P9->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P9->setEnabled(false);
                        }
                        if(siege == "PA10")
                        {
                            ui->P10->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P10->setEnabled(false);
                        }
                        if(siege == "PA11")
                        {
                            ui->P11->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P11->setEnabled(false);
                        }
                        if(siege == "PA12")
                        {
                            ui->P12->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P12->setEnabled(false);
                        }
                        if(siege == "PA13")
                        {
                            ui->P13->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P13->setEnabled(false);
                        }
                        if(siege == "PA14")
                        {
                            ui->P14->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P14->setEnabled(false);
                        }
                        if(siege == "PA15")
                        {
                            ui->P15->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P15->setEnabled(false);
                        }
                        if(siege == "PA16")
                        {
                            ui->P16->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P16->setEnabled(false);
                        }
                        if(siege == "PA17")
                        {
                            ui->P17->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P17->setEnabled(false);
                        }
                        if(siege == "PA18")
                        {
                            ui->P18->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P18->setEnabled(false);
                        }
                        if(siege == "PA19")
                        {
                            ui->P19->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P19->setEnabled(false);
                        }
                        if(siege == "PA20")
                        {
                            ui->P20->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P20->setEnabled(false);
                        }
                        if(siege == "PA21")
                        {
                            ui->P21->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P21->setEnabled(false);
                        }
                        if(siege == "PA22")
                        {
                            ui->P22->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P22->setEnabled(false);
                        }
                        if(siege == "PA23")
                        {
                            ui->P23->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P23->setEnabled(false);
                        }
                        if(siege == "PA24")
                        {
                            ui->P24->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P24->setEnabled(false);
                        }
                        if(siege == "PA25")
                        {
                            ui->P25->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P25->setEnabled(false);
                        }
                        if(siege == "PA26")
                        {
                            ui->P26->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P26->setEnabled(false);
                        }
                        if(siege == "PA27")
                        {
                            ui->P27->setStyleSheet("background-color: rgb(255, 99, 71);");
                            ui->P27->setEnabled(false);
                        }
                        if(siege == "PA28")
                        {
                            ui->P28->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P28->setEnabled(false);
                        }
                       //}
                    }
                    if(reserve == 0)
                    {
                        //Si pas réservé
                        if(siege == "PA1")
                        {
                            ui->P1->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA2")
                        {
                            ui->P2->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA3")
                        {
                            ui->P3->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA4")
                        {
                            ui->P4->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA5")
                        {
                            ui->P5->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA6")
                        {
                            ui->P6->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA7")
                        {
                            ui->P7->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA8")
                        {
                            ui->P8->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA9")
                        {
                            ui->P9->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA10")
                        {
                            ui->P10->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA11")
                        {
                            ui->P11->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA12")
                        {
                            ui->P12->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA13")
                        {
                            ui->P13->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA14")
                        {
                            ui->P14->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA15")
                        {
                            ui->P15->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA16")
                        {
                            ui->P16->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA17")
                        {
                            ui->P17->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA18")
                        {
                            ui->P18->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA19")
                        {
                            ui->P19->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA20")
                        {
                            ui->P20->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA21")
                        {
                            ui->P21->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA22")
                        {
                            ui->P22->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA23")
                        {
                            ui->P23->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA24")
                        {
                            ui->P24->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA25")
                        {
                            ui->P25->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA26")
                        {
                            ui->P26->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA27")
                        {
                            ui->P27->setStyleSheet("background-color: rgb(60, 60, 60);");
                        }
                        if(siege == "PA28")
                        {
                            ui->P28->setStyleSheet("border-image: url(:UserMenGreen.png);");
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
    // Affecter l'idSpectacle dans le Label
    QString spectacle = ui->pCBoxSpectacle->currentText();
    QSqlQuery query;
    query.prepare("SELECT IdSpectacle FROM Spectacles "
                  "WHERE Spectacle = :spectacle");
    query.bindValue(":spectacle", spectacle);

    query.exec();
    while(query.next())
    {
        ui->pLabelIdSpectacle->setText(query.value(0).toString());
    }

    InitialisationEtatDesSieges();
    VerifierSiReserve();
}

void PlanDeSalle::on_pBtnValider_clicked()
{

}
