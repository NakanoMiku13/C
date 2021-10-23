#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Tree Tree,*Function;
struct Node{
    int Value;
    struct Node *Right,*Left;
};
struct Tree{
    struct Node* Root;
    size_t nodes;
    Function (*ctr)(Tree*),(*Add)(Tree*,int);
};
Function Tree_ctr(Tree* self),Tree_Add(Tree* self,int x);
void Print(struct Node*);
int main(){
    Tree tree;
    tree.ctr=Tree_ctr;
    tree.Add=Tree_Add;
    int i;
    tree.ctr(&tree);
    srand(time(NULL));
    for(i=0;i<10;i++){
        int x=rand()%1000;
        printf("%d ",x);
        tree.Add(&tree,x);
    }
    printf("\n");
    Print(tree.Root);
}
void Print(struct Node* root){
    struct Node* move = root;
    if(move!=NULL){
        Print(root->Left);
        printf("%d ",root->Value);
        Print(root->Right);
    }
}
Function Tree_ctr(Tree* self){
    self->Root=(struct Node*)malloc(sizeof(struct Node));
    self->nodes=0;
}
void AddNode(struct Node* node,int x){
    struct Node* tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->Value=x;
    if(x>=node->Value){
        if(node->Right==NULL){
            node->Right=tmp;
        }else{
            AddNode(node->Right,x);
        }
    }else{
        if(node->Left==NULL){
            node->Left=tmp;
        }else{
            AddNode(node->Left,x);
        }
    }
}
Function Tree_Add(Tree* self,int x){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->Value=x;
    self->nodes++;
    if(self->Root==NULL){
        self->Root=new;
    }else{
        struct Node* move = self->Root;
        AddNode(move,x);
    }
}
