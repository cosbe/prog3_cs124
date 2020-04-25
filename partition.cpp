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
int max_iter = 25000;

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

    switch (algorithm) {
      case 0:
        std::cout << "\nresidual: " << karmarkarKarp(A) << "\n";
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 11:
        std::cout << "\n residual for prr: " << repeated_random(p) << "\n";
        break;
      case 12:
        break;
      case 13:
        break;
    }
}

// Generates a random solution sequence P
vector<int> random_P(int n) {
  vector<int> vect(n, -1);

  for (int i = 0; i < n; i++) {
    vect[i] = (rand() % n + 1);
  }

  return vect;
}

// Karmarkar Karp with P and A'
int a_karmarkar_karp (vector<int> p) {
    // create A' based on P and A
    vector<int> ap(p.size(), 0);
    for(int i = 0; i < p.size();  i++) {
        ap[p[i] - 1]+=A[i];
    }

    printf("AP is: \n");
    for(int i = 0; i < ap.size(); i++) {
        printf("i is: %i and val: %d \n", i, ap[i]);
    }

    return(karmarkarKarp(ap));
}

// Pure Karmarkar Karp on A
int karmarkarKarp(vector<int> a) {

    // Karmarkar Karp
    while(a.size()>1) {
        // Sort input
        sort(a.begin(), a.end(), greater<int>());

        //delete all zeroes, keeping the 0 if it is the only element in the array
        while(a.back() == 0 && a.size() > 1){
            a.pop_back();
        }

        if(a.size() <= 1) {
            return a[0];
        }
        //subtract second largest from largest
        a[0]-= a[1];
        //replace second largest with 0
        a[1] = 0;
    }

    return a[0];
}

int repeated_random(vector<int> p) {
    vector<int> s;
    s = p;
    int sk = a_karmarkar_karp(s);

    for (int i = 0; i < max_iter; i++) {
        // Generate randomn solution
        vector<int> sp = random_P(p.size());
        int spk = a_karmarkar_karp(sp);
        if (spk < sk) {
            s = sp;
            sk = spk;
        }
    }
    return (sk);
}

int hill_climbing(vector<int> p) {
    void;
}

int sim_anneal(vector<int> p) {
    void;
}
