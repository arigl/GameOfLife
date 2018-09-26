#include <iostream>
#include <fstream>

using namespace std;

class Main
{
  public:
    Main();
    ~Main();

    string getFileName();
    int getType();

    int width;
    int height;
    int route;
    double density;

    ifstream inFile; // Taking in the File
    string fileName;



  private:
    char *myQueue;
};
