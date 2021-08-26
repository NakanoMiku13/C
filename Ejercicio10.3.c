#include<stdio.h>
#include<math.h>
int Input();
void Function();
float Funct(int);
int main(){
    Function();
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
void Function(){
    int n=Input(),i;
    float r=0;
    for(i=1;i<=n;i++){
        r+=Funct(i);
        printf("%d/2**%d + ",i,i);
    }
    printf("%d/2**%d\n",i,i);
    printf("%f",r);
}
float Funct(int i){
    return i/pow(2,i);
}