//Code by NakanoMiku13
//Find more interesting codes in https://github.com/NakanoMiku13
#include<stdio.h>
#include<stdlib.h>
//Here we recieve the information
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
//He we makes a swap between the data recieve in the function
void Swap(int* a,int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
//Here, we apply a little sort to order the numbers in the given array
void Sort(int* Array,int begin,int end){
	int i;
	for(;begin<end;begin++) for(i=begin;i<end;i++) if((i+1)<=end && Array[begin]>Array[i+1]) Swap(&Array[begin],&Array[i+1]);
}
//Here we divide and decide if we order first the left or the right side of the array
void Divide(int begin,int end,int* Array,int seccion){
	int endf=(begin+end)/2;
	if(seccion==1) Sort(Array,begin,endf-1);
	else Sort(Array,endf,end);
}
//Here we apply the merge process and the final sort is just if some number do not get into his real position
void Merge(int begin,int end,int* Array){
	int i;
	for(i=0;i<end;i++) if(i%2==0) Divide(begin,end,Array,1); else Divide(begin,end,Array,0);
	Sort(Array,begin,end);
}
//Main function
int main(){
	int* Array;
	int n=Input(),x=n-1,i;
	Array=(int*)malloc(sizeof(int)*(n+3));
	for(i=0;i<n;i++) Array[i]=Input();
	Merge(0,x,Array);
	for(i=0;i<n;i++) printf("%d ",Array[i]);
}
