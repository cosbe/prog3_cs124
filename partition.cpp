// my first program in C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> A;
vector<int> random_P(int);


int main(int argc, char *argv[])
{
    int flag = atoi(argv[1]);
    int algorithm = atoi(argv[2]);

    string fileName = argv[3];
    std::ifstream file(fileName);
       // store into A
    string k; 
    while (std::getline(file, k)){
        int i = stoi(k);
        A.push_back(i);
    }
    file.close();

//   given file, read from it to get list L of 100 ints.

// n values from range [1,n])

//   // Record amount of time it takes for each algorithm
//   kar_karp (sorted L)
//   repeated_random P
//   hill_climbing P
//   sim_anneal P

    for(int i = 0; i < A.size(); i++) {
        printf(" %d ", A[i]);
    }
}

// Generates a random solution sequence P
vector<int> random_P(int n) {

}

// Runs karmarkarkarp on the algorithm
vector<int> karmarkarKarp(vector<int> p) {
    // create A' based on P and A
    vector<int> ap(p.size(), 0);
    for(int i = 0; i < p.size();  i++) {
        ap[p[i]]+=A[i];
    }

    // sort A'
    sort(ap.begin(), ap.end(), greater<int>());
    for(int i = 0; i < ap.size(); i++) {
        printf(" %d ", ap[i]);
    }

    // pseudo for kar_karp
    void;
}

vector<int> repeated_random(vector<int> p) {
  // for iter 1 to 25,000
  // S' = random_P
  // if kar_karp S' < kar_karp S then S = S'
  // return S
    void;
}

vector<int> hill_climbing(vector<int> p) {
    void;
}

vector<int> sim_anneal(vector<int> p) {
    void;
}


