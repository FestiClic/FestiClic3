#include "utilisateur.h"
#include "ui_utilisateur.h"
#include <QCryptographicHash>
#include <QByteArray>

Utilisateur::Utilisateur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Utilisateur)
{
    ui->setupUi(this);
}

Utilisateur::~Utilisateur()
{
    delete ui;
}

/* //Hach du mot de passe
QString chaine=user.GetMotDePasse();
QByteArray motDePasseHache = QCryptographicHash::hash(chaine.toUtf8(), QCryptographicHash::Sha1);
*/
