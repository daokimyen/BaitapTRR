#include <iostream>

using namespace std;

class Graph
{
private:
    int *Dinh;
    int soDinh;

public:
    Graph();
    ~Graph();
    void init();


    
    void canhDoThi( int x, int y);
    void docFile();
};