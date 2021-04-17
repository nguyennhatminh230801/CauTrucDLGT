#include <bits/stdc++.h>
using namespace std;

void title() {
	cout << "\n\t\t============= THONG TIN HOC SINH =============\n"
		 << setw(15) << left << "Ho ten"
		 << setw(15) << left << "Gioi tinh"
		 << setw(15) << left << "Nam sinh"
		 << setw(15) << left << "Diem TK" << endl;
}

struct HocSinh {
	char hoTen[30];
	char gioiTinh[10];
	int namSinh;
	float diemTK;
};

void nhapDS(HocSinh* hs, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nThong tin hoc sinh " << i + 1;
		cout << "\nHo ten: ";
		fflush(stdin);
		gets(hs[i].hoTen);
		cout << "Gioi tinh: ";
		gets(hs[i].gioiTinh);
		cout << "Nam sinh: ";
		cin >> hs[i].namSinh;
		cout << "Diem TK: ";
		cin >> hs[i].diemTK;
	}
}

void show(HocSinh* hs, int n) {
	title();
	for (int i = 0; i < n; i++) {
		cout << setw(15) << left << hs[i].hoTen
			 << setw(15) << left << hs[i].gioiTinh
			 << setw(15) << left << hs[i].namSinh
			 << setw(15) << left << hs[i].diemTK << endl;
	}
}

void selectionSort(HocSinh* hs, int n) {
	for (int i = 0; i < n - 1; i++) {
		int index = i;
		for (int j = i + 1; j < n; j++) {
			if (hs[j].diemTK > hs[index].diemTK) {
				index = j;
			}
		}
		HocSinh tg = hs[i];
		hs[i] = hs[index];
		hs[index] = tg;
	}
}

void searchName(HocSinh* hs, int n, char* name) {
	int mark = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(hs[i].hoTen, name) == 0) {
			title();
			cout << setw(15) << left << hs[i].hoTen
				 << setw(15) << left << hs[i].gioiTinh
				 << setw(15) << left << hs[i].namSinh
				 << setw(15) << left << hs[i].diemTK << endl;
			mark = 1;
		}
	}
	if (mark == 0)
		cout << "Khong ton tai hoc sinh trong danh sach";
}

void searchScores(HocSinh* hs, int n, float diem) {
	int mark = 0;
	for (int i = 0; i < n; i++) {
		if (hs[i].diemTK == diem) {
			title();
			cout << setw(15) << left << hs[i].hoTen
				 << setw(15) << left << hs[i].gioiTinh
				 << setw(15) << left << hs[i].namSinh
				 << setw(15) << left << hs[i].diemTK << endl;
			mark = 1;
		}
	}
	if (mark == 0)
		cout << "Khong ton tai hoc sinh trong danh sach";
}

void binarySearchScores(HocSinh* hs, int l, int r, float diem) {
	if (l <= r) {
		int m = (l + r) / 2;
		if (hs[m].diemTK == diem) {
			title();
			cout << setw(15) << left << hs[m].hoTen
				 << setw(15) << left << hs[m].gioiTinh
				 << setw(15) << left << hs[m].namSinh
				 << setw(15) << left << hs[m].diemTK << endl;
		}			
		else if (hs[m].diemTK < diem)
			binarySearchScores(hs, l, m - 1, diem);
		else
			binarySearchScores(hs, m + 1, r, diem);	
	}
	else
		cout << "Khong ton tai hoc sinh trong danh sach";
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	
	HocSinh *ds = new HocSinh[n];
	nhapDS(ds, n);
	show(ds, n);
	
	selectionSort(ds, n);
	show(ds, n);
	
	char name[30];
	cout << "\nNhap ten hoc sinh can tim: ";
	fflush(stdin);
	gets(name);
	searchName(ds, n, name);
	
	float diem;
	cout << "Nhap diem cua hoc sinh can tim: ";
	cin >> diem;
//	searchScores(ds, n, diem);
	binarySearchScores(ds, 0, n - 1, diem);
	
	return 0;
}