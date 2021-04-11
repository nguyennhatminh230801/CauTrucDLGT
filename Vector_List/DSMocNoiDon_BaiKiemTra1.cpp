#include <bits/stdc++.h>
using namespace std;

//1.Cai dat CTDL danh sach
struct MonHoc
{
    char MaMH[10];
    char TenMH[30];
    int SoTC;
};

struct Node
{
    MonHoc infor;
    Node *next;
};

typedef Node *TRO;

TRO L;

//2.khoi tao ds rong
void Init(TRO &l)
{
    L = NULL;
}

//3. kiem tra danh sach rong/ day hay khong
bool isEmpty(TRO L)
{
    return L == NULL;
}

//4. dem so node trong danh sach
int CountNode(TRO L)
{
    TRO Q = L;

    if(isEmpty(Q))
    {
        return 0;
    }
    else
    {
        int i = 0;


        while (Q != NULL)
        {
            Q = Q->next;
            i++;
        }

        return i;
    }
}

//5. Tao 1 Node Moi
TRO CreateNode(MonHoc x1)
{
    TRO P = new Node;
    P->infor = x1;
    P->next = NULL;
    return P;
}

//6. Chen node P vao vi tri dau tien
void FirstAdd(TRO &L, TRO P)
{
    P->next = L;
    L = P;
}

//7. Tim mon hoc X
TRO Search(TRO L, MonHoc X)
{
    TRO Q1 = L;

    while(Q1 != NULL && stricmp(Q1->infor.TenMH, X.TenMH) != 0)
    {
        Q1 = Q1->next;
    }

    return Q1;
}

void PrintList(TRO L)
{
    TRO Q = L;

    while (Q != NULL)
    {
        cout << "Thong Tin Mon Hoc" << endl;
        cout << "Ma Mon: " << Q->infor.MaMH << endl;
        cout << "Ten Mon: " << Q->infor.TenMH << endl;
        cout << "So Tin Chi: " << Q->infor.SoTC << endl;
        Q = Q->next;
    }

    delete Q;
}

//8. Xoa Mon Hoc Dung Sau X
void Delete(TRO &L, MonHoc X)
{
    TRO Q2 = Search(L, X);

    TRO Q3 = Q2->next;

    if(Q3 == NULL)
    {
        return;
    }

    Q2->next = Q3->next;
    delete Q3;
}

int main()
{
    Init(L);

    MonHoc x1, x2;
    strcpy(x1.MaMH, "IT6002");
    strcpy(x1.TenMH, "Cau Truc Du Lieu Va Giai Thuat");
    x1.SoTC = 4;

    strcpy(x2.MaMH, "IT6005");
    strcpy(x2.TenMH, "Lap Trinh Huong Doi Tuong");
    x2.SoTC = 2;

    TRO p1 = CreateNode(x1);
    TRO p2 = CreateNode(x2);

    FirstAdd(L, p1);
    FirstAdd(L, p2);

    cout << "Danh Sach L" << endl;
    PrintList(L);

    cout << "So phan tu trong day:" << CountNode(L) << endl;

    TRO ans = Search(L, x1);

    if(ans == NULL)
    {
        cout << "Khong tim duoc mon hoc nay" << endl;
    }
    else
    {
        PrintList(ans);//Chi in thong tin ans
    }

    Delete(L, x1);

    cout << "Sau Khi Xoa Danh Sach Can Tim La: " << endl;
    PrintList(L);

    return 0;
}
