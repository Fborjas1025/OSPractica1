#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

int f;

	// FIFO file path
	char * myfifo = "/tmp/myfifo";
	char * texto = "texto.txt"; 
	FILE *file = fopen(texto, "w+r");
	FILE *res = fopen("result.txt", "r");

char arr2[80];
int a,b,c;
int e ;   
int num ;

	char let[10];
	int travel;

	printf("Bienvenido\n\n1.\tIngresar origen\n2.\tIngresar destino\n3.\tIngresar hora\n4.\tBuscar tiempo de viaje medio\n5.\tSalir\n");

	while(e!=2){
		scanf("%i",&num);
	switch(num){
		case 1:
			printf("1. ingrese el id de origen: \n");
			scanf("%d",&a);
			fprintf(file,"%d \n ",a);
		break;
		case 2:
			printf("2. ingrese el id de destino: \n");
         		scanf("%d",&b);
			fprintf(file,"%d\n",b);
		break;
		case 3:
			printf("3. ingrese la hora: \n");
			scanf("%d",&c);
			fprintf(file,"%d \n", c);
			fclose(file);

		break;
		case 4:	
			fgets(let,sizeof(let), res);
			travel = atoi(let);

       			printf("Tiempo de viaje medio: %d \n",travel);
		break;
		case 5:
			e= 2;
		break;
	}
 	}
return 0;
}
