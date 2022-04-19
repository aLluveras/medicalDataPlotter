#include "verdb.h"
#include "ui_verdb.h"



verDB::verDB(QWidget *parent) :
    Paciente(parent),
    ui(new Ui::verDB)
{
    ui->setupUi(this);
setAttribute(Qt::WA_DeleteOnClose);

    /*Selection *sel;
sel=new Selection(this);*/

   // sel->hide();

    QTableView*views = ui->tableView;
    views->setModel(model);


   /* if (verDB::close()==true)
    {
        Selection *sel;
                sel=new Selection(this);
                 sel->show();
    }*/

}






verDB::~verDB()
{
    delete ui;
}


