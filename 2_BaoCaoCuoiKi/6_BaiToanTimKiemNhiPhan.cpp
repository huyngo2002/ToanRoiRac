#include <iostream>
#include <algorithm>

using namespace std;

/*

*Cây Nhị Phân:
Mỗi đỉnh gán bằng một khóa (mỗi giá trị khóa chỉ
xác định một phần tử).
Khóa của đỉnh lớn hơn tất cả khóa của các đỉnh
thuộc cây con trái và nhỏ hơn khóa của tất cả các
đỉnh thuộc cây con phải

*Tìm kiếm nhị phân:
Nếu Node hiện tại có giá trị = giá trị cần tìm, trả về true và kết thúc.
Nếu Node hiện tại có giá trị > giá trị cần tìm, gọi đệ quy tìm ở cây con bên trái.
Nếu Node hiện tại có giá trị < giá trị cần tìm, gọi đệ quy tìm ở cây con bên phải
Nếu tìm đến hết cây(Node đó = NULL) mà không xảy ra (1), trả về false và kết thúc.

*/

int main()
{
    int n;
    cout << "Nhap so phan tu cua mang: "; cin >> n;
    int a[n];
    for(int i = 0; i < n ; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
    sort(a, a+n);
    int x;
    cout << "Nhap phan tu can tim: "; cin >> x;
    int d = 0, c = n-1;
    while(d < c)
    {
        int m = (c+d)/2;
        if(x == a[m])
        {
            cout << x << " xuat hien o vi tri thu " << m+1 << " sau khi mang sap xep tang dan" << endl;
            return 0;
        }
        else
        {
            if(x > a[m])
                d = m;
            if(x < a[m])
                c = m;
        }

    }
    cout << "Khong tim duoc " << x << " trong mang" << endl;
}
