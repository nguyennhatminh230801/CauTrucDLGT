#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int DemChuSo(ll number, int cnt)
{
    if(number == 0)
    {
        return (cnt == 0 ? 1 : 0);
    }

    return 1 + DemChuSo(number / 10, cnt + 1);
}

int main()
{
    ll n;
    cin >> n;

    cout << DemChuSo(n, 0) << endl;
    return 0;
}