#include<stdio.h>
#include<math.h>
int main(){
    int n,i;
    float x=0;
    scanf("%d",&n);
    n*=2;
    for(i=1;i<=n;i++){
        x+=(pow(-1,(i+1)))/i;  
    }
    printf("%f",x);
}