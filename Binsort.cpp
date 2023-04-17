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
}

void bucketSort(int arr[], int n) {
    const int num_buckets = 10;
    vector<int> buckets[num_buckets];
    int max_val = *max_element(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int bucket_idx = (int)((double)arr[i] / max_val * (num_buckets - 1));
        buckets[bucket_idx].push_back(arr[i]);
    }
    
    for (int i = 0; i < num_buckets; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    
    int idx = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

void radixSort(int arr[], int n) {
    const int base = 10;
    int exp = 1;
    int max_val = *max_element(arr, arr + n);
    vector<int> output(n);
    
    while (max_val / exp > 0) {
        vector<int> count(base);
        
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % base;
            count[digit]++;
        }
        
        for (int i = 1; i < base; i++) {
            count[i] += count[i - 1];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % base;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
        
        exp *= base;
    }
}

int main() 
{
    const int max_size = 500000;
    int arr[max_size];
    random_device rnd;
    mt19937 gen(rnd());
    uniform_int_distribution<> dis(0, max_size);
    
    for(int i = 0; i < max_size; i++) {
        arr[i] = dis(gen);
    }

    auto start = chrono::high_resolution_clock::now();
    radixSort(arr, max_size);
    //countingSort(arr, max_size);
    //bucketSort(arr, max_size);
    auto stop = chrono::high_resolution_clock::now();

    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Time taken by bucket/counting/radix sort: " << elapsed_time.count() << " microseconds" << endl;

    return 0;
}
