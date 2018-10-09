#include <iostream>
#include <list>
#include <climits>
#include <map>
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
void BellmanFord::pathfind(Grafo *g, int source)
{
  bool negative = true;
  /*Ottengo il numero di vertici totali del nodo*/
  int V = g->getVertex();
  /*
  Vettore delle distanze di gradenzza V, ossia tanto lungo quanti sono i
  vertici del grafo
  */
  int d[V];
  int p[V];


  /*
  Inizializzazione del vettore delle distanza, le cui i-esime componenti
  viene impostata a INT_MAX
  */
  for(int i = 0; i < V; i++)
  {
    d[i] = INT_MAX;
    p[i] = -1;
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
      del vettore "u" più il peso è numore di "v", allora aggiornare il valore
      del nodo "v"*/
      if(d[u] != INT_MAX && d[v] > d[u] + w)
      {
        d[v] = d[u] + w;
        p[v] = u;
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
      negative = false;
    }
  }


  if(negative)
  {
    cout << "\n\t\tNon ci sono cicli negativi" << endl;
    cout << "Vettore delle distanze: " << endl;
    for(int i = 0; i < V; i++)
    {
      if(d[i] != 0)
      {
        cout << d[i] << " -> ";
      }
    }

    cout << "\n\n";

    list<int> l;
    l.push_back(source);

    while(!l.empty())
    {
      int x = l.back();
      l.pop_back();

      for(int i = 0; i < V; i++)
      {
        if(x == p[i])
        {
          cout << "Dal vertice " << x << " verso " <<" -> " << i
          << " con distanza --> " << d[i] << endl;
          l.push_back(i);
        }
      }
    }
  }
  else
  {
    cout << "\n\t\tSono presenti cicli negativi" << endl;
    return;
  }

  cout << "\n";
}
