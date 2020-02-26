#include <iostream>
#include <list>
#include "grafo.h"
#include "vertice.h"
#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

using namespace std;

/*Classe BellmanFord*/
class BellmanFord
{
	public:
		/*Costruttore*/
		BellmanFord();
		/*Distruttore della classe BellmanFord utilizzando un distruttore virtuale*/
		virtual ~BellmanFord();
		/*Metodo pathfind() per eseguire l'algoritmo di BellmanFord*/
		void pathfind(Grafo *g, int source);
};

#endif
