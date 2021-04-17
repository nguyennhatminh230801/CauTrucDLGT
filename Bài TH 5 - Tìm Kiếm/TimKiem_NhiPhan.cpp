#include <bits/stdc++.h>
using namespace std;
 
int binarySearch(int arr[], int left, int right, int x) {
    int middle;
    while(left <= right) {
        middle = (left + right) / 2;

        if (arr[middle] == x)
            return middle;
        if (x > arr[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }
 
    return -1;
}
int main() {
    int arr[] = {04, 14, 24, 34, 54, 64, 74, 84, 94};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binarySearch(arr, 0, n-1, 34) << endl;
    cout << binarySearch(arr, 0, n-1, 60) << endl;
}