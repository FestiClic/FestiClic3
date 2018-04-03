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

    QVector <int> numeroPlace;
    QVector <QString> listeSieges;
    int numSiege = 1666;
    QString nomSiege = "PA_0000";
    QString intituleSiege;


    for(int i = 1001; i <= numSiege; i++)
    {
        qDebug() << "valeur de i" << i;
        intituleSiege = ((nomSiege.right(4)=i )+numeroPlace.value(i));
        qDebug() << "valeur intitule siege" << intituleSiege;


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
*/

    }

}
//changer aspect btn
void PlanDeSalle::ChangerStatutSiege()
{
    QVector <QString> NomPlace;
    NomPlace.push_back(ui->buttonGroup->objectName());
    qDebug() <<"Sieges dans vector" << NomPlace;
}

void PlanDeSalle::alreadybooked()
{
/*    Login connexion;
// /////////////////////////////////////////////////////////////////////////

    int numSiege = 10;
    QString nomSiege = "P_0";
    for(int i = 0; i = numSiege; i++)
    {

    }
// /////////////////////////////////////////////////////////////////////////
    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* query = new QSqlQuery(connexion.maBaseDeDonnee);
    query->prepare("SELECT * FROM Places");
    query->exec();
    modal->setQuery(*query);

    qDebug() << (modal->rowCount());

//-------
    String mycon = "Data Source=HP-PC\\SQLEXPRESS; Initial Catalog=TicketBooking; Integrated Security=True";
    String myquery = "Select * from Seatstatus";
    SqlConnection con = new SqlConnection(mycon);
    SqlCommand cmd = new SqlCommand();
    cmd.CommandText = myquery;
    cmd.Connection = con;
    SqlDataAdapter da = new SqlDataAdapter();
    da.SelectCommand = cmd;
    DataSet ds = new DataSet();
    da.Fill(ds);
    int rows = modal.Tables[0].Rows.Count;
    int i = 0;
    while (i < rows)
    {
        int reserve;
        reserve = modal.Tables[0].Rows[i]["Reserve"].ToString();
        if (reserve == 1)
        {

                bookedseat[i] = 1;
                if (i == 0)
                {
                    ui->P_001->setStyle("backColor = red;");
                    ui->P_001->setEnabled(false);
                }
                if (i == 1)
                {
                    ui->P_002->setStyle("backColor = red;");
                    ui->P_002->setEnabled(false);
                }
                if (i == 2)
                {
                    ui->P_003->setStyle("backColor = red;");
                    ui->P_003->setEnabled(false);
                }
                if (i == 3)
                {
                    ui->P_004->setStyle("backColor = red;");
                    ui->P_004->setEnabled(false);
                }
                if (i == 4)
                {
                    ui->P_005->setStyle("backColor = red;");
                    ui->P_005->setEnabled(false);
                }
                if (i == 5)
                {
                    ui->P_006->setStyle("backColor = red;");
                    ui->P_006->setEnabled(false);
                }
                if (i == 6)
                {
                    ui->P_007->setStyle("backColor = red;");
                    ui->P_007->setEnabled(false);
                }
                if (i == 7)
                {
                    ui->P_008->setStyle("backColor = red;");
                    ui->P_008->setEnabled(false);
                }
                if (i == 8)
                {
                    ui->P_009->setStyle("backColor = red;");
                    ui->P_009->setEnabled(false);
                }
                if (i == 9)
                {
                    ui->P_010->setStyle("backColor = red;");
                    ui->P_010->setEnabled(false);
                }

            }
            if (reserve == 0)
            {
                bookedseat[i] = 0;
                if (i == 0)
                {
                    ui->P_001->setStyle("backColor = green;");
                }
                if (i == 1 )
                {
                    ui->P_002->setStyle("backColor = green;");
                }
                if (i == 2 )
                {
                    ui->P_003->setStyle("backColor = green;");
                }
                if (i == 3 )
                {
                    ui->P_001->setStyle("backColor = green;");
                }
                if (i == 4)
                {
                    ui->P_001->setStyle("backColor = green;");
                }
                if (i == 5)
                {
                    ui->P_001->setStyle("backColor = green;");
                }
                if (i == 6 )
                {
                    ui->P_001->setStyle("backColor = green;");
                }
                if (i == 7)
                {
                    ui->P_001->setStyle("backColor = green;");
                }
                if (i == 8)
                {
                    ui->P_001->setStyle("backColor = green;");
                }
                if (i == 9)
                {
                    ui->P_001->setStyle("backColor = green;");
                }

            }
            i++;
            }
*/
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
