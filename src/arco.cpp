#include <iostream>
#include "../include/arco.h"
#include "../include/vertice.h"

using namespace std;

/*Costruttore della classe Arco a parametri*/
Arco::Arco(Vertice *u, Vertice *v, int w)
{
  this->u = u;
  this->v = v;
  this->w = w;
}

/*Distruttore della classse Arco*/
Arco::~Arco()
{}

/*Metodo setU per settare il vertice "u"*/
void Arco::setU(Vertice *u)
{
  this->u = u;
}

/*Metodo setV per settare il vertice "v"*/
void Arco::setV(Vertice *v)
{
  this->v = v;
}

/*Metodo setW per settmare il peso "w"*/
void Arco::setW(int w)
{
  this->w = w;
}

/*Metodo che ritorna il vertice U*/
Vertice *Arco::getU()
{
  return u;
}

/*Metodo che ritorna il vertice V*/
Vertice *Arco::getV()
{
  return v;
}

/*Metodo che ritorna il peso w dell'arco*/
int Arco::getW()
{
  return w;
}
