#include<stdio.h>
#include<stdlib.h>
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
int main(){
	int n=Input(),i;
	int Array[n+2];
	for(i=0;i<n;i++) Array[i]=Input();
	for(i=0;i<n;i++) printf("%d ",Array[n-1-i]);
}
