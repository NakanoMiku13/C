#include<stdio.h>
int main(){
	int n=10;
	int arreglo[n];
	int matriz[n][n];
	int cubo[n][n][n];
	int CuartaDimension[n][n][n][n];
	int matrizEnCubo[n][n][n][n][n];
	
	int i,j,k,l,m,c=0;
	//For para arreglo simple
	for(i=0;i<n;i++,c++){
		arreglo[i]=c;
	}
	printf("Arreglo: %d\n",c);
	//For's para matriz 2D
	for(i=0,c=0;i<n;i++){
		for(j=0;j<n;j++,c++){
			matriz[i][j]=c;
		}
	}
	printf("Matriz: %d\n",c);
	//For's para matriz 3D (Cubo)
	for(i=0,c=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++,c++){
				cubo[i][j][k]=c;
			}
		}
	}
	printf("Cubo: %d\n",c);
	//For's para una cuarta Dimensión (khe loko jsjsj)
	for(i=0,c=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				for(l=0;l<n;l++,c++){
					CuartaDimension[i][j][k][l]=c;
				}
			}
		}
	}
	printf("4D: %d\n",c);
	//For's para una quinta dimension (Pero estás loco?!)
	for(i=0,c=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				for(l=0;l<n;l++){
					for(m=0;m<n;m++,c++){
						matrizEnCubo[i][j][k][l][m]=c;
					}
				}
			}
		}
	}
	printf("Matrices en un cubo: %d\n",c);
}
