#include <iostream>
#include <chrono>

using namespace std;

class SortingAlgorithm
{
protected:
    int* orig;
    int* arr;
    int n;

public:
    SortingAlgorithm(int arrInput[], int n)
    {
        this->n = n;
        this->orig = new int[n];
        this->arr = new int[n];

        for(int i=0; i<n; ++i)
        {
            this->orig[i] = arrInput[i];
        }
    }

    double getAverageRunTime(int numIterations)
    {
        double sum = 0.0;
        for(int i=0; i<numIterations; ++i)
        {
            sum += this->getRunTime();
        }
        return (sum/numIterations);
    }   

    void initArray()
    {
        for(int i=0; i<n; ++i)
        {
            arr[i] = orig[i];
        }
    }

    double getRunTime()
    {
        this->initArray();
        auto timeStart = chrono::high_resolution_clock::now();
        this->sort();
        auto timeEnd = chrono::high_resolution_clock::now();

        if(!this->isSorted())
        {
            cout << "----BUG in Sorting!----" << endl;
        }

        return chrono::duration_cast<chrono::nanoseconds>(timeEnd - timeStart).count();
    }

    virtual void sort() = 0;

private:
    bool isSorted()
    {
        for(int i=1; i<this->n; ++i)
        {
            if(this->arr[i]<this->arr[i-1])
            {
                return false;
            }
        }
        return true;
    }
}

class SelectionSort : public SortingAlgorithm
{
private:
    int* arr;
    int n;

public:
    SelectionSort( int* arr, int n) : arr(arr), n(n)
    {

    }

    void sort() override
{
    int last = n-1;
    for(int i=0; i<last; ++i)
    {
        int minValue = arr[i];
        int minIndex = i;
        for(int j = i+1; j<n; ++j)
        {
            if(arr[j] < minValue)
            {
                minValue = arr[j];
                minIndex = j;
            }
        }
        arr[minIndex] = arr[i];
        arr[i] = minValue;
    }
}
}




int main()
{
    
    return 0;
}
