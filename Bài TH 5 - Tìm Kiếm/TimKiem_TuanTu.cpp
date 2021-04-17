#include <bits/stdc++.h>
using namespace std;

int TK_tuanTu(int a[], int n, int KH)
{
    int i = 0;
    while (i < n && a[i] != KH)
    {
        i++;
    }
    if (i < n)
        return i;
    return -1;
}

int main()
{
    int a[] = {04, 14, 24, 34, 54, 64, 74, 84, 94};
    int n = sizeof(a) / sizeof(a[0]);
    cout << TK_tuanTu(a, n, 94);
    cout<< endl;
    cout << TK_tuanTu(a, n, 55);
}