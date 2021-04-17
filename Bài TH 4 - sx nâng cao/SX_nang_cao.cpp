#include <bits/stdc++.h>
using namespace std;
//Quick Sort
void quicksort ( int a[], int left, int right)
{
	if(left < right)
    {
        int i = left, j = right;
        int mid = (left + right) / 2;
        int tam = a[mid];
       while(i <= j)
       {
            while(a[i] > a[mid]) i++;
            while(a[j] < a[mid]) j--;
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
void   hoanvi(int a[], int k, int n) {		
	int i = 2*k+1; 
	if(a[i] > a[i+1] && i+1 < n) i = i+1;      
	if(a[k] > a[i] && i < n) {	 	    
		int temp = a[k];
		a[k] = a[i];
		a[i] = temp;
	hoanvi(a, i, n); 
	}
}
void create_heap(int a[], int n) {	
	for(int i = n/2-1; i >= 0; i--) {
	hoanvi(a, i, n);
	}
}
void heapsort(int a[], int n) {		
	create_heap(a, n);
	for(int i = n-1; i >= 1; i--) {
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
	hoanvi(a, 0, i); 
	}
}
//mergeSort
void merge(int a[], int left, int mid, int right) {	
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *a1 = new int[n1], 
		*a2 = new int[n2];

	for(int i = 0; i < n1; i++) {
		a1[i] = a[left + i];
	}
	for(int i = 0; i < n2; i++) {
		a2[i] = a[mid + i + 1];
	}
	
	int i = 0, j = 0, k = left; 
	while(i < n1 && j < n2) {
		a[k++] = (a1[i] > a2[j]) ? a1[i++] : a2[j++];    
	}	
	while(i < n1) {
		a[k++] = a1[i++];
	}
	while(j < n2) {
		a[k++] = a2[j++];
	}
}
void mergesort(int a[], int left, int right) {
	if(left < right) {
		int mid = left + (right-left)/2;
		mergesort(a, left, mid);
		mergesort(a, mid+1, right);
		merge(a, left, mid, right);
	}
}
int main()
{
    int a[] =  {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(a) / sizeof(int);
    int left = 0, right = n-1;
    // quicksort(a, left, right);
    // heapsort(a,n);
    mergesort(a, left, right);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}