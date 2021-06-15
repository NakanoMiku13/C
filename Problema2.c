#include<stdio.h>
#include<stdlib.h>
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
int** Set(int n){
	int i,**a;
	a=(int**)malloc(sizeof(int*)*(n+2));
	for(i=0;i<n;i++) a[i]=(int*)malloc(sizeof(int)*(2));
	return a;
}
void Fill(int n,int** a){
	int i;
	for(i=0;i<n;i++){ a[i][0]=Input(); a[i][1]=Input(); a[i][0]++; a[i][1]++;}
}
float Calc(int** a,int n){
	float x=0,y;
	int i;
	n--;
	for(i=0;i<n;i++){ y=((a[i][0]+a[i+1][0])*(a[i][1]-a[i+1][1])); if(y<0) y*=-1; x+=y;}
	x/=2;
	return x;
}
int main(){
	int n=Input(),**a;
	float r;
	a=Set(n);
	Fill(n,a);
	r=Calc(a,n);
	printf("%f",r);
}




