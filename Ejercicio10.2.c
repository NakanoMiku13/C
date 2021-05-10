#include<stdio.h>
void Input(int*),Show(float);
float Calc(int,int);
int main(){
    int h,m;
    Input(&h);
    Input(&m);
    Show(Calc(h,m));
}
void Input(int* dir){
    scanf("%d",dir);
}
void Show(float x){
    printf("%f",x);
}
float Calc(int h,int m){
    if(h==0 && m<=10){
        return 0;
    }else if(h==0 && (m>10 && m<=59)){
        return 0.30;
    }else if(h==0 && m==60 || h==1 && m==0){
        return 0.60;
    }else if(h>=1){
        if(m>=30){
            return (h*0.6)+(0.3);
        }else{
            return (h*0.6);
        }
    }
}