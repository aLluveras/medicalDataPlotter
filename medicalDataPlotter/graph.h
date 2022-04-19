#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QFileDialog>
#include <QStringList>
#include <complex>
#include <complex.h>
#include <QMetaEnum>


#include <QMainWindow>
#include <QTimer>
#include <qcustomplot.h>

#include <QDebug>
#include <QList>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QDialog>

#include <complex>

namespace Ui {
class graph;
}

class graph : public QDialog
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = 0);
    void Graficar (QVector<double> xx, QVector<double> yy,double minimo, double maximo);
    ~graph();
    void setupFFTDataPlot(QVector<double> data, int N);

private:
    Ui::graph *ui;
    QVector<double> x;
    QVector<double> y;
    QVector<double> z;
    QFileDialog *dialog;
    QString fileName;
    QString line;
    QStringList fields;

   // Paciente *pac;
};

#endif // GRAPH_H
