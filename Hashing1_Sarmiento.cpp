//To run, comment out other mains (either linear,quadratic, or double hash)

//LINEAR
#include <iostream>
#include <random>
#include <chrono>
using namespace std;


const int N = 100;

int hashes(int k) {
    // This hashes function simply returns k mod N,
    // where N is the size of the hashes table.
    return k % N;
}

int search(int A[], int k, int& probeCount) {
    int i = hashes(k);
    int p = 0;
    do {
        probeCount++;
        if (A[i] == 0)
            return -1;
        else if (A[i] == k)
            return i;
        else {
            i = (i + 1) % N;
            p++;
        }
    } while (p < N);
    return -1;
}

int main() {
    const int max_size = 100;
    int keys[max_size];
    random_device rnd;
    mt19937 gen(rnd());
    uniform_int_distribution<> dis(0, max_size);

    for(int i =0; i<max_size; i++) {
        keys[i] = dis(gen);
    }
    int A[N] = {0};
    int probeCount = 0;
    // Insert keys into hashes table

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < max_size; i++) {
        int j = hashes(keys[i]);
        while (A[j] != 0)
            j = (j + 1) % N;
        A[j] = keys[i];
    }

    // Search for keys in hashes table
    for (int i = 0; i < max_size; i++) {
        int j = search(A, keys[i], probeCount);
        if (j == -1)
            cout << keys[i] << " not found" << endl;
        else
            {cout << keys[i] << " found at index " << j << endl;}
    } 
    auto stop = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << "\ntotal probes: " << probeCount << endl;

    // Print final contents of hash table
    cout << "Final contents of hash table:" << endl;
    for (int i = 0; i < N; i++)
        cout << "A[" << i << "] = " << A[i] << endl;
    
    cout << "Time taken by algorithm: " << elapsed_time.count() << " milliseconds" << endl;

    return 0;
}




//QUADRATIC
#include <iostream>
#include <random>
#include <chrono>
using namespace std;

const int N = 100;

int hashes(int k) {
    // This hashes function simply returns k mod N,
    // where N is the size of the hashes table.
    return k % N;
}

int search(int A[], int k, int& probeCount) {
    int i = hashes(k);
    int p = 0;
    do {
        probeCount++;
        if (A[i] == 0)
            return -1;
        else if (A[i] == k)
            return i;
        else {
            i = (i + p * p) % N;
            p++;
        }
    } while (p < N);
    return -1;
}

int main() {
    const int max_size = 100;
    int keys[max_size];
    random_device rnd;
    mt19937 gen(rnd());
    uniform_int_distribution<> dis(0, max_size);

    for(int i =0; i<max_size; i++) {
        keys[i] = dis(gen);
    }
    int A[N] = {0};
    int probeCount = 0;

    // Insert keys into hashes table
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < max_size; i++) {
        int j = hashes(keys[i]);
        int p = 0;
        while (A[j] != 0) {
            p++;
            j = (j + p * p) % N;
        }
        A[j] = keys[i];
    }

    // Search for keys in hashes table
    for (int i = 0; i < max_size; i++) {
        int j = search(A, keys[i], probeCount);
        if (j == -1)
            cout << keys[i] << " not found" << endl;
        else
            cout << keys[i] << " found at index " << j << endl;
    } 
    auto stop = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(stop-start);
    cout << "\nTotal probes: " << probeCount << endl;

    // Print final contents of hash table
    cout << "Final contents of hash table:" << endl;
    for (int i = 0; i < N; i++)
        cout << "A[" << i << "] = " << A[i] << endl;

    cout << "Time taken by algorithm: " << elapsed_time.count() << " microseconds" << endl;

    return 0;
}




//DOUBLE HASH
#include <iostream>
#include <random>
#include <chrono>
using namespace std;

const int N = 100;

int h(int k) {

    return k % N;
}

int d(int k) {
    // Secondary hash function d(k) = 13 - k mod 13
    return 13 - (k % 13);
}

int search(int A[], int k, int& probeCount) {
    int i = h(k);
    int p = 0;
    int dval = d(k);
    do {
        probeCount++;
        if (A[i] == 0)
            return -1;
        else if (A[i] == k)
            return i;
        else {
            i = (i + dval) % N;
            p++;
        }
    } while (p < N);
    return -1;
}

int main() {
    const int max_size = 100;
    int keys[max_size];
    random_device rnd;
    mt19937 gen(rnd());
    uniform_int_distribution<> dis(0, max_size);

    for(int i =0; i<max_size; i++) {
        keys[i] = dis(gen);
    }
    int A[N] = {0};

    int probeCount = 0;

    // Insert keys into hash table
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < max_size; i++) {
        int j = h(keys[i]);
        int dval = d(keys[i]);
        while (A[j] != 0)
            j = (j + dval) % N;
        A[j] = keys[i];
    }

    // Search for keys in hash table
    for (int i = 0; i < max_size; i++) {
        int j = search(A, keys[i], probeCount);

    }
    auto stop = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(stop-start);
    cout << "Total probes: " << probeCount << endl;


    cout << "Time taken by algorithm: " << elapsed_time.count() << " microseconds" << endl;

    return 0;
}
