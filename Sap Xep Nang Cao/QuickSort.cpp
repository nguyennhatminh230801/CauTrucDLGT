#include <bits/stdc++.h>
using namespace std;


int partition(int array1[], int low, int high)
{
    int pivot = array1[high]; //đặt phần tử trong đuôi làm chốt
    int left = low;
    int right = high - 1;

    while (true)
    {
        while (left <= right && array1[left] < pivot) // Tìm phần tử >= arr[pivot]
        {
            left++;
        }
        
        while (left <= right && array1[right] > pivot) // Tìm phần tử <= arr[pivot]
        {
            right--;
        }
        
        if(left >= right) // Đã duyệt xong thì thoát vòng lặp
        {
            break;
        }

        swap(array1[left], array1[right]);// Nếu chưa xong, đổi chỗ.
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    
    swap(array1[left], array1[high]);

    return left;
}

void QuickSort(int array1[], int left, int right)
{
    if(left < right)
    {
        /* par là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int par = partition(array1, left, right);
        
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        QuickSort(array1, left, par - 1);
        QuickSort(array1, par + 1, right);
    }    
}
void PrintArray(int x[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main()
{
    int x[] = {34, 14, 24, 54, 84, 64, 94, 74, 4};
    int n = sizeof(x) / sizeof(x[0]);

    cout << "Truoc Khi Sap Xep: ";
    PrintArray(x, n);

    QuickSort(x, 0, n - 1);
          
    cout << "Sau Khi Sap Xep: ";
    PrintArray(x, n);
    return 0;
}