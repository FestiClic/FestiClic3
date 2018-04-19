#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QDialog>

namespace Ui {
class Utilisateur;
}
/**
 * @brief La class Utilisateur est un fichier utilisateurs
 */

class Utilisateur : public QDialog
{
    Q_OBJECT

public:
    explicit Utilisateur(QWidget *parent = 0);
    ~Utilisateur();

private slots:
    //Création d'un nouveau compte utilisateur
    /**
     * @brief on_uBtnAjouter_clicked Bouton ajouter nouveau exécute la requête d’insertion d’un utilisateur dans la base de données
     */
    void on_uBtnAjouter_clicked();

    /**
     * @brief on_uBtnQuitter_clicked Bouton quitter pour fermer la page
     */
    void on_uBtnQuitter_clicked();

    /**
     * @brief on_uBtnModifier_clicked Bouton modifier exécute la requête de modification d’un enregistrement existant dans la base de données
     */
    void on_uBtnModifier_clicked();

    /**
     * @brief on_uBtnSupprimer_clicked Bouton supprimer exécute la requête de suppression d’un enregistrement existant dans la base de données
     */
    void on_uBtnSupprimer_clicked();

    /**
     * @brief on_uTabV_activated Exécute la requête qui affecte les données aux champs de texte à partir de la tableView
     * @param index
     */
    void on_uTabV_activated(const QModelIndex &index);

    /**
     * @brief on_uBtnViderChamps_clicked Bouton qui vide les champs de saisi
     */
    void on_uBtnViderChamps_clicked();

private:
    Ui::Utilisateur *ui;
    /**
     * @brief MAJTableV Méthode de mise à jour de la TableView
     * exécute la requête pour affecter les données des spectacles dans la tablesView
     */
    void MAJTableV();

    /**
     * @brief ViderLesChamps Méthode d’initialisation de l’ensemble des champs de la page
     */
    void ViderLesChamps();

    /**
     * @brief RendreLesChampsUserNameEtPassWordCliquables Désactive les champs identifiant et mot de passe
     */
    void RendreLesChampsUserNameEtPassWordCliquables();
};

#endif // UTILISATEUR_H
