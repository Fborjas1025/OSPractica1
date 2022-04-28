
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct hash{
    int origen;
    int ref;
};

struct busqueda{
    int origen;
    int destino;
    int hora;
};

struct registro{
    int origen;
    int destino;
    int hora;
    int tiempo;
    int ref;
};

void print_(struct hash hash){
    printf(" origen = %d ref = %d  \n", hash.origen, hash.ref);
}

void print_person(struct registro reg){
    printf("origen = %d destino = %d hora = %d tiempo = %d referencia = %d \n", reg.origen, reg.destino, reg.hora, reg.tiempo, reg.ref);
}

int main(int argc, char const *argv[]){

FILE *review = fopen("archivoo.txt", "rb");
FILE *ph = fopen("archivo_hash.txt", "rb");
FILE *file = fopen("texto.txt","r");
FILE *res = fopen("result.txt", "w+");
    
// Create receive object
struct registro recibePersona;
   
// Verify if file is null
if (review == NULL)
{
	printf("\nError to open the file\n");
	exit(1);
}

char t1[20],t2[20],t3[20];
int p, o, i;
	
fgets(t1, sizeof(t1),file);
fgets(t2, sizeof(t1),file);
fgets(t3, sizeof(t1),file);

p = atoi(t1);
o = atoi(t2);
i = atoi(t3);

int origen = p;
int destino = o;
int hora = i;

printf("Origen:%d Destino: %d hora: %d\n",p, o,i);

int fd1;

while (1){
	
	int origen = p;
	int destino = o;
	int hora = i;


	int a = 0 ,b= 0,c = 0;
	char str2[80];

	int aux1;
	struct registro busqueda;

	//busqueda el origen  en el hash
    	fseek(ph, 8 * origen, SEEK_SET);
    	fseek(ph, 4, SEEK_CUR);
    	fread(&aux1, sizeof(int), 1, ph);//extrae la referencia

	//entra a la primera posicion proporcionada por el hash
	fseek(review, 20 * aux1, SEEK_SET);
	fread(&busqueda, sizeof(struct registro), 1, review);

	while (busqueda.destino != destino || busqueda.hora != hora){
		if (busqueda.ref==-1){
			printf("No se encontro\n");
			break;
        	}
	fseek(review, 20 * busqueda.ref, SEEK_SET);
	fread(&busqueda, sizeof(struct registro), 1, review);
	}
	
	printf("Orign:%i Destino: %i tiempo: %d\n",busqueda.origen,busqueda.destino,busqueda.tiempo);

 
	if( busqueda.destino == destino && busqueda.hora == hora){
        	fprintf(res,"%d",busqueda.tiempo);
		fclose(res);
	break;
	}else{
		strcpy(str2,"NA");
	}
}

fclose(review);
fclose(ph);

return 0;
}

