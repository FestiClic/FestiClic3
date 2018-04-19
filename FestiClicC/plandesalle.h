#ifndef PLANDESALLE_H
#define PLANDESALLE_H

#include <QDialog>

namespace Ui {
class PlanDeSalle;
}
/**
 * @brief La class PlanDeSalle permet la consultation du remplissage des salles par spectacle
 */

class PlanDeSalle : public QDialog
{
    Q_OBJECT

public:
    explicit PlanDeSalle(QWidget *parent = 0);
    ~PlanDeSalle();


private slots:

    /**
     * @brief on_pCBoxSpectacle_currentIndexChanged Exécute la requête qui affecte les spectacles dans le ComboBox
     * @param arg1
     */
    void on_pCBoxSpectacle_currentIndexChanged(const QString &arg1);

    /**
     * @brief steelChange Nécessaire pour le développement futur de l’application,
     * pour automatiser la gestion des sièges
     */
    void steelChange(int);

    /**
     * @brief on_cltBtnQuitter_clicked Bouton quitter pour fermer la page
     */
    void on_cltBtnQuitter_clicked();

private:
    Ui::PlanDeSalle *ui;
    /**
     * @brief VerifierSiReserve Méthode pour identifier les sièges réservés sur le plan
     */
    void VerifierSiReserve();

    /**
     * @brief InitialisationEtatDesSieges Méthode d’initialisation état des sièges,
     * elle passe les sièges à la couleur verte (statut disponible) et rend les boutons des sièges cliquables
     */
    void InitialisationEtatDesSieges();

};

#endif // PLANDESALLE_H
