#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>


using namespace std;

void slowsort(int arr[], int max_size)
{
    while(true)
    {
        int i = rand() % max_size;
        int j = rand() % max_size;

        if(i < j && arr[i] > arr[j])
        {
            swap(arr[i], arr[j]);
        }

    bool sorted = true;
    for(int x = 0; x <max_size; x++)
    {
        if(arr[x+1] < arr[x])
        {
            sorted = false;
            break;
        }
    }
    if(sorted)
    {
        break;
    }
    }
}

int main()
{
    const int max_size = 5000;
    int arr[max_size];
    random_device rnd;
    mt19937 rand(rnd());

    for(int i =0; i<max_size; i++)
    {
        arr[i] = rand() % max_size + 1;
    }

    auto start = chrono::high_resolution_clock::now();
    slowsort(arr, max_size);
    auto stop = chrono::high_resolution_clock::now();

    auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(stop-start);

    cout << "after sorting: " << endl;
    for(int i =0; i<max_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken by algorithm: " << elapsed_time.count() << " microseconds" << endl;


    return 0;
}
