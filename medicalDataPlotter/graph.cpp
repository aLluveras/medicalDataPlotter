#include "graph.h"
#include "ui_graph.h"
#include "paciente.h"


graph::graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);


  /*  Paciente *pac;
    pac=new Paciente(this);*/



        fileName = dialog->getOpenFileName(dialog,"SELECCION", "//home//lluveras//","Text files (Am*.txt)");

        QFile textFile(fileName);
     if(textFile.open(QIODevice::ReadOnly)) {
          QTextStream textStream(&textFile);
         while (!textStream.atEnd()) {
              line = textStream.readLine();
              fields = line.split(' ');
             y<<fields.at(0).toDouble();
             x<<(fields.at(1).toDouble()/615);
    }
}

     /*if (!dialog->exec())
     { QMessageBox::information(this,"Fatal Error","Necesario seleccionar un archivo");
              pac->exec();}*/



    //Average filter
     int size = y.size();
     for (int var = 0; var < size-3; ++var) {
         double b= ((y.at(var+2)+y.at(var+1)+y.at(var)+y.at(var+3))/4);
          z.append(b);
      }


     //limits and count

     int count=0;
 double max=z.at(0), min=z.at(0);
           for (int index = 1; index <size-4; index++) {

               if (min<z.at(index)) {
                   min=min;
               }
               else min= z.at(index);

               if (max>z.at(index)) {
                   max= max;
               }
               else max = z.at(index);

                if (z.at(index-1)<z.at(index) && z.at(index) > z.at(index+1) )
           {
                count++;     }
       }

           qDebug()<<count;
        //   Graficar(x,y,min,max);

           /*if(graph::close())
           {pac->exec();}*/
int ssize=size-3;
           setupFFTDataPlot(z,ssize);
     }


void graph::Graficar (QVector<double> xx, QVector<double> yy,double minimo, double maximo)
{
    ui->CPlot->addGraph();
    ui->CPlot->graph()->setData(xx, yy);
    ui->CPlot->graph()->addData(xx,yy);
    ui->CPlot->graph()->setPen(QPen(Qt::blue));
    ui->CPlot->xAxis->setRange(0,26);
    ui->CPlot->yAxis->setRange(minimo-0.1, maximo+0.1);
    ui->CPlot->xAxis->setLabel("Time");
    ui->CPlot->yAxis->setLabel("ppg");
    ui->CPlot->replot();
    ui->CPlot->saveJpg("image",100,50,2,-1,96);

}

void graph::setupFFTDataPlot(QVector <double> data, int N)
{
qDebug()<<data.size();
qDebug()<<N;

ui->CPlot->addGraph();
ui->CPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
ui->CPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
ui->CPlot->addGraph();
ui->CPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph



// generate some points of data (y0 for first, y1 for second graph):
  QVector<double> x0, y0, y1;


    //****************FFT****************************

 // oldest_data = in[idx];
 // newest_data = in[idx] = data;// */ double(rand() / double(N));



 QVector <double> delta;


 for (int var = 0; var < N-1; ++var) {
     double b= (data.at(var+1)-data.at(var));
     delta.append(b);
 }

qDebug()<<delta.size();


std::complex<double> freqs[N-2], coeffs [N];

      int ci= 0;



  for (int i = 0; i < N-2; ++i)
  {
          //std::cout <<"ci ......"<<ci<<"\n";
          freqs[i] += delta.at(i) /* * coeffs[ci] */;
qDebug()<<delta.at(i);
qDebug()<<"sellsdalskdlasdlkasd;fnmadngjdfnabv";
qDebug()<<freqs[i].imag();

            }




 // QVector <double> powr1[N/2];

  // bump global index
 //*********************************************

  for (int i=0; i<N; i++)
 {
   x0[i] = i;
   y0[i] =freqs[i].real()+20;

   qDebug()<<x0.size();
   qDebug()<<y0.size();
 }
 // configure right and top axis to show ticks but no labels:
 // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
ui->CPlot->xAxis2->setVisible(true);
ui->CPlot->xAxis2->setTickLabels(false);
ui->CPlot->yAxis2->setVisible(true);
ui->CPlot->yAxis2->setTickLabels(false);
 // make left and bottom axes always transfer their ranges to right and top axes:
 connect(ui->CPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->CPlot->xAxis2, SLOT(setRange(QCPRange)));
 connect(ui->CPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->CPlot->yAxis2, SLOT(setRange(QCPRange)));

 // pass data points to graphs:
ui->CPlot->graph(0)->setData(x0, y0);
 ui->CPlot->graph(1)->setData(x0, y1);
 // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
 ui->CPlot->graph(0)->rescaleAxes();
 // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
 ui->CPlot->graph(1)->rescaleAxes(true);
 // Note: we could have also just called customPlot->rescaleAxes(); instead
 // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
 ui->CPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}






graph::~graph()
{
    delete ui;
}
