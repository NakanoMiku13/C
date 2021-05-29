#include<ctype.h>
#include<string.h>
#include<stdio.h>
void Input(char* Array){
	scanf("%[^\n]",Array);
	getchar();
}
void Concat(char* a,char* b){
	strcat(a," ");
	strcat(a,b);
}
int main(){
	char a[55],b[55];
	Input(a);
	Input(b);
	Concat(a,b);
	printf("%s",a);
}
