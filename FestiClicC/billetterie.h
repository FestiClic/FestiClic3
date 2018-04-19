#ifndef BILLETTERIE_H
#define BILLETTERIE_H

#include <QDialog>
#include "login.h"
#include "accueil.h"
#include "spectacles.h"
#include <QtSql>
#include <QInputDialog>

namespace Ui {
class Billetterie;
}
/**
 * @brief La class Billetterie gère la partie billetterie,
 * avec la réservation des sièges sur plan ou dans la liste des sièges disponibles,
 * calcul les prix des billets et valide les réservations avec l’impression de billet.
 */

class Billetterie : public QDialog
{
    Q_OBJECT

public:
    explicit Billetterie(QWidget *parent = 0);
    ~Billetterie();

private slots:
    /**
     * @brief on_bCBoxRepresentations_currentIndexChanged Exécute des requêtes de sélection pour affecter les données
     * de la tables spectacles dans les labels à partir de l’élément sélectionné dans le ComboBox
     * @param arg1
     */
    void on_bCBoxRepresentations_currentIndexChanged(const QString &arg1);

    /**
     * @brief on_bCBoxSpectacteur_currentIndexChanged Exécute des requêtes de sélection pour affecter les données
     * de la tables client dans les labels à partir de l’élément sélectionné dans le ComboBox
     * @param arg1
     */
    void on_bCBoxSpectacteur_currentIndexChanged(const QString &arg1);

    /**
     * @brief on_bBtnAjouter_clicked Bouton ajouter un nouveau client avant réservation.
     * Ouvre la fiche client, rends le GroupBox clients inaccessible et affiche le bouton qui réactive le GroupBox
     */
    void on_bBtnAjouter_clicked();

    /**
     * @brief on_bCBoxTarif_currentIndexChanged Exécute des requêtes de sélection pour affecter les données
     * de la tables tarifs dans les labels à partir de l’élément sélectionné dans le ComboBox
     * @param arg1
     */
    void on_bCBoxTarif_currentIndexChanged(const QString &arg1);

    /**
     * @brief on_bBtnSuivant_clicked Calcul le prix total des places réservées
     * Afficher le plan de salle si la RadioButton salle est sélectionné
     * Affecter le résultat du calcul à la zone de texte du GroupBox paiement et l’afficher
     */
    void on_bBtnSuivant_clicked();

    /**
     * @brief on_bBtnPaiement_clicked Désactive le GroupBox paiement
     * Exécute la requête qui change le statut des sièges réservés pour les passer en non disponible sur le spectacle en question
     * Exécute la requête qui insère les données de la réservation dans la table Billets
     * Exécute la requête qui décrémente le nombre de place pour le spectacle en question
     * Exécute la requête qui insère les données de la réservation dans la table Transactions
     * Exécute la requête qui récupère les données à afficher sur le billet à imprimer
     */
    void on_bBtnPaiement_clicked();

    /**
     * @brief on_bBtnQuitter_clicked Bouton pour quitter la page billetterie
     */
    void on_bBtnQuitter_clicked();

    /**
     * @brief on_bListVNumSiege_activated Affecter les numéros de sièges à la listeView
     * Exécute la requête qui insère les numéros de sièges dans la liste
     * @param index
     */
    void on_bListVNumSiege_activated(const QModelIndex &index);

    /**
     * @brief MAJListeDesSieges Méthode pour affecter les numéros de sièges non réservés à la liste des sièges
     */
    void MAJListeDesSieges();

    /**
     * @brief on_bBtnSuivantPlan_2_clicked Le bouton suivant du GroupBox plan de salle
     * Calcul le prix total des places réservées
     * Affecter le résultat du calcul à la zone de texte du GroupBox paiement et l’afficher
     */
    void on_bBtnSuivantPlan_2_clicked();

    /**
     * @brief on_bBtnClientConcert_clicked Bouton pour ajouter des données fixes pour un client fictif
     * pour l'impression des billets concert à l'avance
     */
    void on_bBtnClientConcert_clicked();

    /**
     * @brief on_bRBtnPlacementLibre_clicked Le RadioButton placement libre, Vide les listes des sièges des sélections précédentes,
     * Affiche les listes des sièges,
     * Masque le plan de salle Affiche le bouton suivant
     */
    void on_bRBtnPlacementLibre_clicked();

    /**
     * @brief on_bRBtnPlacementPlan_clicked Le RadioButton placement sur plan, Vide les listes des sièges des sélections précédentes,
     * Affiche les listes des sièges,
     * Masque la liste qui contient la liste des sièges
     */
    void on_bRBtnPlacementPlan_clicked();

    /**
     * @brief on_bBtnAnnulerPaiement_clicked Bouton du GroupBox paiement,
     * Annuler le paiement,
     * Masquer le GroupBox paiement,
     * Afficher les éléments masqués de la page
     */
    void on_bBtnAnnulerPaiement_clicked();

    /**
     * @brief on_bBtnAnnulerPlan_clicked Afficher le bouton suivant,
     * Vider la liste de la précédente sélection,
     * Masquer le plan de la salle
     */
    void on_bBtnAnnulerPlan_clicked();

    /**
     * @brief on_bBtnActiverZoneClient_clicked Mise à jour des données client après ajout d'un nouveau compte client,
     * Réactiver la zone client
     */
    void on_bBtnActiverZoneClient_clicked();

    /**
     * @brief on_P1_clicked Les boutons du plan (chaque bouton = 1 siège) A l'évènement clic de chaque bouton,
     * il passe à un statut intermédiaire (orange) dans l'attente de la validation du statut dans la BDD
     * A chaque clic le numéro du siège est affecté à la listeView
     * ça concerne les boutons du P1 au P50
     */
    void on_P1_clicked();

    void on_P2_clicked();

    void on_P3_clicked();

    void on_P4_clicked();

    void on_P5_clicked();

    void on_P6_clicked();

    void on_P7_clicked();

    void on_P8_clicked();

    void on_P9_clicked();

    void on_P10_clicked();

    void on_P11_clicked();

    void on_P12_clicked();

    void on_P13_clicked();

    void on_P14_clicked();

    void on_P15_clicked();

    void on_P16_clicked();

    void on_P17_clicked();

    void on_P18_clicked();

    void on_P19_clicked();

    void on_P20_clicked();

    void on_P21_clicked();

    void on_P22_clicked();

    void on_P23_clicked();

    void on_P24_clicked();

    void on_P25_clicked();

    void on_P26_clicked();

    void on_P27_clicked();

    void on_P28_clicked();

    void on_P29_clicked();

    void on_P30_clicked();

    void on_P31_clicked();

    void on_P32_clicked();

    void on_P33_clicked();

    void on_P34_clicked();

    void on_P35_clicked();

    void on_P36_clicked();

    void on_P37_clicked();

    void on_P38_clicked();

    void on_P39_clicked();

    void on_P40_clicked();

    void on_P41_clicked();

    void on_P42_clicked();

    void on_P43_clicked();

    void on_P44_clicked();

    void on_P45_clicked();

    void on_P46_clicked();

    void on_P47_clicked();

    void on_P48_clicked();

    void on_P49_clicked();

    void on_P50_clicked();

private:
    Ui::Billetterie *ui;

    /**
     * @brief AffecterDonneesRepresentation Exécute la requête qui affecte les données de la représentation au ComboBox représentation
     */
    void AffecterDonneesRepresentation();

    /**
     * @brief AffecterLesNomsClients Exécute la requête qui affecte les données du client au ComboBox
     */
    void AffecterLesNomsClients();

    /**
     * @brief AffecterLesTarifs Exécute la requête qui affecte les données du tarif au ComboBox
     */
    void AffecterLesTarifs();

    /**
     * @brief AffecterLesNumerosDesSieges Exécute la requête qui affecte les sièges disponibles à la liste des sièges
     */
    void AffecterLesNumerosDesSieges();

    /**
     * @brief AffecterLesModesDePaiement Exécute la requête qui affecte les données des modes de paiement au ComboBox
     */
    void AffecterLesModesDePaiement();

    /**
     * @brief InitialisationEtatDesSieges Méthode d’initialisation état des sièges,
     * elle passe les sièges à la couleur verte (statut disponible) et rend les boutons des sièges cliquables
     */
    void InitialisationEtatDesSieges();

    /**
     * @brief VerifierSiReserve Méthode pour identifier les sièges réservés sur le plan
     */
    void VerifierSiReserve();

    /**
     * @brief InitialisationDesChamps Méthode pour initialiser l’ensemble des labels et zone de texte
     */
    void InitialisationDesChamps();
};

#endif // BILLETTERIE_H
