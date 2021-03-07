#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int UCLN(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else{
        return UCLN(b, a % b);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << UCLN(a, b) << endl;
    return 0;
}