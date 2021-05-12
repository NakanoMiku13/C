#include<stdio.h>
int Input();
void Menu(),A(int),B(int),C(int),D(int);
int main(){
	Menu();
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
void A(int x){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
}
void B(int x){
	int i,j;
	for(i=x;i>0;i--){
		for(j=i;j>0;j--){
			printf("*");
		}
		printf("\n");
	}
}
void C(int x){
	int i,j;
	for(i=0;i<x;i++){
		int k;
		for(k=0;k<x-i-1;k++){
			printf(" ");
		}
		for(j=i;j<i*2+1;j++){
			printf("*");
		}
		for(j=0;j<i;j++){
			printf("*");
		}
		printf("\n");
	}
}
void D(int x){
	int i,j;
	for(i=x;i>0;i--){
		int k;
		for(k=0;k<x-i;k++){
			printf(" ");
		}
		for(j=i;j<i*2;j++){
			printf("*");
		}
		for(j=1;j<i;j++){
			printf("*");
		}
		printf("\n");
	}
}
void Menu(){
	int x=Input();
	A(x);
	printf("\n");
	B(x);
	printf("\n");
	C(x);
	printf("\n");
	D(x);
}
