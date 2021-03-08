#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e8;
int cnt[maxn];

int main()
{
    int *array1, n, p;
    cout << "Nhap N: ";
    cin >> n;

    cout << "Nhap Tong P: ";

    array1 = new int[n];

    int max1 = INT_MIN;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> array1[i];

        if(max1 < array1[i])
        {
            max1 = array1[i];
        }

        cnt[array1[i]]++;
    }

    int dem = 0;

    for(int i = max1 ; i > 0 ; i--)
    {
        while(cnt[i] > 0 && p > 0)
        {
            cnt[i]--;
            p -= i;
            dem++;
        }
    }

    if(p > 0)
    {
        cout << "Khong Du So De Tong Lon Hon S" << endl;
    }
    else{
        cout << "So luong So Can Tim: " << dem << endl; 
    }
}