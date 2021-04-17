#include <bits/stdc++.h>
using namespace std;

void sxNoiBot (int x[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>i; j--)
        {
            if(x[j-1] < x[j])
            swap(x[j-1], x[j]);
        }
    }
}

void sxChon (int x[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int max = i;
        for(int j = i+1; j<n; j++)
        {
            if(x[j] > x[max])
            max = j;
        }
        swap(x[i], x[max]);
    }
}
void sxChen (int x[], int n)
{
    for(int i=1; i<n; i++)
    {
        int tam = x[i];
        int j = i-1;
        while(j>=0 && x[j] < tam)
        {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = tam;
    }
}

int main()
{
    int x[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(x) / sizeof(int);
    //sxNoiBot(x,n);
    sxChen(x,n);
    //sxChon(x,n);
    for(int i=0; i<n; i++)
    {
        cout<<x[i]<<' ';
    }
    return 0;
}