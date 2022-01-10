#include<ctype.h>
#include<string.h>
#include<stdio.h>
void Input(char* a){
	scanf("%[^\n]",a);
	getchar();
}
void Function(char* a,char* b){
	char dir[55];
	int n=strlen(a),m=strlen(b);
	if(n<m){
		strcpy(dir,a);
		int i=0;
		for(;i<n;i++) printf("%c ",dir[i]);
	}
	else{
		strcat(dir,b);
		strcat(dir,a);
		int i=0;
		printf("%s\n%s\n%s",a,b,dir);
	}
}
int main(){
	char a[55],b[55];
	Input(a);
	Input(b);
	Function(a,b);
}
