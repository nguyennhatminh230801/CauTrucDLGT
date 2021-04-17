#include<bits/stdc++.h>
using namespace std;

struct SinhVien {
    string hoTen;
    string gioiTinh;
    int namSinh;
    float diemTK;
};
typedef struct SinhVien SV;
void nhapDS (SV x[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"nhap thong tin HS thu "<<i+1;
        fflush(stdin);
        cout<<"\nnhap ho ten: ";getline(cin,x[i].hoTen);
        cout<<"nhap gioi tinh: ";getline(cin,x[i].gioiTinh);
        cout<<"nhap nam sinh:  ";cin>>x[i].namSinh;
        cout<<"nhap diem TK: ";cin>>x[i].diemTK;

    }
}
void xuatDS (SV x[], int n)
{
    cout << setw(15) << left << "Ho Ten" << setw(10) << left << "Gioi Tinh" 
        << setw(10) << left << "Nam Sinh" << setw(10) << left << "Diem TK" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << left << x[i].hoTen << setw(10) << left << x[i].gioiTinh 
        << setw(10) << left << x[i].namSinh << setw(10) << left << x[i].diemTK << endl;
    }
}

void sxNoiBot (SV x[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>i; j--)
        {
            if(x[j-1].hoTen > x[j].hoTen)
            {
                swap(x[j-1], x[j]);
            }

        }
    }
    xuatDS(x,n);
}
int main()
{
    SV *x;
    int n;
    cout<<"nhap so sv: ";
    cin>>n;
    x = new SV[n];
    nhapDS(x,n);
    cout<<"\n\t============XUAT DS==============\n";
    xuatDS(x,n);
    cout<<"\t\n=========DS SAU KHI SX=======\n";
    sxNoiBot(x,n);
    return 0;

}