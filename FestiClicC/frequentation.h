#ifndef FREQUENTATION_H
#define FREQUENTATION_H

#include <QDialog>

namespace Ui {
class Frequentation;
}
/**
 * @brief La class Frequentation permet d'avoir une vision globale de la fréquentation des spectacles
 * sur la base du pourcentage de remplissage par séances
 */

class Frequentation : public QDialog
{
    Q_OBJECT

public:
    explicit Frequentation(QWidget *parent = 0);
    ~Frequentation();

private slots:
    /**
     * @brief on_cltBtnQuitter_clicked Bouton quitter pour fermer la page
     */
    void on_cltBtnQuitter_clicked();

    /**
     * @brief on_fCBoxSpectacleProgramme_currentIndexChanged Pour les sénaces programmées et
     * en fonction de l’enregistrement sélectionné dans le ComboBox,
     * exécute la requête qui récupère la totalité des places réservées,
     * Calcule le pourcentage de la fréquentation du spectacle en question,
     * Affiche les résultats dans les champs de texte et dans une ProgressBar
     * @param arg1
     */
    void on_fCBoxSpectacleProgramme_currentIndexChanged(const QString &arg1);

    /**
     * @brief on_fCBoxSpectaclecloture_currentIndexChanged Pour les sénaces cloturées et
     * en fonction de l’enregistrement sélectionné dans le ComboBox,
     * exécute la requête qui récupère la totalité des places réservées,
     * Calcule le pourcentage de la fréquentation du spectacle en question,
     * Affiche les résultats dans les champs de texte et dans une ProgressBar
     * @param arg1
     */
    void on_fCBoxSpectaclecloture_currentIndexChanged(const QString &arg1);

private:
    Ui::Frequentation *ui;
    /**
     * @brief AffecterSpectaclesCloturesDansCombo Exécute la requête qui affecte les séances cloturées dans le ComboBox
     */
    void AffecterSpectaclesCloturesDansCombo();

    /**
     * @brief AffecterSpectaclesProgrammesDansCombo Exécute la requête qui affecte les séances programmées dans le ComboBox
     */
    void AffecterSpectaclesProgrammesDansCombo();
};

#endif // FREQUENTATION_H
