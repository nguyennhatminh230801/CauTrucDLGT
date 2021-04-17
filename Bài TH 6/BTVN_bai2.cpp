#include <bits/stdc++.h>
using namespace std;

#define MAX 10

void title() {
	cout << "\n\t\t================ THONG TIN HANG ================\n"
		 << setw(5) << left << "STT"
		 << setw(15) << left << "Ma hang"
		 << setw(15) << left << "Ten hang"
		 << setw(15) << left << "DV tinh"
		 << setw(15) << left << "Don gia"
		 << setw(15) << left << "So Luong"
		 << setw(15) << left << "Thanh tien" << endl;
}

struct Hang {
	char maHang[15];
	char ten[30];
	char donVT[15];
	int donGia;
	int soLuong;
	long thanhTien;
};

struct List {
	int count;
	Hang info[MAX];
};

List L;

void create(List &L) {
	L.count = -1;
}

void show(List L) {
	title();
	for (int i = 0; i <= L.count; i++) {
		cout << setw(5) << left << i + 1
		 	 << setw(15) << left << L.info[i].maHang
			 << setw(15) << left << L.info[i].ten
			 << setw(15) << left << L.info[i].donVT
			 << setw(15) << left << L.info[i].donGia
			 << setw(15) << left << L.info[i].soLuong
			 << setw(15) << left << L.info[i].thanhTien << endl;
	}
	system("pause");
}

void nhap(List &L) {
	while (L.count < 5) {
		L.count++;
		cout << "\nThong tin mat hang " << L.count + 1 << endl;
		cout << "Ma hang: ";
		fflush(stdin);
		gets(L.info[L.count].maHang);
		cout << "Ten hang: ";
		gets(L.info[L.count].ten);
		cout << "Don vi tinh: ";
		gets(L.info[L.count].donVT);
		cout << "Don gia: ";
		cin >> L.info[L.count].donGia;
		cout << "So luong: ";
		cin >> L.info[L.count].soLuong;
		L.info[L.count].thanhTien = L.info[L.count].donGia * L.info[L.count].soLuong;
	}
	show(L);
}

void xoa(List &L) {
	for (int i = 2; i <= L.count; i++) {
		L.info[i] = L.info[i + 1];
	}
	L.count--;
	show(L);
}

void chen(List &L, Hang t) {
	L.count++;
	for (int i = L.count; i > 0; i--) {
		L.info[i] = L.info[i - 1];
	}
	L.info[0] = t;
	show(L);
}

void sort(List L) {
	for (int i = 0; i < L.count; i++) {
		for (int j = L.count; j > i; j--) {
			if (L.info[j].thanhTien > L.info[j - 1].thanhTien) {
				Hang tg = L.info[j];
				L.info[j] = L.info[j - 1];
				L.info[j - 1] = tg;
			}
		}
	}
	show(L);
}

void menu() {
	while (true) {
		system("cls");
		int luaChon;
		cout << "\tNHAP LUA CHON\n"
			 << "1. Danh sach hang\n"
			 << "2. Xoa phan tu thu 3\n"
			 << "3. Chen hang vao vi tri dau tien\n"
			 << "4. Sap xep danh sach\n"
			 << "0. Ket thuc\n"
			 << "\t-----------------------------\n"
			 << "Lua chon: ";
		cin >> luaChon;
		if (luaChon < 0 || luaChon > 4) {
			cout << "Lua chon khong hop le";
			system("pause");
		}
		else if (luaChon == 1) {
			nhap(L);
		}
		else if (luaChon == 2) {
			xoa(L);
		}
		else if (luaChon == 3) {
			Hang t;
			cout << "\nNhap thong tin hang can chen\n";
			cout << "Ma hang: ";
			fflush(stdin);
			gets(t.maHang);
			cout << "Ten hang: ";
			gets(t.ten);
			cout << "Don vi tinh: ";
			gets(t.donVT);
			cout << "Don gia: ";
			cin >> t.donGia;
			cout << "So luong: ";
			cin >> t.soLuong;
			t.thanhTien = t.donGia * t.soLuong;
			chen(L, t);
		}
		else if (luaChon == 4) {
			sort(L);
		}
		else
			break;
	}
}

int main() {
	create(L);
	menu();
	return 0;
}

