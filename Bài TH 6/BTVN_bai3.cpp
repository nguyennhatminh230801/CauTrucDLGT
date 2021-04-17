#include <bits/stdc++.h>
using namespace std;

#define N 100

void title() {
	cout << setw(15) << left << "Ma CB"
		 << setw(15) << left << "Ho dem"
		 << setw(15) << left << "Ten"
		 << setw(15) << left << "Gioi tinh"
		 << setw(15) << left << "Tuoi"
		 << setw(15) << left << "He so luong"
		 << setw(20) << left << "Luong co ban" << endl; 
}

struct CanBo {
	char maCB[10];
	char hoDem[30];
	char ten[20];
	char gioiTinh[20];
	int tuoi;
	int heSL;
	int luongCB;
};

struct List {
	int count;
	CanBo info[N];
};

List L;

void create(List &L) {
	L.count = -1;
}

void show(List L) {
	cout << "\n\t\t=================== THONG TIN CAN BO ===================\n";
	title();
	for (int i = 0; i <= L.count; i++) {
		cout << setw(15) << left << L.info[i].maCB
			 << setw(15) << left << L.info[i].hoDem
			 << setw(15) << left << L.info[i].ten
			 << setw(15) << left << L.info[i].gioiTinh
			 << setw(15) << left << L.info[i].tuoi
			 << setw(15) << left << L.info[i].heSL
			 << setw(20) << left << L.info[i].luongCB << endl; 
	}
	system("pause");
}

void nhap(List &L, int n) {
	while (L.count < n - 1) {
		L.count++;
		cout << "\nThong tin can bo " << L.count + 1 << endl;
		cout << "Ma can bo: ";
		fflush(stdin);
		gets(L.info[L.count].maCB);
		cout << "Ho dem: ";
		gets(L.info[L.count].hoDem);
		cout << "Ten: ";
		gets(L.info[L.count].ten);
		cout << "Gioi tinh: ";
		gets(L.info[L.count].gioiTinh);
		cout << "Tuoi: ";
		cin >> L.info[L.count].tuoi;
		cout << "He so luong: ";
		cin >> L.info[L.count].heSL;
		L.info[L.count].luongCB = L.info[L.count].heSL * 1490000;
	}
	show(L);
}

void DSCBNu(List L) {
	cout << "\n\t\t=================== DANH SACH CAN BO NU NHO HON 50 TUOI ===================\n";
	title();
	for (int i = 0; i <= L.count; i++) {
		if (L.info[i].tuoi < 50 && strcmp(L.info[i].gioiTinh, "Nu") == 0 || L.info[i].tuoi < 50 && strcmp(L.info[i].gioiTinh, "nu") == 0) {
			cout << setw(15) << left << L.info[i].maCB
				 << setw(15) << left << L.info[i].hoDem
				 << setw(15) << left << L.info[i].ten
				 << setw(15) << left << L.info[i].gioiTinh
				 << setw(15) << left << L.info[i].tuoi
				 << setw(15) << left << L.info[i].heSL
				 << setw(20) << left << L.info[i].luongCB << endl;
		}
	}
	system("pause");
}

void search(List L) {
	cout << "\n\t\t=================== CAN BO TEN TUNG DAU TIEN ===================\n";
	title();
	for (int i = 0; i<= L.count; i++) {
		if (strcmp(L.info[i].ten, "Tung") == 0) {
			cout << setw(15) << left << L.info[i].maCB
				 << setw(15) << left << L.info[i].hoDem
				 << setw(15) << left << L.info[i].ten
				 << setw(15) << left << L.info[i].gioiTinh
				 << setw(15) << left << L.info[i].tuoi
				 << setw(15) << left << L.info[i].heSL
				 << setw(20) << left << L.info[i].luongCB << endl;
			break;
		}
	}
	system("pause");
}

void them(List &L, CanBo t) {
	cout << "\n\t\t=================== DANH SACH CAN BO SAU KHI THEM CAN BO ===================\n";
	title();
	L.count++;
	for (int i = L.count; i > 3; i--) {
		L.info[i] = L.info[i - 1];
	}
	L.info[3] = t;
	show(L);
}

void menu(int n) {
	while (true) {
		system("cls");
		int luaChon;
		cout << "\tNHAP LUA CHON\n"
			 << "1. Danh sach can bo\n"
			 << "2. Danh sach can bo nu co tuoi nho hon 50\n"
			 << "3. Tim kiem can bo ten Tung\n"
			 << "4. Them can bo vao vi tri sau vi tri thu 3\n"
			 << "0. Ket thuc\n"
			 << "\t-----------------------------\n"
			 << "Lua chon: ";
		cin >> luaChon;
		if (luaChon < 0 || luaChon > 4) {
			cout << "Lua chon khong hop le";
			system("pause");
		}
		else if (luaChon == 1) {
			nhap(L, n);
		}
		else if (luaChon == 2) {
			DSCBNu(L);
		}
		else if (luaChon == 3) {
			search(L);
		}
		else if (luaChon == 4) {
			CanBo t;
			cout << "\nNhap thong tin can bo can them\n";
			cout << "Ma can bo: ";
			fflush(stdin);
			gets(t.maCB);
			cout << "Ho dem: ";
			gets(t.hoDem);
			cout << "Ten: ";
			gets(t.ten);
			cout << "Gioi tinh: ";
			gets(t.gioiTinh);
			cout << "Tuoi: ";
			cin >> t.tuoi;
			cout << "He so luong: ";
			cin >> t.heSL;
			t.luongCB = t.heSL * 1490000;
			them(L, t);
		}
		else
			break;
	}
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	create(L);
	menu(n);
	return 0;
}

