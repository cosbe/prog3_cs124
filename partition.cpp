// my first program in C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int[] A;

int** random_P(int**, int**, int);


int main(int argc, char *argv[])
{
    int flag = atoi(argv[1]);

    int algorithm = atoi(argv[2]);

    string fileName = argv[3];
    ifstream inputFile;
    inputFile.open(fileName);
       // store into A
    inputFile.close();

  given file, read from it to get list L of 100 ints.

  create initial random P (generate sequence of n values from range [1,n])

  // Record amount of time it takes for each algorithm
  kar_karp (sorted L)
  repeated_random P
  hill_climbing P
  sim_anneal P


  std::cout << "Hello World!";
}

// Generates a random solution sequence P
int[] random_P(int n) {

}

//runs karmarkarkarp on the algorithm
int[] karmarkarKarp(vector<int> p) {
  // create A' based on P and A
  // sort A'
  // pseudo for kar_karp
    void;
}

int[] repeated_random(int[] part) {
  // for iter 1 to 25,000
  // S' = random_P
  // if kar_karp S' < kar_karp S then S = S'
  // return S
    void;
}

int[] hill_climbing(int[] part) {
    void;
}

int[] sim_anneal(int[] part) {
    void;
}


