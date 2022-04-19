#include "paciente.h"
#include "ui_paciente.h"

Paciente::Paciente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Paciente)
{
    ui->setupUi(this);
//setAttribute(Qt::WA_DeleteOnClose);
    QDir archivo;
    archivo.setPath("//home//lluveras//");
   QString filename = archivo.path() + QDir::separator() + "pacientes.db";
    if (!createDB(filename)){
        QMessageBox::critical(this, tr("No se encuentra la DB"),
                              tr("No se encuentra la DB, la aplicació se cerrará"),
                              QMessageBox::Ok);
        qApp->exit();
    }}

    //**********************************************************************************************************************************
    //**********************************************************************************************************************************

    bool Paciente::createDB(QString DBname)
    {
        DB = QSqlDatabase::addDatabase("QSQLITE");
        DB.setDatabaseName(DBname);

        if (DB.open()) {
               bool found = false;

                foreach (QString table, DB.tables()) {

                         if (table =="pacientes") {
                                 found = true;
                                    break;
                                                    }
                                                            }
                if (!found) {

                        QSqlQuery query(DB);
                        query.exec("CREATE TABLE pacientes (NOMBRE VARCHAR(50) NOT NULL, "
                                   "APELLIDOS VARCHAR(50) NOT NULL, IDENTIDAD  VARCHAR(15) NOT NULL, "
                                   "SEXO VARCHAR(1) NOT NULL, NACIMIENTO VARCHAR(14) NOT NULL, PPG BLOB)");
                                       }

                model = new QSqlTableModel (this,DB);
                model->setTable("pacientes");
                model->setEditStrategy(QSqlTableModel::OnFieldChange);
                model->select();

                filtered = new QSqlTableModel (this,DB);
                filtered->setTable("pacientes");
                filtered->setEditStrategy(QSqlTableModel::OnFieldChange);
                filtered->select();
                     }
        else
            return false;

        return true;    }


    //**********************************************************************************************************************************
    //**********************************************************************************************************************************



    void Paciente::VerDetalles()
    {   QTreeView *view = ui->treeView;

        filtered->removeColumn(5);

        view->setModel(filtered);

                 }

    //******************************************************
    //******************************************************

    void Paciente::Salvar(){

        QString NOMBRE = ui->Nombre->toPlainText();
        QString APELLIDOS = ui->Apellidos->toPlainText();
        long long IDENTIDAD = ui->ID->toPlainText().toLongLong();
        QString SEXO;
        QDate NACIMIENTO;
        QByteArray PPG;


        NuevoPaciente(NOMBRE, APELLIDOS, IDENTIDAD, SEXO, NACIMIENTO, PPG);

        }

    //******************************************************
    //******************************************************


void Paciente::Borrar(){

QModelIndex sample = ui->treeView->currentIndex();
if (sample.row()>=0) {
    QMessageBox::StandardButton dlg;
    dlg = QMessageBox::question(this, tr("Remover Paciente"),
                                QString(tr("Remover Paciente ?")),
                                QMessageBox::Yes | QMessageBox::No);
    if (dlg == QMessageBox::Yes) {
        model->removeRow(sample.row());
    }
         }
                }

    //************************************************************************************************
    //************************************************************************************************

void Paciente::NuevoPaciente(QString Name, QString LName, long long ID, QString Sex, QDate Birth, QByteArray ppg)
{
    QSqlRecord rec = model->record();
    rec.setValue("NOMBRE",Name);
    rec.setValue("APELLIDOS",LName);

// load image
    QDir folderName;
    folderName.setPath("//home//lluveras//");
    QFile nameimg (folderName.path() + QDir::separator() + "image");
    nameimg.open(QIODevice::ReadWrite);
    ppg = nameimg.readAll();
    rec.setValue("PPG",ppg);

// data from id number

    int d1=ID/100000;   int d2=d1%100;   int m1=ID/10000000;   int m2=m1%100;   int m3=m1/100;
    QString q = "0" ;
    QString qq = "00" ;
    QString qqq = "000" ;

    if ( 10000000<ID && ID<=99999999999 && d2<=31 && m2<=12 && m2!=0 && d2!=0) {

            if (0<m2 && m2<10 && m3 == 0) {rec.setValue("IDENTIDAD",qqq.append(QString::number(ID)));}
        else if (10<m2  && m3 == 0) {rec.setValue("IDENTIDAD",qq.append(QString::number(ID)));}
        else if (0<m3 && m3<10) {rec.setValue("IDENTIDAD",q.append(QString::number(ID)));}
        else rec.setValue("IDENTIDAD",ID);

    }
     else
     { QMessageBox::information(this,"ADVERTENCIA","ID Inválida");}



//sex from id number
    long long pt, xt;    pt=ID/10;    xt=pt%10;

    if (xt%2==0) {   Sex = "M";    }
    else         {   Sex = "F";    }
    rec.setValue("SEXO",Sex);


// birth date from id number
QDate FECHA;
int year, month, day, c1, f;

        year= m3;
        month= m2;
        day= d2;
        f= FECHA.currentDate().year();
        c1=f-2000;


   if (year<c1) { year=year+2000; }
   else year=year+1900;

    Birth.setDate(year,month,day);
    rec.setValue("NACIMIENTO",Birth);



            model->insertRecord(-1,rec);
            ui->Nombre->setText("");
            ui->Apellidos->setText("");
            ui->ID->setText("");




}

    //******************************************************
    //******************************************************


Paciente::~Paciente()
{
    delete ui;
}

void Paciente::on_VER_clicked()
{

VerDetalles();

}

void Paciente::on_Borrar_clicked()
{
Borrar();
}

void Paciente::on_Salvar_clicked()
{
Salvar();
}

void Paciente::on_PPG_clicked()
{  //Paciente::hide();

    grap = new graph (this);
    grap->show();
}
