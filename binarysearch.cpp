#include <iostream>
#include <random>
#include <chrono>


using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (key == arr[mid]) {
            return mid;
        } else if (key < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;// Key not found
}

void insertKey(int arr[], int& size, int key) {
    // Shift elements to the right
    for (int i = size - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the key at the first index
    arr[0] = key;

    // Increase the size of the array
    size++;

}
void deleteKey(int arr[], int& size, int key) {
    int deletePosition = binarySearch(arr, size, key);

    if (deletePosition != -1) {
        // Shift elements to the left
        for (int i = deletePosition; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // Decrease the size of the array
        size--;
    }
}

int main() {
    int size = 400000;
    int arr[size];
    random_device rnd;
    mt19937 gen(rnd());
    uniform_int_distribution<> dis(0, size);

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }

    auto start = chrono::high_resolution_clock::now();
    int key = 333333;
    insertKey(arr,size, key); //only use when calculating insertion, comment out when deleting or searching, the same goes with the other operations
    int index = binarySearch(arr, size, key);

    if (index != -1) {
        cout << "Key found at index: " << index << endl;
        deleteKey(arr, size, key);
        cout << "Key deleted." << endl;
    } else {
        cout << "Key not found." << endl;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(stop-start);
    cout << endl;
    cout << "Time taken by algorithm: " << elapsed_time.count() << " microseconds" << endl;


    return 0;
}
