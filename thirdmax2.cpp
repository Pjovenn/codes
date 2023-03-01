#include <iostream>
#include <algorithm>


using namespace std;

int main()
{

int arr[] = {1,2,3,4,5,6,7,8,9,10}; //initialize array

int len = sizeof(arr)/sizeof(arr[0]); //determine the size of array sizeofarr(4*10) / sizeofarr of each element(4)

sort(arr, arr+len, greater<int>()); //sorting algorithm that sorts elements in a descending order
    

    /* //bubble sort algorithm
for(int i=0; i<n-1; i++) //loops 10 times from 0 to 9
{
    for(int j=0;j<n-i-1; j++) // loop count is decreased as i increases
    {
        if(arr[j]<arr[j+1]) // implements only when previous element is less than element, swapping as index(j) increases
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
    */
//optional
for(int i=0; i<len; i++) // prints out all the elements in descending order
{
    cout << arr[i] << " ";
}

cout << "\nThe third max value is: " << arr[2] << endl; //prints out the third maximum value

    return 0;
}
