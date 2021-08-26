#include<stdio.h>
int main(){
	int i,k,j;
	for(j=1;j<=3;j++){
		for(i=1;i<=3;i++){
			k=i;
			for(;k<j;)
				k++;
				printf("%d,%d,%d",i,j,k);
			printf("\n");
		}
	}
}
