//Code by NakanoMiku13
//See more at http://github.com/NakanoMiku13
//DynamicMemory
#include<stdio.h>
#include<stdlib.h>
//Typedef instruction are useful to declare multiple data types of any name that we want to declare
//We reserve the name in this case like LinkedList and Function are reserved words
typedef struct LinkedList LinkedList,*Function;
//First structure that allow us to set a nice linked list, creating here the nodes that will connect all the
//elements in the linked list
struct Node{
    int Value;
    struct Node* Next;
};
//Unique structure that is named linked list that have head, back and middle pointers to know where are the nodes
struct LinkedList{
    //Head to know where is the first node in the linked list
    struct Node* Head;
    //Back to know where is the last node in the linked list
    struct Node* Back;
    //Middle to know where is the middle node in the linked list
    struct Node* Middle;
    //Size of the linked list
    //Private
    size_t _size;
    //Let us know if it is empty without checking for the size of the linked list
    //Private
    int _Empty;
    //Number of Front nodes
    int FE;
    //Number of back nodes
    int BE;
    //Both FE and BE are variables that where created, 'cause the linked list is manipulated
    //as 2 linked lists, but you can travel through the linked with any node, but for make it more convenient
    //is used as 2 linked list, one to check the Front elements and one that check for the back elements
    //is just for make it more ez to manage
    //Function prototypes for the linked list
    Function (*Set)(LinkedList *);
    Function (*Empty)(LinkedList *);
    Function (*AddFront)(LinkedList *,int);
    Function (*PopFront)(LinkedList *);
    Function (*AddBack)(LinkedList *,int);
    Function (*PopBack)(LinkedList *);
    Function (*SetMiddle)(LinkedList *,int);
};
//Function prototypes that are set on the structure linked list any time that we need to invoke them.
Function LinkedList_Set(LinkedList *);
Function LinkedList_Empty(LinkedList *);
Function LinkedList_AddFront(LinkedList *,int);
Function LinkedList_SetMiddle(LinkedList *,int);
Function LinkedList_PopFront(LinkedList *);
Function LinkedList_AddBack(LinkedList *,int);
Function LinkedList_PopBack(LinkedList *);
//Main program Function prototypes
void Input(LinkedList *),PrintList(LinkedList *),PrintElements(LinkedList *),ListInit(LinkedList *);
//Main function
int main(){
    struct LinkedList List;
    ListInit(&List);
    List.Set(&List);
    Input(&List);
    PrintElements(&List);
    PrintList(&List);
}
//Function that invokes all the Functions for the linked list
void ListInit(LinkedList *List) {
    List->Set=LinkedList_Set;
    List->Empty=LinkedList_Empty;
    List->AddFront=LinkedList_AddFront;
    List->SetMiddle=LinkedList_SetMiddle;
    List->PopFront=LinkedList_PopFront;
    List->AddBack=LinkedList_AddBack;
    List->PopBack=LinkedList_PopBack;
}
//Function that only prints the head, back and middle elements of the linked list
void PrintElements(LinkedList *List){
    List->SetMiddle(List,0);
    printf("Front Value: %d\nBack Value: %d\nMiddle Value: %d\n", List->Head->Value,List->Back->Value,List->Middle->Value);
}
//Function that print the elements of the linked list
void PrintList(LinkedList *List){
    int i=1,j=0;
    while(List->FE>0){
        printf("Value %d: %d\n",i,List->Head->Value);
        i++;
        List->PopFront(List);
    }
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    //This is a different way to print the linked list, 'cause, as I mentioned before, I managed
    //The linked list as 2 separate linked lists, so, I print it separate each other
    //And here is less efficient than the first part that only prints the head elements of the linked list
    //In this case if we print it like the first part, we are going to print it from the back to the front
    //Eg. we have the number 5 4 3 2 1, and that is the correct way to print the list, but with the method
    //that I use, the list will be printed like 1 2 3 4 5, and with this we solved that.
    int k=List->BE,l=0;
    for(j=0;j<k;j++,i++){
        tmp=List->Back;
        l=0;
        while(l<List->BE-j-1){
            tmp=tmp->Next;
            l++;
        }
        printf("Value %d: %d\n",i,tmp->Value);
    }
}
//Function that accepts the Input for the LinkedList, and is the main Menu of the program.
void Input(LinkedList *List){
    int x;
    do{
        printf("1) Agregar adelante\n2) Agregar atras\n3) Agregar en medio\n4) Terminar\n");
        scanf("%d",&x);
        if(x<4){
            printf("Ingresa el valor:\n");
            int y;
            scanf("%d",&y);
            if(x==1){
                List->AddFront(List,y);
            }else if(x==2){
                List->AddBack(List,y);
            }else{
                List->SetMiddle(List,y);
            }
        }
    }while(x<4);
}
//This is a rustic constructor of the linked list
Function LinkedList_Set(LinkedList *self){
    self->Middle=self->Head=self->Back=(struct Node*)malloc(sizeof(struct Node));
    self->BE=self->FE=self->_Empty=self->_size=0;
}
//This function set the variable Empty to false or true, depending on the size of the linked list
Function LinkedList_Empty(LinkedList *self){
    if(self->_size>0) self->_Empty=1;
    else self->_Empty=0;
};
//This function allow us to set and add the middle node to the linked list, deppending on the X value, if it is
//different from zero, the function will add the X value in the middle of the linked list
//If the value is equal to zero, the function will check who is the middle value on the linked list
Function LinkedList_SetMiddle(LinkedList *self,int x){
    int a=self->FE,b=self->BE, c=a+b;
    struct Node* tmp;
    tmp=(struct Node*)malloc(sizeof(struct Node));
    if(x==0){
        //Here we check where and who is the middle value
        if(a>b){
            tmp=self->Head;
            int i=0;
            while(i<a-1){
                tmp=tmp->Next;
                i++;
            }
        }else{
            tmp=self->Back;
            int i=0;
            while(i<b-1){
                tmp=tmp->Next;
                i++;
            }
        }
        self->Middle=tmp;
    }else{
        //Here we add the X value to the middle node
        //Creating our tmp nodes
        struct Node *_Move,*_Values,*_Next;
        //Initialize the node as null to avoid some future problem with trash values
        _Values=_Next=_Move=(struct Node*)malloc(sizeof(struct Node));
        //Adding the X value to the node Values
        _Values->Value=x;
        //Finding the middle node
        if(a>b){
            tmp=self->Head;
            int i=0;
            while(i<self->FE-1){
                tmp=tmp->Next;
                i++;
            }
            self->FE++;
        }else{
            tmp=self->Back;
            int i=0;
            while(i<self->BE-1){
                tmp=tmp->Next;
                i++;
            }
            self->BE++;
        }
        //tmp node could be Head or Back, that is going to depend on the size of BE or FE, if BE is higher than FE, BE will be used
        //but if FE is higher than BE, FE will be used as tmp node, to travel around the linked list
        _Move=tmp;
        //We move the node and "cut" the linked list to add the middle value
        _Next=_Move->Next;
        //Here we set the new middle value to the linked list
        _Move->Next=_Values;
        //Here we attach the part that we "cut" before on the linked list
        _Values->Next=_Next;
        //Here we just aim to the mid value
        self->Middle->Value=x;
    }
}
//This function pops the Front element of the linked list, and the next of that one was popped, is the new head
Function LinkedList_PopFront(LinkedList *self){
    self->Empty=LinkedList_Empty;
    self->Empty(self);
    if(self->_Empty==1 && self->FE>0){
        struct Node* _tmp;
        _tmp=(struct Node*)malloc(sizeof(struct Node));
        _tmp=self->Head;
        //Here we move the next front element, to the front node, and will be the new head
        //If we have the list 5 4 3 2 1, and we make a pop, we are going to delete the 5 on the list
        //So the list will be like this 4 3 2 1, and 4 is the new head
        self->Head=self->Head->Next;
        //Using free function to free the memory space, 'cause if we do not do this, the value will be lost on the memory, using resources
        free(_tmp);
        //Decreasing the size and FE count, 'cause when we Pop an element of the linked list, we said that is deleted from.
        self->_size--;
        self->FE--;
    }
}
//Adding a new head, first is checked if the linked list is empty, if is not empty, we move the last head, to the next node of the new head
Function LinkedList_AddFront(LinkedList *self,int x){
    self->Empty=LinkedList_Empty;
    self->SetMiddle=LinkedList_SetMiddle;
    struct Node* _tmp;
    _tmp=(struct Node*)malloc(sizeof(struct Node));
    _tmp->Value=x;
    self->Empty(self);
    //Checking if is empty with a 0, and 1 if is not empty
    if(self->_Empty==1){
        //Creating a tmp node that we call Move, to travel around the linked list
        struct Node* _Move=self->Head;
        //Here we set the new head that is called tmp
        self->Head=_tmp;
        //Here we reallocate the old head, to the next of the new head
        //We said that if we have the next list: 4 3 2 1, and the head is 4; now we add a 5 as the new head
        //Now the new head will be 5, and the next of the new head will be 4, and now we have this list 5 4 3 2 1
        self->Head->Next=_Move;
        //Here we use NULL instead of free, 'cause Move is aiming to the head, and if we use free, we are going to free the memory of head
        _Move=NULL;
    }else{
        //If the list is empty, we just set the values, head and back
        self->Head=_tmp;
        self->Back=self->Head;
    }
    //Increasing the size and FE count, 'cause we add new values to the linked list
    self->_size++;
    self->FE++;
}
//Same function, but in this case we pop the back elements of the linked list
Function LinkedList_PopBack(LinkedList *self){
    self->Empty=LinkedList_Empty;
    if(self->_Empty==1 && self->BE>0){
        struct Node* _tmp;
        _tmp=(struct Node*)malloc(sizeof(struct Node));
        _tmp=self->Back;
        self->Back=self->Back->Next;
        free(_tmp);
        self->_size--;
        self->BE--;
    }
}
//Same function to add values, but in this case at the back of the linked list
Function LinkedList_AddBack(LinkedList *self,int x){
    self->Empty=LinkedList_Empty;
    self->SetMiddle=LinkedList_SetMiddle;
    struct Node* _tmp;
    _tmp=(struct Node*)malloc(sizeof(struct Node));
    _tmp->Value=x;
    self->Empty(self);
    if(self->_Empty==1){
        struct Node* _Move=self->Back;
        self->Back=_tmp;
        self->Back->Next=_Move;
        _Move=NULL;
    }else{
        self->Head=_tmp;
        self->Back=self->Head;
    }
    self->_size++;
    self->BE++;
}