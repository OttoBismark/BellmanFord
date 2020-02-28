#include <iostream>
#include <string>
#include "../include/concreteTemplate.h"

using namespace std;

/*Main del programma*/
int main(int argc, char **argv)
{
  /*Costruzione del template method */
  abstractTemplate *templateMenu = new concreteTemplate();
  /*Chiamata del metodo executeTemplate()*/
  templateMenu->executeTemplate();
  /*Deallocazione dell'istanza templateMenu*/
  delete templateMenu;
}
