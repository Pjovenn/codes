#include <iostream>

using namespace std;

int main()
{
int arr[] = {1,2,3,4,5,6,7,8,9,10}; //initialize array

int n = sizeof(arr)/ sizeof(arr[0]); //size of array(40) / size of each element(4) = 10

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

for(int x=0; x<n; x++) // prints out all elements in loop
{
    cout << arr[x] << " ";
}

cout << "\nthe third max value is: " << arr[2] << endl; // prints out the third max value


return 0;
};