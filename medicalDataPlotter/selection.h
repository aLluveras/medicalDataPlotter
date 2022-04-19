#ifndef SELECTION_H
#define SELECTION_H

#include <QDialog>
#include "paciente.h"
#include "verdb.h"

namespace Ui {
class Selection;
}

class Selection : public QDialog
{
    Q_OBJECT

public:
    explicit Selection(QWidget *parent = 0);
    ~Selection();

private slots:
    void on_PACIENTE_clicked();

    void on_BaseDeDatos_clicked();

private:
    Ui::Selection *ui;
    Paciente *paciente;
    verDB *vdb;

};

#endif // SELECTION_H
