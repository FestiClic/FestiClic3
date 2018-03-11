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

class Login : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase maBaseDeDonnee;

    //ouverture de la connexion bdd
    bool openConnexion();

    //fermeture de la connexion bdd
    void closeConnexion();

    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_lBtnSeConnecter_clicked();

    void on_lBtnAnnuler_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H