#include <iostream>

using namespace std;


class Mode
{
  public:
    Mode();
    ~Mode();

    string getMode();
    string gameMode;

  private:
    char *myQueue;
};
