#include <iostream>
#include "../include/vertice.h"

using namespace std;

/*Costruttore della classe Vertice*/
Vertice::Vertice()
{}

/*Metodo per settare il valore del vertice*/
void Vertice::setValore(int valore)
{
  this->valore = valore;
}

/*Metodo che ritorna il valore del vertice*/
int Vertice::getValore()
{
  return valore;
}

/*Distruttore della classe Vertice*/
Vertice::~Vertice()
{}
