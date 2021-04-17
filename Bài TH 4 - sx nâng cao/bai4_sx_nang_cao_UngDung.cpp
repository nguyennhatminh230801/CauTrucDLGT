#include <bits/stdc++.h>

using namespace std;

struct SinhVien {
    string hoten;
    string gioitinh;
    int namsinh;
    float diemtk;
};
void nhap (SinhVien x[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"nhap sinh vien thu "<<i+1<<endl;
        fflush(stdin);
        cout<<"nhap ho ten: ";getline(cin, x[i].hoten);
        cout<<"nhap gioi tinh: ";getline(cin, x[i].gioitinh);
        cout<<"nhap nam sinh: ";cin>>x[i].namsinh;
        cout<<"nhap diem tk: ";cin>>x[i].diemtk;
    }
}
void xuat(SinhVien x[], int n)
{
    cout<<setw(10)<<left<<"ho ten"<<setw(10)<<left<<"gioi tinh"
        <<setw(10)<<left<<"nam sinh"<<setw(10)<<left<<"diem tk"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<setw(10)<<left<<x[i].hoten<<setw(10)<<left<<x[i].gioitinh
        <<setw(10)<<left<<x[i].namsinh<<setw(10)<<left<<x[i].diemtk<<endl;
    }
}
void sx_theo_ten (SinhVien x[], int left, int right)
{
            if(left < right)
        {
            int i = left, j = right;
            int mid = (left + right) / 2;
            string tam = x[mid].hoten;
        while(i <= j)
        {
                while(x[i].hoten < x[mid].hoten) i++;
                while(x[j].hoten > x[mid].hoten) j--;
                if(i<=j)
                {
                    swap(x[i], x[j]);
                    i++;
                    j--;
                }
        }
        sx_theo_ten(x, left, j);
        sx_theo_ten(x, i, right);

        }
}
int main()
{
    SinhVien *x;
    int n;
    cout<<"nhap so sinh vien: ";cin>>n;
    x = new SinhVien[n];
    int left = 0, right = n-1;
    nhap(x, n);
    cout<<"\n\t\t=============XUAT DS=========\n";
    xuat(x, n);
    cout<<"\nds sinh vien sau khi sx theo ten\n";
    sx_theo_ten(x, left, right);
    xuat(x,n);
    return 0;
}
