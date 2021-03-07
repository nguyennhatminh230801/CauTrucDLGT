#include <bits/stdc++.h>
using namespace std;

int count(int array1[], int left, int right, int x)
{
    if(left == right)
    {
        return (array1[left] == x);
    }
    else if (right - left == 1)
    {
        return(array1[left] == x) + (array1[right] == x);
    }
    else
    {
        int mid = (left + right) / 2;

        int cntleft = count(array1, left, mid, x);
        int cntright = count(array1, mid + 1, right, x);

        return cntleft + cntright;
    }
}

int main()
{
    int n, x;
    cin >> n >> x;

    int array1[n + 1];

    for (int i = 1 ; i <= n ; i++) {
        cin >> array1[i];
    }

    cout << count(array1, 1, n, x) << endl;
    return 0;
}