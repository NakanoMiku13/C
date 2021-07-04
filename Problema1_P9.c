#include<stdio.h>
#include<stdlib.h>
int** Set(int n){
	int i;
	int** a;
	a=(int**)malloc(sizeof(int*)*(n+2));
	for(i=0;i<n;i++) a[i]=(int*)malloc(sizeof(int)*(n+2));
	return a;
}
void Calc(int** a,int** b,int n){
	int i,j,k=0,l=0;
	int* x;
	int* y;
	//x=Inferior
	//y=Superior
	x=(int*)malloc(sizeof(int)*(n*2+2));
	y=(int*)malloc(sizeof(int)*(n*2+2));
	for(i=1;i<n;i++) for(j=0;j<i-1;j++){ x[k]+=a[i][j]; k++;}
	k=0;
	for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){ y[k]+=a[i][j]; k++;}
	for(i=0;i<k;i++){ printf("X=%d Y=%d\n",x[i],y[i]); x[i]+=y[i]; printf("%d ",x[i]);}
	for(i=1;i<n;i++) for(j=0;j<i-1;j++){ b[i][j]=x[l]; l++;}
}
void Zero(int** a,int n){
	int i,j;
	for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j]=0;
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
void Fill(int** a,int n){
        int i,j;
        for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j]=Input();
}

int main(){
	int n=Input(),**a,**b,i,j;
	a=Set(n);
	b=Set(n);
	Fill(a,n);
	Zero(b,n);
	Calc(a,b,n);
	for(i=0;i<n;i++){ for(j=0;j<n;j++) printf("%d ",b[i][j]); printf("\n");}
}
