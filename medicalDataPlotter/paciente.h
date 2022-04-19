#ifndef PACIENTE_H
#define PACIENTE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QtCore>
#include <QMessageBox>
#include <QImage>
#include <QDir>
#include <QFile>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QByteArray>
#include "graph.h"

namespace Ui {
class Paciente;
}

class Paciente : public QDialog
{
    Q_OBJECT

public:
    explicit Paciente(QWidget *parent = 0 );
    ~Paciente();
    void NuevoPaciente (QString Name, QString LName, long long ID, QString Sex, QDate Birth, QByteArray ppg /*, bool Ing*/);
    bool createDB (QString DBname);
    void Borrar();
  virtual  void VerDetalles();
    void Salvar();

private slots:
    void on_VER_clicked();

    void on_Borrar_clicked();

    void on_Salvar_clicked();

    void on_PPG_clicked();



protected :
    QSqlTableModel *model;
QSqlTableModel *filtered;
private:
    Ui::Paciente *ui;
    QSqlDatabase DB;
    bool Ingreso;
    graph *grap;

};

#endif // PACIENTE_H
