#include <iostream>
#include <list>
#include <string>
#include "vertice.h"
#include "arco.h"
#ifndef GRAFO_H
#define GRAFO_H

using namespace std;

/*Classe Grafo*/
class Grafo
{
private:
  /*V = Numero di vertici*/
  int V;
  /* list *adj = lista di adiacenze*/
  list<Arco *> *adj;

public:
  /*Costruttore*/
  Grafo(string fileName);
  /*Distruttore*/
  virtual ~Grafo();
  void addEdge(int u, int v, int w);
  void getListAdj();
  void setVertex(int V);
  int getVertex();
  list< Arco *> *getAdj();
};

#endif
