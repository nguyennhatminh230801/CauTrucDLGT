#include<bits/stdc++.h>
using namespace std;

void sxNoiBot (string x[], int n)
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

void sxChon (string x[], int n)
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
void sxChen (string x[], int n)
{
    for(int i=1; i<n; i++)
    {
        string tam = x[i];
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
    string x[] =  {"John", "Cool", "Bee", "Try", "Thor", "Zil", "Adam", "Dany", "Milk"};
    sxNoiBot(x,9);
    //sxChon(x,9);
    //sxChen(x,9);
    for(int i=0; i<9; i++)
    {
        cout<<x[i]<<' ';
    }
    return 0;
}
