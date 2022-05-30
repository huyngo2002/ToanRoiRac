#include<iostream>
#include<math.h>

using namespace std;

/*
Thuật toán To màu đọ thi:

Bước 1: Sắp xếp các đỉnh theo thứ tự giảm dần của bậc.
Bước 2: SM=0 (SM là số màu)
Bước 3: Tìm lần lượt theo thứ tự sắp xếp (từ trái qua phải) ,
đỉnh X đầu tiên chưa được tô. Nếu không tìm được  Kết thúc.
Bước 4: SM=SM+1, và tô đỉnh X bằng màu SM.
Bước 5: Tìm lần lượt từ X sang phải (theo thứ tự sắp xếp) các
đỉnh chưa tô mà không kề với những đỉnh đã có màu SM, tô
màu những đỉnh như vậy bằng màu SM.
Quay lại bước 3


*/

//nhap ma tran do thi

void nhapmatran(int a[100][100], int &n){
	do{
		cout<<"nhap so dinh cua do thi : ";
		cin>>n;
		if(n <= 0 ){
			cout<<endl<<"nhap sai";
		}
	}
	while(n <= 0);

	cout<<endl<<"nhap ma tran ke cua do thi(0 neu i khong ke j va nguoc lai) : ";
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n;j++){
			cout<<endl<<"A["<<i<<","<<j<<"] : ";
			cin>>a[i][j];
		}
	}
}


// in ma tran ke
void inmatran(int a[100][100],int n){
	for(int i = 0; i <n ;i++){
		for(int j = 0; j <n;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}

//Ham tinh bac
int  Bac(int a[100][100], int n, int x)
{
    int b  = 0;
    for(int i = 0; i < n; i++)
        b += a[x][i];
    return b;
}

//Sap xep cac dinh giam dan theo bac
void SapXep(int a[100][100], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
        {
            if(Bac(a, n, i) > Bac(a, n, j))
                for(int k = 0; k < n; k++)
                    swap(a[i][k], a[j][k]);
        }
}

// ham kiem tra dinh i co to duoc mau c khong
int toduoc(int a[100][100], int n, int v[], int i, int somau){
	for(int j = 0; j < n;j++){
		if(a[i][j] == 1 && v[j] == somau){
			return 0;
		}
	}
	return 1;
}


//Ham dung mot mau to cho tat ca cac dinh co the to, tra ve so dinh da duoc to
int  tomotmau(int a[100][100],int n, int v[],int somau){
	int dem = 0;

	for(int i = 0 ; i < n;i++){
		if(v[i] == 0 && toduoc(a,n,v,i,somau) == 1){
			v[i] = somau;
			dem++;
		}
	}


	return dem;
}

//ham to mau tat ca cac dinh cua do thi , ham tra ve so luong mau da duoc dung
int tomau(int a[100][100],int n, int v[]){
	for(int i = 0; i < n;i++){
		v[i] = 0; // chua co dinh nao duoc to
	}

	int somau = 0;//mau thu ... duoc to
	int dem = 0; //tong so dinh duoc to

	while(dem < n ){ //dam bao cac dinh duoc to
		somau++;
		dem += tomotmau(a,n,v,somau);
	}

	return somau;
}




int main(){
	int a[100][100];
	int n;
	int kq;
	int v[100];

	nhapmatran(a,n);
	cout<<endl<<"ma tran ke cua do thi vua nha la : "<<endl;
	inmatran(a,n);
    SapXep(a, n);
    inmatran(a, n);
	kq = tomau(a,n,v);

	cout<<endl<<"So mau dung de to : "<<kq;
	cout<<endl<<"Ket qua to mau : "<<endl;
	for(int i = 0; i < n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;

	return 0;


}









