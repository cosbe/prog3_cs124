// my first program in C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> A;
vector<int> random_P(int);

int main(int argc, char *argv[]) {
  srand((unsigned) time(0));

  int flag = atoi(argv[1]);
  int algorithm = atoi(argv[2]);
  //testing purposes
  int n = atoi(argv[3]);

  // vector<int> vect = random_P(n);

  // for (int i = 0; i < n; i++) {
  //   cout << vect.at(i) << '\n';
  // }

//   // Record amount of time it takes for each algorithm
//   kar_karp (sorted L)
//   repeated_random P
//   hill_climbing P
//   sim_anneal P

  std::cout << "Hello World!";
}

// Generates a random solution sequence P
vector<int> random_P(int n) {
  vector<int> vect(n, -1);

  for (int i = 0; i < n; i++) {
    vect[i] = (rand() % n) + 1;
  }

  return vect;
}

// Runs karmarkarkarp on the algorithm
vector<int> karmarkarKarp(vector<int> p) {
  // create A' based on P and A
  // sort A'
  // pseudo for kar_karp
    void;
}

vector<int> repeated_random(int[] part) {
  // for iter 1 to 25,000
  // S' = random_P
  // if kar_karp S' < kar_karp S then S = S'
  // return S
    void;
}

vector<int> hill_climbing(int[] part) {
    void;
}

vector<int> sim_anneal(int[] part) {
    void;
}
