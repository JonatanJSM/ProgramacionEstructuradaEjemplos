#include <stdio.h>
#include <ctype.h>
#define MAX 120
#define FINCAD '\0'
int Espre(char Presv[][30],char token[]);

int main(int argc, char *argv[]) {
	char linea[MAX], token[32];
	char Presv[11][30] = {" ","si", "entonces", "sino", "mientras", "repite","ciclo","entero","real","cadena","caracter"};
	int i, j,*ii;
	// strcmp(Presv[i],token)
	printf("Linea;");
	gets(linea);
	
	i=0; j=0;
	
	while(linea[i] != FINCAD){
		if (isalpha(linea[i])){
			token[j]=linea[i];
			j++; i++;
			while (isalpha(linea[i])|| isdigit(linea[i])){
				token[j]=linea[i];
				j++; i++;
			}
			token[j]=FINCAD;
			printf("Token : ");puts(token);
			j=0;
			
			// Es palabraReservada?
			
		}
		else
			if(isdigit(linea[i])){
				token[j] = linea[i];
				j++; i++;
				while(isdigit(linea[i])){
					token[j]=linea[i];
					j++;i++;
				}
				token[j]=FINCAD;
				printf("token : "); puts(token);
				j=0;
		}
			else
				if (linea[i]==' ')
					i++;
	}
	
	return 0;
}

