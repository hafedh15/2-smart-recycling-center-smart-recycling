#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QString>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tap_produit->setModel(p.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_valider_clicked()
{

    QString type=ui->lineEdit_type->text();
    QString dater=ui->lineEdit_date->text();
    int id=ui->lineEdit_code->text().toInt();
    int quantity=ui->lineEdit_date_3->text().toInt();
    int prix=ui->lineEdit_date_4->text().toInt();
    Produit p(type,dater,id,quantity,prix);
    bool test=p.ajouter();
    QMessageBox msgBox;
    if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n""click cancel to exit ."),QMessageBox::Cancel);
            ui->tap_produit->setModel(p.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
            QObject::tr("ajout non effectue\n""click cancel to exit ."),QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    Produit p1;
    p1.setid(ui->lineEdit_code_supp->text().toInt());
    bool test=p1.supprimer(p1.getid());
    if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("suppression effectue\n""click cancel to exit ."),QMessageBox::Cancel);
            ui->tap_produit->setModel(p.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
            QObject::tr("suppression non effectue\n""click cancel to exit ."),QMessageBox::Cancel);
}


