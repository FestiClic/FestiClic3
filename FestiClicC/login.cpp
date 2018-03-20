#include "login.h"
#include "ui_login.h"
#include "accueil.h"
#include "database.h"
#include <QtSql>



Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    if(openConnexion())
    {
        ui->lLabConnexion->setText("Connexion Billetterie principale");
    }
    else
    {
        ui->lLabConnexion->setText("Connexion non établie !");
    }
}

bool Login::openConnexion()
{
    maBaseDeDonnee=QSqlDatabase::addDatabase("QSQLITE");

    //maBaseDeDonnee.setDatabaseName("Z:/Projet C++/FestiClic3/database.db");  //CCI Z:
    maBaseDeDonnee.setDatabaseName("C:/Users/adai10/Desktop/projet Qt C++/FestiClic3/database.db"); //CCI C:

    //maBaseDeDonnee.setDatabaseName("C:/Users/Mourad/Desktop/ADAI/Fclic/database.db");   //Maison Projet B
    //maBaseDeDonnee.setDatabaseName("C:/Users/Mourad/Desktop/ADAI/FestiClic3/database.db");  //Maison Projet C

    if(maBaseDeDonnee.open())
    {
        qDebug()<<("Connexion...");
        return true;
    }
    else
    {
        qDebug()<<("Connexion a ouvrir");
        return false;
    }
}

void Login::closeConnexion()
{
    maBaseDeDonnee.close();
    maBaseDeDonnee.removeDatabase(QSqlDatabase::defaultConnection);
}


Login::~Login()
{
    delete ui;
}




void Login::on_lBtnSeConnecter_clicked()
{
    QString nomUtilisateur;
    QString motDePasse;

    nomUtilisateur = ui->lTxtNomUtilisateur->text();
    motDePasse = ui->lTxtMotDePasse->text();

    if(!openConnexion())
    {
        qDebug()<<"Connexion non établie";
        return;
    }

    openConnexion();

    QSqlQuery query;
    query.prepare("SELECT * FROM Utilisateurs WHERE Username='"+nomUtilisateur +"' AND Password='"+motDePasse +"'");

    if(query.exec())
    {
        int compteur = 0;
        while(query.next())
        {
            compteur++;
        }
        if(compteur==1)
        {
            ui->lLabConnexion->setText("Acces accepté");

            closeConnexion(); //fermeture de la connexion bdd

            //Fermeture de la page login pour afficher l'accueil
            //this->hide();
            this->accept();
            this->close();
        }
        else
        {
            ui->lLabConnexion->setText("Le nom d'tilisateur ou le mot de passe est erroné");
        }
    }
}

void Login::on_lBtnAnnuler_clicked()
{
    this->reject();
    this->close();


    //Si fermer il faut aussi fermer la page Accueil

    //Accueil accueil;
    //accueil.close(); //A modifier car ca ne marche pas comme il faut
    //qApp->exit(0);








}
