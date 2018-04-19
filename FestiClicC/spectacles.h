#ifndef SPECTACLES_H
#define SPECTACLES_H

#include <QDialog>
#include "login.h"
#include "accueil.h"
#include <QtSql>

namespace Ui {
class Spectacles;
}
/**
 * @brief La class Spectacles est un catalogue des différents spectacles
 */

class Spectacles : public QDialog
{
    Q_OBJECT

public:
    explicit Spectacles(QWidget *parent = 0);
    ~Spectacles();

private slots:
    /**
     * @brief on_sBtnQuitter_clicked Bouton quitter pour fermer la page
     */
    void on_sBtnQuitter_clicked();

    /**
     * @brief on_sBtnAjouter_clicked Bouton ajouter nouveau exécute la requête d’insertion d’un spectacle dans la base de données
     */
    void on_sBtnAjouter_clicked();

    /**
     * @brief on_sBtnModifier_clicked Bouton modifier exécute la requête de modification d’un enregistrement existant dans la base de données
     */
    void on_sBtnModifier_clicked();

    /**
     * @brief on_sCBoxIdConfidSalle_currentIndexChanged Exécute la requête qui affecte les données
     * de la tables configuration de salle dans le ComboBox
     * @param arg1
     */
    void on_sCBoxIdConfidSalle_currentIndexChanged(const QString &arg1);
    /**
     * @brief on_sBtnSupprimer_clicked Bouton supprimer exécute la requête de suppression d’un enregistrement existant dans la base de données
     */
    void on_sBtnSupprimer_clicked();

    /**
     * @brief on_sTabV_activated Exécute la requête qui affecte les données aux champs de texte à partir de la tableView
     * @param index
     */
    void on_sTabV_activated(const QModelIndex &index);

    /**
     * @brief on_sBtnViderChamps_clicked Bouton qui vide les champs de saisi
     */
    void on_sBtnViderChamps_clicked();



private:
    Ui::Spectacles *ui;
    /**
     * @brief ViderLesChamps Méthode d’initialisation de l’ensemble des champs de la page
     */
    void ViderLesChamps();

    /**
     * @brief MAJTableV Méthode de mise à jour de la TableView
     * exécute la requête pour affecter les données des spectacles dans la tablesView
     */
    void MAJTableV();

};

#endif // SPECTACLES_H
