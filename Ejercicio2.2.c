#include<stdio.h>
void Input(float*),Show(float);
float Data(float);
int main(){
    float x;
    Input(&x);
    x=Data(x);
    Show(x);
}
void Input(float* dir){
    scanf("%f",dir);
}
void Show(float x){
    printf("%f",x);
}
float Data(float x){
    if(x>=40){
        return (40*16)+((x-40)*20);
    }
    return x*16;
}