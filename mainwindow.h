#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_valider_clicked();

    void on_pb_supprimer_clicked();

private:
    Ui::MainWindow *ui;
    Produit p;
};
#endif // MAINWINDOW_H
