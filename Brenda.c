#include<stdlib.h>
#include<stdio.h>
int max(const int valueA,const int valueB){
    if(valueA>valueB) return valueA;
    return valueB;
}
int maxSum(int* array,int maxi,const int index,const int size,const int maxs){
    int maxis = max(array[index],maxi+array[index]);
    if(index<size) return maxSum(array,maxis,index+1,size,max(maxs,maxis));
    return maxs;
}
int main(){
    int n,i=0,x=0;
    scanf("%d",&n);
    int* array = (int*)malloc(sizeof(int)*(n+2));
    for(i=0;i<n;i++){
        scanf("%d",&x);
        array[i]=x;
    }
    int maxi = maxSum(array,array[0],1,n,array[0]);
    printf("%d",maxi);
}