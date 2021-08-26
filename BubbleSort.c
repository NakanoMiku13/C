//Code by NakanoMiku13
//Find more interesting codes in https://github.com/NakanoMiku13
#include<stdio.h>
#include<stdlib.h>
int Input(){
	int x;
	scanf("%d",&x);
	return x;
}
//This functions makes a swap eg: 5 8 to 8 5
void swap(int* a,int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
//This function travels around all the array, and swap the higher with the lower
void Sort(int begin,int end, int* Array){
	int i;
	for(;begin<end;begin++){
		for(i=begin;i<end;i++) if(Array[begin]>Array[i+1] && (i+1)<=end) swap(&Array[begin],&Array[i+1]);
	}
}
int main(){
	int n=Input(),i;
	int* Array;
	Array=(int*)malloc(sizeof(int)*(n+3));
	for(i=0;i<n;i++) Array[i]=Input();
	Sort(0,n-1,Array);
	for(i=0;i<n;i++) printf("%d ",Array[i]);
}
