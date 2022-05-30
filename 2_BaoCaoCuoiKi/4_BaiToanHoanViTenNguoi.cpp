#include <bits/stdc++.h>
using namespace std;
struct Ten
{
    char Nguoi[20];
    int vitri;
};
int main()
{
    int n, i, k, x, y;
    cin>>n;
    Ten a[10];
    for( i=1; i<=n; i++)
    {
        fflush(stdin);
        gets(a[i].Nguoi);
    }
    for(i=1; i<=n; i++)
    {
        a[i].vitri=i;
    }
    do
    {
        for( i=1; i<=n; i++)
        {
            cout<<a[i].Nguoi<<" ";
        }
        cout<<endl;
        i=n-1;
        while(i>0 && a[i].vitri>a[i+1].vitri) i--;
        if(i>0)
        {
            k=n;
            while(a[k].vitri<a[i].vitri) k--;
            swap(a[k], a[i]);
            x=i+1;
            y=n;
            while(x<y)
            {
                swap(a[x], a[y]);
                x++;
                y--;
            }
        }
    }
    while(i!=0);
    return 0;
}
