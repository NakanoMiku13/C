#include<ctype.h>
#include<string.h>
#include<stdio.h>
void Input(char* a){
	scanf("%[^\n]",a);
	getchar();
}
void Function(char* a,char* b){
	int i=0,n=strlen(a);
	for(;i<n;i++) if(a[i+1]==' ' || a[i-1]==' ' || i==0 || i+1>=n) b[i]=toupper(a[i]); else b[i]=a[i];
}
int main(){
	char a[55],b[55];
	Input(a);
	Function(a,b);
	printf("%s",b);
}
