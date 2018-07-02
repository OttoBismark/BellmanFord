#include <iostream>
#ifndef VERTICE_H
#define VERTICE_H

using namespace std;

/*Classe Vertice*/
class Vertice
{
private:
  /*Valore del singolo vertice*/
  int valore;

public:
  /*Costruttore della classe Vertice*/
  Vertice();
  /*Distruttore della classe vertice*/
  virtual ~Vertice();
  void setValore(int valore);
  int getValore();
};

#endif
