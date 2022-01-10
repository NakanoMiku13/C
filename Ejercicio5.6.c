#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void Input(char* a){
	scanf("%[^\n]",a);
	getchar();
}
int Count(char* array,char digit){
	int n=strlen(array),i=0,c=0;
	for(;i<n;i++) if(array[i]==digit) c++;
	return c;
}
int main(){
	char a[55],number[12]={'0','1','2','3','4','5','6','7','8','9'};
	int i=0,numbers[12];
	Input(a);
	int n=strlen(a);
	for(;i<10;i++) numbers[i]=Count(a,number[i]);
	for(i=0;i<10;i++) if(numbers[i]!=0) printf("%d numeros %d\n",numbers[i],i);
}
