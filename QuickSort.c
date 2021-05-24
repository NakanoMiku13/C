//Code by NakanoMiku13
//Find more interesting codes in https://github.com/NakanoMiku13
#include<stdio.h>
#include<stdlib.h>
//Function that recieve the data as int
void Input(int* x){
	scanf("%d",x);
}
//Function that swap 2 numbers, eg: 5 8 swpan them as 8 5
void Swap(int* a,int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
//Function that mades the order method recieving the pivot and the array
//This function works while the j be higher than i, if j is equal or less than i the cycle finish
//The second while travels from the right to the left, looking for a value that is less than the pivot, it only continue if the value is higher than the pivot
//The third while travles form the left to the right, as the same way as the last while, but in this one, it is looking for the values that are higher than the pivot, and only continues if it is less than the pivot
//When that happens, you make a swap of positions
//eg: in the array 5 8 4 3 7 2 6
//Our pivot will be the number 6, so lets start
//In this case we start from the right to the left, and ask, is 6 higher than 6?, in this case the answer is no, because they are the same, so, there will finish the cycle 
//Then we go from the left to the right and check, is 5 less than 6?, in this case, the answer is yes, so we continue, and now we ask, is 8 higher than 8?, the answer is no, so in here will finish the cycle
//Now, both cycles finished, now we swap that values, and we have this new array 5 6 8 4 3 7 2 8
void Sort(int* Array, int j,int i,int pivot){
	while(j>i){
		while(Array[j]>pivot) j--;
		while(Array[i]<pivot) i++;
		Swap(&Array[i],&Array[j]);
	}
}
//In this function we invoke the Sort function that I have explained, but in this case we are going to repeat it while the array is in disorder, just changin the pivot
void QuickSort(int* Array,int n,int j,int i){
	int pivot=Array[0],k;
	for(k=0;k<n+1;k++){
		pivot=Array[k];
		Sort(Array,j,i,pivot);
	}
}
//The main function
int main(){
	int i,n,x;
	Input(&n);
	x=n-1;
	int* Array;
	//This is very important if we want to work with pointer arrays, because, if we does not do this, the array will have garbage values when it travels around the functions, so, with this, we save some memory for the array
	//First we declare the free space with malloc and inside of malloc we said the size of the array, in this case is declared by n, we can change the n for any value, in this case is a dynamic array
	Array = (int *) malloc(sizeof(int)*(n+3));
	for(i=0;i<n;i++){
		int x=0;
		Input(&x);
		Array[i]=x;
	}
	printf("Result: ");
	QuickSort(Array,x,x,0);
	for(i=0;i<n;i++){
		printf("%d ",Array[i]);
	}
}
