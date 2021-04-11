#include <bits/stdc++.h>
using namespace std;

//Khai báo CTDL danh sách 
struct SinhVien
{
    char MaSV[10];
    char HoDem[20];
    char Ten[10];
    char GioiTinh[4];
    int NamSinh;
    float DiemTK;

    SinhVien()
    {
        strcpy(this->MaSV, "");
        strcpy(this->HoDem, "");
        strcpy(this->Ten, "");
        strcpy(this->GioiTinh, "");
        this->NamSinh = 0;
        this->DiemTK = 0;
    }

    SinhVien(char *MaSV, char *HoDem, char *Ten, char *GioiTinh, int NamSinh, float DiemTK)
    {
        strcpy(this->MaSV, MaSV);
        strcpy(this->HoDem, HoDem);
        strcpy(this->Ten, Ten);
        strcpy(this->GioiTinh, GioiTinh);
        this->NamSinh = NamSinh;
        this->DiemTK = DiemTK;
    }
};

const int maxn = 100;

struct List
{
    int count;
    SinhVien e[maxn];
};

List L;

//Khởi tạo
void Init(List &L)
{
    L.count = -1;
}

//Kiểm tra rỗng
int Full(List &L)
{
    return (L.count == maxn - 1);
}

//Kiểm tra đầy
int Empty(List &L)
{
    return (L.count == -1);
}

//Thêm 1 phần tử vào cuối danh sách
int Append(List &L, SinhVien elem)
{
    if(Full(L))
    {
        return 0;
    }
    else
    {
        L.count++;
        L.e[L.count] = elem;
        return 1;
    }
}

//Xóa 1 phần tử khỏi danh sách
int Remove(List &L, int pos)
{
    if(!Empty(L) && pos > 0 && pos <= L.count + 1)
    {
        for(int i = pos ; i <= L.count ; i++)
        {
            L.e[i - 1] = L.e[i];
        }
        L.count--;
        return 1;
    }
    else
    {
        return 0;
    }
}

//Chèn 1 phần tử vào danh sách
int Insert(List &L, int pos, SinhVien elem)
{
    if(!Full(L) && pos > 0 && pos <= L.count + 1)
    {
        for(int i = L.count ; i >= pos - 1; i--)
        {
            L.e[i + 1] = L.e[i];
        }
        L.e[pos - 1] = elem;
        return 1;
    }
    else
    {
        return 0;
    }
}

//Sắp xếp DSSV theo chiều tăng dần của Tên SV(phương pháp lựa chọn)
void SortListBySelectionSort(List &L)
{
    for(int i = 0 ; i <= L.count - 1; i++)
    {
        int m = i;

        for(int j = i + 1 ; j <= L.count ; j++)
        {
            if(stricmp(L.e[m].Ten, L.e[j].Ten) == 1)
            {
                m = j;
            }
        }

        SinhVien temp = L.e[m];
        L.e[m] = L.e[i];
        L.e[i] = temp;
    }
}

//Hiển thị thông tin
void PrintList(List L)
{
    cout << setw(45) << "Thong Tin Danh Sach" << endl;
    cout << setw(12) << "Ma SV" 
         << setw(22) << "Ho Dem" 
         << setw(12) << "Ten" 
         << setw(10) << "Gioi Tinh"
         << setw(10) << "Nam Sinh"
         << setw(10) << "Diem TK"
         << endl; 

    for(int i = 0 ; i <= L.count ; i++)
    {
        cout << setw(12) << L.e[i].MaSV 
            << setw(22) << L.e[i].HoDem
            << setw(12) << L.e[i].Ten
            << setw(10) << L.e[i].GioiTinh
            << setw(10) << L.e[i].NamSinh
            << setw(10) << L.e[i].DiemTK
            << endl; 
    }
}

int main()
{
    Init(L);

    SinhVien SV1("SV1001", "Tran Van", "Thanh", "Nam", 1999, 7.5);
    SinhVien SV2("SV1002", "Nguyen Thi", "Huong", "Nu", 2000, 7.3);
    SinhVien SV3("SV1003", "Nguyen Van", "Binh", "Nam", 1998, 6.4);
    SinhVien SV4("SV1004", "Bui Thi", "Hong", "Nu", 2000, 5.8);
    SinhVien SV5("SV1005", "Duong Van", "Giang", "Nam", 2998, 8.3);

    Append(L, SV1);
    Append(L, SV2);
    Append(L, SV3);
    Append(L, SV4);
    Append(L, SV5);

    PrintList(L);

    int checkRemove = Remove(L, 4);
    cout << "Loai Bo Phan Tu " << (checkRemove ? "" : " Khong ") << " Thanh Cong" << endl;

    cout << "Sau khi thuc hien loai bo" << endl;
    PrintList(L);

    SinhVien SV6("SV1006", "Le Thi", "Doan", "Nu", 1998, 7.6);

    int checkInsert = Insert(L, 4, SV6);
    cout << "Chen Phan Tu " << (checkInsert ? "" : " Khong ") << " Thanh Cong" << endl;

    cout << "Sau khi thuc hien chen" << endl;
    PrintList(L);

    SortListBySelectionSort(L);

    cout << "Sau khi thuc hien sap xep" << endl;
    PrintList(L);
    return 0;
}