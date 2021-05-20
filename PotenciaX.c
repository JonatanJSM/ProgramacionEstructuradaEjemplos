//
// Programa: Potencia
// Objetivo: Calcular la potencia de un numero
// Programó: Jonatan Jafet Santana May
// Fecha: 7 de mayo de 2021
//

#include <stdio.h>
#include <math.h>

float potencia(float x, float n);

int main(int argc, char *argv[]) {
	float yy, xx, nn;
	int ct;
	char c;
	ct = 1;
	
	while(ct){
		
		printf("Valor ");
		scanf("%f", &xx);
		printf("Potencia ");
		scanf("%f", &nn);
		
		yy = potencia(xx, nn);
		printf("%8.2f a la %8.2f = %8.2f \n", xx, nn, yy);
		
		getchar(); //Para que no se peguen
		printf("\n\n Continuar <s/n> ");
		c= getchar();
		if (c=='n')ct=0;
		
	}
	
	return 0;
}

float potencia(float x, float n){
	
	float y;
	y = exp(n*log(x));   //base e   //Logaritmo natural 
	//exp es e^(n*log)
	
	return y;
}
