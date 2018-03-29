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

private:
    Ui::Frequentation *ui;
};

#endif // FREQUENTATION_H
