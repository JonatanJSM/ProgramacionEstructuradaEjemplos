#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorio(int liinf, int linsup);
void proceso(int m);

int main() {
	int lin,lip;
	int numa;
	lin = 10;  lip = 60;
	
	numa = aleatorio(lin, lip);
	printf("Numero %d:",numa);
	printf("\n\n");
	
	proceso(numa);
	
	
	return 0; //Preguntar si esto se quita
}


int aleatorio(int liinf, int linsup){   //Generar el numero aleatorio
	int x;
	srand(time(NULL));
	x = rand() % (linsup-liinf + 1) + liinf; 
	//x = rand()%11;  // 0 a 10   //(N-M+1)+M   Entre M y N   n>m
	return x;
}
	
void proceso(int m){   //Proceso para adivinar 
	int y,enc,i;
	
	printf("EL numero para adivinar ya se genero\n");
	
	
	enc = 0;
	i=1;
	
	while(!enc){
		
		printf("Comienza a adivinar: ");
		scanf("%d",&y);
		
	if(y==m){
		printf("Felicidades has adivinado el numero\n");
		enc = 1;
		printf("Lo intentaste %d veces",i);
	}
		else{
		if(y<m){
			printf("El numero es mayor\n");
		}
		else{
			printf("El numero es menor\n");
		}
	}
	i++;
	}
	
	return;
}

