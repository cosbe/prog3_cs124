// my first program in C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int[] A; 

int main(int argc, char *argv[])
{
    int flag = atoi(argv[1]); 

    int algorithm = atoi(argv[2]); 

    string fileName = argv[3];
    ifstream inputFile;
    inputFile.open(fileName);

    
    inputFile.close();
  std::cout << "Hello World!" << " " << flag << " " << algorithm << " " << fileName ;
}

//runs karmarkarkarp on the algorithm
int[] karmarkarKarp(vector<int> p) {
    void; 
}

int[] repeated_random(int[] part) {
    void;
}

int[] hill_climbing(int[] part) {
    void;
}

