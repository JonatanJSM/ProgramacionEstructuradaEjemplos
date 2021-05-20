//
// Programa: suma con funcion
// Objetivo: Utilizar funciones para sumar
// Programó: Jonatan Jafet Santana May
// Fecha: 7 de mayo de 2021
//

#include <stdio.h>


float suma(float x, float y);
float multiplica(float x, float y);

int main(int argc, char *argv[]) {
	float a, b, c;
	
	printf("Suma dos valores reales \n\n");
	printf("Calor de a ? ");
	scanf("%f", &a);
	printf("Calor de b ? ");
	scanf("%f", &b);
	
	c = suma(a,b);
	
	//printf("La suma de %f y %f = %f\n",a,b,suma(a,b));
	printf("La suma de %8.2f y %8.2f = %8.2f\n", a, b, c);
	
	c = multiplica(a,b);
	
	//printf("La suma de %f y %f = %f\n",a,b,multiplica(a,b));
	printf("La multiplicacion de %8.2f y %8.2f = %8.2f\n", a, b, c);
	
	return 0;
}

float suma(float x, float y){
	float z;
	z = x + y;
	return z;  //En lugar de z podemos poner x+y;
}

float multiplica(float x, float y){
	float z;
	z = x * y;
	return z;  //En lugar de z podemos poner x+y;
	}
