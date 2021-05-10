#include<stdio.h>
int Input();
void Function();
int main(){
    Function();
}
void Function(){
    int i,n=Input(),Y=0,R=0,P=0,G=0,B=0;;
    for(i=0;i<n;i++){
        int x=Input();
        if(x==1 || x==2){
            //ama
            Y++;
        }else if(x==3 || x==4){
            //rosa
            P++;
        }else if(x==5 || x==6){
            //roja
            R++;
        }else if(x==7 || x==8){
            //ver
            G++;
        }else if(x==9 || x==0){
            //azul
            B++;
        }
    }
    printf("%d\n%d\n%d\n%d\n%d\n",Y,P,R,G,B);
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}