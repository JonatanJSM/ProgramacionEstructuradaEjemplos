// 
// Análisis de datos de investigación con arreglos:
// cálculo de la media, mediana y moda del conjunto de datos

//Unsigned para manejar numeros positivos
#include <stdio.h>
#include <math.h>
#define SIZE 99
//size_t   tipo entero sin signo

// prototipos de funciones 
float media(const unsigned int answer[] );
void mediana(unsigned int answer[] );
void moda(unsigned int freq[], unsigned const int answer[] ) ;
void burbujaSort(unsigned int a[] );
void imprimeArray(unsigned const int a[] );
float varianza(float media);


// function main begins program execution
int main (void) {
	unsigned int frequency[ 10 ] = { 0 }; // inicia arreglo de frecuencias
	float vvar, vmedia;
	
	// inicia arreglo response
	unsigned int response[SIZE] =
		{ 6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
		7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
		6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
		7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
		6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
		7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
		5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
		7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
		7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
		4, 5, 6, 1, 6, 5, 7, 8, 7 }; 
	
	// cáculos sobre arreglo response
	vmedia = media(response);
	media(response);
	mediana(response);
	moda(frequency, response);
	vvar = varianza(vmedia);
	printf("La varizan es %8.2f \n",vvar);
	printf("La desviacionestandar es %8.2f", sqrt(vvar));
} // fin main


// calcula promedio de todos los valores de response 
float media( const unsigned int answer[] ) {
	size_t j; // countador de los elementos del arreglo
	unsigned int total = 0; // total de la suma de los elementos del arreglo
	float med;
	printf( "%s\n%s\n%s\n", "********", " Media", "********" );
	// total de los valores de response 
	for ( j = 0; j < SIZE; ++j ) {
		total += answer[ j ];
	} // fin for

	printf( "La media es el valor promedio de los datos. \n"
		   "La media es igual al total de todos los valores \n"
		   "entre el número de datos (%u). \n"
		   "La media para estos valores es: %u/%u = %.4f\n\n",
		   SIZE, total, SIZE, ( double ) total / SIZE );
	med=( double ) total / SIZE ;
	return med;
} // fin funcion media

// ordena el arreglo y determina el valor de la mediana
void mediana( unsigned int answer[] )	{
	printf( "\n%s\n%s\n%s\n%s",
		   "********", " Mediana", "********",
		   "Los valores del arreglo response son:" );
	
	imprimeArray(answer); // output unsorted array
	
	printf( "%s", "\n\nEl arreglo ordenado es:" );
	burbujaSort(answer);
	imprimeArray(answer); // output sorted array
	
	// display median element
	printf( "\n\nLa mediana es el elemento (%u)/(%u) del arreglo ordenado.\n"
		   "En este caso la mediana es %u\n\n",
		   SIZE/2, SIZE, answer[SIZE/2]);
} // fin funcion mediana

// determine most frequent response
void moda( unsigned int freq[], const unsigned int answer[] ) {
	size_t rating; // contador de acceso de los elementos de frecuencias
	size_t j; // cuenta acumulado de las respuestas del arreglo
	unsigned int h; // contador de elementos del histograma
	unsigned int largest = 0; // representa frecuencia mayor
	unsigned int modeValue = 0; // respuesta más frecuente
	
	printf( "\n%s\n%10s\n%s\n",
		   "****************", "Moda", "****************" );
	// initialize frequencies to 0
	for (rating = 1; rating <= 9; ++rating ) {
		freq[rating] = 0;
	} // end for
	
	// resumen frecuencias
	for ( j = 0; j < SIZE; ++j ) {
		++freq[answer[j]];
	} // fin for
	
	// Imprime encabezados de las columnas
	printf( "%s%11s%12s\n\n%28s\n%28s\n\n",
		   "Respuesta", "Frecuencia", "Histograma",
		   "1 1 2 2", "5 0 5 0 5" );
	// output results
	for (rating = 1; rating <= 9; ++rating ) {
		printf( "%8u%11u ", rating, freq[ rating ] );
		
		if (freq[rating]>largest) {
			largest = freq[rating];
			modeValue = rating;
		}
		
		// output histogram bar representing frequency value
		for ( h = 1; h <= freq[ rating ]; ++h ) {
			printf("%s", "*");
		} // 
		
		puts(""); // salto de linea
	} // fin for externo
	
	// despliega el valor de la moda
	printf( "\nLa moda es el valor más frecuente.\n"
		   "En este caso la moda es  %u y ocurrió"
		   " %u veces.\n", modeValue, largest );
} // fin funcion moda

// funcion que ordena un arreglo con burbuja sort
void burbujaSort(unsigned int a[]) {
	unsigned int pass; // contador de paso
	size_t j; // contador de comparación
	unsigned int hold;  
	
	// número de pasos
	for ( pass = 1; pass < SIZE; ++pass ) {
		// número de comparaciones por paso
		for ( j = 0; j < SIZE - pass; ++j ) {
			// intercambia elementos desordenados
			if ( a[j] > a[j+1] ) {
				hold = a[j];
				a[j] = a[j+1];
				a[j+1] = hold;
			} // 
		} // 
	} // 
} // fin funcion burbujaSort

// imprime el contenido del arreglo (20 valores por fila)
void imprimeArray( const unsigned int a[] ) {
	size_t j; // contador
	// 
	for (j=0; j < SIZE; ++j ) {
		if (j%20 == 0 ) { // inicia una linea nueva cada 20 valores
			puts( "" );
		} 
		printf( "%2u", a[j] );
	} 
} // fin funcion imprimeArray


float varianza(float media){
	int i, suma;
	float varza;
	suma = 0;
	for(i=0; i<9; i++)
		suma += ((i-media)*(i-media));
	varza = (float)suma/(float)SIZE;
	return varza;
}
