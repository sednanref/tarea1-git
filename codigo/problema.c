#include <stdio.h>
#include <stdlib.h>

char palabra[100];
char letras[27];
int ocurr[27];

int Ocurre_En_Letras(char letra){
	int i=0;
	while(letras[i]!=0){
		if  (letra == letras[i]) return i;
		i++;
	}
	return -1;
}

int main(int argc, char const *argv[])
{	
	printf("Introduzca la palabra: ");
	scanf("%s", palabra);

	int i = 0;

	while(palabra[i]!= 0){
		
		int pos = Ocurre_En_Letras(palabra[i]);
		if (pos == -1){
			int j=0;
			while(letras[j] != 0) j++;
			letras[j] = palabra[i];
			ocurr[j] = 1;
		}else{
			if(palabra[i]==palabra[i-1]) ocurr[pos] = ocurr[pos] + 1;
		}
		
		i++;
	}
	i = 0;
	printf("Letras que no ocurren dos veces consecutivamente: \n");
	while(letras[i]!=0){
		if (ocurr[i]==1) printf("%c ", letras[i]);
		i++;
	}
	printf("\n");

	return 0;
}