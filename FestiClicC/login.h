#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "accueil.h"

namespace Ui {
class Login;
}
/**
 * @brief La class Login pour l'identification de l'utilisateur
 */

class Login : public QDialog
{
    Q_OBJECT

public:

    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    /**
     * @brief on_lBtnSeConnecter_2_clicked Exécute la requête de vérification de l’existence
     * du compte ou pas dans la base de données
     */
    void on_lBtnSeConnecter_2_clicked();

    /**
     * @brief on_lBtnAnnuler_2_clicked Bouton annuler pour fermer la page
     */
    void on_lBtnAnnuler_2_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
