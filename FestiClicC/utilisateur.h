#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QDialog>

namespace Ui {
class Utilisateur;
}

class Utilisateur : public QDialog
{
    Q_OBJECT

public:
    explicit Utilisateur(QWidget *parent = 0);
    ~Utilisateur();

private:
    Ui::Utilisateur *ui;
};

#endif // UTILISATEUR_H
