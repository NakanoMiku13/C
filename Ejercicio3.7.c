#include<stdio.h>
#include<stdlib.h>
int Input(),**Set(int,int),*CalcSm(int,int,int**,int);
void Show(int*,int),Fill(int**,int,int);
int main(){
	printf("m1\n");
	int n=Input(),m=Input(),x,y;
	int *s1,*s2,*s3,*s4;
	int **m1,**m2;
	m1=Set(n,m);
	printf("m2\n");
	x=Input();
	y=Input();
	m2=Set(x,y);
	printf("Fill m1\n");
	Fill(m1,n,m);
	s1=CalcSm(n,m,m1,0);
	s2=CalcSm(n,m,m1,1);
	printf("Fill m2\n");
	Fill(m2,x,y);
	s3=CalcSm(x,y,m2,0);
	s4=CalcSm(x,y,m2,1);
	printf("Sum M1 Fil\n");
	Show(s1,m);
	printf("Sum M1 Col\n");
	Show(s2,n);
	printf("Sum M2 Fil\n");
	Show(s3,y);
	printf("Sum M2 Col\n");
	Show(s4,x);
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
int** Set(int n,int m){
	int i,j;
	int** a;
	a=(int**)malloc(sizeof(int*)*(n+2));
	for(i=0;i<n;i++) for(j=0;j<m;j++) a[i]=(int*)malloc(sizeof(int)*(m+2));
	return a;
}
void Fill(int** a,int n,int m){
	int i,j;
	for(i=0;i<n;i++) for(j=0;j<m;j++) a[i][j]=Input();
}
int* CalcSm(int n,int m,int** a,int aux){
	int i,j;
	int* vr;
	if(aux==0){
		vr=(int*)malloc(sizeof(int)*(m+2));
		for(i=0;i<n;i++) for(j=0;j<m;j++) vr[j]+=a[i][j];
		return vr;
	}else{
		vr=(int*)malloc(sizeof(int)*(n+2));
		for(i=0;i<n;i++) for(j=0;j<m;j++) vr[i]+=a[i][j];
		return vr;
	}
}
void Show(int* a,int n){
	int i;
	for(i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
