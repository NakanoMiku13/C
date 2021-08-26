#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Function();
int Input();
int main(){
    Function();
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
void Function(){
    int x = Input(),i,c=0;
    for(i=100;i>0;i--){
        long long int d = pow(10,i);
        if(x>=d){
                int z = x/d;
                c+=z;
                x-=(d*z);
                x=abs(x);
        }
    }
    c+=x;
    printf("%d",c);
}