#include <bits/stdc++.h>
using namespace std;

void MergeofMergeSort(int array1[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    int L[n1], R[n2];
 
    
    for (int i = 0; i < n1; i++)
        L[i] = array1[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array1[mid + 1 + j];
 
   
    int i = 0;
    int j = 0;
    int k = left;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array1[k] = L[i];
            i++;
        }
        else {
            array1[k] = R[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1) {
        array1[k] = L[i];
        i++;
        k++;
    }
 
  
    while (j < n2) {
        array1[k] = R[j];
        j++;
        k++;
    }
}
void Sapxep(int array1[], int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    Sapxep(array1, left, mid);
    Sapxep(array1, mid + 1, right);
    MergeofMergeSort(array1, left, mid, right);
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

    Sapxep(array1, 0, n - 1);

    cout << "Day so sau khi sap: ";

    for(int i = 0 ; i < n ; i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;
    return 0;
}