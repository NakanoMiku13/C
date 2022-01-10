#include<stdio.h>
#include <stdlib.h>
int Input(),**GenTable(int,int),Line(int,int,int,int,int**),Diagonal(int,int,int,int,int**);
void FillTable(int,int,int**),NoAttackQueens(int,int,int**),SetQueens(int,int,int,int,int**),SetFirstQueen(int,int,int**);
size_t Queens=0;
int main(){
    int n=Input(),m=n,**table=GenTable(n,m);
    if(n==1){
        printf("1");
    }else if(n>=4){
        FillTable(n,m,table);
        //SetFirstQueen(n,m,table);
        if(n%2==0) table[0][1]=1;
        NoAttackQueens(n,n,table);
        int i=0,j=0;
        for(;i<n;i++){
            for(j=0;j<m;j++){
                printf("%d ",table[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("Not possible\n");
    }
}
void SetFirstQueen(int n,int m,int** table){
    printf("Do you want to set the first queen? or I do it?\n1) I want\n2) You choose\nType it down:\n");
    int x=Input();
    if(x==1){
        printf("Nice decision, well, choose from 1 to %d, to the rows and from 1 to %d to the columns:\n",n,m);
        int r=Input(),c=Input();
        r--;
        c--;
        table[c][r]=2;
    }else{
        printf("Well, I choose...\n");
        int r=random()%n,c=random()%m;
        printf("I want it at (%d,%d)\n",c+1,r+1);
        table[c][r]=2;
    }
    Queens++;
}
void NoAttackQueens(int n,int m,int** table){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            SetQueens(i,j,n,m,table);
        }
    }
}
void SetQueens(int y,int x,int n,int m,int** table){
    if(Line(y,x,n,m,table)==1  && Diagonal(y,x,n,m,table)==1 && table[y][x]!=1){
        table[y][x]=1;
        Queens++;
    }
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
int** GenTable(int n,int m){
    int** table = (int**)malloc(sizeof(int*)*n+3),i=0;
    for(;i<n;i++){
        table[i] = (int*)malloc(sizeof(int)*m+3);
    }
    return table;
}
void FillTable(int n,int m,int** table){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            table[i][j]=0;
        }
    }
}
int Diagonal(int y,int x,int n,int m,int** table){
    int i=y-1,j=x-1;
    //Checking up left diagonal
    while(i>=0 && j>=0){
        if(table[i][j]==1){
            //Found a queen
            return -1;
        }
        i--;
        j--;
    }
    i=y-1,j=x+1;
    //Checking up right diagonal
    while(i>=0 && j<=m){
        if(table[i][j]==1){
            //Found a queen
            return -1;
        }
        i--;
        j++;
    }
    i=y+1,j=x-1;
    //Checking down left diagonal
    while(i<n && j>=0){
        if(table[i][j]==1){
            //Found a queen
            return -1;
        }
        i++;
        j--;
    }
    i=y+1,j=x+1;
    //Checking down right diagonal
    while(i<n && j<m){
        if(table[i][j]==1){
            //Found a queen
            return -1;
        }
        i++;
        j++;
    }
    //No queen found
    return 1;
}
int Line(int y,int x,int n,int m,int** table){
    //Cheking rows
    int i=x-1;
    while(i>=0){
        if(table[y][i]==1){
            //Found a queen
            return -1;
        }
        i--;
    }
    i=x+1;
    while(i<n){
        if(table[y][i]==1){
            //Found a queen
            return -1;
        }
        i++;
    }
    //Checking cols
    int j=y-1;
    while(j>=0){
        if(table[j][x]==1){
            //Found a queen
            return -1;
        }
        j--;
    }
    j=y+1;
    while(j<m){
        if(table[j][x]==1){
            //Found a queen
            return -1;
        }
        j++;
    }
    //On the line there is no queen
    return 1;
}