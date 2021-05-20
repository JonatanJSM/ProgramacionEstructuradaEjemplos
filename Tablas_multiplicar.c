#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define NMAX 20

int gotoYX(int columna, int linea){
	COORD coord;
	coord.Y= columna;
	coord.X=linea;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	return 0;
}
	void DespEncabezado();
	
	void Encabezadotabla();

int main(int argc, char *argv[]) {
	int i,factor;
	
	DespEncabezado();
	gotoYX(5,30);  //(y,x)
	printf("Factor ? ");
	scanf("%i",&factor);
	Encabezadotabla();
	//getchar();
	for (i=1;i<=NMAX;i++){
		gotoYX(8+i,30);
		printf("%3i       x %6i       = %6i", i, factor, i*factor);
	} 
	
	return 0;
}

	
void DespEncabezado(){
	system("cls");
	gotoYX(0,30);
	printf("Universidad Autonoma De Yucatán");
	gotoYX(1,34);
	printf("Facultad de matematicas");
	gotoYX(2,35);
	printf("Tablas de multiplicar");
}
	

	void Encabezadotabla() {
		gotoYX(8,30); printf("====");
		gotoYX(8,46); printf("====");
		gotoYX(8,60), printf("====");
	}
