#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, k, x, y;
    cin>>n;
    int a[n];
    for(i=1; i<=n; i++)// khởi tạo cấu hình ban đầu
        a[i]=i;
    do
    {
        for(int i=1; i<=n; i++)// in ra cấu hình hiện tại
            cout<<a[i]<<" ";
        cout<<endl;
        i=n-1;
        while(i>0 && a[i]>a[i+1]) i--;
        if(i>0) // chưa gặp phải hoán vị cuối
        {
            k=n; //a[k] là phần tử cuối dãy
            while(a[k]<a[i]) k--; // lùi dần k để tìm gặp a[k] đầu tiên lớn hơn a[i]
            swap(a[k], a[i]); // đổi chỗ a[k] và a[i]
            x=i+1; y=n; // lật ngược đoạn cuối giảm dần; a: đầu đoạn, b: cuối đoạn
            while(x<y)
            {
                swap(a[x], a[y]);
                x++;
                y--;
            }
        }

    }while(i!=0);// toàn dãy là giảm dần - không sinh tiếp được - hết cấu hình
    return 0;
}
