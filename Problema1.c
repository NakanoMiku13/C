#include<stdio.h>
#include<stdlib.h>
int** Set(int n,int m){
	int i,x;
	int** a;
	a=(int**)malloc(sizeof(int*)*(n+2));
	for(i=0;i<n;i++) a[i]=(int*)malloc(sizeof(int)*(m+2));
	return a;
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
void Fill(int** a,int n,int m){
	int i,j;
	for(i=0;i<n;i++) for(j=0;j<m;j++) a[i][j]=Input();
}
void Swap(int* a,int* b){
	int tmp = *a;
	*a=*b;
	*b=tmp;
}
void Change(int** a,int x1,int x2,int m){
	int j;
	for(j=0;j<m;j++) Swap(&a[x1][j],&a[x2][j]);
}
void Compare(int* x1,int n){
	int aux=0;
	do{
                if(*x1<=n) aux=1;
                else{ printf("El valor excede los limites\n"); *x1=Input();}
        }while(aux!=1);
}
int main(){
	int n=Input(),m=Input(),x1,x2,**a;
	a=Set(n,m);
	Fill(a,n,m);
	x1=Input();
	Compare(&x1,n);
	x2=Input();
	Compare(&x2,n);
	Change(a,x1-1,x2-1,m);
	int i,j;
	for(i=0;i<n;i++){ for(j=0;j<m;j++) printf("%d ",a[i][j]); printf("\n");}
}

