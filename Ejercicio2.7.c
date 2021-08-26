#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int Input();
void Fill(int,int),Show(char);
int main(){
	int n=Input(),m=Input();
	getchar();
	Fill(n,m);
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
void Fill(int n,int m){
	int i,j;
	char a[12][12];
	for(i=0;i<n;i++) for(j=0;j<m;j++){ scanf("%c",&a[i][j]); getchar();}
	for(i=0;i<n;i++){ for(j=0;j<m;j++) Show(a[i][j]); printf("\n");}
}
void Show(char a){
	printf("%c ",a);
}
