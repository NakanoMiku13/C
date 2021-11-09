#include<stdio.h>
#include<stdlib.h>
#define n 8
#define m 6
typedef struct Tree Tree,*FunctionsTree;
typedef struct List List,*FunctionsList;
typedef struct Table Table,*FunctionTable;
typedef struct Pair Pair;
struct Pair{
    int x;
    int y;
};
struct Node{
    int Value;
    struct Node *Next,*Prev,*Top,*Bottom,*Front,*Back;
};
struct NodeList{
    Pair coordinates;
    struct NodeList *Next;
};
struct NodeTree{
    int value;
    Pair Coordinates;
    struct Node* Right,*Left,*Up,*Down;
};
struct List{
    struct NodeList *Head;
    size_t Size;
    FunctionsList (*ctr)(List* self),(*Add)(List* self,Pair),(*Print)(List* self),(*PopLast)(List* self);
};
struct Table{
    struct Node *Head;
    size_t _size,_cols,_rows,_ccols,_crows,_cback,_back;
    FunctionTable (*Ctr)(Table *),(*Add)(Table *,int),(*Print)(Table *),(*SumFace)(Table*,int);
};
struct Tree{
    struct NodeTree* root;
    FunctionsTree (*ctr)(Tree* self),(*Add)(Tree* self,int position,struct NodeList* node,int Value);
};
void CheckLeftRight(int x,int y,int** table,List* visited,List* pending),InitializeList(List* self),InitializeTable(Table* self);
FunctionsList List_ctr(List* self),List_Add(List* self,Pair coordinates),List_Pop(List* self),List_Print(List* self);
FunctionsTree Tree_ctr(Tree* self),Tree_Add(Tree* self,int position,struct NodeList* node,int Value);
FunctionTable Table_Ctr(Table *),Table_Add(Table *,int),Table_Print(Table *),Table_SumFace(Table*,int);
int main(){
    List positionList,Pending;
    Table table;
    InitializeList(&positionList);
    InitializeList(&Pending);
    InitializeTable(&table);
    int** Face = (int**)malloc(sizeof(int*)*n+1);
    int Faces[10][10]={
        {1,1,1,1,1,1},//0
        {1,0,0,0,0,1},//1
        {1,0,0,0,0,1},//2
        {1,0,0,0,0,1},//3
        {1,0,0,0,0,1},//4
        {1,0,0,0,0,1},//5
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
    CheckLeftRight(6,3,Face,&positionList,&Pending);
    positionList.Print(&positionList);
}
void InitializeList(List* s){
    s->ctr=List_ctr;
    s->Add=List_Add;
    s->Print=List_Print;
    s->PopLast=List_Pop;
    s->ctr(s);
}
void InitializeTable(Table* s){
    s->Ctr=Table_Ctr;
    s->Add=Table_Add;
    s->Print=Table_Print;
    s->Ctr(s);
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
        pending.x=x+1; pending.y=y;
        pnd->Add(pnd,pending);
        pending.x=x-1; pending.y=y;
        pnd->Add(pnd,pending);
    }else if(table[y][x+1]==0 && IsVisited(visited,x+1,y)==0){
        pending.x=x+1; pending.y=y;
        pnd->Add(pnd,pending);
    }else if(table[y][x-1]==0 && IsVisited(visited,x-1,y)==0){
        pending.x=x-1; pending.y=y;
        pnd->Add(pnd,pending);
    }else{
        return;
    }
}
void Down(int y,int x,int** table,List* lst,List* pnd){
    if(y<n && table[y][x]!=1){
        if(table[y][x]==2){ printf("Exit found at x=%d y=%d\n",x,y); return;}
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
        if(table[y][x]==2){ printf("Exit found at x=%d y=%d\n",x,y); return;}
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
        pending.x=x; pending.y=y-1;
        pnd->Add(pnd,pending);
        pending.x=x; pending.y=y+1;
        pnd->Add(pnd,pending);
    }else if(table[y-1][x]==0 && IsVisited(visited,x,y-1)==0){
        pending.x=x; pending.y=y-1;
        pnd->Add(pnd,pending);
    }else if(table[y+1][x]==0 && IsVisited(visited,x,y+1)==0){
        pending.x=x; pending.y=y+1;
        pnd->Add(pnd,pending);
    }else{
        return;
    }
}
void Right(int y,int x,int** table,List* lst,List* pnd){
    if(x<m){
        if(table[y][x]==2){ printf("Exit found at x=%d y=%d\n",x,y); return;}
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
        if(table[y][x]==2){ printf("Exit found at x=%d y=%d\n",x,y); return;}
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
FunctionsTree Tree_ctr(Tree* self){
    self->root=(struct NodeTree*)malloc(sizeof(struct NodeTree));
}
FunctionsTree Tree_Add(Tree* self,int position,struct NodeList* node,int Value){
    struct NodeTree* new = (struct NodeTree*)malloc(sizeof(struct NodeTree));
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
FunctionTable Table_Ctr(Table *Self){
    Self->Head=(struct Node*)malloc(sizeof(struct Node));
    Self->_size=Self->_cols=Self->_rows=Self->_ccols=Self->_crows=Self->_cback=Self->_back=0;
}
FunctionTable Table_Add(Table *Self,int value) {
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->Value=value;
    if(Self->_size>0){
        if(Self->_ccols<Self->_cols && Self->_crows==0 && Self->_cback==0){
            struct Node* _Move=Self->Head;
            int i=0;
            for(i=0;i<Self->_ccols-1;i++,_Move=_Move->Next);
            tmp->Prev=_Move;
            _Move->Next=tmp;
            Self->_ccols++;
        }else if(Self->_ccols<Self->_cols && Self->_cback==0){
            struct Node *_MoveUp=Self->Head;
            struct Node *_Move=Self->Head;
            int i=0;
            if(Self->_rows>0) for(i=0;i<Self->_crows-1;i++,_MoveUp=_MoveUp->Bottom);
            for(i=0;i<Self->_ccols;i++,_MoveUp=_MoveUp->Next);
            for(i=0;i<Self->_crows;i++,_Move=_Move->Bottom);
            for(i=0;i<Self->_ccols-1;i++,_Move=_Move->Next);
            tmp->Top=_MoveUp;
            _MoveUp->Bottom=tmp;
            tmp->Prev=_Move;
            _Move->Next=tmp;
            Self->_ccols++;
        }else if(Self->_ccols<Self->_cols && Self->_cback<Self->_back){
            struct Node *_MoveRight=Self->Head,*_MoveUp=Self->Head,*_MoveBack=Self->Head,*test=Self->Head;
            int i=0;
            for(i=0;i<Self->_cback-1;i++,_MoveBack=_MoveBack->Back);
            for(i=0;i<Self->_ccols;i++,_MoveBack=_MoveBack->Next);
            for(i=0;i<Self->_crows;i++,_MoveBack=_MoveBack->Bottom);
            for(i=0;i<Self->_cback;i++,_MoveUp=_MoveUp->Back);
            if(Self->_crows>0){
                for(i=0;i<Self->_crows-1;i++,_MoveUp=_MoveUp->Bottom);
                for(i=0;i<Self->_ccols;i++,_MoveUp=_MoveUp->Next);
            }
            for(i=0;i<Self->_cback;i++,_MoveRight=_MoveRight->Back);
            for(i=0;i<Self->_ccols-1;i++,_MoveRight=_MoveRight->Next);
            if(Self->_crows>0) for(i=0;i<Self->_crows;i++,_MoveRight=_MoveRight->Bottom);
            tmp->Prev = _MoveRight;
            _MoveRight->Next=tmp;
            tmp->Top=_MoveUp;
            _MoveUp->Bottom=tmp;
            tmp->Front=_MoveBack;
            _MoveBack->Back=tmp;
            Self->_ccols++;
        }else if(Self->_crows<Self->_rows-1 && Self->_crows==0 && Self->_cback==0){
            struct Node* _Move=Self->Head;
            tmp->Top=Self->Head;
            _Move->Bottom=tmp;
            _Move=_Move->Bottom;
            Self->_ccols=0;
            Self->_crows++;
            Self->_ccols++;
        }else if(Self->_crows<Self->_rows-1 && Self->_cback==0){
            struct Node* _Move=Self->Head;
            int i=0;
            for(i=0;i<Self->_crows;i++,_Move=_Move->Bottom);
            tmp->Top=_Move;
            _Move->Bottom=tmp;
            Self->_ccols=1;
            Self->_crows++;
        }else if(Self->_crows<Self->_rows-1 && Self->_cback!=0 && Self->_cback<Self->_back){
            struct Node* _Move=Self->Head,*_Move2=Self->Head;
            int i=0;
            for(i=0;i<Self->_crows;i++,_Move=_Move->Bottom);
            for(i=0;i<Self->_cback;i++,_Move=_Move->Back);
            for(i=0;i<=Self->_crows;i++,_Move2=_Move2->Bottom);
            for(i=0;i<Self->_cback-1;i++,_Move2=_Move2->Back);
            tmp->Top=_Move;
            _Move->Bottom=tmp;
            tmp->Front=_Move2;
            _Move2->Back=tmp;
            Self->_crows++;
            Self->_ccols=1;
        }else if(Self->_cback!=0 && Self->_cback<Self->_back-1){
            struct Node* _Move=Self->Head;
            int i=0;
            for(i=0;i<Self->_cback;i++,_Move=_Move->Back);
            tmp->Front=_Move;
            _Move->Back=tmp;
            Self->_ccols=1;
            Self->_crows=0;
            Self->_cback++;
        }else if(Self->_cback==0 && Self->_crows<Self->_rows){
            struct Node* _Move=Self->Head;
            tmp->Front=_Move;
            _Move->Back=tmp;
            Self->_ccols=1;
            Self->_crows=0;
            Self->_cback++;
        }
    }else{
        Self->Head=tmp;
        Self->_ccols++;
    }

    Self->_size++;
}
FunctionTable Table_Print(Table *Self){
    struct Node* _Move=Self->Head,*_Move2=Self->Head,*_Move3=Self->Head;
    int i=0,j=0,k=0;
    for(i=0;i<Self->_back;i++,_Move3=_Move3->Back){
        _Move2=_Move3;
        for(j=0;j<Self->_rows;j++,_Move2=_Move2->Bottom){
            _Move=_Move2;
            for(k=0;k<Self->_cols;k++,_Move=_Move->Next){
                printf("%d ",_Move->Value);
            }
            printf("\n");
        }
        printf("\n");
    }
}
