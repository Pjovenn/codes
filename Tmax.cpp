#include <iostream>

using namespace std;

int SortThird() //Bubble sort algorithm in descending order
{
    int arr[] = {5,2,1,3,4}; //Initialized array
    int len = sizeof(arr) / sizeof(arr[0]); //Number of elements in the array

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
    cout << "The third max value is: ";

    return arr[2]; //Returns the third value of the sorted array
}

int CopyThird()
{
    int arr[] = {11,12,13,14,15,16,17,18,19,20}; //Initialized array
    int len = sizeof(arr) / sizeof(arr[0]); //Number of elements in the array


    cout << "The third max value is: ";
    
    return ;
}

int CompThird()
{
    int arr[] = {11,12,13,14,15,16,17,18,19,20}; //Initialized array
    int len = sizeof(arr) / sizeof(arr[0]); //Number of elements in the array


    cout << "The third max value is: ";

    return ;
}



int main()
{
    cout << SortThird() << endl;
    cout << CopyThird() << endl;
    cout << CompThird() << endl;
    return 0;
}