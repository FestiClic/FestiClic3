#ifndef CLIENTS_H
#define CLIENTS_H

#include <QDialog>
#include "login.h"
#include "accueil.h"
#include <QtSql>

namespace Ui {
class Clients;
}
/**
 * @brief La class Clients est un fichier client
 */

class Clients : public QDialog
{
    Q_OBJECT

public:
    explicit Clients(QWidget *parent = 0);
    ~Clients();

private slots:
    /**
     * @brief on_cltBtnQuitter_clicked Bouton quitter pour fermer la page
     */
    void on_cltBtnQuitter_clicked();

    /**
     * @brief on_cltBtnAjouter_clicked Bouton ajouter nouveau client exécute la requête d’insertion d’un nouveau client dans la base de données
     */
    void on_cltBtnAjouter_clicked();

    /**
     * @brief on_cltBtnModifier_clicked Bouton modifier exécute la requête de modification d’un enregistrement existant dans la base de données
     */
    void on_cltBtnModifier_clicked();

    /**
     * @brief on_cltBtnSupprimer_clicked Bouton supprimer exécute la requête de suppression d’un enregistrement existant dans la base de données
     */
    void on_cltBtnSupprimer_clicked();

    /**
     * @brief on_cltTabV_activated Exécute la requête qui affecte les données aux champs de texte à partir de la tableView
     * @param index
     */
    void on_cltTabV_activated(const QModelIndex &index);

    /**
     * @brief on_cltBtnViderChamps_clicked Bouton qui vide les champs de saisi
     */
    void on_cltBtnViderChamps_clicked();

private:
    Ui::Clients *ui;
    /**
     * @brief MAJTableV Méthode de mise à jour de la TableView
     * exécute la requête pour affecter les données des clients dans la tablesView
     */
    void MAJTableV();

    /**
     * @brief ViderLesChamps Méthode d’initialisation de l’ensemble des champs de la page
     */
    void ViderLesChamps();
};

#endif // CLIENTS_H
