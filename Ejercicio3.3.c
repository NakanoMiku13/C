#include<stdio.h>
int main(){

}
void Show(){

}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
void Data(){
    int n=Input(),MZ=0,CMZ=0,LZ=0,c=0,i;
    for(i=0;i<n;i++){
        Check(&MZ,&CMZ,&LZ,&c,Input());
    }
}
void Check(int* x,int* y,int* z,int* j,int dir){
    if(dir>0){
        *x+=dir;
        *y+=1;
    }else if(dir<0){
        *z+=dir;
    }
    *j+=1;
}