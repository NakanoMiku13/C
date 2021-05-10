#include<stdio.h>
int main(){
    int x=4;
    int* z=&x;
    printf("%d\n%p\n%p\n%d\n%p",x,&x,z,*z,&z);
}