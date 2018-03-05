#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>
#include "login.h"


namespace Ui {
class Accueil;
}

class Accueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = 0);
    ~Accueil();

private slots:
    void on_aBtnSpectacles_clicked();

private:
    Ui::Accueil *ui;
};

#endif // ACCUEIL_H
