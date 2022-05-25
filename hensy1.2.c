#include<stdlib.h>
#include<stdio.h>
int* reverse(int*,int,int);
int main(){
    int *n=(int*)malloc(sizeof(int)*6);
    int i=1;
    for(i=1;i<=5;i++) n[i-1]=i;
    int *new = reverse(n,0,4);
    for(i=0;i<5;i++) printf("%d ",new[i]);
}
int* reverse(int* array,int ini,int end){
    if(ini>=end) return array;
    int tmp = array[end],tmp2=array[ini];
    array[ini]=tmp;
    array[end]=tmp2;
    return reverse(array,ini+1,end-1);
}