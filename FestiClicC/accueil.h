#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>
#include "login.h"


namespace Ui {
class Accueil;
}

class Accueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = 0);

    ~Accueil();

    //int valeur;
    bool lanceApp;

private slots:
    //Ouverture de la fiche spectacles
    void on_aBtnSpectacles_clicked();

    //Ouverture de la liste et fiche Clients
    void on_aBtnClients_clicked();

    //Ouverture de la fiche billetterie
    void on_aBtnBilletterie_clicked();

    //Ouverture de la fiche plan de salle
    void on_aBtnPlanDeSalle_clicked();

    //Ouverture de la fiche utilisateur
    void on_aBtnUtilisateur_clicked();

    //Ouverture de la fiche administration des billets
    void on_aBtnAdministratioBillet_clicked();

    //Ouverture de la fiche fréquentation
    void on_aBtnFrequentation_clicked();

    //Quitter l'application
    void on_aBtnQuitter_clicked();

private:
    Ui::Accueil *ui;

    //Insérer données dans la base de données
    void InsererDonneesDansBDD();
};

#endif // ACCUEIL_H
