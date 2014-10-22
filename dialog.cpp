#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(true);
    connect(ui->expected_sb1,SIGNAL(valueChanged(double)),this,SLOT(checkForm()));
    connect(ui->expected_sb2,SIGNAL(valueChanged(double)),this,SLOT(checkForm()));
    connect(ui->deviation_sb1,SIGNAL(valueChanged(double)),this,SLOT(checkForm()));
    connect(ui->deviation_sb2,SIGNAL(valueChanged(double)),this,SLOT(checkForm()));
    connect(ui->size_sb1,SIGNAL(valueChanged(int)),this,SLOT(checkForm()));
    connect(ui->size_sb2,SIGNAL(valueChanged(int)),this,SLOT(checkForm()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(accept()));
}

void Dialog::checkForm()
{
    bool result = ui->expected_sb1->value() && ui->expected_sb2->value() &&
            ui->deviation_sb1->value() && ui->deviation_sb2->value() &&
            ui->size_sb1->value() && ui->size_sb2->value();

    if(result)
    {
        ui->pushButton->setEnabled(true);
    }
}

sample Dialog::getParam(int i)
{
    sample s;
    if(i==1)
    {
        s.size=ui->size_sb1->value();
        s.deviation=ui->deviation_sb1->value();
        s.expected=ui->expected_sb1->value();
    }else{
        s.size=ui->size_sb2->value();
        s.deviation=ui->deviation_sb2->value();
        s.expected=ui->expected_sb2->value();
    }
    return s;
}

double Dialog::getALevel(){
    return ui->level_sb->value();
}

Dialog::~Dialog()
{
    delete ui;
}
