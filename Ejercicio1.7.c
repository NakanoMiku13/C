#include<stdio.h>
#include<stdlib.h>
void Fill(int,int,int**),Show(int,int,int**);
int Input(),**Create(int,int);
int main(){
	int** a;
	int n=Input(),m=Input();
	a=Create(n,m);
	Fill(n,m,a);
	Show(n,m,a);
}
int** Create(int n,int m){
	int i,j;
	int** a;
	a=(int**)malloc((n+2)*sizeof(int*));
	for(i=0;i<n;i++) a[i]=(int*)malloc(sizeof(int)*(m+2));
	return a;
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
void Fill(int n,int m,int** a){
	int i,j;
	for(i=0;i<n;i++) for(j=0;j<m;j++) if(i==j) a[i][j]=1; else a[i][j]=0;
}
void Show(int n,int m,int** a){
	int i,j;
	for(i=0;i<n;i++){ for(j=0;j<m;j++) printf("%d ",a[i][j]); printf("\n");}
}

