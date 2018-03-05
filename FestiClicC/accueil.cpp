#include "accueil.h"
#include "ui_accueil.h"
#include "login.h"

Accueil::Accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
    Login login;
    login.setModal(true);
    login.exec();

}

Accueil::~Accueil()
{
    delete ui;
}
