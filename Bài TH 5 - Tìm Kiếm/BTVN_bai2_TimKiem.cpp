#include <bits/stdc++.h>
using namespace std;

void title() {
	cout << "\n\t\t============== THONG TIN TAI SAN ==============\n"
		 << setw(15) << left << "Ma TS"
		 << setw(15) << left << "Ten TS"
		 << setw(15) << left << "Gia tri"
		 << setw(15) << left << "Tinh trang" << endl;
}

struct TaiSan {
	int maTS;
	char tenTS[30];
	float GT;
	char TT[30];
};

void nhapDS(TaiSan* ts, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nThong tin tai san " << i + 1;
		cout << "\nMa TS: ";
		cin >> ts[i].maTS;
		cout << "Ten TS: ";
		fflush(stdin);
		gets(ts[i].tenTS);
		cout << "Gia tri: ";
		cin >> ts[i].GT;
		cout << "Tinh trang: ";
		fflush(stdin);
		gets(ts[i].TT);
	}
}

void show(TaiSan* ts, int n) {
	title();
	for (int i = 0; i < n; i++) {
		cout << setw(15) << left << ts[i].maTS
			 << setw(15) << left << ts[i].tenTS
			 << setw(15) << left << ts[i].GT
			 << setw(15) << left << ts[i].TT << endl;
	}
}

void selectionSort(TaiSan* ts, int n) {
	for (int i = 0; i < n - 1; i++) {
		int index = i;
		for (int j = i + 1; j < n; j++) {
			if (ts[j].GT > ts[index].GT) {
				index = j;
			}
		}
		TaiSan tg = ts[i];
		ts[i] = ts[index];
		ts[index] = tg;
	}
}

void searchMaTS(TaiSan* ts, int n, int maTS) {
	int mark = 0;
	for (int i = 0; i < n; i++) {
		if (ts[i].maTS == maTS) {
			title();
			cout << setw(15) << left << ts[i].maTS
				 << setw(15) << left << ts[i].tenTS
				 << setw(15) << left << ts[i].GT
				 << setw(15) << left << ts[i].TT << endl;
			mark = 1;
		}
	}
	if (mark == 0)
		cout << "Khong ton tai tai san trong danh sach";
}

void searchTenTS(TaiSan* ts, int n, char* tenTS) {
	int mark = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(ts[i].tenTS, tenTS) == 0) {
			title();
			cout << setw(15) << left << ts[i].maTS
				 << setw(15) << left << ts[i].tenTS
				 << setw(15) << left << ts[i].GT
				 << setw(15) << left << ts[i].TT << endl;
			mark = 1;
		}
	}
	if (mark == 0)
		cout << "Khong ton tai tai san trong danh sach";
}

void searchGTTS(TaiSan* ts, int n, float GT) {
	int mark = 0;
	for (int i = 0; i < n; i++) {
		if (ts[i].GT == GT) {
			title();
			cout << setw(15) << left << ts[i].maTS
				 << setw(15) << left << ts[i].tenTS
				 << setw(15) << left << ts[i].GT
				 << setw(15) << left << ts[i].TT << endl;
			mark = 1;
		}
	}
	if (mark == 0)
		cout << "Khong ton tai tai san trong danh sach";
}

void searchTTTS(TaiSan* ts, int n, char* TT) {
	int mark = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(ts[i].TT, TT) == 0) {
			title();
			cout << setw(15) << left << ts[i].maTS
				 << setw(15) << left << ts[i].tenTS
				 << setw(15) << left << ts[i].GT
				 << setw(15) << left << ts[i].TT << endl;
			mark = 1;
		}
	}
	if (mark == 0)
		cout << "Khong ton tai tai san trong danh sach";
}

void binarySearchGT(TaiSan* ts, int l, int r, float GT) {
	if (l <= r) {
		int m = (l + r) / 2;
		if (ts[m].GT == GT) {
			title();
			cout << setw(15) << left << ts[m].maTS
				 << setw(15) << left << ts[m].tenTS
				 << setw(15) << left << ts[m].GT
				 << setw(15) << left << ts[m].TT << endl;
		}			
		else if (ts[m].GT < GT)
			binarySearchGT(ts, l, m - 1, GT);
		else
			binarySearchGT(ts, m + 1, r, GT);	
	}
	else
		cout << "Khong ton tai tai san trong danh sach";
}

void menu(TaiSan* ts, int n) {
	while (true) {
		system("cls");
		int luaChon;
		cout << "\nNhap thong tin tai san can tim kiem\n"
			 << "1. Ma tai san\n"
			 << "2. Ten tai san\n"
			 << "3. Gia tri tai san\n"
			 << "4. Tinh trang tai san\n"
			 << "0. Ket thuc\n" 
			 << "\t\t---------------------------------\n"
			 << "Lua chon: ";
		cin >> luaChon;
		if (luaChon < 0 || luaChon > 4) {
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luaChon == 1) {
			int maTS;
			cout << "Ma TS: ";
			cin >> maTS;
			searchMaTS(ts, n, maTS);
			system("pause");
		}
		else if (luaChon == 2) {
			char tenTS[30];
			cout << "Ten TS: ";
			fflush(stdin);
			gets(tenTS);
			searchTenTS(ts, n, tenTS);
			system("pause");
		}
		else if (luaChon == 3) {
			float GT;
			cout << "Gia tri: ";
			cin >> GT;
//			searchGTTS(ts, n, GT);
			binarySearchGT(ts, 0, n - 1, GT);
			system("pause");
		}
		else if (luaChon == 4) {
			char TT[30];
			cout << "Tinh trang: ";
			fflush(stdin);
			gets(TT);
			searchTTTS(ts, n, TT);
			system("pause");
		}
		else
			break;
	}
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	
	TaiSan *ds = new TaiSan[n];
	nhapDS(ds, n);
	selectionSort(ds, n);
	
	menu(ds, n);
	return 0;
}
