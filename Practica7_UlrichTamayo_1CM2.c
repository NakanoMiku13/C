#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define t 52
void Input(char*),VowelRep(char* a,char* r),Change(char*,char,char);
int check(char,char);
int main(){
	char a[t],b[t],r1,r2;
	Input(a);
	Input(b);
	VowelRep(a,&r1);
	VowelRep(b,&r2);
	Change(b,r1,r2);
	printf("%s",b);
}
void Input(char* a){
	scanf("%[^\n]",a);
	getchar();
}
void Change(char* a,char r1,char r2){
	int n=strlen(a),i;
	for(i=0;i<n;i++) if(a[i]==r2) a[i]=r1;
}
int check(char a,char b){
	if(a==b) return 1;
	return 0;
}
void VowelRep(char* a,char* r){
	int n=strlen(a),i,c,j,*con,max=0,p=0,aux=0;
	con=(int*)malloc(sizeof(int)*12);
	char vr,v[12]={'a','e','i','o','u','A','E','I','O','U'};
	for(i=0;i<n;i++) for(j=0;j<strlen(v);j++) if(a[i]==v[j]) con[j]++;
	for(i=0;i<10;i++) if(con[i]>max){ max=con[i]; p=i;}
	*r=v[p];
}
