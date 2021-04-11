#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int array1[], int n, int x)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(array1[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int array1[] = {34, 14, 24, 54, 84, 64, 94, 74, 4};
    int n = sizeof(array1) / sizeof(array1[0]);

    int x;
    cout << "Nhap Gia Tri Can Tim: ";
    cin >> x;

    int pos = LinearSearch(array1, n, x);

    if(pos == -1)
    {
        cout << "Khong Tim Duoc X trong day so";
    }
    else
    {
        cout << "Phan tu " << x << " nam o vi tri " << pos << endl; 
    }
 
    return 0;
}