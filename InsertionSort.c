//Code by NakanoMiku13
//See more at http://github.com/NakanoMiku13
//Insertion Sort
#include<stdio.h>
#include<stdlib.h>
//Defining the structure list and the functions
typedef struct List List,*Function;
//Creating the nodes
struct Node{
    int Value;
    struct Node* Next;
};
//Creating the list
struct List{
    struct Node* Head;
    size_t size;
    Function (*AddF)(List*,int),(*AddB)(List*,int),(*ctr)(List*);
};
//Prototypes of the list
Function List_ctr(List*),List_AddF(List*,int),List_AddB(List*,int);
//main function
int main(){
    //Creating the list
    struct List list;
    list.ctr=List_ctr;
    list.AddF=List_AddF;
    list.AddB=List_AddB;
    list.ctr(&list);
    int n,i=0;
    //Setting the length of the list
    scanf("%d",&n);
    for(;i<n;i++){
        int x;
        scanf("%d",&x);
        //Checking if X is the first element of the list
        if(i==0){ 
            //Adding the first element of the list to the front
            list.AddF(&list,x);
        }else{
            //Comparing if the new value is higher than the head, if is higher, this value will be added to the back of the list
            if(x>list.Head->Value){
                list.AddB(&list,x);
            }else{
                //If the value is lower than the head this will be added to the front
                list.AddF(&list,x);
            }
        }
    }
    i=0;
    //Printing the sorted list
    struct Node* tmp = list.Head;
    while(i<list.size){
        printf("%d ",tmp->Value);
        tmp=tmp->Next;
        i++;
    }
}
//Constructor
Function List_ctr(List* self){
    self->Head=(struct Node*)malloc(sizeof(struct Node));
    self->size=0;
}
//Function that add to the front the new element of the list
Function List_AddF(List *self,int x){
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->Value=x;
    //If the list is empty, the head will be x, and if it is not empty, the actual head, will be removed, and X will be the new head, and the old head will be the next of the new head
    if(self->size>0){
        struct Node* move= self->Head;
        tmp->Next=move;
        self->Head=tmp;
    }else{
        self->Head=tmp;
    }
    self->size++;
}
//Function that add the new node to the back of the list
Function List_AddB(List* self, int x){
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->Value=x;
    int i=0,in=0;
    struct Node* Move=self->Head;
    //Travelling with 2 conditions, this while, will stop only if the new value is lower than the actual value of the list
    //and it will stop, if we get to the end of the list
    while(Move->Value<x && i<self->size-1){
        Move=Move->Next;
        i++;
    }
    //Checking that if the while finished by the size
    if(i>=self->size-1){
        //If it finished by the size, that means that the new node is higher than the last nodes of the list, and will be added to the end
        Move->Next=tmp;
    }else{
        //Else if it did not finish by the size, that means that the actual node of the list, is higher than the new node, so in this case, we swap them
        struct Node* tm=Move;
        tmp->Next=tm;
        Move->Next=tmp;
    }
    self->size++;
}