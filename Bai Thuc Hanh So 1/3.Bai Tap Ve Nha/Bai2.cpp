#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void Innguoc(char *s1, int pos1)
{
    if(pos1 == 0)
    {
        cout << s1[0] << endl;
        return;
    }
    
    cout << s1[pos1];
    Innguoc(s1, pos1 - 1);
}

int main()
{
    char str1[30];

    fflush(stdin);
    gets(str1);

    Innguoc(str1, strlen(str1) - 1);
    return 0;
}