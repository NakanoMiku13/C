#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Queue Queue,*Function;
typedef struct Node Node;
struct Node{
    int v;
    Node* n;
};
struct Queue{
    Node* head;
    Node* back;
    size_t size;
    Function (*ctr)(Queue* s),(*Push)(Queue* s,int x),(*Pop)(Queue* s),(*Print)(Queue* s);
};
Function ctr(Queue* s){
    s->head=s->back=(Node*)malloc(sizeof(Node));
    s->size=0;
}
Function Push(Queue* s, int x){
    Node* new = (Node*)malloc(sizeof(Node));
    new->v=x;
    if(s->size==0){
        s->back=s->head=new;
    }else{
        Node* move=s->head;
        int i;
        for(i=0;i<s->size-1;i++,move=move->n);
        move->n=new;
        s->back=move->n;
    }
    s->size++;
}
Function Pop(Queue* s){
    if(s->size>0){
        Node* tmp=s->head;
        s->head=s->head->n;
        free(tmp);
        s->size--;
    }
}
Function Print(Queue* s){
    if(s->size>0){
        Node* m=s->head;
        int i;
        for(i=0;i<s->size;i++,m=m->n){
            printf("%d ",m->v);
        }
    }
}

int main(){
    srand(time(0));
    int clientes = 10 + rand()%50,i=0,tiempos[]={10,20,30,40,50};
    for(i=0;i<clientes;i++){
        
    }
    Queue fila1,fila2,fila3;
    fila1.ctr=fila2.ctr=fila3.ctr=ctr;
    fila1.Push=fila3.Push=fila3.Push=Push;
    fila1.Pop=fila2.Pop=fila3.Pop=Pop;
    fila1.Print=fila2.Print=fila3.Print=Print;
    
}