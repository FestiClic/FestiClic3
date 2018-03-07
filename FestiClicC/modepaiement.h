#ifndef MODEPAIEMENT_H
#define MODEPAIEMENT_H

#include <QDialog>
#include "login.h"
#include "accueil.h"
#include "spectacles.h"
#include <QtSql>

namespace Ui {
class ModePaiement;
}

class ModePaiement : public QDialog
{
    Q_OBJECT

public:
    explicit ModePaiement(QWidget *parent = 0);
    ~ModePaiement();

private:
    Ui::ModePaiement *ui;
};

#endif // MODEPAIEMENT_H
