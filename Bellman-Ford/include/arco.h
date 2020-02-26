#include <iostream>
#include "vertice.h"
#ifndef ARCO_H
#define ARCO_H

using namespace std;

/*Classe Arco*/
class Arco
{
private:
  /*Attributi "Vertice "u" e "v" */
  Vertice *u, *v;
  /*Attributo "w" che indicherà il valore dell'arco tra i due vertici*/
  int w;
public:
  /*Costruttore a parametri della classe Arco*/
  Arco(Vertice *u, Vertice *v, int w);
  /*Distruttore della classe Arco*/
  virtual ~Arco();
  void setU(Vertice *u);
  void setV(Vertice *v);
  void setW(int w);
  Vertice *getU();
  Vertice *getV();
  int getW();
};

#endif
