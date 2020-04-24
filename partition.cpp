// my first program in C++
#include <iostream>

global var for A

int main()
{
    int flag = -1;
    std::cin >> flag;

    int algorithm = -1;
    std::cin >> algorithm;

  given file, read from it to get list L of 100 ints.

  create initial random P (generate sequence of n values from range [1,n])

  // Record amount of time it takes for each algorithm
  kar_karp (sorted L)
  repeated_random P
  hill_climbing P
  sim_anneal P


  std::cout << "Hello World!";
}

random_P

kar_karp (P) (A) {
  create A' based on P and A
  sort A'
  pseudo for kar_karp
}

repeated_random
  for iter 1 to 25,000
    S' = random_P
    if kar_karp S' < kar_karp S then S = S'
  return S

hill_climbing

sim_anneal
