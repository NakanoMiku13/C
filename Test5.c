#include<stdio.h>
int main(){
    int x;
    scanf("%d",&x);
    while(x!=1){
        printf("%d ",x);
        if(x%2==0) x/=2;
        else x=(x*3)+1;
    }
    printf("1");
}
