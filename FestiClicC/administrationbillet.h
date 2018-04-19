#ifndef ADMINISTRATIONBILLET_H
#define ADMINISTRATIONBILLET_H

#include <QDialog>

namespace Ui {
class AdministrationBillet;
}
/**
 * @brief La class AdministrationBillet elle permet de gérer les différentes configurations de salles,
 * les modes de paiement et les tarifs avec la possibilité l’ajouter de modifier ou de supprimer
 * des enregistrements dans la base de données
 */

class AdministrationBillet : public QDialog
{
    Q_OBJECT

public:
    explicit AdministrationBillet(QWidget *parent = 0);
    ~AdministrationBillet();

private slots:
    /**
     * @brief on_AdBBtnModifierFiche_clicked bouton Modifier de la fiche des configuration des salles.
     * Affiche les champs de la configuration des salles et masque le bouton Modifier (AdBBtnModifierFiche)
     * pour faire apparaitre le bouton Annuler (AdBBtnAnnuler).
     */
    void on_AdBBtnModifierFiche_clicked();

    /**
     * @brief on_AdBBtnAnnuler_clicked bouton annuler de la fiche des configuration des salles.
     * Masque les champs de la configuration des salles, vide les données dans les champs
     * et masque le bouton Annuler (AdBBtnAnnuler)  pour faire apparaitre le bouton Modifier (AdBBtnModifierFiche).
     */
    void on_AdBBtnAnnuler_clicked();

    /**
     * @brief on_AdBBtnModifierFicheTarif_clicked bouton Modifier de la fiche des tarifs.
     * Affiche les champs des tarifs et masque le bouton Modifier (AdBBtnModifierFicheTarif)
     * pour faire apparaitre le bouton Annuler (AdBBtnAnnulerTarif).
     */
    void on_AdBBtnModifierFicheTarif_clicked();

    /**
     * @brief on_AdBBtnAnnulerTarif_clicked bouton annuler de la fiche des tarifs.
     * Masque les champs des tarifs, vide les données dans les champs et masque
     * le bouton Annuler (AdBBtnAnnulerTarif)  pour faire apparaitre le bouton Modifier (AdBBtnModifierFicheTarif).
     */
    void on_AdBBtnAnnulerTarif_clicked();

    /**
     * @brief on_AdBBtnModifierFicheMPaiement_clicked bouton Modifier de la fiche des modes de paiement.
     * Affiche le champ des modes de paiement et masque le bouton Modifier (AdBBtnModifierFicheMPaiement)
     * pour faire apparaitre le bouton Annuler (AdBBtnAnnulerMPaiement).
     */
    void on_AdBBtnModifierFicheMPaiement_clicked();

    /**
     * @brief on_AdBBtnAnnulerMPaiement_clicked bouton annuler de la fiche des modes de paiement.
     * Masque le champ des modes de paiement, vide les données dans le champ et masque
     * le bouton Annuler (AdBBtnAnnulerMPaiement)  pour faire apparaitre le bouton Modifier ((AdBBtnModifierFicheMPaiement).
     */
    void on_AdBBtnAnnulerMPaiement_clicked();

    /**
     * @brief on_TabVConfigSalle_activated au clic sur un élément dans la TableView, exécuter la requête qui affecte les données
     * aux champs de texte à partir de la table des configurations de salles de la base de données.
     * @param index
     */
    void on_TabVConfigSalle_activated(const QModelIndex &index);

    /**
     * @brief on_TabVTarif_activated au clic sur un élément dans la TableView, exécuter la requête qui affecte les données
     * aux champs de texte à partir de la table des tarifs de la base de données.
     * @param index
     */
    void on_TabVTarif_activated(const QModelIndex &index);

    /**
     * @brief on_TabVMPaiement_activated au clic sur un élément dans la TableView, exécuter la requête qui affecte les données
     * au champ de texte à partir de la table des modes de paiement de la base de données.
     * @param index
     */
    void on_TabVMPaiement_activated(const QModelIndex &index);

    /**
     * @brief on_AdBBtnAjouter_clicked Bouton Ajouter pour l'insertion d'un nouvel enregistrement, il exécute la requête
     * d'insertion dans la table configurations des salles dans la base de données
     */
    void on_AdBBtnAjouter_clicked();

    /**
     * @brief on_AdBBtnAjouterTarif_clicked Bouton Ajouter pour l'insertion d'un nouvel enregistrement, il exécute la requête
     * d'insertion dans la table tarifs dans la base de données
     */
    void on_AdBBtnAjouterTarif_clicked();

    /**
     * @brief on_AdBBtnAjouterMPaiement_clicked Bouton Ajouter pour l'insertion d'un nouvel enregistrement, il exécute la requête
     * d'insertion dans la table mode de paiement dans la base de données
     */
    void on_AdBBtnAjouterMPaiement_clicked();

    /**
     * @brief on_AdBBtnModifier_clicked Bouton Modifier un enregistrement dans la table configurations des salles dans la base de données
     */
    void on_AdBBtnModifier_clicked();

    /**
     * @brief on_AdBBtnModifierTarif_clicked Bouton Modifier un enregistrement dans la table tarifs dans la base de données
     */
    void on_AdBBtnModifierTarif_clicked();

    /**
     * @brief on_AdBBtnSupprimer_clicked Bouton Supprimer un enregistrement dans la table configurations des salles dans la base de données
     */
    void on_AdBBtnSupprimer_clicked();

    /**
     * @brief on_AdBBtnSupprimerTarif_clicked Bouton Supprimer un enregistrement dans la table tarifs dans la base de données
     */
    void on_AdBBtnSupprimerTarif_clicked();

    /**
     * @brief on_AdBBtnSupprimerMPaiement_clicked Bouton Supprimer un enregistrement dans la table mode de paiement dans la base de données
     */
    void on_AdBBtnSupprimerMPaiement_clicked();

    /**
     * @brief on_AdBtnQuitter_clicked Bouton qpour quitter la fiche Administration des billet et revenir à la page Accueil
     */
    void on_AdBtnQuitter_clicked();

private:
    Ui::AdministrationBillet *ui;

    /**
     * @brief MAJTablesViewPage Méthode de mise à jour de l'ensemble des TableView de la page
     * exécute les requêtes pour affecter les données des configurations des salles, des tarifs et des modes de paiement
     * dans chacune  des tablesView
     */
    void MAJTablesViewPage();

    /**
     * @brief MasquerLesChampsConfigSalle Méthode pour masquer les champs et les boutons de la fiche configurations des salles
     */
    void MasquerLesChampsConfigSalle();

    /**
     * @brief AfficherLesChampsConfigSalle Méthode pour afficher les champs et les boutons de la fiche configurations des salles
     */
    void AfficherLesChampsConfigSalle();

    /**
     * @brief ViderLesChampsConfigSalle Méthode pour vider les champs de la fiche configurations des salles
     */
    void ViderLesChampsConfigSalle();

    /**
     * @brief MasquerLesChampsTarif Méthode pour masquer les champs et les boutons de la fiche tarifs
     */
    void MasquerLesChampsTarif();

    /**
     * @brief AfficherLesChampsTarif Méthode pour afficher les champs et les boutons de la fiche tarifs
     */
    void AfficherLesChampsTarif();

    /**
     * @brief ViderLesChampsTarif Méthode pour vider les champs de la fiche tarifs
     */
    void ViderLesChampsTarif();

    /**
     * @brief MasquerLesChampsModePaiement Méthode pour masquer le champ et les boutons de la fiche mode de paiement
     */
    void MasquerLesChampsModePaiement();

    /**
     * @brief AfficherLesChampsModePaiement Méthode pour afficher le champ et les boutons de la fiche mode de paiement
     */
    void AfficherLesChampsModePaiement();

    /**
     * @brief ViderLesChampsModePaiemenet Méthode pour vider le champ de la fiche mode de paiement
     */
    void ViderLesChampsModePaiemenet();

};

#endif // ADMINISTRATIONBILLET_H
