#include<stdio.h>
void Check(char*), Function();
int Input();
int main(){
    Function();
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
void Check(char* dir){
    scanf("%c",dir);
}
void Function(){
    char x='s';
    int y=0,z=2,tmp=0;
    do{
        switch (x)
        {
        case 'N':
            z=1;
            break;
        case 'n':
            z=1;
            break;
        default:
            if(x!='n' && x!='N'){
                int c=Input();
                y+=c;
                tmp=c;
                scanf("%c",&x);
            }
            break;
        }
    }while(z!=1 && x!='n' && x!='N');
    printf("%d",y-tmp);
}