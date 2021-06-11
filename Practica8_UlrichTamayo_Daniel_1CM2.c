#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define t 12
void Fill(char**,int,int),Show(char**,int,int);
char** SetBig(char**,int,int);
int Inpt();
char Input();
char** Create(int,int);
int main(){
	int n=Inpt(),m=Inpt();
	char** a;
	char** b;
	a=Create(n,m);
	Fill(a,n,m);
	b=SetBig(a,n,m);
	//SetBig(b,n,m,a);
	Show(b,n*2,m*2);
}
char** Create(int n,int m){
	char** a;
	int i;
	a=(char**)malloc(sizeof(char*)*(t*2));
	for(i=0;i<n;i++) a[i]=(char*)malloc(sizeof(char)*(t*2));
	return a;
}
char Input(){
	char x;
	getchar();
	scanf("%c",&x);
	return x;
}
int Inpt(){
	int x;
	scanf("%d",&x);
	return x;
}
void Fill(char** a,int n,int m){
	int i,j;
	for(i=0;i<n;i++) for(j=0;j<m;j++) a[i][j]=Input();
}
void Show(char** a,int n,int m){
	int i,j;
	for(i=0;i<n;i++){ for(j=0;j<m;j++) printf("%c ",a[i][j]); printf("\n");}
}
char** SetBig(char** a,int n,int m){
	int i,j,x=n,y=m,l,o;
	n*=2;
	m*=2;
	char** tmp;
	tmp=Create(n,m);
	for(i=0;i<n;i++) for(j=0;j<m;j++) tmp[i][j]='0';
	for(i=0;i<x;i++) for(j=0;j<y;j++) tmp[i][j]=a[i][j];
	for(i=x,l=0;i<n;i++,l++) for(j=y,o=0;j<m;j++,o++) tmp[i][j]=a[l][o];
	return tmp;
}

