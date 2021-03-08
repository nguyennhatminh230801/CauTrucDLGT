#include <bits/stdc++.h>
using namespace std;

int menhgia[5] = {10000, 5000, 2000, 1000, 500};
int main()
{
    int SoTien;
    cin >> SoTien;

    //so to tien
    int numbers = 0;
    
    for(int i = 0 ; i < 5 ; i++)
    {
        numbers += SoTien / menhgia[i];
        SoTien = SoTien % menhgia[i];
    }

    cout << "So To Tien It Nhat La: " << numbers << endl;
}