#include <iostream>
#include <random>
#include <chrono>

void var(int a[], int n)
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0,n-1);
  
  //algorithm
  
  //main
