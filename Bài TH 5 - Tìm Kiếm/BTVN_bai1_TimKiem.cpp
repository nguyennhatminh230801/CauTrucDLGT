#include <bits/stdc++.h>
using namespace std;

struct Word {
	char info[30];
};

void nhapDS(Word *s, int n) {
	fflush(stdin);
	for (int i = 0; i < n; i++) {
		gets(s[i].info);
	}
}

void selectionSort(Word *s, int n) {
	for (int i = 0; i < n - 1; i++) {
		int index = i;
		for (int j = i + 1; j < n; j++) {
			if (strcmp(s[j].info, s[index].info) < 0) {
				index = j;
			}
		}
		Word tg = s[i];
		s[i] = s[index];
		s[index] = tg;
	}
}

void binarySearch(Word* s, int l, int r, char* name) {
	if (l <= r) {
		int m = (l + r) / 2;
		if (strcmp(s[m].info, name) == 0) {
			cout << "Tu " << name << " o vi tri thu " << m + 1 << " trong tu dien";
		}			
		else if (strcmp(s[m].info, name) > 0)
			binarySearch(s, l, m - 1, name);
		else
			binarySearch(s, m + 1, r, name);	
	}
	else
		cout << "Khong ton tai tu trong tu dien";
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	Word *ds = new Word[n];
	nhapDS(ds, n);
	selectionSort(ds, n);
	char name[30];
	cout << "\nNhap tu can tim: ";
	fflush(stdin);
	gets(name);
	binarySearch(ds, 0, n - 1, name);
	return 0;
}
