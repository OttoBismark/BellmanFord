#include "../include/abstractTemplate.h"
#include "../include/concreteTemplate.h"
#include "../include/bellmanFord.h"
#include "../include/grafo.h"
#include <iostream>

using namespace std;

/*
Implementazione dei metodi della classe concreteTemplate che sono incapsulati
dentro l'executeTemplate della classe astratta.
*/

/* Metodo intro() */
void concreteTemplate::intro()
{
  system("clear");
  cout << "*********************************************" << endl;
  cout << "*   Progetto di Algoritmi e Strutture dati  *" << endl;
  cout << "*   e Lab. di Algoritmi e Strutture Dati    *" << endl;
  cout << "*                                           *" << endl;
  cout << "*    Progetto di Pauciullo Valerio          *" << endl;
  cout << "*        Matricola: 0124001023              *" << endl;
  cout << "*       Anno Accademico 2017-2018           *"<< endl;
  cout << "*********************************************" << endl;

  cout << "Premere un tasto per continuare" << endl;
  cin.get();
}

/* Metodo menuApplication() */
void concreteTemplate::menuApplication()
{
  unsigned char c;
  short int corretto = 0;
  int V, vertice;
  BellmanFord *bf;
  string name;
  cout << endl;
  system("clear");
  cout << "*     Progetto 'Algoritmo di Bellman-Ford'    *" << endl;
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;
  cout << " Inserire file.txt" << endl;
  cin >> name;

  Grafo *g = new Grafo(name);

  cout << "\n";
  g->getListAdj();
  cout << "\n";
  cout << "\t\tGrafo creato e file caricato."<< endl;
  cout << "\t\tEseguire comando pathfind?"<< endl;
  cout << "Y/N" << endl;
  cin >> c ;

  if(c == 'y' || c == 'Y')
  {
    bf = new BellmanFord();
    V = g->getVertex();

    while(!corretto)
    {
      cout << "\n\n" << endl;
      cout << "Inserire indice del vertice sorgente" << endl;
      cout << "Inserire un numero da 0 a " << V-1 << endl;
      cin >> vertice;

      if(vertice > V-1)
      {
        cerr << "Errore! Numero di vertici incorretto" << endl;
        cerr << "Inserire un numero di vertici che va da 0 a " << V-1 << endl;
      }
      else
      {
        corretto = 1;
      }
    }

    bf->pathfind(g, vertice);
  }
  else
  {
    cout << "Uscita dal programma" << endl;
    delete g, bf;
    exit(1);
  }
  delete g;
}

/*Distruttore della classe "concreteTemplate"*/
concreteTemplate::~concreteTemplate()
{}
