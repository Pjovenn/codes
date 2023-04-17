#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

void countingSort(int arr[], int n) {
    int max_val = *max_element(arr, arr + n);
    vector<int> count(max_val + 1);
    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    int idx = 0;
    for (int i = 0; i <= max_val; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[idx++] = i;
        }
    }
  for (int i =0; i<1000; i++)
  {
    cout << arr[i] << " ";
  }
}
int main() 
{
    const int max_size = 1000;
    int arr[max_size];
    random_device rnd;
    mt19937 gen(rnd());
    uniform_int_distribution<> dis(0, max_size);
    
    for(int i = 0; i < max_size; i++) {
        arr[i] = dis(gen);
    }

    auto start = chrono::high_resolution_clock::now();
    countingSort(arr, max_size);
    auto stop = chrono::high_resolution_clock::now();

    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Time taken by bucket/counting/radix sort: " << elapsed_time.count() << " microseconds" << endl;

    return 0;
}