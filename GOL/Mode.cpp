#include <iostream>
#include "Mode.h"

using namespace std;

// Mode Class
Mode::Mode(){

}

Mode::~Mode(){

}

string Mode::getMode(){
  cout << "Which mode would you like to play? (1 for Classic, 2 for Doughnut, 3 for Mirror)" << endl;
  cin >> gameMode;

  return gameMode;
}
