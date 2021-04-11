#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int x[], int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        int m = i;

        for(int j = i + 1; j < n ; j++)
        {
            if(x[m] > x[j])
            {
                m = j;
            }
        }

        int temp = x[m];
        x[m] = x[i];
        x[i] = temp;
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

    SelectionSort(x, n);
       
    cout << "Sau Khi Sap Xep: ";
    PrintArray(x, n);
    
    return 0;
}