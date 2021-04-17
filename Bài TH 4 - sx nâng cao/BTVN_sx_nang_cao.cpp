#include <bits/stdc++.h>
using namespace std;
//Quick Sort
void quicksort ( string a[], int left, int right)
{
	if(left < right)
    {
        int i = left, j = right;
        int mid = (left + right) / 2;
        string tam = a[mid];
       while(i <= j)
       {
            while(a[i] < a[mid]) i++;
            while(a[j] > a[mid]) j--;
            if(i<=j)
            {
                swap(a[i], a[j]);
                i++;
                j--;
            }
       }
       quicksort(a, left, j);
       quicksort(a, i, right);

    }
}
// Heap Sort
void heapify(string a[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1;
    int r = 2*i + 2; 
    if (l < n && a[l] > a[largest]) 
        largest = l; 
    if (r < n && a[r] > a[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(a[i], a[largest]); 
        heapify(a, n, largest); 
    } 
} 
  
void heapSort(string a[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(a, n, i); 
    for (int i=n-1; i>0; i--) 
    {
        swap(a[0], a[i]); 
        heapify(a, i, 0); 
    } 
} 
//mergeSort
void merge(string a[], int left, int mid, int right) {	
	int n1 = mid - left + 1;
	int n2 = right - mid;

	string *a1 = new string[n1], 
		*a2 = new string[n2];

	for(int i = 0; i < n1; i++) {
		a1[i] = a[left + i];
	}
	for(int i = 0; i < n2; i++) {
		a2[i] = a[mid + i + 1];
	}
	
	int i = 0, j = 0, k = left; 
	while(i < n1 && j < n2) {
		a[k++] = (a1[i] < a2[j]) ? a1[i++] : a2[j++];    
	}	
	while(i < n1) {
		a[k++] = a1[i++];
	}
	while(j < n2) {
		a[k++] = a2[j++];
	}
}
void mergesort(string a[], int left, int right) {
	if(left < right) {
		int mid = left + (right-left)/2;
		mergesort(a, left, mid);
		mergesort(a, mid+1, right);
		merge(a, left, mid, right);
	}
}
int main()
{
    string a[] =  {"John", "Cool", "Bee", "Try", "Thor", "Zil", "Adam", "Dany", "Milk"};
    int n = 9;
    int left = 0, right = n-1;
    // quicksort(a, left, right);
    // heapSort(a,n);
    mergesort(a, left, right);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}