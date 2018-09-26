#include "Grid.h"
#include "Main.h"
#include "Mode.h"
#include "Simulation.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  // Initiliaze Main
  int type;

  Main m;
  type = m.getType();
  Grid g;
  if (type == 1){
    g.getFileName();
    g.makeFile();
  }
  if (type == 0){
    g.getDimensions();
    g.makeRandom();
  }

  Mode gm();

  Simulation s();

  return 0;
}
