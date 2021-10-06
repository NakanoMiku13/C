//Code by NakanoMiku13
//Check more interesting codes at http://github.com/NakanoMiku13
//Queens that do not attack (Recursive way)
#include<stdio.h>
#include<stdlib.h>
//Function Prototypes
int **GenTable(int,int),Input(),SetQueen(int y,int x,int n,int m,int** table),Cross(int y,int x,int n,int m,int** table),Cross2(int y,int x,int n,int m,int** table),DownLeft(int y,int x,int n,int** table),UpRight(int y,int x,int m,int** table),DownRight(int y,int x,int n,int m,int** table),UpLeft(int y,int x,int** table),LeftLine(int y,int x,int m,int** table),RightLine(int y,int x,int m,int** table),DownLine(int y,int x,int n,int** table),UpLine(int y,int x,int n,int** table);
void FillTable(int,int,int**),SetFirstQueen(int,int,int**);
//Global variable to count the number of queens set on the board
size_t Queens;
//Main Function
int main(){
    printf("Type the rows, and the columns of the table:\n");
    int n=Input(),m=Input(),**table=GenTable(n,m),i,j;
    FillTable(n,m,table);
    SetFirstQueen(n,m,table);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            table[i][j]=SetQueen(i,j,n,m,table);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("There are %d queens on the board\n",Queens);
}
//This function gave the possibility to choose if the user wants to set the first queen or if it is set random
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
//Function that receive the input int
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
//This function reserve the memory for the table that the user gives
int** GenTable(int n,int m){
    int** table = (int**)malloc(sizeof(int*)*n+3),i=0;
    for(;i<n;i++){
        table[i] = (int*)malloc(sizeof(int)*m+3);
    }
    return table;
}
//With this, we fill the board with zero, but it is not necessary
void FillTable(int n,int m,int** table){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            table[i][j]=0;
        }
    }
}
//The next functions check in all the positions of the board
//This one check the up line of the board, so if we have the next board 
/* (Number 2 are queens, and number 1 is an available space)
    1 1 2 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
*/
//In this case, we start at X=3-1 and Y=3-1, so we are on a 1, so in theory we can set a queen there, but
//we have to check this in all directions, so first we check up to the coordinate given
//In this case the first number found is 1, so we can continue, but the next one is 2, that is at X=1-1 and Y=1-1
//So we return -1, that indicates that it exist a queen that could attack the new queen 
//So we finish to check and move to the next position
int UpLine(int y,int x,int n,int** table){
    int i=y-1;
    if(y>0){
        //printf("%d ",table[i][x]);
        if(table[i][x]==2){
            return -1;
        }else if(table[i][x]!=2 && i>0){
            return UpLine(i,x,n,table);
        }else{
            if(table[i][x]!=2 && !(i>0)){
                return 1;
            }else{
                return -1;
            }
        }
    }else{
        return 1;
    }
}
//This function is the same process as the last one, but this check down the X and Y coordinate
int DownLine(int y,int x,int n,int** table){
    int i=y+1;
    if(y<n-1){
        //printf("%d ",table[i][x]);
        if(table[i][x]==2){
            return -1;
        }else if(table[i][x]!=2 && i<n-1){
            return DownLine(i,x,n,table);
        }else{
            if(table[i][x]!=2 && !(i<n-1)){
                return 1;
            }else{
                return -1;
            }
        }
    }else{
        return 1;
    }
}
//Same, this check to the right of the coordinate
int RightLine(int y,int x,int m,int** table){
    int i=x+1;
    if(i<m){
        //printf("%d ",table[y][i]);
        if(table[y][i]==2){
            return -1;
        }else{
            if(table[y][i]!=2 && i<m-1){
                return RightLine(y,i,m,table);
            }else{
                if(table[y][i]!=2 && !(i<m-1)){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
    }else{
        return 1;
    }
}
//This check to the Left side
int LeftLine(int y,int x,int m,int** table){
    int i=x-1;
    if(i>-1){
        //printf("%d ",table[y][i]);
        if(table[y][i]==2){
            return -1;
        }else{
            if(table[y][i]!=2 && i>0){
                return LeftLine(y,i,m,table);
            }else{
                if(table[y][i]!=2 && !(i>0)){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
    }else{
        return 1;
    }
}
//This is the first function that check the diagonal, so in this case, with this board
/*
    2 1 1
    1 1 1
    1 1 1
*/
//And we are at X=3-1, Y=3-1, so we start to check, and we have 1, and then 2, so we can not set here a queen
//And is the same process as the last functions
int UpLeft(int y,int x,int** table){
    int i=y-1,j=x-1;
    if(i>-1 && j>-1){
        //printf("%d ",table[i][j]);
        if(table[i][j]==2){
            return -1;
        }else{
            if(table[i][j]!=2 && (i>0 && j>0)){
                return UpLeft(i,j,table);
            }else{
                if(table[i][j]!=2 && !(i>0 && j>0)){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
    }else{
        return 1;
    }
}
//Checking the down right line
int DownRight(int y,int x,int n,int m,int** table){
    int i=y+1,j=x+1;
    if(i<n && j<m){
        //printf("%d ",table[i][j]);
        if(table[i][j]==2){
            return -1;
        }else{
            if(table[i][j]!=2 && (i<n-1 && j<m-1)){
                return DownRight(i,j,n,m,table);
            }else{
                if(table[i][j]!=2 && !(i<n-1 && j<m-1)){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
    }else{
        return 1;
    }
}
//Up right line
int UpRight(int y,int x,int m,int** table){
    int i=y-1,j=x+1;
    if(i>-1 && j<m){
        //printf("%d ",table[i][j]);
        if(table[i][j]==2){
            return -1;
        }else{
            if(table[i][j]!=2 && (i>0 && j<m-1)){
                return UpRight(i,j,m,table);
            }else{
                if(table[i][j]!=2 && !(i>0 && j<m-1)){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
    }else{
        return 1;
    }
}
//Down left line
int DownLeft(int y,int x,int n,int** table){
    int i=y+1,j=x-1;
    if(i<n && j>-1){
        //printf("%d ",table[i][j]);
        if(table[i][j]==2){
            return -1;
        }else{
            if(table[i][j]!=2 && (i<n-1 && j>0)){
                return DownLeft(i,j,n,table);
            }else{
                if(table[i][j]!=2 && !(i<n-1 && j>0)){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
    }else{
        return 1;
    }
}
//Here we concentrate the las functions, in this case, the diagonal of the XY coordinate that the user give
//If one of this conditions return -1, we will not continue to check, 'cause it is not necessary
int Cross2(int y,int x,int n,int m,int** table){
    if(UpLeft(y,x,table)==1 && DownLeft(y,x,n,table)==1 && UpRight(y,x,m,table)==1 && DownRight(y,x,n,m,table)==1){
        return 1;
    }else{
        return -1;
    }
}
//Here we concentrate the Lines, up, down, right and left, and is the same as Cross2
int Cross(int y,int x,int n,int m,int** table){
    if(LeftLine(y,x,m,table)==1 && RightLine(y,x,m,table)==1 && UpLine(y,x,n,table)==1 && DownLine(y,x,n,table)==1){
        return 1;
    }else{
        return -1;
    }
}
//And here is the function that invoke both Cross, and here we determine if we can set a queen on the X Y position
int SetQueen(int y,int x,int n,int m,int** table){
    if(Cross(y,x,n,m,table)==1 && Cross2(y,x,n,m,table)==1){
        Queens++;
        return 2;
    }else{
        return 0;
    }
}