#include<stdio.h>
#include<math.h>
void Function();
float f1(int,float,float),f2(int,float,float),Input();
int main(){
    Function();
}
float f1(int n,float a,float b){
    int i;
    float r=0;
    for(i=1;i<=n;i++){
        r+=(pow((a-b),i)-3)+n;
    }
    return r;
}
float f2(int n,float a,float b){
    int i;
    float r=1;
    for(i=2;i<n;i++){
        r*=(2+a*(i-1));
    }
    return r;
}
void Function(){
    int n=Input();
    float a=Input(),b=Input(),x1=f1(n,a,b),x2=f2(n,a,b),z=x1/x2;
    printf("%f",z);
}
float Input(){
    float x;
    scanf("%f",&x);
    return x;
}