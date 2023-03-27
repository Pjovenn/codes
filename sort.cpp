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
 
 //merge
 void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
 //heap
 
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
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
