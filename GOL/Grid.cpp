#include <iostream>
#include "Grid.h"
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

// Grid Class
Grid::Grid(){
}

Grid::Grid(int width,int height){
}

Grid::~Grid(){

}

int Grid::getDimensions(){
  cout << "What would you like for the width of your grid?" << endl;
  cin >> width;
  cout << "What would you like for the height of your grid?" << endl;
  cin >> height;
  cout << "What would you like for the density of your grid?" << endl;
  cin >> density;

  return 0;
}

string Grid::getFileName(){
  cout << "What is the name of your file?" << endl;
  cin >> fileName;
  return fileName;
}

char* Grid::makeRandom(){
  char board[width][height];
  //char DArray[width][height];
  //board* = DArray;

  cout << width << " width" << endl;
  cout << height << " height" << endl;
  cout << density << " density" << endl;

  for (int i = 0; i < width; i++){
    for (int x = 0; x < height; x++){
      random = (int)(rand() * 100.0)/100.0;
      if (random > (double)density){
        board[i][x] = 'X';
      }
      else{
        board[i][x] = '-';
      }
    }
  }

  for (int r = 0; r < width; r++){
    for (int e = 0; e < height; e++){
      cout << board[r][e]  << "  ";
    }
    cout << endl;
  }

  // if random number is bigger than density for the size, make a cell
  return *board;
}
int Grid::makeFile(){
  inFile.open(fileName);
  // look for width in first row
  // Look for height in second row

  // Get the characters from the file and make the grid
  // return the grid
}
