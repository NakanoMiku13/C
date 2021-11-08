#include<stdio.h>
#include<stdlib.h>
typedef struct Tree Tree,*FunctionsTree;
typedef struct List List,*FunctionsList;
typedef struct Pair Pair;
struct Pair{
    int x;
    int y;
};
struct NodeList{
    Pair coordinates;
    struct NodeList *Next;
};
struct List{
    struct NodeList *Head;
    size_t Size;
    FunctionsList (*ctr)(List* self),(*Add)(List* self,Pair),(*Print)(List* self),(*PopLast)(List* self);
};
FunctionsList List_Print(List* self){
    struct NodeList *move=self->Head;
    int i;
    if(self->Size>0)
    for(i=0;i<self->Size && move!=NULL;i++,move=move->Next){
        printf("Y:%d X:%d\n",move->coordinates.y,move->coordinates.x);
    }
}
FunctionsList List_ctr(List* self){
    self->Head=(struct NodeList*)malloc(sizeof(struct NodeList));
    self->Size=0;
}
FunctionsList List_Add(List* self,Pair coordinates){
    struct NodeList* new = (struct NodeList*)malloc(sizeof(struct NodeList));
    new->coordinates=coordinates;
    if(self->Size==0){
        self->Head=new;
    }else{
        struct NodeList* Move=self->Head;
        int i;
        for(i=0;i<self->Size-1;i++,Move=Move->Next);
        Move->Next=new;
    }
    self->Size++;
}
FunctionsList List_Pop(List* self){
    if(self->Size>0){
        int i=0;
        struct NodeList* Move = self->Head;
        for(i=0;i<self->Size-1;i++,Move=Move->Next);
        free(Move);
        self->Size--;
    }
}
struct Node{
    int value;
    Pair Coordinates;
    struct Node* Right,*Left,*Up,*Down;
};
struct Tree{
    struct Node* root;
    FunctionsTree (*ctr)(Tree* self),(*Add)(Tree* self,int position,struct NodeList* node,int Value);
};
FunctionsTree Tree_ctr(Tree* self){
    self->root=(struct Node*)malloc(sizeof(struct Node));
}
FunctionsTree Tree_Add(Tree* self,int position,struct NodeList* node,int Value){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->value=Value;
    new->Coordinates=node->coordinates;
    if(self->root=NULL){
        self->root=new;
    }else{
        switch(position){
            //case 1: //Right 
                
        }
    }
}
void SearchExit(int,int,int**,List*);
void CheckLeftRight(int,int,int**,List*,List*);
int n=8,m=6;
int main(){
    List positionList,Pending;
    Pending.ctr=positionList.ctr=List_ctr;
    Pending.Add=positionList.Add=List_Add;
    Pending.Print=positionList.Print=List_Print;
    Pending.PopLast=positionList.PopLast=List_Pop;
    positionList.ctr(&positionList);
    Pending.ctr(&Pending);
    int** Face = (int**)malloc(sizeof(int*)*n+1);
    /*int Faces[10][10]={
        {2},
        {0},
        {0},
        {0},
        {0},
        {0},
        {1}
    };*/
    int Faces[10][10]={
        {1,1,1,1,1,1},//0
        {1,0,0,0,1,1},//1
        {1,0,1,0,0,1},//2
        {1,0,1,1,0,1},//3
        {1,0,1,0,0,1},//4
        {1,0,0,1,0,1},//5
        {1,3,1,0,0,1},//6
        {1,1,1,2,1,1}//7
       //0 1 2 3 4 5
    };
    for(int i=0;i<n;i++) Face[i] = (int*)malloc(sizeof(int)*m+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Face[i][j] = Faces[i][j];
        }
    }
    //SearchExit(6,1,Face,&positionList);
    CheckLeftRight(6,3,Face,&positionList,&Pending);
    positionList.Print(&positionList);
    printf("dd");
    //Pending.Print(&Pending);
}
int IsVisited(List* list,int x,int y){
    struct NodeList* check=list->Head;
    int i=0;
    for(i=0;i<list->Size;i++,check=check->Next){
        if(check->coordinates.x==x && check->coordinates.y==y) return 1;
    }
    return 0;
}
void CheckLeftRight1(int x,int y,int** table,List* pnd,List* visited){
    Pair pending;
    if(table[y][x+1]==0 && table[y][x-1]==0 && IsVisited(visited,x+1,y)==0  && IsVisited(visited,x-1,y)==0){
        printf("Found Right and left at x=%d y=%d\n",x,y);
        pending.x=x+1; pending.y=y;
        pnd->Add(pnd,pending);
        pending.x=x-1; pending.y=y;
        pnd->Add(pnd,pending);
    }else if(table[y][x+1]==0 && IsVisited(visited,x+1,y)==0){
        printf("Found Right at x=%d y=%d\n",x,y);
        pending.x=x+1; pending.y=y;
        pnd->Add(pnd,pending);
    }else if(table[y][x-1]==0 && IsVisited(visited,x-1,y)==0){
        printf("Found Left at x=%d y=%d\n",x,y);
        pending.x=x-1; pending.y=y;
        pnd->Add(pnd,pending);
    }else{
        return;
    }
}
void Down(int y,int x,int** table,List* lst,List* pnd){
    if(y<n && table[y][x]!=1){
        if(table[y][x]==2) return;
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Down(y+1,x,table,lst,pnd);
        }
        if(table[y][x]==0){
            CheckLeftRight1(x,y,table,pnd,lst);
            Pair cordvisited;
            cordvisited.x=x;
            cordvisited.y=y;
            lst->Add(lst,cordvisited);
        }else{
            return;
        }
    }else{
        return;
    }
}
void Up(int y,int x,int** table,List* lst,List* pnd){
    if(y>0 && table[y][x]!=1){
        if(table[y][x]==2) return;
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Up(y-1,x,table,lst,pnd);
        }
        if(table[y][x]==0){
            CheckLeftRight1(x,y,table,pnd,lst);
            Pair cordvisited;
            cordvisited.x=x;
            cordvisited.y=y;
            lst->Add(lst,cordvisited);
        }else{
            return;
        }
    }else{
        return;
    }
}
void CheckUpDown(int x,int y,List* pnd,int** table, List* visited){
    Pair pending;
    if(table[y+1][x]==0 && table[y-1][x]==0 && IsVisited(visited,x,y-1)==0 && IsVisited(visited,x,y+1)==0){
        printf("Found up and down at x=%d y=%d\n",x,y);
        pending.x=x; pending.y=y-1;
        pnd->Add(pnd,pending);
        pending.x=x; pending.y=y+1;
        pnd->Add(pnd,pending);
    }else if(table[y-1][x]==0 && IsVisited(visited,x,y-1)==0){
        printf("Found Up at x=%d y=%d\n",x,y);
        pending.x=x; pending.y=y-1;
        pnd->Add(pnd,pending);
    }else if(table[y+1][x]==0 && IsVisited(visited,x,y+1)==0){
        printf("Found Down at x=%d y=%d\n",x,y);
        pending.x=x; pending.y=y+1;
        pnd->Add(pnd,pending);
    }else{
        return;
    }
}
void Right(int y,int x,int** table,List* lst,List* pnd){
    if(x<m){
        if(table[y][x]==2) return;
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Right(y,x+1,table,lst,pnd);
        }
        if(table[y][x]==0){
            CheckUpDown(x,y,pnd,table,lst);
            Pair cordvisited;
            cordvisited.x=x;
            cordvisited.y=y;
            lst->Add(lst,cordvisited);
        }else{
            return;
        }
    }else{
        return;
    }
}
void Left(int y,int x,int** table,List* lst,List* pnd){
    if(x>0){
        if(table[y][x]==0) CheckUpDown(x,y,pnd,table,lst);
        if(table[y][x]==2) return;
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Left(y,x-1,table,lst,pnd);
        }
        if(table[y][x]==0){
            Pair cordvisited;
            cordvisited.x=x;
            cordvisited.y=y;
            lst->Add(lst,cordvisited);
        }else{
            return;
        }
    }else{
        return;
    }
}
void CheckCross(int x,int y,int** table,List* pnd){
    if(table[y][x+1]==0 && table[y][x-1]==0 && table[y-1][x]==0 && table[y+1][x]==0){
        Pair pending;
        //Right
        pending.x=x+1; pending.y=y;
        pnd->Add(pnd,pending);
        //Left
        pending.x=x-1; pending.y=y;
        pnd->Add(pnd,pending);
        //Up
        pending.x=x; pending.y=y-1;
        pnd->Add(pnd,pending);
        //Down
        pending.x=x; pending.y=y+1;
        pnd->Add(pnd,pending);
    }
}
void CheckLeftRight(int y,int x,int** table,List* lst,List* pnd){
    //Checking if we have a pending position or coordinate
    printf("%d pnd\n",pnd->Size);
    if(pnd->Size>0){
        printf("Pending list %d\n",pnd->Size);
        struct NodeList* move = pnd->Head;
        int i=0;
        for(i=0;i<pnd->Size-1;i++,move=move->Next);
        int x1=move->coordinates.x,y1=move->coordinates.y;
        lst->Add(lst,move->coordinates);
        pnd->PopLast(pnd);
        Left(y1,x1-1,table,lst,pnd);
        Right(y1,x1+1,table,lst,pnd);
        Up(y1-1,x1,table,lst,pnd);
        Down(y1+1,x1,table,lst,pnd);
    }else
    if(table[y][x+1]!=1 && table[y][x-1]!=1 && IsVisited(lst,x,y)==0){
        //Check Right and left
        Left(y,x-1,table,lst,pnd);
        Right(y,x+1,table,lst,pnd);
    }else if(table[y+1][x]!=1 && table[y-1][x]!=1 && IsVisited(lst,x,y)==0){
        //Check Up and Down
        Up(y-1,x,table,lst,pnd);
        Down(y+1,x,table,lst,pnd);
    }else{
        Left(y,x-1,table,lst,pnd);
        Right(y,x+1,table,lst,pnd);
        Up(y-1,x,table,lst,pnd);
        Down(y+1,x,table,lst,pnd);
    }
    if(pnd->Size>0){
        CheckLeftRight(y,x,table,lst,pnd);
    }
}
void SearchExit(int y,int x,int** table,List* list){
    
}