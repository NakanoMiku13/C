#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList LinkedList,*Function;
struct Node{
    int Value;
    struct Node* Next;
};
struct LinkedList{
    struct Node* Head;
    size_t size;
    Function (*ctr)(LinkedList* self),
    (*Add)(LinkedList* self,int x),
    (*Pop)(LinkedList* self);
};
Function List_ctr(LinkedList* self),List_Add(LinkedList* self,int x),List_Pop(LinkedList* self);
int main(){
    LinkedList lista;
    lista.ctr=List_ctr;
    lista.Add=List_Add;
    lista.Pop=List_Pop;
    lista.ctr(&lista);
    lista.Add(&lista,2);
    lista.Add(&lista,5);
    lista.Add(&lista,7);
    lista.Pop(&lista);
    lista.Add(&lista,8);
    lista.Add(&lista,15);
    while(lista.Head!=NULL){
        printf("%d ",lista.Head->Value);
        lista.Head=lista.Head->Next;
    }
}
Function List_ctr(LinkedList* self){
    self->Head=(struct Node*)malloc(sizeof(struct Node));
    self->size=0;
}
Function List_Add(LinkedList* self,int x){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->Value=x;
    if(self->size==0 || self->Head==NULL){
        self->Head=new;
    }else{
        struct Node* move=self->Head;
        int i=0;
        for(i=0;i<self->size-1;i++,move=move->Next);
        move->Next=new;
    }
    self->size++;
}
Function List_Pop(LinkedList* self){
    if(self->size>0){
        struct Node* move=self->Head;
        int i=0;
        for(i=0;i<self->size;i++,move=move->Next);
        move=NULL;
        self->size--;
    }
}