#include<stdio.h>
int main(){
    int Brenda=15,x;
    int* Daniel=&Brenda;
    scanf("%d",&x);
    printf("%d\n",Brenda);
    printf("%d\n",*Daniel);
    *Daniel=20;
    int Sofi=90;
    Daniel=&Sofi;
    printf("%p\n",&Sofi);
    printf("%p\n",Daniel);
    printf("%d\n",Brenda);
    printf("%p\n",&Brenda);
    printf("%p\n",Daniel);
    printf("%p\n",&Daniel);
}