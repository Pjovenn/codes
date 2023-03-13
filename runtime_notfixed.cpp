#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int CompThird(int arr[], int len) {
    int maxA, maxB, maxC;
    int Tmax[3] = {arr[0], arr[1], arr[2]};

    for(int i=3; i<len; i++) {
        if(Tmax[i%3]<arr[i]) {
            Tmax[i%3] = arr[i];
        }
    }
    maxA = Tmax[0], maxB = Tmax[1], maxC = Tmax[2];

    cout << "\nThe third max value is: ";
    if(maxA < maxB && maxA < maxC) {  //Returns maxA as the lowest value of the three maxes
        return maxA;
    } else if(maxB < maxA && maxB < maxC) { //Returns maxB as the lowest value of the three maxes
        return maxB;
    } else {    //Returns maxC as the lowest value of the three maxes
        return maxC;
    }
}

int main() {
    int n = 400;
    int arr[n];

    // Seed the random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, n);

    // Initialize the array with random values
    for(int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }

    // Measure the runtime of the algorithm
    auto start = chrono::high_resolution_clock::now();
    int thirdMax = CompThird(arr, n);
    auto end = chrono::high_resolution_clock::now();

    cout << "The third maximum value is: " << thirdMax << endl;

    // Calculate the runtime in nanoseconds
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "The runtime is: " << duration.count() << " microseconds" << endl;

    return 0;
}


