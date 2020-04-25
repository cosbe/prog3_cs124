// my first program in C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> A;

// Generates a random solution sequence P
vector<int> random_P(int n) {
  vector<int> vect(n, -1);

  for (int i = 0; i < n; i++) {
    vect[i] = (rand() % n) + 1;
  }

  return vect;
}

// Runs karmarkarkarp on the algorithm
int karmarkarKarp(vector<int> p) {
    // create A' based on P and A

    vector<int> ap(p.size(), 0);
    for(int i = 0; i < p.size();  i++) {
        ap[p[i]]+=A[i];
    }
    // sort A'
    sort(ap.begin(), ap.end(), greater<int>());

    printf("AP is: \n");
    for(int i = 0; i < ap.size(); i++) {
        printf("i is: %i and val: %d \n", i, ap[i]);
    }

    // pseudo for kar_karp
    while(ap.size()>1) {
        //delete all zeroes
        while(ap.back() == 0){
            ap.pop_back();
        }
        if(ap.size() <= 1) {
            break;
        }
        //subtract second largest from largest
        ap[0]-= ap[1];
        //replace second largest with 0
        ap[1] = 0;
        //sort again
        sort(ap.begin(), ap.end(), greater<int>());
    }
    if(ap.size() == 0) {
        ap.push_back(0);
    }
    //returns residual
    return ap[0];
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

int main(int argc, char *argv[]) {
    srand((unsigned) time(0));

    int flag = atoi(argv[1]);
    int algorithm = atoi(argv[2]);
    // Reading file into vector A
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
    vector<int> p = random_P(A.size());
    printf("Printing the rand P: \n");
    for(int i = 0; i < p.size(); i++) {
        printf("i is: %i and val: %d \n", i,  p[i]);
    }
    printf("\n");

    int resid = karmarkarKarp(p);
    std::cout << "\nresidual: " << resid << "\n";
//   // Record amount of time it takes for each algorithm
//   kar_karp (sorted L)
//   repeated_random P
//   hill_climbing P
//   sim_anneal P

}