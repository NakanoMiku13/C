#include<stdio.h>
#include<stdlib.h>
typedef struct Heap Heap,*Function;
struct Node{
    int Value;
    struct Node *Right,*Left;
};
struct Heap{
    struct Node* Root;
    Function (*ctr)(Heap *),(*MinHeap)(Heap*,int),(*MaxHeap)(Heap*,int);
};
Function Heap_MinHeap(Heap*,int),Heap_MaxHeap(Heap*,int),ctr(Heap*);
int main(){
    Heap heap;
    heap.ctr=ctr;
    heap.MaxHeap=heap.MaxHeap;
    heap.ctr(&heap);
    int x=10,i;
    for(i=0;i<5;i++,x--){
        heap.MaxHeap(&heap,x);
    }
}
Function ctr(Heap* self){
    self->Root=(struct Node*)malloc(sizeof(struct Node));
}
void MaxHeap(struct Node* node,int x){
    struct Node* tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->Value=x;
    if(node->Value<x){
        int y = node->Value;
        node->Value=x;
        tmp->Value = y;
        if(node->Left==NULL){
            node->Left=tmp;
        }else{
            if(node->Right==NULL){
                node->Right=tmp;
            }else{
                MaxHeap(node,y);
            }
        }
    }else{
        if(node->Value>x){
            if(node->Left==NULL){
                node->Left=tmp;
            }else{
                if(node->Right==NULL){
                    node->Right=tmp;
                }else{
                    MaxHeap(node->Left,x);
                }
            }
        }
    }
}
Function Heap_MaxHeap(Heap* heap,int x){
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    new->Value = x;
    if(heap->Root == NULL){
        heap->Root=new;
    }else{
        struct Node* move = heap->Root;
        MaxHeap(move,x);
    }
}