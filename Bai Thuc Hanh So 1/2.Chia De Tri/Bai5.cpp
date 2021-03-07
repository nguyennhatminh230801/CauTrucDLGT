#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binpow(ll a, ll n)
{
    if(n == 1)
    {
        return 1ll * a;
    }
    
    ll res1 = binpow(a, n / 2);
    
    return 1ll * res1 * res1 * (n % 2 == 1 ? a : 1);
}

int main()
{
    int a, n;
    cin >> a >> n;

    cout << pow(a, n) << endl;
    return 0; 
}