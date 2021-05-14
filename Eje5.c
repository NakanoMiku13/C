#include<stdio.h>
int main(){
	int x,i,j;
	scanf("%d",&x);
	for(i=1;i<=x;i++){
		for(j=0;j<i;j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for(i=x;i>=1;i--){

		for(j=i;j>=1;j--){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<x;i++){
		for(j=0;j<x-i;j++){
			printf(" ");
		}
		for(j=0;j<((i*2)+1);j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<x;i++){
		for(j=0;j<i;j++){
			printf(" ");
		}
		for(j=0;j<(((x-i)*2)-1);j++) printf("*");
		printf("\n");
	}
}

