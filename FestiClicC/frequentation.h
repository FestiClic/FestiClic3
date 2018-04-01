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
    void on_fCBoxSpectaclecloture_currentIndexChanged(int index);

    void on_fCBoxSpectacleProgramme_currentIndexChanged(int index);


    void on_cltBtnQuitter_clicked();

private:
    Ui::Frequentation *ui;
};

#endif // FREQUENTATION_H
