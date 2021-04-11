#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int x[], int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1; j++)
        {
            if(x[j] > x[j + 1])
            {
                int temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
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

    BubbleSort(x, n);
       
    cout << "Sau Khi Sap Xep: ";
    PrintArray(x, n);
    return 0;
}