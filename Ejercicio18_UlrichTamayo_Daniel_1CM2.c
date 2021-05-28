#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int Size(char*),Vowels(char*),Upper(char*),Compare(char*),Input2();
void Input(char*),Reverse(char*),Menu(char*);
int main(){
	char Array[100];
	Menu(Array);
}
int Input2(){
	int x;
	scanf("%d",&x);
	return x;
}
void Input(char* Array){
	scanf("%[^\n]",Array);
	getchar();
}
void Swap(char* a,char* b){
	char tmp=*a;
	*a=*b;
	*b=tmp;
}
int Size(char* Array){
	return strlen(Array);
}
void Reverse(char* Array){
	int n=Size(Array),i;
	for(i=0;i<n-1;i++) Swap(&Array[i],&Array[n-1-i]);
	printf("Reverse: %s\n",Array);
}
int Vowels(char* Array){
	int n=Size(Array),i,c=0,j=0;
	for(i=0;i<n;i++){ char a=tolower(Array[i]); if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') c++;}
	return c;
}
int Upper(char* Array){
	int n=Size(Array),i,c=0;
	for(i=0;i<n;i++) if(toupper(Array[i])==Array[i]) c++;
	return c;
}
int Compare(char* Array){
	char Array2[Size(Array)+2];
	strcpy(Array2,Array);
	Reverse(Array2);
	int r=strcmp(Array,Array2);
	if(r==0) return 1;
	return 0;
}
void Menu(char* Array){
	int n;
	do{
		n=Input2();
		getchar();
		printf("Option: %d\n",n);
		if(n==1) Input(Array);
		else if(n==2) Reverse(Array);
		else if(n==3) printf("Vowels: %d\n",Vowels(Array));
		else if(n==4) printf("Uppers: %d\n",Upper(Array));
		else if(n==5){
			if(Compare(Array)==1) printf("Equals\n");
			else printf("Diferent\n");
		}
		else if(n==6) printf("Size: %d\n",Size(Array));
	}while(n<=6);
}
