#include<stdio.h>
#include<stdlib.h>
void darDim(int*,int*),darDatos(int**,int,int),mostrarMtz(int**,int,int),Show(int*,int);
int* CalcSum(int,int,int**,int);
int** crearMatriz(int,int);
int main(){
	int n,m,**a,*sc,*sf;
	darDim(&n,&m);
	a=crearMatriz(n,m);
	darDatos(a,n,m);
	sf=CalcSum(n,m,a,0);
	sc=CalcSum(n,m,a,1);
	printf("\nLa suma de las columnas es:\n");
	Show(sf,n);
	printf("La suma de las filas es:\n");
	Show(sc,m);
}
int* CalcSum(int n,int m,int** a,int aux){
	int i,j;
	int* vr;
	if(aux==0){
                vr=(int*)malloc(sizeof(int)*(m+2));
                for(i=0;i<n;i++) for(j=0;j<m;j++) vr[j]+=a[i][j];
                return vr;
        }else{
                vr=(int*)malloc(sizeof(int)*(n+2));
                for(i=0;i<n;i++) for(j=0;j<m;j++) vr[i]+=a[i][j];
                return vr;
        }

}
void Show(int* a,int n){
        int i;
        for(i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
}
void darDim(int* fil,int* col){
	printf("Indique el numero de filas:\n");
	scanf("%d",fil);
	printf("Indique el numero de columnas:\n");
	scanf("%d",col);
}
int** crearMatriz(int fil,int col){
	int** mtz,i;
	mtz=(int**)malloc(fil*sizeof(int*));
	if(mtz==NULL){
		printf("No hay memoria disponible:\n");
		exit(0);
	}
	for(i=0;i<fil;i++) mtz[i]=(int*)malloc(sizeof(int)*col);
	return mtz;
}
void darDatos(int** mtz,int fil,int col){
	int i,j;
	printf("Ingrese los datos de la Matriz:\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			printf("Dato[%d][%d]=",i+1,j+1);
			scanf("%d",&mtz[i][j]);
		}
	}
}
