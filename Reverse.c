#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Swap(char* a,char* b){
	char tmp=*a;
	*a=*b;
	*b=tmp;
}
void Reverse(char* a){
	int n = strlen(a),i=0,j=n-1;
	while(j!=i){
		printf("%d ",i);
		Swap(&a[i],&a[j]);
		i++;
		j--;
	}
}
int main(){
	char a[100];
	scanf("%[^\n]",a);
	getchar();
	printf("asdf");
	Reverse(a);
	printf("\n%s",a);
}
