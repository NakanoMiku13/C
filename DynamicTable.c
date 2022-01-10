//Code by NakanoMiku13
//Find more interesting codes in https://github.com/NakanoMiku13
//DynamicTable
#include<stdio.h>
#include <stdlib.h>
//Defining the main structs
typedef struct Table Table,*Function;
//Creating the Main Node Structure, that contains a pointer aiming to the next, previous, top and bottom node of the table
struct Node{
    int Value;
    struct Node *Next,*Prev,*Top,*Bottom;
};
//Table structure, it contains a unique node that is the Head, then we have 4 variables 
//_size, _cols and _rows are variables to the size of the table, in this case _size is just the quantity of values on the table
//_ccols and _crows are variables that allow us to now where we are on the table without indexing values
struct Table{
    struct Node *Head;
    size_t _size,_cols,_rows,_ccols,_crows;
    //Main functions for the table structure
    Function (*Ctr)(Table *);
    Function (*Add)(Table *,int);
    Function (*Print)(Table *);
};
//Function prototypes
Function Table_Ctr(Table *),Table_Add(Table *,int),Table_Print(Table *);
//Main function
int main(){
    //Creating table
    struct Table table;
    //Initializing the table functions
    table.Ctr=Table_Ctr;
    table.Add=Table_Add;
    table.Print=Table_Print;
    //Reserving memory for the nodes
    table.Ctr(&table);
    int x,y,i,j;
    //Inserting the data to the table
    printf("Rows and Cols\n");
    scanf("%d %d",&y,&x);
    table._cols=x;
    table._rows=y;
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            int d;
            scanf("%d",&d);
            table.Add(&table,d);
        }
    }
    //Printing the table
    table.Print(&table);
}
//Function to initialize the variables of the table structure
Function Table_Ctr(Table *Self){
    Self->Head=(struct Node*)malloc(sizeof(struct Node));
    Self->_size=Self->_cols=Self->_rows=Self->_ccols=Self->_crows=0;
}
//Function to add values to the table
Function Table_Add(Table *Self,int value) {
    //Creating a temporary node to manage the data that will be inserted into the table.
    struct Node* tmp;
    //Reserving memory
    tmp=(struct Node*)malloc(sizeof(struct Node));
    //Giving the value received to the temporary node
    tmp->Value=value;
    //Checking if the table is empty or not
    if(Self->_size>0){
        //Checking if the value that we are going to insert will be on the first row of the table
        //If this is the first row we make the first if process
        if(Self->_ccols<Self->_cols && Self->_crows==0){
            //Aiming to the Head, creating a movement node
            struct Node* _Move=Self->Head;
            int i=0;
            //Travelling on the first row of the table, while we get to the end -1, so if we have 1 2 3 and the new value is 4
            //Instead of set the pointer on a null position, we set the pointer in the number 3
            while(i<Self->_ccols-1){
                _Move=_Move->Next;
                i++;
            }
            //Here we said this, "Number 4 (the new number), your previous node is 3; and number 3, your next node is 4"
            tmp->Prev=_Move;
            _Move->Next=tmp;
            //Increasing the columns count to manage the positions
            Self->_ccols++;
        //In this if, is a little bit same as the last if, but in this case we are working if the table have more than 1 column
        }else if(Self->_ccols<Self->_cols){
            //Creating 2 nodes, the first MoveUp is to travel up a position of the new node; and Move is the pointer that will travel around the table to find the new position to the new node
            struct Node *_MoveUp=Self->Head;
            struct Node *_Move=Self->Head;
            int i=0;
            //This is just a validation if we have more than 1 row, 'cause the process will change
            if(Self->_rows>0){
                //Travelling around the table rows, eg: we have the next table
                //   1 2 3
                //   4 5 6
                //   7 8 9
                //The number 9 will be the new node that we will insert on the table
                //But to find the top node we have to travel to the row 3-1, in this case we are on the row 
                //   4 5 6
                //And we set MoveUp in this row
                while(i<Self->_crows-1){
                    _MoveUp=_MoveUp->Bottom;
                    i++;
                }
                i=0;
            }
            //Here we travel around the columns of the table, in this case
            //we are going to travel in the row 4 5 6, that we set before, and we are going to travel to the
            //Top value of the new node, so in this case that will be the number 6
            while(i<Self->_ccols){
                _MoveUp=_MoveUp->Next;
                i++;
            }
            //Now we repeat the proces to the Move Node, to travel to N row, so in this case, instead of the last
            //process that we travel to the n-1 row, we travel to the n row
            // 1 2 3
            // 4 5 6
            // 7 8 9
            //Now we move to the row 7 8 9, remember that 9 is the node that we will inster 
            i=0;
            while(i<Self->_crows){
                _Move=_Move->Bottom;
                i++;
            }
            i=0;
            //And now we travel on the table columns
            // 1 2 3
            // 4 5 6
            // 7 8 9
            //So we said that we set to the n-1 column, so we said that we are going to set on the number 8
            while(i<Self->_ccols-1){
                _Move=_Move->Next;
                i++;
            }
            //And here we repeat the same process as the previous if, we said
            //New node (9), your top node will be 6, and Node 6, your bottom node will be 9
            //New Node (9), your previous node will be 8, and 8 your next node will be 9
            tmp->Top=_MoveUp;
            _MoveUp->Bottom=tmp;
            tmp->Prev=_Move;
            _Move->Next=tmp;
            Self->_ccols++;
        //This if is for check if we are on the first row of the table
        }else if(Self->_crows<Self->_rows && Self->_ccols==Self->_cols && Self->_crows==0){
            //Creating a movement node
            struct Node* _Move=Self->Head;
            //And here we just add a new Row, using a new example
            // 1 2 3
            // 4 * *
            // * empty nodes 
            //Where the second row is the new row
            //And we add just the number 4, and we said, Number 4, your Top node is 1, and 1 your bottom node is 4
            tmp->Top=Self->Head;
            _Move->Bottom=tmp;
            _Move=_Move->Bottom;
            Self->_ccols=0;
            Self->_crows++;
            Self->_ccols++;
        //This if is used to add a new row to the table
        }else if(Self->_crows<Self->_rows && Self->_ccols==Self->_cols){
            //Creating a new movement node
            struct Node* _Move=Self->Head;
            int i=0;
            //Travelling on the table rows
            while(i<Self->_crows){
                _Move=_Move->Bottom;
                i++;
            }
            //We repeat the same process as the last if process
            tmp->Top=_Move;
            _Move->Bottom=tmp;
            Self->_ccols=1;
            Self->_crows++;
        }
    }else{
        //This is when the new value is the first on the table, and we set it as the head of the table
        Self->Head=tmp;
        Self->_ccols++;
    }
    //Increasing the size number table
    Self->_size++;
}
//Function to print the table
Function Table_Print(Table *Self){
    struct Node* _Move=Self->Head;
    struct Node* _Row=Self->Head;
    int i=0,j=0,k=0,l=0;
    while(i<Self->_rows){
        j=0;
        l=0;
        while(l<Self->_cols){
            printf("%d ",_Move->Value);
            _Move=_Move->Next;
            l++;
        }
        _Row=_Row->Bottom;
        _Move=_Row;
        printf("\n");
        i++;
    }
    /*_Move=_Row=Self->Head;
    i=0,j=0,k=0,l=0;
    while(i<Self->_rows){
        j=0;
        l=0;
        while(l<Self->_cols){
            if(_Move->Top!=NULL)
            printf("The value: %d; is linked with: %d, %d and %d",_Move->Value,_Move->Top->Value!=NULL,0,0);
            _Move=_Move->Next;
            l++;
        }
        _Row=_Row->Bottom;
        _Move=_Row;
        printf("\n");
        i++;
    }*/
}