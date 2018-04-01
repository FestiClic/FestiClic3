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

    //masquer les champs et boutons
    void MasquerLesChampsConfigSalle();

    //afficher les champs et boutons
    void AfficherLesChampsConfigSalle();

    //Mise a jour des TableView de la page
    void MAJTablesViewPage();

    void MasquerLesChampsTarif();

    void AfficherLesChampsTarif();

    void MasquerLesChampsModePaiement();

    void AfficherLesChampsModePaiement();

    void on_AdBBtnModifierFicheTarif_clicked();

    void on_AdBBtnAnnulerTarif_clicked();

    void on_AdBBtnModifierFicheMPaiement_clicked();

    void on_AdBBtnAnnulerMPaiement_clicked();

    void on_TabVConfigSalle_activated(const QModelIndex &index);

    void on_TabVTarif_activated(const QModelIndex &index);

    void on_TabVMPaiement_activated(const QModelIndex &index);

private:
    Ui::AdministrationBillet *ui;
};

#endif // ADMINISTRATIONBILLET_H
