#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#include <random>
using namespace std;

int main () {

  ofstream file;
  file.open ("input");

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<long long> dis(1, 1000000000000);

  for (int i = 0; i < 100; i++) {
    long long n = dis(gen);
    file << n << "\n";// the rand gen number
  }

  file.close();
  return 0;
}
