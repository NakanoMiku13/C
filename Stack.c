#include<stdio.h>
#include<stdlib.h>
typedef struct Stack Stack,*Function;
typedef struct Node Node;
struct Node{
    int Value;
    Node* Next;
};
struct Stack{
    Node* Head;
    size_t size;
    Function (*ctr)(Stack* self),(*Add)(Stack* self,int x),(*Pop)(Stack* self),(*Print)(Stack* self);
};
Function Stack_ctr(Stack* self){
    self->Head=(Node*)malloc(sizeof(Node));
    self->size=0;
}
Function Stack_Add(Stack* self,int x){
    Node* new = (Node*)malloc(sizeof(Node));
    new->Value=x;
    if(self->size==0){
        self->Head=new;
    }else{
        int i;
        Node* move=self->Head;
        new->Next=move;
        self->Head=new;
    }
    self->size++;
}
Function Stack_Pop(Stack* self){
    if(self->size>0){
        Node* tmp=self->Head;
        self->Head=self->Head->Next;
        free(tmp);
        self->size--;
    }
}
Function Stack_Print(Stack* self) {
    if(self->size>0){
        Node* move=self->Head;
        while(move!=NULL){
            printf("%d ",move->Value);
            move=move->Next;
        }
    }
}
int main(){
    Stack pila;
    pila.Add=Stack_Add;
    pila.ctr=Stack_ctr;
    pila.Pop=Stack_Pop;
    pila.Print=Stack_Print;
    pila.ctr(&pila);
    pila.Add(&pila,1);
    pila.Add(&pila,2);
    pila.Add(&pila,3);
    pila.Print(&pila);
}