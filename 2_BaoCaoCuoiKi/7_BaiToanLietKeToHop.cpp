#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i;
    cin>>n>>k;
    int a[n];
    for(int i=1; i<=k; i++)
        a[i]=i;
    do
    {
        // in ra cấu hình hiện tại
        cout<<"{ ";
        for(i=1; i<=k; i++)
            cout<<a[i]<<" ";
        cout<<"}"<<endl;
        //sinh tiếp
        i=k;//x[i] là phần tử cuối dãy, lùi dần i cho tới khi gặp một x[i] chưa đạt giói hạn trên n-k+i
        while(i>0 && a[i]==n-k+i) i--;
        if(i>0) // nếu chưa lùi đến 0 thì chưa phải cấu hình kết thúc
        {
            a[i]++;// tăng x[i] lên 1, đặt các phần tử đứng sau xi bằng giới hạn dưới của nó
            for(int j=i+1; j<=k; j++)
                a[j]=a[j-1]+1;
        }
    }while(i!=0);// lùi đến tận 0 có nghĩa là tất cả các phần tử đã đạt giới hạn trên- hết cấu hình
    return 0;
}
