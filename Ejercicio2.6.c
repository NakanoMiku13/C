#include<stdio.h>
#include<string.h>
#include<ctype.h>
void Input(char* a){
	scanf("%[^\n]",a);
	getchar();
}
void Function(char* a,char* b,char* dir){
	int n=strlen(a),m=strlen(b),i=0,j=0,k=0,t=n+m,aux=0;
	for(;i<t;i++){
		if(aux==0){ dir[i]=a[j]; j++; aux=1;}
		else { dir[i]=b[k]; k++; aux=0;}
	}
}
int main(){
	char a[55],b[55],c[55];
	Input(a);
	Input(b);
	Function(a,b,c);
	printf("%s",c);
}
