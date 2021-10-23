
//Find more interesting codes in https://github.com/NakanoMiku13
//DynamicTable
#include<stdio.h>
#include<time.h>
#include <stdlib.h>
//Defining the main structs
typedef struct Table Table,*Function;
//Creating the Main Node Structure, that contains a pointer aiming to the next, previous, top and bottom node of the table
struct Node{
    int Value;
    struct Node *Next,*Prev,*Top,*Bottom,*Front,*Back;
};
struct Table{
    struct Node *Head;
    size_t _size,_cols,_rows,_ccols,_crows,_cback,_back;
    Function (*Ctr)(Table *);
    Function (*Add)(Table *,int);
    Function (*Print)(Table *);
    Function (*SumFace)(Table*,int);
};
Function Table_Ctr(Table *),Table_Add(Table *,int),Table_Print(Table *),Table_SumFace(Table*,int);
int main(){
    struct Table table;
    table.Ctr=Table_Ctr;
    table.Add=Table_Add;
    table.Print=Table_Print;
    table.SumFace=Table_SumFace;
    table.Ctr(&table);
    int x,y,i,j,o=1,z,k,op;
    printf("Type the Y coordinate, X coordinate and Z coordinate\n");
    scanf("%d %d %d",&y,&x,&z);
    printf("Type the face that you want to make the sum operation\n1) Front Face\t2) Back Face\t3) Right Face\t4) Left Face\t5) Top Face\t6) Bottom Face\n");
    scanf("%d",&op);
    system("clear");
    table._cols=x;
    table._rows=y;
    table._back=z;
    srand(time(NULL));
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            for(k=0;k<z;k++,o++){
                table.Add(&table,rand()%100);
            }
        }
    }
    table.SumFace(&table,op);
    printf("This is the table:\n\n");
    table.Print(&table);
}
Function Table_Ctr(Table *Self){
    Self->Head=(struct Node*)malloc(sizeof(struct Node));
    Self->_size=Self->_cols=Self->_rows=Self->_ccols=Self->_crows=Self->_cback=Self->_back=0;
}
Function Table_Add(Table *Self,int value) {
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
Function Table_Print(Table *Self){
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
int FrontFace(Table* t){
    struct Node* Move = t->Head,*Move2=t->Head;
    int i,j,r=0;
    for(i=0;i<t->_rows;i++,Move2=Move2->Bottom){
        Move=Move2;
        for(j=0;j<t->_cols;j++,Move=Move->Next){
            printf("%d ",Move->Value);
            r+=Move->Value;
        }
        printf("\n");
    }
    return r;
}
int BackFace(Table *t){
    struct Node* Move = t->Head,*Move2=t->Head;
    int i,j,r=0;
    for(i=0;i<t->_back-1;i++,Move=Move->Back,Move2=Move2->Back);
    for(i=0;i<t->_rows;i++,Move2=Move2->Bottom){
        Move=Move2;
        for(j=0;j<t->_cols;j++,Move=Move->Next){
            printf("%d ",Move->Value);
            r+=Move->Value;
        }
        printf("\n");
    }
    return r;
}
int RightFace(Table * t){
    struct Node * Move = t->Head,*Move2=t->Head;
    int i,j,r=0;
    for(i=0;i<t->_cols-1;i++,Move=Move->Next,Move2=Move2->Next);
    for(i=0;i<t->_rows;i++,Move2=Move2->Bottom){
        Move=Move2;
        for(j=0;j<t->_back;j++,Move=Move->Back){
            printf("%d ",Move->Value);
            r+=Move->Value;
        }
        printf("\n");
    }
    return r;
}
int LeftFace(Table *t){
    struct Node* Move = t->Head,*Move2=t->Head;
    int i,j,r=0;
    for(i=0;i<t->_rows;i++,Move2=Move2->Bottom){
        Move=Move2;
        for(j=0;j<t->_back;j++,Move=Move->Back){
            printf("%d ",Move->Value);
            r+=Move->Value;
        }
        printf("\n");
    }
    return r;
}
int TopFace(Table *t){
    struct Node * Move = t->Head,*Move2=t->Head;
    int i,j,r=0;
    for(i=0;i<t->_back;i++,Move2=Move2->Back){
        Move=Move2;
        for(j=0;j<t->_cols;j++,Move=Move->Next){
            printf("%d ",Move->Value);
            r+=Move->Value;
        }
        printf("\n");
    }
    return r;
}
int BottomFace(Table *t){
    struct Node * Move = t->Head,*Move2=t->Head;
    int i,j,r=0;
    for(i=0;i<t->_rows-1;i++,Move=Move->Bottom,Move2=Move2->Bottom);
    for(i=0;i<t->_back;i++,Move2=Move2->Back){
        Move=Move2;
        for(j=0;j<t->_cols;j++,Move=Move->Next){
            printf("%d ",Move->Value);
            r+=Move->Value;
        }
        printf("\n");
    }
    return r;
}
Function Table_SumFace(Table *Self,int FaceNumber){
    switch(FaceNumber){
        case 1:
            printf("Value: %d\n",FrontFace(Self));
            break;
        case 2:
            printf("Value: %d\n",BackFace(Self));
            break;
        case 3:
            printf("Value: %d\n",RightFace(Self));
            break;
            break;
        case 4:
            printf("Value: %d\n",LeftFace(Self));
            break;
        case 5:
            printf("Value: %d\n",TopFace(Self));
            break;
        case 6:
            printf("Value: %d\n",BottomFace(Self));
            break;
        default:
            printf("Error\n");
            break;
    }
}