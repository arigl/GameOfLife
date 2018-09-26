#include <iostream>
#include <fstream>
#include "Main.h"

using namespace std;

// Main Class
Main::Main(){
}

Main::~Main(){
  cout << "Main has been destroyed" << endl;
}

int Main::getType(){
  cout << "Would you like to import a file, or make a random grid? (1 for import, 0 for random) " << endl;
  cin >> route;
  if (route == 1){
    cout << "1" << endl;
    return 1;
  }
  if (route == 0){
    cout << "0" << endl;
    return 0;
  }
  else{
    cout << "Choose a valid option, random will be default" << endl;
    return 0;
  }
}
