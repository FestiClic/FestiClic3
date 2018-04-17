#ifndef ADMINISTRATIONBILLET_H
#define ADMINISTRATIONBILLET_H

#include <QDialog>

namespace Ui {
class AdministrationBillet;
}

class AdministrationBillet : public QDialog
{
    Q_OBJECT

public:
    explicit AdministrationBillet(QWidget *parent = 0);
    ~AdministrationBillet();

private slots:

    void on_AdBBtnModifierFiche_clicked();

    void on_AdBBtnAnnuler_clicked();

    void on_AdBBtnModifierFicheTarif_clicked();

    void on_AdBBtnAnnulerTarif_clicked();

    void on_AdBBtnModifierFicheMPaiement_clicked();

    void on_AdBBtnAnnulerMPaiement_clicked();

    void on_TabVConfigSalle_activated(const QModelIndex &index);

    void on_TabVTarif_activated(const QModelIndex &index);

    void on_TabVMPaiement_activated(const QModelIndex &index);

    void on_AdBBtnAjouter_clicked();

    void on_AdBBtnAjouterTarif_clicked();

    void on_AdBBtnAjouterMPaiement_clicked();

    void on_AdBBtnModifier_clicked();

    void on_AdBBtnModifierTarif_clicked();

    void on_AdBBtnSupprimer_clicked();

    void on_AdBBtnSupprimerTarif_clicked();

    void on_AdBBtnSupprimerMPaiement_clicked();

    void on_AdBtnQuitter_clicked();

private:
    Ui::AdministrationBillet *ui;

    //Mise a jour des TableView de la page
    void MAJTablesViewPage();

    //masquer les champs et boutons
    void MasquerLesChampsConfigSalle();

    //afficher les champs et boutons
    void AfficherLesChampsConfigSalle();

    //Vider les champs de la configuration de salle
    void ViderLesChampsConfigSalle();

    //Masquer les champs tarif
    void MasquerLesChampsTarif();

    //Afficher les champs tarif
    void AfficherLesChampsTarif();

    //Vider les champs tarif
    void ViderLesChampsTarif();

    //Masquer les champs du GroupBox mode de paiement
    void MasquerLesChampsModePaiement();

    //Afficher les champs du GroupBox mode de paiement
    void AfficherLesChampsModePaiement();

    //Vider les champs du GroupBox mode de paiement
    void ViderLesChampsModePaiemenet();

};

#endif // ADMINISTRATIONBILLET_H
