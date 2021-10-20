#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList LinkedList,*Function;
struct Node{
    int Edad,Boleta;
    float Promedio,Estatura,Peso;
    char *Nombre;
    struct Node *Siguiente,*Anterior;
};
struct LinkedList{
    struct Node *Primero,*Ultimo;
    size_t CantAlumnos;
    Function (*ctr)(LinkedList*),(*ImprimirLista)(LinkedList*),(*NuevoAlumno)(LinkedList*,int,int,float,float,float,char*),(*BuscarBoleta)(LinkedList*,int),(*EliminarAlumno)(LinkedList*,int);
};
Function ctr(LinkedList*),ImprimirLista(LinkedList*),NuevoAlumno(LinkedList*,int,int,float,float,float,char*),BuscarBoleta(LinkedList*,int),EliminarAlumno(LinkedList*,int);
int Input();
float Inpt();
char* Nombre();
int main(){
    LinkedList Alumnos;
    Alumnos.ctr=ctr;
    Alumnos.ImprimirLista=ImprimirLista;
    Alumnos.NuevoAlumno=NuevoAlumno;
    Alumnos.BuscarBoleta=BuscarBoleta;
    Alumnos.EliminarAlumno=EliminarAlumno;
    int n,i;
    printf("Cuantos alumnos va a registrar?\n");
    n=Input();
    for(i=0;i<n;i++){
        printf("Alumno %d\nEdad, Boleta, Promedio, Estatura, Peso y Nombre\n",i);
        getchar();
        Alumnos.NuevoAlumno(&Alumnos,Input(),Input(),Inpt(),Inpt(),Inpt(),Nombre());
        getchar();
    }
    i=0;
    do{
        printf("1) Ingresar Alumno nuevo\n2) Eliminar Alumno\n3) Buscar Alumno\n4) Imprimir Lista\n5) Salir\n");
        int x;
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("Alumno %d\nEdad, Boleta, Promedio, Estatura, Peso y Nombre\n",Alumnos.CantAlumnos);
                getchar();
                Alumnos.NuevoAlumno(&Alumnos,Input(),Input(),Inpt(),Inpt(),Inpt(),Nombre());
                getchar();
                break;
            case 2:
                printf("Ingresa la boleta del alumno\n");
                Alumnos.EliminarAlumno(&Alumnos,Input());
                break;
            case 3:
                printf("Ingresa la boleta del alumno\n");
                Alumnos.BuscarBoleta(&Alumnos,Input());
                break;
            case 4:
                Alumnos.ImprimirLista(&Alumnos);
                break;
            default:
                printf("Gracias\n");
                break;
        }
    }while(i<5);
    printf("La lista final, es la siguiente:\n");
    Alumnos.ImprimirLista(&Alumnos);
}
int Input(){
    int x;
    scanf("%d",&x);
    return x;
}
float Inpt(){
    float x;
    scanf("%f",&x);
    return x;
}
char* Nombre(){
    char* nm=(char*)malloc(sizeof(char)*75);
    getchar();
    scanf("%[^\n]",nm);
	getchar();
    return nm;
}
Function ctr(LinkedList* list){
    list->Primero=(struct Node*)malloc(sizeof(struct Node));
    list->CantAlumnos=0;
}
Function ImprimirLista(LinkedList* list){
    int i;
    struct Node* tmp = list->Primero;
    for(i=0;i<list->CantAlumnos;i++,tmp=tmp->Siguiente){
        printf("Alumno: %s   Boleta: %d\nEdad: %d, Peso: %f, Estatura: %f\nPromedio general: %f\n",tmp->Nombre,tmp->Boleta,tmp->Edad,tmp->Peso,tmp->Estatura,tmp->Promedio);
    }
}
Function NuevoAlumno(LinkedList* list,int Boleta,int Edad,float Promedio,float Estatura,float Peso,char* Nombre){
    struct Node* Nuevo=(struct Node*)malloc(sizeof(struct Node));
    Nuevo->Nombre=Nombre;
    Nuevo->Edad=Edad;
    Nuevo->Promedio=Promedio;
    Nuevo->Estatura=Estatura;
    Nuevo->Boleta=Boleta;
    Nuevo->Peso=Peso;
    if(list->CantAlumnos>0){
        int i;
        struct Node* Alumno=list->Primero;
        for(i=0;i<list->CantAlumnos-1;i++,Alumno=Alumno->Siguiente);
        Nuevo->Anterior=Alumno;
        Alumno->Siguiente=Nuevo;
        list->Ultimo=Nuevo;
    }else{
        list->Primero=Nuevo;
    }
    list->CantAlumnos++;
}
Function BuscarBoleta(LinkedList* list,int Boleta){
    if(list->CantAlumnos>0){
        struct Node* Alumno=list->Primero;
        int i=0;
        for(;i<list->CantAlumnos;i++,Alumno=Alumno->Siguiente){
            if(Alumno->Boleta==Boleta){
                printf("Alumno: %s   Boleta: %d\nEdad: %d, Peso: %f, Estatura: %f\nPromedio general: %f\n",Alumno->Nombre,Alumno->Boleta,Alumno->Edad,Alumno->Peso,Alumno->Estatura,Alumno->Promedio);
                break;
            }
        }
    }else{
        printf("No hay alumnos registrados\n");
    }
}
Function EliminarAlumno(LinkedList* list,int Boleta){
    if(list->CantAlumnos>0){
        if(list->Ultimo->Boleta==Boleta){
            int i;
            struct Node* tmp= list->Primero;
            for(i=0;i<list->CantAlumnos-1;i++,tmp=tmp->Siguiente);
            list->Ultimo=tmp;
            list->CantAlumnos--;
            tmp=tmp->Siguiente;
            free(tmp);
        }else{
            struct Node *Alumno=list->Primero,*tmp=list->Primero;
            int i=0,j=0;
            for(;i<list->CantAlumnos;i++,Alumno=Alumno->Siguiente){
                if(Alumno->Boleta==Boleta){
                    break;
                }
            }
            for(;j<i-1;j++,tmp=tmp->Siguiente);
            printf("I: %d\n",i);
            tmp->Siguiente=Alumno->Siguiente;
            Alumno->Siguiente->Anterior=tmp;
            list->CantAlumnos--;
            free(Alumno);
        }
    }else{
        printf("No hay alumnos registrados\n");
    }
}