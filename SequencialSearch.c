//Code by NakanoMiku13
//Find more interesting codes in https://github.com/NakanoMiku13
//Sequencial search
#include<stdio.h>
//Declaring the main array
int Array[100];
//Function Prototypes
int Input(),Search(int,int);
//Main function
int main(){
    //n variable defines the length of the array, and the numbers of the array
    int n=Input(),i=0;
    for(;i<n;i++){
        //Setting the values of the array
        *(Array+i)=Input();
    }
    //Receiving the value that will be searched on the array
    int x = Input();
    //Invoking the function search, if is equal to zero, the value does not exist on the array
    //If the value is different from zero, is the value that we find on the array
    if(Search(x,n)==0){
        printf("No matches found\n");
    }else{
        printf("Found!");
    }
}
//Function to receive numbers
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
//This function is the ones that look for the value received, in this case, we check on any position on the array.
//If we find the value, we return it, but if we do not find it, we return 0
int Search(int x,int n){
    int i=0;
    for(;i<n;i++){
        if(*(Array+i)==x){
            return *(Array+i);
        }
    }
    return 0;
}