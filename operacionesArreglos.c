#include<stdio.h>
#include<stdlib.h>
void Function(),Show(int*,int),InputElementsArray(int*),FillArray(int,int*),ShowSearch(int,int,int),Swap(int*,int*),Sort(int*,int,int),ShowBinary(int,int,int);
int Search(int*,int,int,int*),Input(),Binary(int*,int,int,int);
int main(){
	Function();
}
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
void InputElementsArray(int* n){
	printf("Number of elements: ");
	*n=Input();
}
void FillArray(int n,int* Array){
	int i=0;
	for(;i<n;i++){
		printf("Element %d: ",i);
		Array[i]=Input();
	}
}
void Show(int* Array,int n){
	int i=0;
	for(;i<n;i++) printf("%d ",Array[i]);
	printf("\n");
}
int Search(int* Array, int x,int n,int* pos){
	int i=0;
	for(;i<n;i++){
		if(Array[i]==x){ *pos=i; return 1;}
	}
	return 0;
}
void ShowSearch(int x,int pos,int r){
	if(x==1) printf("The value was found at position %d, and the value was: %d\n",pos,r);
	else printf("The value was not found in the array\n");
}
void Swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void Sort(int* Array,int begin,int end){
	int i=0;
	for(;begin<end;begin++) for(i=begin;i<end;i++) if((i+1)<=end && Array[begin]>Array[i+1]) Swap(&Array[begin],&Array[i+1]);
}
int Binary(int* Array,int x, int begin,int end){
	int mid=0;
	while(begin<=end){
		mid=(begin+end)/2;
		if(x==Array[mid]) return mid;
		else if(x>Array[mid]) begin=mid+1;
		else end=mid-1;
	}
	return -1;
}
void ShowBinary(int x,int pos,int r){
	if(x!=-1) printf("The item was found in the position: %d and the value was: %d",pos,r);
	else printf("The item was not found");
}
void Function(){
	int n,x,r,pos;
	int* Array;
	Array=(int*)malloc(sizeof(int)*(53));
	InputElementsArray(&n);
	FillArray(n,Array);
	Show(Array,n);
	printf("Type a number to search in the array: ");
	x=Input();
	r=Search(Array,x,n,&pos);
	ShowSearch(r,pos+1,x);
	x=0;
	Sort(Array,0,n-1);
	Show(Array,n);
	printf("Type a number to search in the array: ");
	x=Input();
	r=Binary(Array,x,0,n-1);
	pos=r;
	ShowBinary(r,pos+1,x);
}
