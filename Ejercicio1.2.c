#include<stdio.h>
void Input(float*),Show(float);
float Ask(float);
int main(){
    float x;
    Input(&x);
    x=Ask(x);
    Show(x);
}
void Input(float* dir){
    scanf("%f",dir);
}
float Ask(float value){
    if(value>1000){
        return (value-(value*0.2));
    }
    return value;
}
void Show(float x){
    printf("%f",x);
}