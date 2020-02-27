#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "vertice.h"
#include "arco.h"
#include "grafo.h"

using namespace std;

/*Costruttore della classe grafo*/
Grafo::Grafo(string fileName)
{
  /*Buffer del file*/
  string buffer;
  /* Oggetto della classe fstream per caricare il file da input */
  fstream file;
  /*Indici del grafo. Rispettivamente, vertici(u,v) e peso w*/
  int u, v, w;

  file.open(fileName, ios::in | ios::binary);

  if(!file.is_open())
  {
    cerr << "File inesistente." << endl;
    exit(-1);
  }
  else
  {
    cout << "File aperto" << endl;
  }
  /*Acquisisco la prima riga dal file*/
  getline(file, buffer, '\n');
  /*
  Copio il primo valore del file di testo che conterrà il numero complessivo
  di nodi del Grafo
  */
  this->V = atoi(buffer.c_str());
  cout << "Numero nodi del grafo ->" << V << endl;
  /*Creazione della lista di adiacenze*/
  adj = new list<Arco *>;

  /*
  Scorro riga per riga il file di testo e inserisco i vertici e la funzione
  costo del peso dell'arco che collega due vertici
  */
  while(file >> u >> v >> w)
  {
    getline(file, buffer, '\n');
    Vertice *x = new Vertice();
    Vertice *y = new Vertice();
    x->setValore(u);
    y->setValore(v);
    Arco *e = new Arco(x, y, w);
    adj->push_back(e);
  }
  file.close();
}

/*Metodo che setta manualmente il grafo*/
void Grafo::addEdge(int u, int v, int w)
{
  Vertice *x = new Vertice();
  Vertice *y = new Vertice();
  x->setValore(u);
  y->setValore(v);
  Arco *e = new Arco(x, y, w);
  adj->push_back(e);
}

/*Metodo che ci permette di visualizzare a video gli indici dei nodi e i pesi
degli archi */
void Grafo::getListAdj()
{
  /*Iteratore che itera nella lista di archi per vedere i loro collegamenti*/
  list<Arco *>::iterator it;

  cout << "Sorgente - " << "Destinazione - " << "Peso" << endl;

  for(it = adj->begin(); it != adj->end(); it++)
  {
    cout << (*it)->getU()->getValore() <<"\t\t" << (*it)->getV()->getValore()
    << "\t" << (*it)->getW() << endl;
  }
}

/*Metodo che ritorna la lista di adiacenze del grafo*/
list<Arco *> *Grafo::getAdj()
{
  return adj;
}

/*Metodo per settare i vertici*/
void Grafo::setVertex(int V)
{
  this->V = V;
}

/*Metodo per ottenere i numero totale di vertici*/
int Grafo::getVertex()
{
  return V;
}

/*Distruttore della classe grafo*/
Grafo::~Grafo()
{
  delete adj;
}
