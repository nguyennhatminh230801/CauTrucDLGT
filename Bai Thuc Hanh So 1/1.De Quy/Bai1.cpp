#include <bits/stdc++.h>
using namespace std;

/*
    -Định nghĩa số fibonacci:
    
    f(n) = 1 nếu n <= 2
    f(n) = f(n - 1) + f(n - 2) nếu n > 2
*/
typedef long long ll;

ll fibonacci(int n)
{
    if(n <= 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    cin >> n;
    
    cout << "So fibonacci thu " << n << "la: " << fibonacci(n) << endl;

    for(int i = 1 ; i <= n ; i++)
    {
        cout << "So fibonacci thu " << i << "la: " << fibonacci(i) << endl;
    }
    return 0;
}