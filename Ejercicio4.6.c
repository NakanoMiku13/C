#include<ctype.h>
#include<stdio.h>
#include<string.h>
void Input(char* a){
	scanf("%[^\n]",a);
}
void Swap(char* a,char* b){
	char tmp=*a;
	*a=*b;
	*b=tmp;
}
void Sort(char* a){
	int n=strlen(a),i,j;
	for(i=0;i<n-1;i++) for(j=i;j<n-1;j++) if(a[i]>a[j+1] && j+1<=n) Swap(&a[i],&a[j+1]);
}
int main(){
	char a[55];
	Input(a);
	Sort(a);
	printf("%s",a);
}
