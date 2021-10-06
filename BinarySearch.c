//Code by NakanoMiku13
//Find more interesting codes in https://github.com/NakanoMiku13
//Binary Search
#include<stdio.h>
#include <stdlib.h>
//Defining the function prototypes
int Input(),BS(int*,int,int,int),*Array(int);
void Swap(int*,int*),Sort(int,int,int*);
//Main function
int main(){
    //Setting the length of the array and reserving memory for the array
    int n=Input(),*array=Array(n),x,i=0;
    //Receiving the numbers that will be on the array
    for(;i<n;i++){
        array[i]=Input();
    }
    //Sorting the array, this is necessary 'cause, if we do not sort the array, it will be impossible to solve it by Binary Search
    Sort(0,n-1,array);
    //Recreiving the number that will be search on the array
    x=Input();
    //Saving the value that the BS function returns, if it is equal to -1, it says, that the number do no exits
    //But if the value is higher than -1, it says the position of this one on the array
    int y=BS(array,0,n-1,x);
    if(y==-1){
        printf("Value not found\n");
    }else{
        printf("The value have been found at the position: %d\n",y+1);
    }
    for(i=0;i<n;i++){ 
        printf("%d ",array[i]);
    }
}
//Function to receive int
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
//Function to swap numbers, if we have 4 5, and we swap them, we will have 5 and 4
void Swap(int* a,int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
//Sort function, her I use the bubblesort algorithm 
void Sort(int begin,int end, int* Array){
	int i;
	for(;begin<end;begin++){
		for(i=begin;i<end;i++) if(Array[begin]>Array[i+1] && (i+1)<=end) Swap(&Array[begin],&Array[i+1]);
	}
}
//Reserving memory for the array
int* Array(int n){
    int* array=(int*)malloc(sizeof(int)*n+3);
    return array;
}
//The binary search function
int BS(int *array,int begin,int end,int x){
    //Defining the middle of the array, between begin and end
    int mid=((end+begin)/2)+1;
    //Checking if the begin is higher than the end, if this is the case, we said, that we can check more on the array
    if(begin>=end){
        //And we check if the value in that position is the number that we are looking for
        //If the value is correct, we return the position, and if it is not, we return -1
        if(array[begin]==x){
            return begin;
        }else{
            return -1;
        }
    }else{
        //But if the begin is lower than the end, we said that we have no finished yet
        //And here, we ask for the value in the middle of the range, and if it is higher than the ones that we look for
        //We delete the second half, and restart the process on the first half
        //else, we delete the first half and check the second half, and repeat the process
        //But now, the new half is the full array, so if we have this example:
        // 1 2 3 4 5 (sorted array)
        // 8 (Number that we are looking for)
        // We step on the middle that is 3, and ask 3>8, in this case is false, so we delete, 1 2.
        // And now, our new array is: 3 4 5
        // And step on the middle that is 4, and ask, 4>8, false, so we delete 3
        // The new array is: 4 5
        // We step on the middle that is 4, and ask, 4>8, false, so we delete, 4
        // Now, begin is equal to end, and we do the first part of the if condition.
        if(array[mid]>x){
            return BS(array,begin,mid-1,x);
        }else{
            return BS(array,mid,end,x);
        }
    }
}