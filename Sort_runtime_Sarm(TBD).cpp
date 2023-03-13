#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int SortThird() //Bubble sort algorithm in descending order
{
    const int MAX = 10000;
    random_device rnd;
    mt19937 rand(rnd());
    int arr[MAX];

 for(int i=0; i<MAX; i++)
    {
        arr[i] = rand() % MAX + 1;
    }
    clock_t start = clock();

    for(int i=0; i<MAX; i++)
    {
        for(int j =0; j<MAX-1-i; j++)
        {
            if(arr[j]< arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t stop = clock();

    double el_time = double(stop-start)/CLOCKS_PER_SEC;
    int el_elap = static_cast<int>(el_time *1000);
    cout << "\ntime taken by Sort algorithm: " << el_elap << " milliseconds";

    cout << "\nThe third max value is: ";

    return arr[2]; //Returns the third value of the sorted array
    cout << endl;
}

int CopyThird()
{
    const int MAX = 10000;
    random_device rnd;
    mt19937 rand(rnd());
    int arr[MAX];

    for(int i=0; i<MAX; i++)
    {
        arr[i] = rand() % MAX + 1;
    }

    int copyarr[3], Tmax;
    int i, j;

       clock_t start = clock();
    for(i=0; i<3; i++)
    {
        Tmax = arr[i];
        for(j =(i+1); j<MAX; j++)
        {
            if(arr[j] > Tmax)
            {
                Tmax = arr[j];
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        copyarr[i] = Tmax;
    }
    clock_t stop = clock();

    double el_time = double(stop-start)/CLOCKS_PER_SEC;
    int el_elap = static_cast<int>(el_time *1000);
    cout << "\ntime taken by Copy algorithm: " << el_elap << " milliseconds";



    cout << "\nThe third max value is: ";

    return copyarr[2];
    cout << endl;
}

int CompThird()
{
    const int MAX = 10000;
    random_device rnd;
    mt19937 rand(rnd());
    int arr[MAX];

    for(int i=0; i<MAX; i++)
    {
        arr[i] = rand() % MAX + 1;
    }

           clock_t start = clock();
    int maxA, maxB, maxC;
    int Tmax[3] = {arr[0], arr[1], arr[2]};

    for(int i=3; i<MAX; i++)
    {
        if(Tmax[i%3]<arr[i])
        {
            Tmax[i%3] = arr[i];
        }
    }

    clock_t stop = clock();

    double el_time = double(stop-start)/CLOCKS_PER_SEC;
    int el_elap = static_cast<int>(el_time *1000);
    cout << "\ntime taken by Compare algorithm: " << el_elap << " milliseconds";

    maxA = Tmax[0], maxB = Tmax[1], maxC = Tmax[2];

    cout << "\nThe third max value is: ";
    if(maxA < maxB && maxA < maxC)  //Returns maxA as the lowest value of the three maxes
    {
        return maxA;
    }
    else if(maxB < maxA && maxB < maxC) //Returns maxB as the lowest value of the three maxes
    {
        return maxB;
    }
    else    //Returns maxC as the lowest value of the three maxes
    {
        return maxC;
    }
    cout << endl;
}

int main()
{
    //cout << SortThird(), or CopyThird(), or CompThird() to calculate 3 algorithms one by one
    cout << SortThird();
    cout << CopyThird();
    cout << CompThird();

    return 0;
}
