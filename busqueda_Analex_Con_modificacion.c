#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 120
#define FINCAD '\0'

int Espre(char datos[][30],char tok[]);

int main(int argc, char *argv[]) {
	char linea[MAX], token[32];
	char Presv[11][30] = {" ","si", "entonces", "sino", "mientras", "repite","ciclo","entero","real","cadena","caracter"};
	int i, j,enc;
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
			
			printf("\n");
			enc=Espre(Presv,token);		
			if (enc){
				printf("El valor es %i   ",enc);
				printf("%s\n", Presv[enc]);
			}
			else{
				printf("El valor no se encontró\n\n");
			}
			
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
	
	Espre(Presv,token);
	return 0;
}
int Espre(char datos[][30],char tok[]){
	int i, pos,encontra;
	encontra=0;
	pos=0;
	i=1;
	while(i<=10 && !encontra){
		if(strcmp(tok,datos[i]) == 0){
			encontra = 1; 
			pos = i; 
		}
		i++;
	}
	
	return pos;
}


