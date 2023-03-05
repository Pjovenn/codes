#include <iostream>

using namespace std;

int SortThird() //Bubble sort algorithm in descending order
{
    int arr[] = {5,2,1,3,4}; //Initialized array
    int len = sizeof(arr) / sizeof(arr[0]); //Number of elements in the array

    cout << "\nThe elements are: ";
    for(int i=0; i<len; i++)
    {
        cout << arr[i] << " ";
    }

    for(int i=0; i<len; i++)
    {
        for(int j =0; j<len-1-i; j++)
        {
            if(arr[j]< arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "\nThe third max value is: ";

    return arr[2]; //Returns the third value of the sorted array
    cout << endl;
}

int CopyThird()
{
    int arr[] = {11,12,13,14,15,16,17,18,19,20}; //Initialized array
    int len = sizeof(arr) / sizeof(arr[0]); //Number of elements in the array
    int copyarr[3], Tmax;
    int i, j;

    cout << "\nThe elements are: ";
    for(int i=0; i<len; i++)
    {
        cout << arr[i] << " ";
    }

    for(i=0; i<3; i++)
    {
        Tmax = arr[i];
        for(j =(i+1); j<len; j++)
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


    cout << "\nThe third max value is: ";
    
    return copyarr[2];
    cout << endl;
}

int CompThird()
{
    int arr[] = {21,28,23,27,24,25,26,22,29}; //Initialized array
    int len = sizeof(arr)/ sizeof(arr[0]); //Number of elements in the array
    
    cout << "\nThe elements are: ";
    for(int i=0; i<len; i++)
    {
        cout << arr[i] << " ";
    }
    int maxA, maxB, maxC;
    int Tmax[3] = {arr[0], arr[1], arr[2]};

    for(int i=3; i<len; i++)
    {
        if(Tmax[i%3]<arr[i])
        {
            Tmax[i%3] = arr[i];
        }
    }
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
    cout << SortThird() << endl;
    cout << CopyThird() << endl;
    cout << CompThird() << endl;
    return 0;
}
