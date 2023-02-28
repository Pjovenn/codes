#include <iostream>
#include <algorithm>


using namespace std;

int main()
{

int arr[] = {1,2,3,4,5,6,7,8,9,10}; //initialize array

int len = sizeof(arr)/sizeof(arr[0]); //determine the size of array sizeofarr(4*10) / sizeofarr of each element(4)

sort(arr, arr+len, greater<int>()); //sorting algorithm that sorts elements in a descending order

//optional
for(int i=0; i<len; i++)
{
    cout << arr[i] << " ";
}

cout << "\nThe third max value is: " << arr[2] << endl; //prints out the third maximum value

    return 0;
}