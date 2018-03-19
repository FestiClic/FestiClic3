#include "accueil.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Accueil w;
    //image de fond page Accueil
    //w.setStyleSheet("background-image:url(:spactacle2.jpg); background-color: cornflowerblue;");
    w.show();

    return a.exec();

//*********************************************************************************************************************************
    //Solution Adrien ferme l'appli mais pas d'acces a la page suivante
    //var valeur déclaré dans accueil.h et login.h
 /*
    Login login;
    Accueil w;
    //image de fond page Accueil
    //w.setStyleSheet("background-image:url(:spactacle2.jpg); background-color: cornflowerblue;");
    if(login.exec()==QDialog::Accepted)
    {
        //w.valeur = login.valeur;
        w.show();
    }
    else
    {
        return 0;
    }

    return a.exec();
}*/
}
