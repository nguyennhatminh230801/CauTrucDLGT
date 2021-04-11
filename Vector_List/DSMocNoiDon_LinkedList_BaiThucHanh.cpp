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

struct Node
{
    SinhVien infor;
    Node *next;
};

typedef Node* TRO;

TRO L;

//Khởi tạo Danh Sách
void Init(TRO &L)
{
    L = NULL;
}

//Kiểm Tra Danh Sách Rỗng
int Empty(TRO L)
{
    return L == NULL;
}

//Duyệt Danh Sách
void Traversal(TRO L)
{
    TRO Q = L;

    if(!Empty(L))
    {
        cout << setw(45) << "Thong Tin Danh Sach" << endl;
        cout << setw(12) << "Ma SV" 
            << setw(22) << "Ho Dem" 
            << setw(12) << "Ten" 
            << setw(10) << "Gioi Tinh"
            << setw(10) << "Nam Sinh"
            << setw(10) << "Diem TK"
            << endl; 

        while (Q != NULL)
        {
            cout << setw(12) << Q->infor.MaSV
                << setw(22) << Q->infor.HoDem
                << setw(12) << Q->infor.Ten
                << setw(10) << Q->infor.GioiTinh
                << setw(10) << Q->infor.NamSinh
                << setw(10) << Q->infor.DiemTK
                << endl; 
            
            Q = Q->next;
        }
    }
}

//Tìm kiếm 1 nút trên danh sách (Giả sử )
TRO Search(TRO L, char *Ten)
{
    TRO Q = L;

    while (Q != NULL && strcmp(Q->infor.Ten, Ten) != 0)
    {
        Q = Q->next;
    }
    
    return Q;
}

//Chèn 1 nút vào đầu danh sách
void FirstAdd(TRO &L, SinhVien elem)
{
    TRO P = new Node;
    P->infor = elem;
    P->next = L;
    L = P;
}

//Chèn 1 nút vào cuối danh sách
void Append(TRO &L, SinhVien elem)
{
    TRO P = new Node;
    TRO Q;
    P->infor = elem;
    P->next = NULL;

    if(Empty(L))
    {
        L = P;
    }
    else
    {
        Q = L;

        while (Q->next != NULL)
        {
            Q = Q->next;
        }

        Q->next = P;
    }
}

//Chen 1 nut sau con tro Q
void InsertAfter(TRO &L, TRO Q, SinhVien elem)
{
    TRO P = new Node;
    P->infor = elem;
    P->next = Q->next;
    Q->next = P;
}

//Xóa nút đàu tiên trong danh sách
void FirstNodeDelete(TRO &L)
{
    TRO Q = L;
    L = L->next;
    delete Q;
}

//Xóa nút đứng sau con trỏ M
void DeleteNodeAfter(TRO &L, TRO M)
{
    TRO Q = M->next;
    M->next = Q->next;
    delete Q;
}

int main()
{
    Init(L);

    SinhVien SV1("SV1001", "Tran Van", "Thanh", "Nam", 1999, 7.5f);
    SinhVien SV2("SV1002", "Nguyen Thi", "Huong", "Nu", 2000, 7.3f);
    SinhVien SV3("SV1003", "Nguyen Van", "Binh", "Nam", 1998, 6.4f);
    SinhVien SV4("SV1004", "Bui Thi", "Hong", "Nu", 2000, 5.8f);
    SinhVien SV5("SV1005", "Duong Van", "Giang", "Nam", 2998, 8.3f);

    Append(L, SV1);
    Append(L, SV2);
    Append(L, SV3);
    Append(L, SV4);
    Append(L, SV5);

    //Traversal(L);

    //tìm SV có Tên Bình
    TRO find = Search(L, "Binh");
    cout << ((find != NULL) ? "Co" : "Khong") << " tim duoc SV Ten Binh trong danh sach" << endl;
    
    FirstAdd(L, SV1);
    Traversal(L);

    InsertAfter(L, find, SV5);
    Traversal(L);

    FirstNodeDelete(L);
    Traversal(L);   

    DeleteNodeAfter(L, find);
    Traversal(L);
    return 0;   
}