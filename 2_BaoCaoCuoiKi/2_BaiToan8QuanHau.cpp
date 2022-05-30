#include <bits/stdc++.h>
using namespace std;
const int n=8;
int x[20];
bool a[20];
bool b[20];
bool c[20];
void Init()
{
    for(int i = 1; i <= 20; i++) a[i] = true; // mọi cột đều tự do
    for(int i = 2; i <= 20; i++) b[i] = true; // mọi đường chéo Đông Bắc - Tây Nam đều tự do
    for(int i = -10; i <= 10; i++) c[i] = true;// mọi đường chéo Đông Nam - Tây Bắc đều tự do
}
void PrintResult()
{
    for(int i = 1; i <= n; i++)
        cout<<"("<<i<<", "<<x[i]<<"); ";
    cout<<endl;
}
void NQueen(int i) // thử các cách đặt quân hậu thứ  i vào hàng i
{
    for(int j = 1; j <= n; j++)
    {
        if(a[j] && b[i + j] && c[i - j]) // chỉ xét những cột j mà ô (i,j) chưa bị khống chế
        {
            x[i] = j; // thử đặt quân hậu i vào cột j
            if(i == n)  PrintResult();
            else
            {
                a[j] = false; b[i + j] = false; c[i - j] = false; // đánh dấu
                NQueen(i + 1); // tìm các cách đặt quân hậu thứ i+1
                a[j] = true; b[i + j] = true; c[i - j] = true; // bỏ đánh dấu
            }
        }
    }
}
int main()
{
    Init();
    NQueen(1);
    return 0;
}
