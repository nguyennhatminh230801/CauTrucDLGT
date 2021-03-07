#include <bits/stdc++.h>
using namespace std;

int ChiaDeTri(int array1[], int left, int right)
{
    if(left == right)
    {
        return array1[left];
    }
    else if(left == right - 1)
    {
        return array1[left] + array1[right];
    }
    else
    {
        int mid = (left + right) / 2;
        int answer1 = ChiaDeTri(array1, left, mid);
        int answer2 = ChiaDeTri(array1, mid + 1, right);

        return answer1 + answer2;
    }
}
int main()
{
    int n;
    cout << "Nhap N: ";
    cin >> n;

    int array1[n];
    cout << "Nhap Day so: ";
    for(int i = 0 ; i < n ; i++)
    {
        cin >> array1[i];
    }

    
    cout << "Tong day so la: " << ChiaDeTri(array1, 0, n - 1) << endl;
}