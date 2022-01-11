#include<stdlib.h>
#include<stdio.h>
typedef struct Pila Pila,*Funcion;
typedef struct Nodo Nodo;
struct Nodo{
    Nodo* lazo,*cuerda;
};
struct Pila{
    Nodo* gruta, *tunel;
    int longitud;
    Funcion (*construir)(Pila*);
};
Funcion construir(Pila* cola){
    //Aqui se construlle el tunel
    cola->tunel=cola->gruta=(Nodo*)malloc(sizeof(Nodo));
    cola->longitud=0;
}
Funcion insertar(Pila* ex1,Pila* ex2){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(ex1->longitud>0 && ex2->longitud>0){
        Nodo* m1= ex1->tunel;
        Nodo* m2 = ex2->tunel;
        int i=0;
        //cuerda es siguiente y lazo anterior
        for(i=0;i<ex1->longitud-1;i++,m1=m1->cuerda);
        for(i=0;i<ex2->longitud-1;i++,m2=m2->cuerda);
        m1=nuevo;
    }else{
        //Decimos que tunel es la cabeza y gruta es el final
        ex1->tunel=nuevo;
        ex1->gruta= ex1->tunel;
        nuevo=(Nodo*)malloc(sizeof(Nodo));
        ex2->tunel=nuevo;
        ex2->gruta= ex2->tunel;
    }
}
int main(){

}