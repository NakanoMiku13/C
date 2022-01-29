#include<stdio.h>
int main(){
	char sombrilla,soleado,gripa,sed;
	//s = si
	//n = no
	printf("Llevamos sombrilla?\n");
	scanf("%c",&sombrilla);
	getchar();
	printf("Esta soleado?\n");
	scanf("%c",&soleado);
	getchar();
	printf("Tengo gripa?\n");
	scanf("%c",&gripa);
	getchar();
	printf("Tengo Sed?\n");
	scanf("%c",&sed);
	//s = si
	//n = no
	if( (soleado=='s') && (sed=='s') && (sombrilla=='s') ){
		printf("Vamos por un helado\n");
	}else if((soleado=='s') && (gripa == 'n')){
		printf("Vamos a la alberca\n");
	}else{
		if((soleado=='n')){
			printf("Quedate en casa\n");
		}else if((soleado=='s') && (gripa=='s')){
			printf("Quedate en casa que estas enfermo\n");
		}
	}
}
