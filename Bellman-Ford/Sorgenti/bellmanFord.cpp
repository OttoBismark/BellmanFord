#include <iostream>
#include <list>
#include <climits>
#include "grafo.h"
#include "vertice.h"
#include "bellmanFord.h"
#include "arco.h"

using namespace std;

/*Costruttore della classe BellmanFord*/
BellmanFord::BellmanFord()
{}

/*Distruttore della classe BellmanFord*/
BellmanFord::~BellmanFord()
{}

/*

Algoritmo di Bellman - Ford

*/
bool BellmanFord::pathfind(Grafo *g, int source)
{
  /*Ottengo il numero di vertici totali del nodo*/
  int V = g->getVertex();
  /*
  Vettore delle distanze di gradenzza V, ossia tanto lungo quanti sono i
  vertici del grafo
  */
  int d[V];

  /*
  Inizializzazione del vettore delle distanza, le cui i-esime componenti
  viene impostata a INT_MAX
  */
  for(int i = 0; i < V; i++)
  {
    d[i] = INT_MAX;
  }

  /*Inizializzazione della sorgente a zero*/
  d[source] = 0;

  /*Dichiarazione della lista di adiacenze*/
  list<Arco *> *e = g->getAdj();
  /*Dichiarazione dell'iteratore*/
  list<Arco *>::iterator it;

  /*Iterazione di tutti i V-1 vertici del grafo*/
  for(int i = 0; i < V; i++)
  {
    /*Scorrimento della lista di adiacenze per ogni i-esimo vertice del grafo*/
    for(it = e->begin(); it != e->end(); it++)
    {
      /*Ottengo i valori dei singoli vertici "u", e "v" e peso "w"*/
      int u = (*it)->getU()->getValore();
      int v = (*it)->getV()->getValore();
      int w = (*it)->getW();

      /*Rilassamento: se il vertice "u" ha valore diverso da INT_MAX e la somma
      del vettore "u" più il peso è numore di "u", allora aggiornare il valore
      del nodo "v"*/
      if(d[u] != INT_MAX && d[v] > d[u] + w)
      {
        d[v] = d[u] + w;
      }
    }
  }

  list<Arco *> *ee = g->getAdj();
  list<Arco *>::iterator itt;

  /*Seconda iterazione per verificare se ci sono cicli negativi o meno.
  L'algoritmo di BellmanFord ritorna true se non ci sono cicli negativi.
  Altrimenti ritorna false se esiste almeno un valore il cui ciclo risulta
  essere negativo*/
  for(itt = ee->begin(); itt != ee->end(); itt++)
  {
    int u = (*itt)->getU()->getValore();
    int v = (*itt)->getV()->getValore();
    int w = (*itt)->getW();

    if(d[u] != INT_MAX && d[v] > d[u] + w)
    {
      return false;
    }
  }

  return true;
}
