#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
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
Function ctr(Queue* s),Push(Queue* s,int x),Pop(Queue* s),Print(Queue* s);
Queue newQueue();
int main(){
    srand(time(NULL));
    char* nom = (char*)malloc(sizeof(char)*150);
	int cajeras=0,tiempoLlegada=0,i=0;
    int* tiempo=(int*)malloc(sizeof(int)*15);
    Queue caja1=newQueue(),caja2=newQueue(),caja3=newQueue();
	scanf("%s",nom);
	scanf("%d",&cajeras);
	for(i=0;i<cajeras;i++){
        int x=0;
		scanf("%d",&x);
        tiempo[i]=x;
	}
    int tiempos[]={10,20,30,40,50},atendidos=0,contador=1;
    while(1){
        if(atendidos>10 && caja1.size>0 && caja2.size>0 && caja3.size>0){
            return 0;
        }else{
            //cliente nuevo
            if(caja1.size==0){
                caja1.Push(&caja1,contador);
            }else if(caja2.size==0){
                caja2.Push(&caja2,contador);
            }else if(caja3.size==0){
                caja3.Push(&caja3,contador);
            }else{
                caja1.Push(&caja1,contador);
            }
        }
        
        atendidos++;
    }
}
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
Queue newQueue(){
    Queue new;
    new.ctr=ctr;
    new.Push=Push;
    new.Pop=Pop;
    new.Print=Print;
    return new;
}