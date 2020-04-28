#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

//global vars
vector<long long> A;
int max_iter = 25000;

// functions
vector<int> random_P(int, int);
long long karmarkarKarp(vector<long long>);
long long a_karmarkar_karp(vector<long long>);
long long repeated_random(vector<int> );
long long hill_climbing(vector<int> );
long long sim_anneal(vector<int> );
long long prepar_repeated_random(vector<int> );
long long prepar_hill_climbing(vector<int> );
long long prepar_sim_anneal(vector<int> );

int main(int argc, char *argv[]) {
    srand((unsigned) time(0));

    ofstream file;
    file.open ("task_4_results");

    for (int i = 0; i < 98; i++) {
        A.clear();
        // Generate A
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<long long> dis(1, 1000000000000);

        for (int i = 0; i < 100; i++) {
            A.push_back(dis(gen)); // the rand gen number
        }

        // Initial solutions for prepartitioned vs. regular
        vector<int> reg_p = random_P(A.size(), 2);
        vector<int> prepar_p = random_P(A.size(), A.size());
        int ans;

        // Standard KK
        auto start = high_resolution_clock::now();
        ans = karmarkarKarp(A);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        file << ans << " " << duration.count() << " ";

        // Repeated Random
        start = high_resolution_clock::now();
        ans = repeated_random(reg_p);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        file << ans << " " << duration.count() << " ";

        // Hill climbing
        start = high_resolution_clock::now();
        ans = hill_climbing(reg_p);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        file << ans << " " << duration.count() << " ";

        // Simulated Anneal
        start = high_resolution_clock::now();
        ans = sim_anneal(reg_p);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        file << ans << " " << duration.count() << " ";

        // PP Repeated Random
        start = high_resolution_clock::now();
        ans = prepar_repeated_random(prepar_p);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        file << ans << " " << duration.count() << " ";

        // PP Hill climbing
        start = high_resolution_clock::now();
        ans = prepar_hill_climbing(prepar_p);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        file << ans << " " << duration.count() << " ";

        // PP Simulated Anneal
        start = high_resolution_clock::now();
        ans = prepar_sim_anneal(prepar_p);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        file << ans << " " << duration.count() << "\n";
    }

    file.close();
    return 0;
}

// Generates a random solution sequence P with size n, values from 1 to n
vector<int> random_P(int n, int range) {
    vector<int> vect(n, -1);

    for (int i = 0; i < n; i++) {
        vect[i] = (rand() % range);
    }
    // printf("Printing the rand P: \n");
    // for(int i = 0; i < vect.size(); i++) {
    //     printf("i is: %i and val: %d \n", i,  vect[i]);
    // }

    return vect;
}

// Generates a random neighbor to sequence P
vector<int> random_neighbor(vector<int> p, int range) {
  vector<int> vect;
  vect = p;
  // printf("Printing the input to random neighbor P: \n");
  // for(int i = 0; i < vect.size(); i++) {
  //     printf("i is: %i and val: %d \n", i,  vect[i]);
  // }
    if(range == 2) {
        //A random move on this state space can be defined as follows.
        //Choose two random indices i and j from [1,n] with i ̸= j.
        //Set si to −si and with probability 1/2, set sj to −sj.
        //That is, with probability 1/2, we just try to move one element to the other set;
        //with probability 1/2, we try to swap two elements.
        //(The two elements we try to swap may be from the same set or different sets.)
        int i = rand() % vect.size();
        int j = rand() % vect.size();
        while(i == j) {
            //hopefully no infinite loop
            j = rand() % vect.size();
        }

        //hopefully this works 0 + 1 = 1 % 2 = 1, 1 + 1 = 2 %2 = 0;
        vect[i] = (vect[i]+1)%2;

        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, 1);

        if(dis(gen) == 0) {
            vect[j] = (vect[j]+1)%2;  //flip the switch
        }
    }
    else {
        int j = rand() % range;

        while(true) {
            int i = rand() % p.size();

            if (vect[i] != j) { // make a swap if the index values are not the same
                vect[i] = j;
                break;
            }
        }
    }
  return vect;
}

// Karmarkar Karp with P and A' - has A' and uses P?
long long a_karmarkar_karp (vector<int>  p) {
    // create A' based on P and A
    vector<long long>  ap(p.size(), 0);
    for(int i = 0; i < p.size();  i++) {
        ap[p[i]]+=A[i];
    }

    // printf("AP is: \n");
    // for(int i = 0; i < ap.size(); i++) {
    //     printf("i is: %i and val: %lld \n", i, ap[i]);
    // }

    return(karmarkarKarp(ap));
}

// Pure Karmarkar Karp, with input just A and no P
long long karmarkarKarp(vector<long long> a) {

    // Karmarkar Karp
    while(a.size()>1) {
        // Sort input
        sort(a.begin(), a.end(), greater<long long>());

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

long long prepar_repeated_random(vector<int>  p) {
    vector<int>  s;
    s = p;
    long long sk = a_karmarkar_karp(s);

    for (int i = 0; i < max_iter; i++) {
        // Generate random solution
        vector<int>  sp = random_P(p.size(), p.size());
        long long spk = a_karmarkar_karp(sp);
        if (spk < sk) {
            s = sp;
            sk = spk;
        }
    }
    return(sk);
}

long long prepar_hill_climbing(vector<int>  p) {
    vector<int>  s;
    s = p;
    long long sk = a_karmarkar_karp(s);

    for (int i = 0; i < max_iter; i++) {
        // Generate random neighbor
        vector<int>  sp = random_neighbor(s, s.size());
        long long spk = a_karmarkar_karp(sp);
        if (spk < sk) {
            s = sp;
            sk = spk;
        }
    }
    return(sk);
}

long long prepar_sim_anneal(vector<int>  p) {
    vector<int>  s;
    s = p;
    long long sk = a_karmarkar_karp(s);

    vector<int>  spp;
    spp = s;
    long long sppk = a_karmarkar_karp(spp);

    for (int i = 0; i < max_iter; i++) {
        // Generate random neighbor
        vector<int>  sp = random_neighbor(s, s.size());
        long long spk = a_karmarkar_karp(sp);
        if (spk < sk) {
            s = sp;
            sk = spk;
        } else {
            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.0, 1.0);
            // probablity stuff  exp(−(res(S′)-res(S))/T(iter))
            //T(iter) = 10^10 * (0.8)^⌊iter/300⌋
            double k = fmod(exp(-((long double) spk - sk)/((pow(10.0,10.0))*pow(0.8, floor((long double) i/300)))),(long double) 1.0);  //i think this is right?
            double i = dis(gen);
            //selected k
            if(i < k) {
                s = sp;
                sk = spk;
            }
        }

        if (sk < sppk) {
          spp = s;
          sppk = sk;
        }
    }

    return(sppk);
}

// All of the below functions use range 2, to simulate a swap between two subsets
long long repeated_random(vector<int>  p) {
    vector<int>  s;
    s = p;
    long long sk = a_karmarkar_karp(s);

    for (int i = 0; i < max_iter; i++) {
        // Generate random solution
        vector<int>  sp = random_P(p.size(), 2);
        double spk = a_karmarkar_karp(sp);
        if (spk < sk) {
            s = sp;
            sk = spk;
        }
    }
    return(sk);
}


long long hill_climbing(vector<int>  p) {
    vector<int>  s;
    s = p;
    long long sk = a_karmarkar_karp(s);

    for (int i = 0; i < max_iter; i++) {
        // Generate random neighboring solution
        vector<int>  sp = random_neighbor(s, 2);
        long long spk = a_karmarkar_karp(sp);
        if (spk < sk) {
            s = sp;
            sk = spk;
        }
    }
    return(sk);
}

long long sim_anneal(vector<int>  p) {
    vector<int>  s;
    s = p;
    long long sk = a_karmarkar_karp(s);   //this is Resid(s)

    vector<int>  spp;
    spp = s;
    long long sppk = a_karmarkar_karp(spp);

    for (int i = 0; i < max_iter; i++) {
        // Generate random neighbor
        vector<int>  sp = random_neighbor(s, 2);
        long long spk = a_karmarkar_karp(sp); //this is the residual for S'

        if (spk < sk) {
            s = sp;
            sk = spk;
        } else {
            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.0, 1.0);

            // probablity stuff  exp(−(res(S′)-res(S))/T(iter))
            //T(iter) = 10^10 * (0.8)^⌊iter/300⌋
            double k = fmod(exp(-((long double) spk - sk)/((pow(10.0,10.0))*pow(0.8, floor((long double) i/300)))),(long double) 1.0);  //i think this is right?
            double i = dis(gen);
            //selected k
            if(i < k) {
                s = sp;
                sk = spk;
            }
        }

        if (sk < sppk) {
          spp = s;
          sppk = sk;
        }
    }

    return(sppk);
}
