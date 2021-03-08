#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, w;
    cin >> n >> w;

    int array1[n + 1], array2[n + 1];
    for (int i = 0 ; i < n ; i++) {
        cin >> array1[i];
    }

    for (int i = 0 ; i < n ; i++) {
        cin >> array2[i];
    }

    int dp[n + 1][w + 1];

    for(int i = 0 ; i <= n ; i++)
    {
        for(int weight = 0 ; weight <= w ; weight++)
        {
            if(i == 0 or weight == 0)
            {
                dp[i][weight] = 0;
            }
            else if (array1[i - 1] <= weight)
            {
                dp[i][weight] = max(array2[i - 1] + dp[i - 1][w - array1[i - 1]], dp[i - 1][weight]);
            }
            else
            {
                dp[i][weight] = dp[i - 1][weight];
            }
        }
    }

    cout << dp[n][w] << endl;
     
    return 0;
}