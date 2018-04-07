#ifndef FREQUENTATION_H
#define FREQUENTATION_H

#include <QDialog>

namespace Ui {
class Frequentation;
}

class Frequentation : public QDialog
{
    Q_OBJECT

public:
    explicit Frequentation(QWidget *parent = 0);
    ~Frequentation();

private slots:

    void on_cltBtnQuitter_clicked();

    void on_fCBoxSpectacleProgramme_currentIndexChanged(const QString &arg1);

    void on_fCBoxSpectaclecloture_currentIndexChanged(const QString &arg1);

private:
    Ui::Frequentation *ui;

    void AffecterSpectaclesCloturesDansCombo();

    void AffecterSpectaclesProgrammesDansCombo();
};

#endif // FREQUENTATION_H
