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

    //Masquer le label IdSpectacle
    ui->pLabelIdSpectacle->hide();
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

        // Affecter les num sièges au vector tant que les dernier 4 caractères correspondent à i.
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

//Nécessaire pour le développement futur de l’application, pour automatiser la gestion des sièges
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



void PlanDeSalle::InitialisationEtatDesSieges()
{
    ui->P1->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P2->setStyleSheet("border-image: url(:wheelchairCircVert.png);");   //Fauteuil handicapé
    ui->P3->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P4->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P5->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P6->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P7->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P8->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P9->setStyleSheet("border-image: url(:wheelchairCircVert.png);");   //Fauteuil handicapé
    ui->P10->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P11->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P12->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P13->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P14->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P15->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P16->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P17->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P18->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P19->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P20->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P21->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P22->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P23->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P24->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P25->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P26->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P27->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P28->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P29->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P30->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P31->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P31->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P32->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P33->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P34->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P35->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P36->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P37->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P38->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P39->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P40->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P41->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P42->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P43->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P44->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P45->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P46->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P47->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P48->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P49->setStyleSheet("border-image: url(:CircPlusGreen.png);");
    ui->P50->setStyleSheet("border-image: url(:CircPlusGreen.png);");

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
    ui->P29->setEnabled(true);
    ui->P30->setEnabled(true);
    ui->P31->setEnabled(true);
    ui->P32->setEnabled(true);
    ui->P33->setEnabled(true);
    ui->P34->setEnabled(true);
    ui->P35->setEnabled(true);
    ui->P36->setEnabled(true);
    ui->P37->setEnabled(true);
    ui->P38->setEnabled(true);
    ui->P39->setEnabled(true);
    ui->P40->setEnabled(true);
    ui->P41->setEnabled(true);
    ui->P42->setEnabled(true);
    ui->P43->setEnabled(true);
    ui->P44->setEnabled(true);
    ui->P45->setEnabled(true);
    ui->P46->setEnabled(true);
    ui->P47->setEnabled(true);
    ui->P48->setEnabled(true);
    ui->P49->setEnabled(true);
    ui->P50->setEnabled(true);
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
            // InitialisationEtatDesSieges();
            bool trouver = false;
            while(query.next())
            {
                siege = query.value(1).toString();
                qDebug() << "siege : " << siege;

                trouver = true;
                // Si la requete revoie des données
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
                            ui->P1->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P1->setEnabled(false);
                        }
                        if(siege == "PA2")
                        {
                            ui->P2->setStyleSheet("border-image: url(:wheelchairCircRouge.png);");
                            ui->P2->setEnabled(false);
                        }
                        if(siege == "PA3")
                        {
                            ui->P3->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P3->setEnabled(false);
                        }
                        if(siege == "PA4")
                        {
                            ui->P4->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P4->setEnabled(false);
                        }
                        if(siege == "PA5")
                        {
                            ui->P5->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P5->setEnabled(false);
                        }
                        if(siege == "PA6")
                        {
                            ui->P6->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P6->setEnabled(false);
                        }
                        if(siege == "PA7")
                        {
                            ui->P7->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P7->setEnabled(false);
                        }
                        if(siege == "PA8")
                        {
                            ui->P8->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P8->setEnabled(false);
                        }
                        if(siege == "PA9")
                        {
                            ui->P9->setStyleSheet("border-image: url(:wheelchairCircRouge.png);");
                            ui->P9->setEnabled(false);
                        }
                        if(siege == "PA10")
                        {
                            ui->P10->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P10->setEnabled(false);
                        }
                        if(siege == "PA11")
                        {
                            ui->P11->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P11->setEnabled(false);
                        }
                        if(siege == "PA12")
                        {
                            ui->P12->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P12->setEnabled(false);
                        }
                        if(siege == "PA13")
                        {
                            ui->P13->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P13->setEnabled(false);
                        }
                        if(siege == "PA14")
                        {
                            ui->P14->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P14->setEnabled(false);
                        }
                        if(siege == "PA15")
                        {
                            ui->P15->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P15->setEnabled(false);
                        }
                        if(siege == "PA16")
                        {
                            ui->P16->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P16->setEnabled(false);
                        }
                        if(siege == "PA17")
                        {
                            ui->P17->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P17->setEnabled(false);
                        }
                        if(siege == "PA18")
                        {
                            ui->P18->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P18->setEnabled(false);
                        }
                        if(siege == "PA19")
                        {
                            ui->P19->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P19->setEnabled(false);
                        }
                        if(siege == "PA20")
                        {
                            ui->P20->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P20->setEnabled(false);
                        }
                        if(siege == "PA21")
                        {
                            ui->P21->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P21->setEnabled(false);
                        }
                        if(siege == "PA22")
                        {
                            ui->P22->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P22->setEnabled(false);
                        }
                        if(siege == "PA23")
                        {
                            ui->P23->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P23->setEnabled(false);
                        }
                        if(siege == "PA24")
                        {
                            ui->P24->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P24->setEnabled(false);
                        }
                        if(siege == "PA25")
                        {
                            ui->P25->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P25->setEnabled(false);
                        }
                        if(siege == "PA26")
                        {
                            ui->P26->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P26->setEnabled(false);
                        }
                        if(siege == "PA27")
                        {
                            ui->P27->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P27->setEnabled(false);
                        }
                        if(siege == "PA28")
                        {
                            ui->P28->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P28->setEnabled(false);
                        }
                        if(siege == "PA29")
                        {
                            ui->P29->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P29->setEnabled(false);
                        }
                        if(siege == "PA30")
                        {
                            ui->P30->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P30->setEnabled(false);
                        }
                        if(siege == "PA31")
                        {
                            ui->P31->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P31->setEnabled(false);
                        }
                        if(siege == "PA32")
                        {
                            ui->P32->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P32->setEnabled(false);
                        }
                        if(siege == "PA33")
                        {
                            ui->P33->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P33->setEnabled(false);
                        }
                        if(siege == "PA34")
                        {
                            ui->P34->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P34->setEnabled(false);
                        }
                        if(siege == "PA35")
                        {
                            ui->P35->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P35->setEnabled(false);
                        }
                        if(siege == "PA36")
                        {
                            ui->P36->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P36->setEnabled(false);
                        }
                        if(siege == "PA37")
                        {
                            ui->P37->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P37->setEnabled(false);
                        }
                        if(siege == "PA38")
                        {
                            ui->P38->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P38->setEnabled(false);
                        }
                        if(siege == "PA39")
                        {
                            ui->P39->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P39->setEnabled(false);
                        }
                        if(siege == "PA40")
                        {
                            ui->P40->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P40->setEnabled(false);
                        }
                        if(siege == "PA41")
                        {
                            ui->P41->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P41->setEnabled(false);
                        }
                        if(siege == "PA42")
                        {
                            ui->P42->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P42->setEnabled(false);
                        }
                        if(siege == "PA43")
                        {
                            ui->P43->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P43->setEnabled(false);
                        }
                        if(siege == "PA44")
                        {
                            ui->P44->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P44->setEnabled(false);
                        }
                        if(siege == "PA45")
                        {
                            ui->P45->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P45->setEnabled(false);
                        }
                        if(siege == "PA46")
                        {
                            ui->P46->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P46->setEnabled(false);
                        }
                        if(siege == "PA47")
                        {
                            ui->P47->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P47->setEnabled(false);
                        }
                        if(siege == "PA48")
                        {
                            ui->P48->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P48->setEnabled(false);
                        }
                        if(siege == "PA49")
                        {
                            ui->P49->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P49->setEnabled(false);
                        }
                        if(siege == "PA50")
                        {
                            ui->P50->setStyleSheet("border-image: url(:UserMenRed.png);");
                            ui->P50->setEnabled(false);
                        }
                    }
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

//Affecter les spectacles dans le ComboBox
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



void PlanDeSalle::on_cltBtnQuitter_clicked()
{
    this->close();
}
