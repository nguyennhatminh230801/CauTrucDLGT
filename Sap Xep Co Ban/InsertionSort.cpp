#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int x[], int n)
{
    for(int i = 1 ; i < n ; i++)
    {
        int tam = x[i];
        int j = i - 1;

        while (j >= 0 && x[j] > tam)
        {
            x[j + 1] = x[j];
            j--;
        }
        
        x[j + 1] = tam;
    }
}

void PrintArray(int x[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main()
{
    int x[] = {34, 14, 24, 54, 84, 64, 94, 74, 4};
    int n = sizeof(x) / sizeof(x[0]);

    cout << "Truoc Khi Sap Xep: ";
    PrintArray(x, n);

    InsertionSort(x, n);
    
    cout << "Sau Khi Sap Xep: ";
    PrintArray(x, n);
    
    return 0;
}