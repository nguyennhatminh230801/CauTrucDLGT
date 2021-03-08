#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;

//bang luu tru ket qua
int board[maxn][maxn];

//cac huong di chuyen cua quan ma
int MoveX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 },
    MoveY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

//kiem tra xem 1 o co nam ngoai khoang hoac da dat chan den
bool IsSafe(int resX, int resY, int n)
{
    return resX >= 1 && resX <= n && resY >= 1 && resY <= n && board[resX][resY] == -1;
}

//xay dung cac cau hinh quay lui bai toan
bool Backtrack(int x, int y, int iThChessPlace, int n)
{
    int resX, resY;

    //neu di chuyen du n * n - 1 thi dung viec tim kiem
    if(iThChessPlace == n * n)
    {
        return true;
    }

    //thu cac huong di chuyen cua quan co
    for(int i = 0 ; i < 8 ; i++)
    {
        resX = x + MoveX[i];
        resY = y + MoveY[i];

        if(IsSafe(resX, resY, n) == true)
        {
            //dat tam vi tri dat chan la i
            board[resX][resY] = iThChessPlace;
            
            //neu co the di tiep
            if(Backtrack(resX, resY, iThChessPlace + 1, n) == true){
                return true;
            }
            else{
                //con khong se lui lai va chon huong di khac
                board[resX][resY] = -1;
            }
        }
    }

    //tra ve sai neu nhu khong tim duoc ket qua thoa man bai toan
    return false;
}

int main()
{
    //khoi tao gia tri -1 de coi nhu quan co chua dat chan toi
    for(int i = 0 ; i < maxn ; i++)
    {
        for(int j = 0 ; j < maxn ; j++)
        {
            board[i][j] = -1;
        }
    }

    int n;
    cout << "Nhap N: ";
    cin >> n;

    //con co xuat phat o vi tri (1, 1)
    board[1][1] = 0;

    //kiem tra ket qua hop le
    bool check = Backtrack(1, 1, 1, n);

    if(check == false){
        cout << "Khong tim duoc ket qua" << endl;
    }
    else{
        cout << "KET QUA LA: " << endl;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}
