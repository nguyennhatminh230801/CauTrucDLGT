#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int array1[], int left1, int right1, int x)
{
    if(left1 > right1)
    {
        return -1;
    }

    int mid = (left1 + right1) / 2;

    if(array1[mid] == x)
    {
        return mid;
    }
    else if (array1[mid] > x)
    {
        BinarySearch(array1, left1, mid - 1, x);
    }
    else
    {
        BinarySearch(array1, mid + 1, right1, x);
    }
}   

int main()
{
    int array1[] = {4, 14, 24, 34, 54, 64, 74, 84, 94};
    int n = sizeof(array1) / sizeof(array1[0]);

    int x;
    cout << "Nhap Gia Tri Can Tim: ";
    cin >> x;

    int pos = BinarySearch(array1, 0, n - 1, x);

    if(pos == -1)
    {
        cout << "Khong Tim Duoc " << x << " trong day so";
    }
    else
    {
        cout << "Phan tu " << x << " nam o vi tri " << pos << endl; 
    }
 
    return 0;
}