#include <stdio.h>
void sortSelec(int datos[], int n);
void busqueBina(int datos[],int n);

int main(void) {
	int valores[50];
	int i, ne;
	
	//lee arreglo
	printf("Lee un conjunto de valores enteros \n");
	printf("Ordena por el Sort Seleccion \n");
	
	printf("\nNumero de elementos : ");
	scanf("%d",&ne);
	for (i=1; i<=ne; i++){
		printf("Teclea el valor (%d): ", i);    // Diferencia de d y la i
		scanf("%d", &valores[i]);
	}
	
	sortSelec(valores,ne);
	busqueBina(valores, ne);

	
}


//Sort de selección
void sortSelec(int datos[],int n){   //Diferencia de void con el otro
	size_t i,j;
	int menor;
	int elem;
	
	for(i=1; i<=n-1; i++){
		menor = i;
		for(j=i+1;j<=n; j++){
			if(datos[j]<datos[menor])
				menor = j;
		}
		//Svap - intercambio elementos
		elem = datos[i];
		datos[i]= datos[menor];
		datos[menor]=elem;
	}
	
	printf("\n \n Arreglo ordenado \n");
	for(i=1;i<=n; i++)
		printf("\tElemento %d: (%d) \n",i,datos[i]);
}
	

void busqueBina(int datos[],int n){   //Si lo mencionamos aquí es neceario definilo?
	int linf, lsup,valor,pos,med,enc;
		
	printf("\nBusqueda binaria");
	printf("\nValor a buscar : ? ");
	scanf("%i",&valor);
	
	
	linf=1;
	lsup = n;
	enc=0;
	
	while(linf<=lsup && !enc){
		med = (linf + lsup)/2;
		
		if(valor == datos[med]){
			enc = 1;
			pos = med;
		}
		else
			if(valor<datos[med])
			lsup = med-1;
			else
				linf = med+1;
	}
	
	if (enc)
		printf("El valor de %i se encontró en la posicion %i \n", valor, pos);
	else
		printf("El valor %i no se encontró",valor);
}
