#include <iostream>

using namespace std;


void Selsort()
{
    int arr[] = {11,2,31,14,56,65,72,18,19,90};
    int n = sizeof(arr)/ sizeof(arr[0]);
    for(int i=0; i < n-1; ++i)
    {
        int minVal = arr[i];
        int minInd = i;
        for(int j= i+1; j<n; ++j)
        {
            if(arr[j] < minVal)
            {
                minVal = arr[j];
                minInd = j;
            }
        }
        arr[minInd] = arr[i];
        arr[i] = minVal;
    }

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

void insort()
{
    int arr[] = {10,2,31,42,51,16,27,38,29,110};
    int n = sizeof(arr)/ sizeof(arr[0]);

    for(int i=0; i<n; i++)
    {
        int curr = arr[i];
        int pos = i;
        while(pos >= 1 && curr <arr[pos-1])
        {
            arr[pos] = arr[pos-1];
            pos = pos-1;
            arr[pos] = curr;
        }
    }
    //shell
void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int j = i;
            int temp = arr[i];
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}
cout << endl;
    for(int i =0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}


int main()
{
    Selsort();
    insort();
    return 0;
}
