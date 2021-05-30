#include<ctype.h>
#include<string.h>
#include<stdio.h>
void Input(char* a){
	scanf("%[^\n]",a);
	getchar();
}
void Function(char* a,char* b){
	char tmp[55];
	int n=strlen(a),i=0,j=0,k=0;
	for(;i<n;i++) if(toupper(a[i])==a[i] && a[i]!=' '){ b[j]=a[i]; j++;}else{tmp[k]=a[i]; k++;}
	strcpy(a,tmp);
}
int main(){
	char a[55],b[55];
	Input(a);
	Function(a,b);
	printf("%s\n%s",a,b);
}
