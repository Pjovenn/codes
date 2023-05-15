//linear
#include <iostream>
using namespace std;

const int N = 17;

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
    int A[N] = {0};
    int keys[10] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    int probeCount = 0;
    // Insert keys into hashes table
    for (int i = 0; i < 10; i++) {
        int j = hashes(keys[i]);
        while (A[j] != 0)
            j = (j + 1) % N;
        A[j] = keys[i];
    }

    // Search for keys in hashes table
    for (int i = 0; i < 10; i++) {
        int j = search(A, keys[i], probeCount);
        if (j == -1)
            cout << keys[i] << " not found" << endl;
        else
            {cout << keys[i] << " found at index " << j << endl;}
    } 
    cout << "\ntotal probes: " << probeCount << endl;

    // Print final contents of hash table
    cout << "Final contents of hash table:" << endl;
    for (int i = 0; i < N; i++)
        cout << "A[" << i << "] = " << A[i] << endl;
    

    return 0;
}

//quadratic
#include <iostream>
using namespace std;

const int N = 17;

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
    int A[N] = {0};
    int keys[10] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    int probeCount = 0;
    // Insert keys into hashes table
    for (int i = 0; i < 10; i++) {
        int j = hashes(keys[i]);
        int p = 0;
        while (A[j] != 0) {
            p++;
            j = (j + p * p) % N;
        }
        A[j] = keys[i];
    }

    // Search for keys in hashes table
    for (int i = 0; i < 10; i++) {
        int j = search(A, keys[i], probeCount);
        if (j == -1)
            cout << keys[i] << " not found" << endl;
        else
            cout << keys[i] << " found at index " << j << endl;
    } 
    cout << "\nTotal probes: " << probeCount << endl;

    // Print final contents of hash table
    cout << "Final contents of hash table:" << endl;
    for (int i = 0; i < N; i++)
        cout << "A[" << i << "] = " << A[i] << endl;
    

    return 0;
}

//double hash
#include <iostream>
using namespace std;

const int N = 17;

int h(int k) {
    // Primary hash function h(k) = k mod 17
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
    int A[N] = {0};
    int keys[10] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    int probeCount = 0;
    // Insert keys into hash table
    for (int i = 0; i < 10; i++) {
        int j = h(keys[i]);
        int dval = d(keys[i]);
        while (A[j] != 0)
            j = (j + dval) % N;
        A[j] = keys[i];
    }

    // Search for keys in hash table
    for (int i = 0; i < 10; i++) {
        int j = search(A, keys[i], probeCount);
        if (j == -1)
            cout << keys[i] << " not found" << endl;
        else
            cout << keys[i] << " found at index " << j << endl;
    }
    cout << "Total probes: " << probeCount << endl;

    // Print final contents of hash table
    cout << "Final contents of hash table:" << endl;
    for (int i = 0; i < N; i++)
        cout << "A[" << i << "] = " << A[i] << endl;

    return 0;
}
