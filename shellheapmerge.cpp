#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
 //heap

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 

    if (l < n && arr[l] > arr[largest])
        largest = l;
 

    if (r < n && arr[r] > arr[largest])
        largest = r;
 

    if (largest != i) {
        swap(arr[i], arr[largest]);
 

        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 

    for (int i = n - 1; i >= 0; i--) {

        swap(arr[0], arr[i]);
 

        heapify(arr, i, 0);
    }
}
  
    //shell
void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int j = i;
            int temp = arr[i];
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}



int main()
{
    const int max_size = 1000000;
    int arr[max_size];
    random_device rnd;
    mt19937 gen(rnd());
    uniform_int_distribution<> dis(0, max_size);
    
    for(int i =0; i<max_size; i++)
    {
        arr[i] = dis(gen);
    }

    auto start = chrono::high_resolution_clock::now();
    shellSort(arr, max_size);
    auto stop = chrono::high_resolution_clock::now();

    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(stop-start);


    cout << "Time taken by algorithm: " << elapsed_time.count() << " microseconds" << endl;


    return 0;
}
