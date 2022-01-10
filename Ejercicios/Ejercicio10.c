#include<stdio.h>
#include<math.h>
const float PI=3.1415;
void Input(float* dir),Show(float r),Op(float a,float b,float* dir),integreer(float x,float* dir);
float absolute(float val);
int main(){
    float a,b,r;
    Input(&a);
    Input(&b);
    Op(a,b,&r);
    Show(r);
}
void Input(float* dir){
    scanf("%f",dir);
}
void Show(float r){
    printf("%f",r);
}
void Op(float a,float b,float* dir){
    float x,y;
    integreer(a,&x);
    integreer(b,&y);
    *dir=x-y;
}
void integreer(float x,float* dir){
    *dir=log(absolute((x+1)))-((3*sin(2*PI*x))/(2*PI));
}
float absolute(float val){
    if(val<0){
        return val*-1;
    }else{
        return val;
    }
}
