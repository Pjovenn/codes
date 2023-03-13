#include <iostream>
#include <random>

using namespace std;

int main()
{
    const int MAX = 10000;
    random_device rd;
    mt19937 rand(rd());
    
    cout << 4 << endl;
    
    int numItems = 100;
    cout << numItems << endl;
    for (int i = 0; i < numItems; ++i)
    {
        cout << rand() % MAX << " ";
    }
    cout << endl;
    
    numItems = 100;
    cout << numItems << endl;
    for (int i = 0; i < numItems; ++i)
    {
        cout << rand() % MAX << " ";
    }
    cout << endl;
    
    numItems = 100;
    cout << numItems;
    for (int i = 0; i < numItems; ++i)
    {
        if (i % 10000 == 0)
            cout << endl;
        cout << rand() % MAX << " ";
    }
    cout << endl;
    
    numItems = 100;
    cout << numItems;
    for (int i = 0; i < numItems; ++i)
    {
        if (i % 10000 == 0)
            cout << endl;
        cout << rand() % MAX << " ";
    }
    cout << endl;
    
    return 0;
}
