//Code by NakanoMiku13
//Check more codes on http://github.com/NakanoMiku13/
//Cube 2.0
#include<graphics.h>
#include<conio.h>
int Array[5][5][5];
int gmode,gdriver=DETECT;
void InitGraphMode(),CloseGraph(),PrintError(),PrintFace(),PrintFaceBackFront(int,int), PrintColFrontBack(int,int,int),PrintRowFrontBack(int,int,int), PrintRowFrontBack(int Result,int x,int y),PrintFaceLeftRight(int Result,int z),PrintRowLeftRight(int Result, int y,int z), PrintColLeftRight(int Result,int x,int z), PrintFaceTopBottom(int Result,int y),PrintRowTopBottom(int Result,int x,int y), PrintColTopBottom(int Result,int y,int z),Fill(),SumMenu(),Menu();
int SumTopBottomCol(int x,int y), SumTopBottomRow(int y, int z), SumColLeftRightFrontBack(int x,int z), SumRowLeftRight(int y, int z), SumRowFrontBack(int x,int y), FaceFront(),FaceBack(),FaceRight(),FaceTop(),FaceLeft(),FaceBottom(),SumFaceMenu();
//Main Function
int main(){
    Menu();
}
void InitGraphMode(){
    initgraph(&gdriver,&gmode,"");
}
void CloseGraph(){
    getch();
    closegraph();
}
void PrintError(){
    InitGraphMode();
    setcolor(RED);
    outtextxy(300,300,"Error... try again.");
    CloseGraph();
}
void PrintFace(){
    for(int i=0,top=10,bottom=60;i<5;i++,top+=60,bottom+=60){
        for(int j=0,right=60,left=10;j<5;j++,right+=60,left+=60){
            rectangle(left,top,right,bottom);
        }
    }
}
void PrintFaceBackFront(int Result,int x){
    InitGraphMode();
    PrintFace();
    char Number[5];
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+x)+i)+(4-k));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            setcolor(GREEN);
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
void PrintColFrontBack(int Result,int x,int z){
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    for(int i=0,j=0;i<5;i++,j++){
        *(number+j)=*(*(*(Array+x)+i)+z);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+x)+i)+k);
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    setcolor(WHITE);
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
void PrintRowFrontBack(int Result,int x,int y){
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i)=*(*(*(Array+x)+y)+i);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+x)+i)+(5-k));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    setcolor(WHITE);
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
void PrintFaceLeftRight(int Result,int z){
    InitGraphMode();
    PrintFace();
    char Number[5];
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+i)+k)+z);
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
void PrintRowLeftRight(int Result, int y,int z){
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i)=*(*(*(Array+i)+y)+z);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+i)+k)+z);
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    setcolor(WHITE);
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
void PrintColLeftRight(int Result,int x,int z){
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i)=*(*(*(Array+x)+i)+z);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+x)+i)+k);
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    setcolor(WHITE);
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
void PrintFaceTopBottom(int Result,int y){
    InitGraphMode();
    PrintFace();
    char Number[5];
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+(5-i)+y)+(5-k)));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
void PrintRowTopBottom(int Result,int x,int y){
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i) =*(*(*(Array+x)+y)+(5-i));
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+(4-i)+y)+(5-k)));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
void PrintColTopBottom(int Result,int y,int z){
    InitGraphMode();
    PrintFace();
    char Number[5];
    int* number;
    number=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<5;i++){
        *(number+i) =*(*(*(Array+(5-i))+y)+z);
    }
    for(int i=0,y1=32;i<5;i++,y1+=60){
        int tmp;
        for(int k=0,x1=-32;k<5;k++){
            tmp= (int)*(*(*(Array+(5-i)+y)+(5-k)));
            sprintf(Number,"%d",tmp);
            if(tmp>9 and tmp<100){
                x1+=59;
            }else if(tmp>99){
                x1+=58;
            }else{
                x1+=60;
            }
            if(tmp==*(number+k)){
                setcolor(GREEN);
            }else{
                setcolor(WHITE);
            }
            outtextxy(x1,y1,Number);
        }
    }
    char Text[1000];
    sprintf(Text,"The result of the addition is: %d\nPress any key to continue...\n",Result);
    outtextxy(10,350,Text);
    CloseGraph();
}
//This function fills all the array with random numbers between 0 and 10k
void Fill(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                Array[i][j][k]=rand()%100;
            }
        }
    }
}
//This function make the addition in the top and bottom columns of the cube, you have to give the x and y position of the column
//to make the correct addition.
int SumTopBottomCol(int x,int y){
    int Sum=0;
    for(int i=0;i<5;i++){
        //In this case we only have to travel in the Z coordinate just for add the top or bottom values
        //This is equal to Sum+=Array[x][y][5-i]
        Sum+=*(*(*(Array+x)+y)+(5-i));
    }
    return Sum;
}
//This function make the addition in the top and bottom columns of the cube, the same process like the last function.
int SumTopBottomRow(int y, int z){
    int Sum=0;
    for(int i=0;i<5;i++){
        //Here we just have to travel in the X coordinate of the cube to make the addition of the rows
        Sum+=*(*(*(Array+i)+y)+z);
    }
    return Sum;
}
//Function to add the the left or right columns of the cube
int SumColLeftRightFrontBack(int x,int z){
    int Sum=0;
    for(int i=0;i<5;i++){
        //You only have to travel in the Y coordinate of the cube to get the result
        Sum+=*(*(*(Array+x)+i)+z);
    }
    return Sum;
}
//Function to add the left or right rows of the cube
int SumRowLeftRight(int y, int z){
    int Sum=0;
    for(int i=0;i<5;i++){
        //You only have to travel in the Z coordinate
        Sum+=*(*(*(Array+i)+y)+z);
    }
    return Sum;
}
//Function that make the addition othe rows from the front or back of the cube
int SumRowFrontBack(int x,int y){
    int Sum = 0;
    for(int i=0;i<5;i++){
        Sum+=*(*(*(Array+x)+y)+i);
    }
    return Sum;
}
//This function make the add of the front face of the cube
int FaceFront(){
    int Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //You only have to travel as a simple matrix
            Sum+=Array[i][j][0];
            Sum+=*(*(*(Array+i)+j)+0);
        }
    }
    return Sum;
}
//This function make the add of the Right face of the cube
int FaceRight(){
    int Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //You have to set the cursor on the last X position, and then you travel like another matrix
            Sum+=*(*(*(Array+5)+i)+j);
        }
    }
    return Sum;
}
//Function to add the Left Face values
int FaceLeft(){
    int Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //You have to travel from the initial X position to the Z last position
            Sum+=*(*(*(Array+0)+i)+(5-j));
        }
    }
    return Sum;
}
//Function that add the back face values
int FaceBack(){
    int Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                //Is the opposite of the front face code
                Sum+=*(*(*(Array+(5-i))+j)+(5-k));
            }
        }
    }
    return Sum;
}
//Function that add the top values of the cube
int FaceTop(){
    int Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //You only have to travel in the top, you must not have to move in the Y coordinate
            Sum+=*(*(*(Array+i)+0)+j);
        }
    }
    return Sum;
}
//Function that add the bottom values of the cube
int FaceBottom(){
    int Sum=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //The same as the last function, but in this case, you are in the last position of Y coordinate.
            Sum+=*(*(*(Array+i)+5)+j);
        }
    }
    return Sum;
}
//Main menu to attach all the Face Addition to make it more accessible, you only have to give the number of the face
int SumFaceMenu(int face){
    switch(face){
        case 1:
            return FaceFront();
            break;
        case 2:
            return FaceRight();
            break;
        case 3:
            return FaceLeft();
            break;
        case 4:
            return FaceBack();
            break;
        case 5:
            return FaceTop();
            break;
        case 6:
            return FaceBottom();
            break;
        default:
            PrintError();
            break;
    }
}
//Main menu where you make all the decitions of the program, if you want to add the top face, or just a col or row, here you choose.
void SumMenu(int face){
    int option,x,y,z;
    switch(face) {
        case 1:
            printf("Front Face:\n1) Col Sum\n2) Row sum\n3) Face sum\n"); 
            scanf("%d",&option);
            switch(option){
                case 1:
                    printf("Type the X col position and Z col position:\n"); 
                    scanf("%d %d",&x,&z); 
                    PrintColFrontBack(SumColLeftRightFrontBack(x,z),x,z); 
                    break;
                case 2:
                    printf("Type the X row position and Y row position:\n"); 
                    scanf("%d %d",&x,&y); 
                    PrintRowFrontBack(SumRowFrontBack(x,y),x,y); 
                    break;
                case 3:
                    printf("Type the front face number that you want to see:\n"); 
                    scanf("%d",&x);
                    PrintFaceBackFront(SumFaceMenu(1),x); 
                    break;
                default: 
                    PrintError(); 
                    break;
            } 
        break;
        case 2:
            printf("Right Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"); 
            scanf("%d",&option);
            switch(option){
                case 1:
                    printf("Type the X col position and Z col position:\n"); 
                    scanf("%d %d",&x,&z); 
                    PrintColLeftRight(SumColLeftRightFrontBack(x,z),x,z); 
                    break;
                case 2:
                    printf("Type the Y row position and Z row position:\n"); 
                    scanf("%d %d",&y,&z); 
                    PrintRowLeftRight(SumRowLeftRight(y,z),y,z); 
                    break;
                case 3:
                    printf("Type the Right face number that you want to see:\n"); 
                    scanf("%d",&z);
                    PrintFaceLeftRight(SumFaceMenu(2),z); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        case 3:
            printf("Left Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"); 
            scanf("%d",&option);
            switch(option){
                case 1:
                    printf("Type the X col position and Z col position:\n"); 
                    scanf("%d %d",&x,&z); 
                    PrintColLeftRight(SumColLeftRightFrontBack(x,z),x,z); 
                    break;
                case 2:
                    printf("Type the Y row position and Z row position:\n"); 
                    scanf("%d %d",&y,&z); 
                    PrintRowLeftRight(SumRowLeftRight(y,z),y,z); 
                    break;
                case 3:
                    printf("Type the Left face number that you want to see:\n"); 
                    scanf("%d",&z);
                    PrintFaceLeftRight(SumFaceMenu(2),z); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        case 4:
            printf("Top Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"); 
            scanf("%d",&option);
            switch(option){
                case 1:
                    printf("Type the X col position and Y col position:\n"); 
                    scanf("%d %d",&x,&y);
                    PrintColTopBottom(SumTopBottomCol(x,y),x,y); 
                    break;
                case 2:
                    printf("Type the Y row position and Z row position:\n"); 
                    scanf("%d %d",&y,&z);
                    PrintRowTopBottom(SumTopBottomRow(y,z),y,z); 
                    break;
                case 3:
                    printf("Type the Top face number that you want to see:\n"); 
                    scanf("%d",&y);
                    PrintFaceTopBottom(SumFaceMenu(4),y); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        case 5:
            printf("Bottom Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"); 
            scanf("%d",&option);
            switch(option){
                case 1:
                    printf("Type the X col position and Y col position:\n"); 
                    scanf("%d %d",&x,&y);
                    PrintColTopBottom(SumTopBottomCol(x,y),x,y); 
                    break;
                case 2:
                    printf("Type the Y row position and Z row position:\n"); 
                    scanf("%d %d",&y,&z);
                    PrintRowTopBottom(SumTopBottomRow(y,z),y,z); 
                    break;
                case 3:
                    printf("Type the Bottom face number that you want to see:\n"); 
                    scanf("%d",&y);
                    PrintFaceTopBottom(SumFaceMenu(4),y); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        case 6:
            printf("Back Face:\n1) Col Sum\n2) Row sum\n3 Face sum\n"); 
            scanf("%d",&option); 
            switch(option){
                case 1:
                    printf("Type the X col position and Z col position:\n"); 
                    scanf("%d %d",&x,&z); 
                    PrintColFrontBack(SumColLeftRightFrontBack(x,z),x,z); 
                    break;
                case 2:
                    printf("Type the X row position and Y row position:\n"); 
                    scanf("%d %d",&x,&y); 
                    PrintRowFrontBack(SumRowFrontBack(x,y),x,y); 
                    break;
                case 3:
                    printf("Type the back face number that you want to see:\n"); 
                    scanf("%d",&x);
                    PrintFaceBackFront(SumFaceMenu(1),x); 
                    break;
                default: 
                    PrintError(); 
                    break;
            }
        break;
        default: PrintError(); 
        break;
    }
}
//Single function that invokes the menu and print the result, if the resul is equal to -1 that is an error, you have to choose again.
void Menu(){
    Fill();
    int x,result;
    printf("1) Front Face\n2) Right face\n3)Left face\n4)Top face\n5)Bottom face\n6) Back face\n");
    scanf("%d",&x);
    SumMenu(x);
}