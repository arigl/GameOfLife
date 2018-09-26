#include <iostream>
#include <fstream>
using namespace std;


class Grid
{
  public:
    Grid();
    Grid(int widthm,int heightm);
    ~Grid();
    char* makeRandom();

    int makeFile();
    int getDimensions();
    string getFileName();
    string fileName;

    ifstream inFile;

    int width;
    int height;
    double density;
    double random;

  private:
    char *myQueue;
};
