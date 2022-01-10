#include<stdio.h>
float Input();
void Function();
int main(){
    Function();
}
float Input(){
    float x;
    scanf("%f",&x);
    return x;
}
void Function(){
    int n=Input(),i,r=0,a=0,sr=0,sa=0;
    float p1=0,p2=0;
    for(i=0;i<n;i++){
        int x = Input();
        if(x>=6){
            a++;
            sa+=x;
        }else{
            r++;
            sr+=x;
        }
    }
    p1=sa/a;
    p2=((sa+sr)/(a+r));
    printf("%d %d %f %f",r,a,p1,p2);
}