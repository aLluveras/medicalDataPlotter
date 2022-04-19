#ifndef VERDB_H
#define VERDB_H

#include <QDialog>
#include "paciente.h"
#include <QTableView>
#include <QCloseEvent>

namespace Ui {
class verDB;
}

class verDB : public Paciente
{
    Q_OBJECT

public:
    explicit verDB(QWidget *parent = 0);

    //void VerDetalles();
    ~verDB();



private:
    Ui::verDB *ui;
};

#endif // VERDB_H
