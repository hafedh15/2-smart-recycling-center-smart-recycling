#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Produit
{
    QString type,dater;
    int id,quantity,prix;
public:
    Produit();
    Produit(QString,QString,int,int,int);
        QString gettype();
        QString getdater();
        int getid();
        int getquantity();
        int getprix();
        void settype(QString);
        void setdater(QString);
        void setid(int);
        void setquantity(int);
        void setprix(int);
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int );
};

#endif // PRODUIT_H
