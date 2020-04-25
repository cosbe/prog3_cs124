// my first program in C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<long long> A;
vector<int> random_P(int, int);
vector<int> random_P(int);
int karmarkarKarp(vector<long long>);
int a_karmarkar_karp(vector<long long>);
int repeated_random(vector<long long> );
int hill_climbing(vector<long long> );
int sim_anneal(vector<long long> );
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
    vector<long long>  p;
    switch (algorithm) {
      case 0:
        std::cout << "\nresidual: " << karmarkarKarp(A) << "\n";
        break;
      case 1:
        p = random_P(A.size(),2);


        break;
      case 2:
        p = random_P(A.size(),2);


        break;
      case 3:

        p = random_P(A.size(),2);

        break;

        //pp
      case 11:
        p = random_P(A.size(), A.size());

        std::cout << "\n residual for prr: " << repeated_random(p) << "\n";
        break;
        //pp
      case 12:
        p = random_P(A.size(), A.size());

        std::cout << "\n residual for phc: " << hill_climbing(p) << "\n";
        break;
        //pp
      case 13:
        p = random_P(A.size(), A.size());

        break;
    }
}

// Generates a random solution sequence P with size n, values from 1 to n
vector<int> random_P(int n, int range) {
    vector<int> vect(n, -1);

    for (int i = 0; i < n; i++) {
        vect[i] = (rand() % range + 1);
    }
    printf("Printing the rand P: \n");
    for(int i = 0; i < vect.size(); i++) {
        printf("i is: %i and val: %d \n", i,  vect[i]);
    }

    return vect;
}

//range = n
vector<int> random_P(int n) {
    vector<int> vect(n, -1);

    for (int i = 0; i < n; i++) {
        vect[i] = (rand() % n + 1);
    }
    printf("Printing the rand P: \n");
    for(int i = 0; i < vect.size(); i++) {
        printf("i is: %i and val: %d \n", i,  vect[i]);
    }

    return vect;
}

// Generates a random neighbor to sequence P
vector<int> random_neighbor(vector<int> p) {
  int n = p.size();
  vector<int> vect;
  vect = p;

  int j = rand() % n + 1;

  while(true) {
      int i = rand() % n;       //need to change to accomodate different n. 
      if (vect[i] != j) {
        vect[i] = j;
          printf("randomn neighbor is: \n");
          for(int i = 0; i < vect.size(); i++) {
              printf("i is: %i and val: %d \n", i, vect[i]);
          }
        return vect;
      }
  }
  return vect;
}

// Karmarkar Karp with P and A' - has A' and uses P? 
int a_karmarkar_karp (vector<int>  p) {
    // create A' based on P and A
    vector<long long>  ap(p.size(), 0);
    for(int i = 0; i < p.size();  i++) {
        ap[p[i] - 1]+=A[i];
    }

    printf("AP is: \n");
    for(int i = 0; i < ap.size(); i++) {
        printf("i is: %i and val: %d \n", i, ap[i]);
    }

    return(karmarkarKarp(ap));
}

// Pure Karmarkar Karp, with input just A and no P
int karmarkarKarp(vector<long long> a) {

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

int repeated_random(vector<long long>  p) {
    vector<long long>  s;
    s = p;
    int sk = a_karmarkar_karp(s);

    for (int i = 0; i < max_iter; i++) {
        // Generate random solution
        vector<long long>  sp = random_P(p.size());
        int spk = a_karmarkar_karp(sp);
        if (spk < sk) {
            s = sp;
            sk = spk;
        }
    }
    return(sk);
}

int hill_climbing(vector<long long>  p) {
    vector<long long>  s;
    s = p;
    int sk = a_karmarkar_karp(s);

    for (int i = 0; i < max_iter; i++) {
        // Generate random neighbor
        vector<long long>  sp = random_neighbor(s);
        int spk = a_karmarkar_karp(sp);
        if (spk < sk) {
            s = sp;
            sk = spk;
        }
    }
    return(sk);
}

int sim_anneal(vector<long long>  p) {
    vector<long long>  s;
    s = p;
    int sk = a_karmarkar_karp(s);

    vector<long long>  spp;
    spp = s;
    int sppk = a_karmarkar_karp(spp);

    for (int i = 0; i < max_iter; i++) {
        // Generate random neighbor
        vector<long long>  sp = random_neighbor(s);
        int spk = a_karmarkar_karp(sp);
        if (spk < sk) {
            s = sp;
            sk = spk;
        } else {
// probablity stuff
        }

        if (sk < sppk) {
          spp = s;
        }
    }

    return(sppk);
}
