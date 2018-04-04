#ifndef RECTTES_H
#define RECTTES_H

#include <QDialog>

namespace Ui {
class Recttes;
}

class Recttes : public QDialog
{
    Q_OBJECT

public:
    explicit Recttes(QWidget *parent = 0);
    ~Recttes();

private:
    Ui::Recttes *ui;
};

#endif // RECTTES_H
