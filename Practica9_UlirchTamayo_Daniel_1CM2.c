#include<stdio.h>
#include<stdlib.h>
int** Set(int);
int Input();
void Fill(int**,int), Calc(int,int,int*,int**),Show(int,int*);
int main(){
	int n=Input(),i,k;
	int** a;
	a=Set(n);
	Fill(a,n);
	int* b;
	b=(int*)malloc(sizeof(int)*(n+2));
	for(i=0;i<n;i++) Calc(n,i,b,a);
	Show(n,b);
}
void Show(int n,int* b){
	int i;
	for(i=0;i<n;i++) printf("%d ",b[i]);
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
int** Set(int n){
	int i,**a;
	a=(int**)malloc(sizeof(int*)*(n+2));
	for(i=0;i<n;i++) a[i]=(int*)malloc(sizeof(int)*(n+2));
	return a;
}
void Fill(int** a,int n){
	int i,j;
	for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j]=Input();
}
void Calc(int n,int i,int* b,int** a){
	int k,l;
	n--;
	if(i%3==1) for(k=i-1;k<n;k++) b[i]+=a[k][i];
	else if(i%3==2) for(k=0;k<n;k++) b[i]+=a[i][k];
	else b[i]=0;
}
