#include <bits/stdc++.h>
using namespace std;

int findMax(int array1[], int left, int right)
{
    if(left == right)
    {
        return array1[left];
    }
    else if (right - left == 1)
    {
        return (array1[left] > array1[right] ? array1[left] : array1[right]);
    }
    else{
        int mid = (left + right) / 2;
        
        int value1 = findMax(array1, left, mid);
        int value2 = findMax(array1, mid + 1, right);
        
        return (value1 > value2 ? value1 : value2);
    }
}

int main()
{
    int n;
    cin >> n;

    int array1[n + 1];

    for (int i = 1 ; i <= n ; i++) {
        cin >> array1[i];
    }

    cout << findMax(array1, 1, n) << endl;
    return 0;
}