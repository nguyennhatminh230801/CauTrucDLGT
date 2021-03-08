#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    //so manh bia it nhat
    int answer = 0;

    //neu m le va n le se ton tai 1 x 1
    if(m % 2 == 1 && n % 2 == 1)
    {
        answer++;
    }
    
    //Lay 2 x 2
    int n1 = n / 2, m1 = m / 2;
    answer += n1 * m1;

    int n2, m2;
    n2 = n - (2 * n1);
    m2 = m - (2 * m1);
    
    if(n2 > 0)
    {
        answer += (m / 2);
    }

    if(m2 > 0)
    {
        answer += (n / 2);
    }

    cout << answer << endl;
}   