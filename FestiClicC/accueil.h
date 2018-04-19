#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>
#include "login.h"


namespace Ui {
class Accueil;
}
/**
 * @brief La class Accueil regroupe l'ensemble des modules de l'application
 */
class Accueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = 0);

    ~Accueil();

    /**
     * @brief lanceApp est un attribut nécessaire pour le lancement de l'application
     */
    bool lanceApp;

private slots:
    /**
     * @brief on_aBtnSpectacles_clicked bouton pour l'ouverture de la fiche spectacles
     */
    void on_aBtnSpectacles_clicked();


    /**
     * @brief on_aBtnClients_clicked bouton pour l'ouverture de la fiche clients
     */
    void on_aBtnClients_clicked();


    /**
     * @brief on_aBtnBilletterie_clicked bouton pour l'ouverture de la fiche billetterie
     */
    void on_aBtnBilletterie_clicked();


    /**
     * @brief on_aBtnPlanDeSalle_clicked bouton pour l'ouverture de la fiche du plan de salle
     */
    void on_aBtnPlanDeSalle_clicked();


    /**
     * @brief on_aBtnUtilisateur_clicked bouton pour l'ouverture de la fiche utilisateurs
     */
    void on_aBtnUtilisateur_clicked();


    /**
     * @brief on_aBtnAdministratioBillet_clicked bouton pour l'ouverture de la fiche administration de billetterie
     */
    void on_aBtnAdministratioBillet_clicked();


    /**
     * @brief on_aBtnFrequentation_clicked bouton pour l'ouverture de la fiche fréquentations
     */
    void on_aBtnFrequentation_clicked();


    /**
     * @brief on_aBtnQuitter_clicked bouton pour quitter l'application
     */
    void on_aBtnQuitter_clicked();

private:
    /**
     * @brief ui
     */
    Ui::Accueil *ui;


    /**
     * @brief InsererDonneesDansBDD Méthode qui insère les données fixes dans la base de données
     * Ces données sont nécessaires pour le fonctionnement de l’application :
     * Un compte utilisateur pour accéder à l’application
     * Un premier enregistrement dans la table Billets
     * Des clients fictifs
     * Deux configurations de salle
     * Les différents Modes de paiement
     * Une ligne dans la table Transactions
     * Les différents tarifs
     * Insertion des 50 sièges de la salle de spectacle
     * Insertion de spectacles dans la table Spectacles
     */
    void InsererDonneesDansBDD();
};

#endif // ACCUEIL_H
