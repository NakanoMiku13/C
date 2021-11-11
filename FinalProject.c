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
    FunctionsList (*ctr)(List* self),(*Add)(List* self,Pair),(*Print)(List* self),(*PopLast)(List* self),(*Clear)(List* self);
};
struct Table{
    struct Node *Head;
    size_t _size,_cols,_rows,_ccols,_crows,_cback,_back;
    FunctionTable (*Ctr)(Table *),(*Add)(Table *,int),(*Print)(Table *),(*SumFace)(Table*,int);
    FunctionTable (*FrontFace)(Table* From,int** To),(*BackFace)(Table* From,int** To),(*RightFace)(Table* From,int** To),(*LeftFace)(Table* From,int** To),(*TopFace)(Table* From,int** To),(*BottomFace)(Table* From,int** To);
};
struct Tree{
    struct NodeTree* root;
    FunctionsTree (*ctr)(Tree* self),(*Add)(Tree* self,int position,struct NodeList* node,int Value);
};
void SearchExit(int x,int y,int** table,List* visited,List* pending,Pair* exit),Initialize(List*,List*,Table*),SetFaces(int x,int y,int Fn,Table* table,List* visited,List* pending,Pair* exit);
int** CreateFace(Table* table,int face);
FunctionsList List_ctr(List* self),List_Add(List* self,Pair coordinates),List_Pop(List* self),List_Print(List* self),List_Clear(List* self);
FunctionsTree Tree_ctr(Tree* self),Tree_Add(Tree* self,int position,struct NodeList* node,int Value);
FunctionTable Table_Ctr(Table *),Table_Add(Table *,int),Table_Print(Table *),Table_FrontFace(Table*,int**),Table_BackFace(Table*,int**),Table_RightFace(Table*,int**),Table_LeftFace(Table*,int**),Table_TopFace(Table*,int**),Table_BottomFace(Table*,int**);
int main(){
    List positionList,Pending;
    Table table;
    Pair ExitCoordinates;
    Initialize(&positionList,&Pending,&table);
    SetFaces(1,6,1,&table,&positionList,&Pending,&ExitCoordinates);
    //positionList.Print(&positionList);
    printf("x=%d y=%d",ExitCoordinates.x,ExitCoordinates.y);
}
void PrintFace(int** table){
    int i=0,j=0;
    for(i=0;i<n;i++){ 
        for(int j=0;j<n;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void SetFaces(int x,int y,int Fn,Table* table,List* pslst,List* pndlst,Pair* Exit){
    int** Face;
    pslst->Clear(pslst);
    pndlst->Clear(pndlst);
    Face=CreateFace(table,Fn);
    Face[y][x]=3;
    PrintFace(Face);
    SearchExit(y,x,Face,pslst,pndlst,Exit);
    if(Face[Exit->y][Exit->x]==5) printf("Exit Found\n");
    else{
        //Right Face
        if(Exit->x<=n && (Face[Exit->y][Exit->x]==2 || Face[Exit->y][Exit->x+1]==2) && Fn==1){
            int x=0;
            int y=Exit->y;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,3,table,pslst,pndlst,Exit);
        //Back Face
        }else if(Exit->x<=n && (Face[Exit->y][Exit->x]==2 || Face[Exit->y][Exit->x+1]==2) && Fn==3){
            int x=Exit->x;
            int y=Exit->y;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,2,table,pslst,pndlst,Exit);
        //Bottom Face
        }else if(Exit->y<=n && (Face[Exit->y][Exit->x]==2 || Face[Exit->y+1][Exit->x]==2) && Fn==2){
            int x=Exit->y;
            int y=Exit->x;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,6,table,pslst,pndlst,Exit);
        //Left Face
        }else if(Exit->y>=0 && (Face[Exit->y][Exit->x]==2 || Face[Exit->y-1][Exit->x]==2) && Fn>=6){
            int x=Exit->x;
            int y=n-1;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,4,table,pslst,pndlst,Exit);
        }else if(Fn==4){
            int x=Exit->x;
            int y=Exit->y;
            Exit->x=0; Exit->y=0;
            SetFaces(x,y,5,table,pslst,pndlst,Exit);
        }
    }
}
void AsignTable(Table* s){
    int i,j,k;
    s->_cols=s->_rows=s->_back=n;
    int fill[10][10][10]={
        {{1,1,1,1,1,1,1,1},
        {1,0,1,0,1,0,0,2},
        {1,0,0,0,0,0,1,1},
        {1,0,1,0,1,0,1,1},   
        {1,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1},
        {1,3,1,0,0,0,0,1},
        {1,1,1,1,1,1,1,1}},

        {{2,0,1,1,0,0,0,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,0,0,0,1,0,0,1}},
        

        {{1,0,1,0,0,1,0,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0},
        {1,0,1,0,0,0,0,1}},
        
        {{1,0,1,0,0,0,1,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,0},
        {1,0,1,1,0,1,1,1}},
        
        {{1,0,0,0,0,0,5,1},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1},
        {2,0,1,0,0,0,0,1}},

        {{1,0,0,0,0,1,0,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {1,1,1,0,1,0,1,1}},

        {{1,0,1,0,0,0,1,1},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {1,0,0,0,0,0,0,1}},

        {{1,1,1,1,1,1,1,1},
        {1,1,0,0,1,0,0,1},
        {1,0,1,0,0,0,0,1},
        {1,0,0,0,1,1,0,1},
        {1,1,0,1,0,0,0,1},
        {1,0,0,0,0,1,0,1},
        {1,0,1,0,1,0,0,2},
        {1,2,1,1,1,1,1,1}}

    };
    for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++) s->Add(s,fill[i][j][k]);
    //s->Print(s);
}
int** CreateFace(Table* s,int face){
    int** Face = (int**)malloc(sizeof(int*)*n+1),i,j;
    for(i=0;i<n;i++) Face[i]=(int*)malloc(sizeof(int)*n+1);
    switch(face){
        //front face
        case 1:
            s->FrontFace(s,Face);
            break;
        //back face
        case 2:
            s->BackFace(s,Face);
            break;
        //right face
        case 3:
            s->RightFace(s,Face);
            break;
        //left face
        case 4:
            s->LeftFace(s,Face);
            break;
        //top face
        case 5:
            s->TopFace(s,Face);
            break;
        //bottom face
        default:
            s->BottomFace(s,Face);
            break;
    }
    return Face;
}
void InitializeList(List* s){
    s->ctr=List_ctr;
    s->Add=List_Add;
    s->Print=List_Print;
    s->PopLast=List_Pop;
    s->Clear=List_Clear;
    s->ctr(s);
}
void InitializeTable(Table* s){
    s->Ctr=Table_Ctr;
    s->Add=Table_Add;
    s->Print=Table_Print;
    s->FrontFace=Table_FrontFace;
    s->BackFace=Table_BackFace;
    s->RightFace=Table_RightFace;
    s->LeftFace=Table_LeftFace;
    s->TopFace=Table_TopFace;
    s->BottomFace=Table_BottomFace;
    s->Ctr(s);
}
void Initialize(List* positionList, List* PendingPositionList,Table* table){
    InitializeList(positionList);
    InitializeList(PendingPositionList);
    InitializeTable(table);
    AsignTable(table);
}
int IsVisited(List* list,int x,int y){
    struct NodeList* check=list->Head;
    int i=0;
    for(i=0;i<list->Size;i++,check=check->Next){
        if(check->coordinates.x==x && check->coordinates.y==y) return 1;
    }
    return 0;
}
void CheckLeftRight(int x,int y,int** table,List* pnd,List* visited,Pair* exit){
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
        if(table[y][x+1]==2 || table[y][x+1]==5){
            exit->x=x+1;
            exit->y=y;
        }else if(table[y][x-1]==2 || table[y][x-1]==5){
            exit->x=x-1;
            exit->y=y;
        }else{
            return;
        }
    }
}
void Down(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    if(y<n && table[y][x]!=1){
        if(table[y][x]==5){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y][x]==2){
            exit->x=x;
            exit->y=y;
            return;
        }
        if((y+1)<n && table[y+1][x]==2){
            exit->x=x;
            exit->y=y+1;
            return;
        }
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3 && y+1<n){
            Down(y+1,x,table,lst,pnd,exit);
        }
        if(table[y][x]==0){
            CheckLeftRight(x,y,table,pnd,lst,exit);
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
void Up(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    if(y>0 && table[y][x]!=1){
        if(table[y][x]==5){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y][x]==2){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y-1][x]==2){
            exit->x=x;
            exit->y=y-1;
            return;
        }
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Up(y-1,x,table,lst,pnd,exit);
        }
        if(table[y][x]==0){
            CheckLeftRight(x,y,table,pnd,lst,exit);
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
void CheckUpDown(int x,int y,List* pnd,int** table, List* visited,Pair* exit){
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
        if(table[y-1][x]==2 || table[y-1][x]==5){
            exit->x=x;
            exit->y=y-1;
        }else if(table[y+1][x]==2 || table[y+1][x]==5){
            exit->x=x;
            exit->y=y+1;
        }else{
            return;
        }
    }
}
void Right(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    if(x<n){
        if(table[y][x]==5){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y][x+1]==2){
            exit->x=x+1;
            exit->y=y;
            return;
        }else if(table[y][x]==2){
            exit->x=x;
            exit->y=y;
            return;
        }
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Right(y,x+1,table,lst,pnd,exit);
        }
        if(table[y][x]==0){
            CheckUpDown(x,y,pnd,table,lst,exit);
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
void Left(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    if(x>0){
        if(table[y][x]==5){
            exit->x=x;
            exit->y=y;
            return;
        }
        if(table[y][x-1]==2){
            exit->x=x-1;
            exit->y=y;
            return;
        }else if(table[y][x]==2){
            exit->x=x;
            exit->y=y;
            return;
        }
        if((table[y][x]==0 && IsVisited(lst,x,y)==0) || table[y][x]==3){
            Left(y,x-1,table,lst,pnd,exit);
        }
        if(table[y][x]==0){
            CheckUpDown(x,y,pnd,table,lst,exit);
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
void SearchExit(int y,int x,int** table,List* lst,List* pnd,Pair* exit){
    //Checking if we have a pending position or coordinate
    if(exit==NULL || (exit->x==0 && exit->y==0)){
        if(y==0 && table[y+1][x]==0 && (table[y][x]==2 || table[y][x]==3) ) y++;
        else if(y<=n && table[y-1][x]==0 && (table[y][x]==2 || table[y][x]==3) ) y--;
        if(x==0 && table[y][x+1]==0 && (table[y][x]==2 || table[y][x]==3)) x++;
        else if(x==n && table[y][x-1]==0 && (table[y][x]==2 || table[y][x]==3) ) x--;
        if(table[y][x]==5 || table[y][x]==2){
            exit->x=x; exit->y=y;
            return;
        }
        if(pnd->Size>0){
            struct NodeList* move = pnd->Head;
            int i=0;
            for(i=0;i<pnd->Size-1;i++,move=move->Next);
            int x1=move->coordinates.x,y1=move->coordinates.y;
            lst->Add(lst,move->coordinates);
            pnd->PopLast(pnd);
            Left(y1,x1-1,table,lst,pnd,exit);
            Right(y1,x1+1,table,lst,pnd,exit);
            Up(y1-1,x1,table,lst,pnd,exit);
            Down(y1+1,x1,table,lst,pnd,exit);
        }else if(table[y][x+1]!=1 && table[y][x-1]!=1 && IsVisited(lst,x,y)==0){
            //Check Right and left
            Left(y,x-1,table,lst,pnd,exit);
            Right(y,x+1,table,lst,pnd,exit);
        }else if(table[y+1][x]!=1 && table[y-1][x]!=1 && IsVisited(lst,x,y)==0){
            //Check Up and Down
            Up(y-1,x,table,lst,pnd,exit);
            Down(y+1,x,table,lst,pnd,exit);
        }else{
            Left(y,x-1,table,lst,pnd,exit);
            Right(y,x+1,table,lst,pnd,exit);
            Up(y-1,x,table,lst,pnd,exit);
            Down(y+1,x,table,lst,pnd,exit);
        }
        if(pnd->Size>0){
            SearchExit(y,x,table,lst,pnd,exit);
        }
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
FunctionsList List_Clear(List* self){
    if(self->Size>0){
        self->PopLast(self);
        List_Clear(self);
    }else{
        self->ctr(self);
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
FunctionTable Table_FrontFace(Table* self,int** table){
    int i,j;
    struct Node *move=self->Head,*move2=self->Head;
    for(i=0;i<self->_rows;i++,move=move->Bottom){
        move2=move;
        for(j=0;j<self->_cols;j++,move2=move2->Next){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_BackFace(Table* self,int** table){
    int i,j,k;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_back-1;i++,move=move->Back,move2=move2->Back);
    for(i=0;i<self->_rows;i++,move=move->Bottom){
        move2=move;
        for(j=0;j<self->_cols;j++,move2=move2->Next){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_RightFace(Table* self,int** table){
    int i,j;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_cols-1;i++,move=move->Next,move2=move->Next);
    for(i=0;i<self->_rows;i++,move=move->Bottom){
        move2=move;
        for(j=0;j<self->_back;j++,move2=move2->Back){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_LeftFace(Table* self,int** table){
    int i,j;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_rows;i++,move=move->Bottom){
        move2=move;
        for(j=0;j<self->_back;j++,move2=move2->Back){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_TopFace(Table* self,int** table){
    int i,j;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_cols;i++,move=move->Next){
        move2=move;
        for(j=0;j<self->_back;j++,move2=move2->Back){
            table[i][j]=move2->Value;
        }
    }
}
FunctionTable Table_BottomFace(Table* self,int** table){
    int i,j;
    struct Node* move=self->Head,*move2=self->Head;
    for(i=0;i<self->_rows-1;i++,move=move->Bottom,move2=move2->Bottom);
    for(i=0;i<self->_cols;i++,move=move->Next){
        move2=move;
        for(j=0;j<self->_back;j++,move2=move2->Back){
            table[i][j]=move2->Value;
        }
    }
}