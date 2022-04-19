#include "selection.h"
#include "ui_selection.h"

Selection::Selection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selection)
{
    ui->setupUi(this);
}

Selection::~Selection()
{
    delete ui;
}

void Selection::on_PACIENTE_clicked()
{
    paciente = new Paciente(this);
    paciente->show();
   // Selection::hide();

}

void Selection::on_BaseDeDatos_clicked()
{
    vdb = new verDB(this);
    vdb -> show();
   // Selection::hide();
}
