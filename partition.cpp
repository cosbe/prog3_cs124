// my first program in C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> A;
vector<int> random_P(int);
int karmarkarKarp(vector<int>);
int a_karmarkar_karp(vector<int>);
int repeated_random(vector<int>);
int hill_climbing(vector<int>);
int sim_anneal(vector<int>);

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

    printf("Printing the matrix A: \n");
    for(int i = 0; i < A.size(); i++) {
        printf("i is: %i and val: %d \n", i,  A[i]);
    }

//   // Record amount of time it takes for each algorithm
//   kar_karp (sorted L)
//   repeated_random P
//   hill_climbing P
//   sim_anneal P

    // Generating initial random solution
    vector<int> p = random_P(A.size());

    printf("Printing the rand P: \n");
    for(int i = 0; i < p.size(); i++) {
        printf("i is: %i and val: %d \n", i,  p[i]);
    }

    int resid = karmarkarKarp(A);
    std::cout << "\nresidual: " << resid << "\n";
}

// Generates a random solution sequence P
vector<int> random_P(int n) {
  vector<int> vect(n, -1);

  for (int i = 0; i < n; i++) {
    vect[i] = (rand() % n) + 1;
  }

  return vect;
}

// Karmarkar Karp with P and A'
int a_karmarkar_karp (vector<int> p) {
    // create A' based on P and A
    vector<int> ap(p.size(), 0);
    for(int i = 0; i < p.size();  i++) {
        ap[p[i]]+=A[i];
    }

    printf("AP is: \n");
    for(int i = 0; i < ap.size(); i++) {
        printf("i is: %i and val: %d \n", i, ap[i]);
    }

    return(karmarkarKarp(ap));
}

// Pure Karmarkar Karp on A
int karmarkarKarp(vector<int> a) {
    // Sorting input
    sort(a.begin(), a.end(), greater<int>());

    // Karmarkar Karp
    while(a.size()>1) {
        //delete all zeroes
        while(a.back() == 0){
            a.pop_back();
        }
        if(a.size() <= 1) {
            break;
        }
        //subtract second largest from largest
        a[0]-= a[1];
        //replace second largest with 0
        a[1] = 0;
        //sort again
        sort(a.begin(), a.end(), greater<int>());
    }
    if(a.size() == 0) {
        a.push_back(0);
    }
    //returns residual
    return a[0];
}

int repeated_random(vector<int> p) {
  // for iter 1 to 25,000
  // S' = random_P
  // if kar_karp S' < kar_karp S then S = S'
  // return S
    void;
}

int hill_climbing(vector<int> p) {
    void;
}

int sim_anneal(vector<int> p) {
    void;
}
