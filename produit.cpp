#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
Produit::Produit()
{

    type="";
    dater="";
    quantity=0;
    prix=0;
    id=0;
}
Produit::Produit(QString type,QString dater,int id,int quantity,int prix)
{
    this->type=type;
    this->id=id;
    this->dater=dater;
    this->quantity=quantity;
    this->prix=prix;
}
QString Produit::gettype()
{
    return type;
}
QString Produit::getdater()
{
    return dater;
}
int Produit::getid(){
return id;
}
int Produit::getquantity()
{
    return quantity;
}
int Produit::getprix()
{
    return prix;
}
void Produit::settype(QString type)
{this->type=type;}

void Produit::setdater(QString dater)
{this->dater=dater;}
void Produit::setid(int id)
{this->id=id;}
void Produit::setquantity(int quantity)
{this->quantity=quantity;}
void Produit::setprix(int prix)
{this->prix=prix;}
bool Produit::ajouter()
{

 QSqlQuery query;
 QString res=QString::number(id);
 QString res1=QString::number(quantity);
 QString res2=QString::number(prix);
               query.prepare("insert into produit(id,type,dater,quantity,prix)" "values ( :id, :type, :dater,  :quantity, :prix)");
               query.bindValue(":id",res);
               query.bindValue(":type",type);
               query.bindValue(":date",dater);
               query.bindValue(":quantity",res1);
               query.bindValue(":prix",res2);
              return query.exec();

}
QSqlQueryModel * Produit::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM produit ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantity"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

return model;
}
bool Produit::supprimer(int id)
{
QSqlQuery query;
QString res=QString::number(id);
query.prepare("delete from produit where ID=:id");
query.bindValue(0,id);
return query.exec();
}

