#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void Chuyen(int n, char a, char b, char c)
{
    if(n == 1)
    {
        cout << "Chuyen 1 dia tu " << a  << " sang " << c << endl;
    }
    else
    {
        Chuyen(n - 1, a, c, b);
        Chuyen(1, a, b, c);
        Chuyen(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    cout << "Nhap N:";
    cin >> n;

    Chuyen(n, 'A', 'B', 'C');

    return 0;
}