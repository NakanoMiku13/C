#include<stdio.h>
#include <stdlib.h>
typedef struct Stack Stack,*Function;
typedef struct Node *Node;
struct Node{
    int Value;
    Node Next;
};
struct Stack{
    Node Head;
    size_t size;
    Function (*ctr)(Stack*),(*Add)(Stack*,int),(*Pop)(Stack*);
};
Function Stack_Add(Stack*,int),Stack_ctr(Stack*),Stack_Pop(Stack*);
void SetT1(Stack*,int),Print(Stack),MoveTo(Stack*,Stack*),Hanoi(int,Stack*,Stack*,Stack*),SetSt(Stack*);
int Input();
int main(){
    int n=Input();
    Stack Tower1,Tower2,Tower3;
    SetSt(&Tower1); SetSt(&Tower2); SetSt(&Tower3);
    SetT1(&Tower1,n);
    Hanoi(n,&Tower1,&Tower3,&Tower2);
    Print(Tower3);
    printf("\n");
}
void SetSt(Stack* p){
    p->Add=Stack_Add;
    p->Pop=Stack_Pop;
    p->ctr=Stack_ctr;
    p->ctr(p);
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
void Hanoi(int n,Stack* From, Stack* To,Stack* Free){
    if(n>0){
        // 3     From=1 To=3 Free=2
        // 2     From=1 To=2 Free=3       (Move de 1 a 2   N=2, From=1, To=2, Free=3)
        // 1     From=1 To=3 Free=2       (Move de 1 a 3   N=1, From=1, To=3, Free=2)
        // 0
        //Move 1 a 2    n=2, 1, 2, 3 
        //
        Hanoi(n-1,From,Free,To);
        MoveTo(From,To);
        Hanoi(n-1,Free,To,From);
    }
}
void Print(Stack t){
    while(t.size>0){
        printf("%d\n",t.Head->Value);
        t.Pop(&t);
    }
}
void SetT1(Stack* T,int n){
    int i=n;
    while(i>0){
        T->Add(T,i);
        i--;
    }
}
void MoveTo(Stack* From,Stack* To){
    int x=From->Head->Value;
    From->Pop(From);
    To->Add(To,x);
}
Function Stack_ctr(Stack *self){
    self->Head=(Node)malloc(sizeof(Node));
    self->size=0;
}
Function Stack_Add(Stack *self,int x){
    Node tmp = (Node)malloc(sizeof(Node));
    tmp->Value=x;
    if(self->size>0){
        int i=0;
        Node move=self->Head;
        self->Head=tmp;
        self->Head->Next=move;
    }else{
        self->Head=tmp;
    }
    self->size++;
}
Function Stack_Pop(Stack *self){
    if(self->size>0){
        Node tmp=self->Head;
        self->Head=self->Head->Next;
        free(tmp);
        self->size--;
    }
}