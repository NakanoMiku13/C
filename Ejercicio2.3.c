#include<stdio.h>
void Dat(int* x,int* y,int* z,float val),Show(int,int,int),XD();
float Input();
int main(){
    XD();
}
float Input(){
    float x;
    scanf("%f",&x);
    return x;
}
void Dat(int* x,int* y,int* z,float val){
    if(val<=200){
        *x+=1;
    }else if(val>200 && val<600){
        *y+=1;
    }else{
        *z+=1;
    }
}
void Show(int x,int y,int z){
    printf("200 o menos: %d\n600 o menos: %d\nMas de 600: %d",x,y,z);
}
void XD(){
    int n=Input(),i,x=0,y=0,z=0;
    for(i=0;i<n;i++){
        Dat(&x,&y,&z,Input());
    }
    Show(x,y,z);
}