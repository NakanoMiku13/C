#include<stdio.h>
#include <stdlib.h>
typedef struct Table Table,*Function;
struct Node{
    int Value,_row,_col;
    struct Node *Next,*Prev;
};
struct Table{
    struct Node *Head;
    size_t _size,_rows,_cols,_ccols,_crows;
    Function (*Ctr)(Table *);
    Function (*Add)(Table *,int);
    Function (*Print)(Table *);
};
Function Table_Ctr(Table *),Table_Add(Table *,int),Table_Print(Table *);
int main(){
    struct Table table;
    table.Ctr=Table_Ctr;
    table.Add=Table_Add;
    table.Print=Table_Print;
    table.Ctr(&table);
    int x,y,i,j;
    scanf("%d %d",&x,&y);
    table._cols=x-1;
    table._rows=y-1;
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            int d;
            scanf("%d",&d);
            table.Add(&table,d);
        }
    }
    table._cols++;
    table.Add(&table,0);
    table.Add(&table,0);
    table.Add(&table,0);
    table.Print(&table);
}
Function Table_Ctr(Table *Self){
    Self->Head = (struct Node*)malloc(sizeof(struct Node));
    Self->_size=Self->_rows=Self->_cols=0;
}
Function Table_Add(Table *Self,int value) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->Value=value;
    if(Self->_size>0){
        struct Node* _Move = Self->Head;
        if(Self->_ccols<Self->_cols){
            /*tmp->_col=Self->_ccols;
            tmp->_row=Self->_crows;*/
            Self->Head=tmp;
            _Move->Prev=Self->Head;
            Self->Head->Next=_Move;
            Self->_ccols++;
        }else if(Self->_crows<Self->_rows){
            Self->Head=tmp;
            /*tmp->_col=Self->_ccols;
            tmp->_row=Self->_crows;*/
            _Move->Prev=tmp;
            Self->Head->Next=_Move;
            Self->_crows++;
            Self->_ccols=0;
        }else{
            Self->Head=tmp;
            /*tmp->_col=Self->_ccols;
            tmp->_row=Self->_crows;*/
            _Move->Prev=tmp;
            Self->Head->Next=_Move;
            Self->_ccols=0;
            Self->_crows=0;
        }
        _Move=NULL;
    }else{
        tmp->Prev=NULL;
        /*tmp->_col=0;
        tmp->_row=0;*/
        Self->Head=tmp;
        Self->_ccols++;
    }
    Self->_size++;
}
Function Table_Print(Table *Self){
    int i=0,j=0;
    struct Node* _Move = Self->Head;
    for(i=0;i<Self->_rows+1;i++){
        for(j=0;j<Self->_cols+1;j++){
            printf("%d ",_Move->Value);
            _Move=_Move->Next;
        }
        printf("\n");
    }
}