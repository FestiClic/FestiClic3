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

private slots:
    void on_uBtnAjouter_clicked();

    void on_uBtnQuitter_clicked();

    void on_uBtnModifier_clicked();

    void on_uBtnSupprimer_clicked();

    void on_uTabV_activated(const QModelIndex &index);

    void on_uBtnViderChamps_clicked();

private:
    Ui::Utilisateur *ui;

    void MAJTableV();

    void ViderLesChamps();
};

#endif // UTILISATEUR_H
