/*
	-----------------------------------
	DynamicTravelingSalesman.c 
	Author: Ricardo Portilho de Andrade
	-----------------------------------
	OBS.: Resolvendo o caxeiro viajante
	de forma dinamica.
	-----------------------------------
*/

/* Bibliotecas da Linguagem */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Valores definidos para a criacao das cidades
#define LENGTH_CITY 100
#define LENGTH_MATRIX 1000

// Representacao de cidades
typedef struct 
{
	bool busy;
	int coordinate_x;
	int coordinate_y;
} City;

typedef struct 
{
	City city[LENGTH_CITY];
} VectorCity;

void createVectorCity(VectorCity *vectorCity)
{
	for(int i = 0; i < LENGTH_CITY; i++) 
	{
		vectorCity->city[i].busy = false;
		vectorCity->city[i].coordinate_x = -1;
		vectorCity->city[i].coordinate_y = -1;
	}
}

void printVectorCity(VectorCity *vectorCity)
{
	printf("|--- [Vetor de Cidades] ---|\n");
	for(int i = 0; i < LENGTH_CITY; i++) 
	{
		printf("|");
		printf("%d) ", i);
		printf("X: %d |", vectorCity->city[i].coordinate_x);
		printf("Y: %d |", vectorCity->city[i].coordinate_y);
		printf("Usado: %d", vectorCity->city[i].busy);
		printf("|\n");
	}
	printf("|----- ---- --- -- -\n");
}

int main(void) {
	// Variaveis
	char stringDataCity[10] = "";
	char valueStringDataCity[10] = {"0123456789"}; 
	VectorCity vectorCity;
	FILE *dataCity;
	
	// Inicializar
	createVectorCity(&vectorCity);
	dataCity = fopen("Input.txt", "r"); 

	// Fazer
	if(dataCity == NULL)
	{
		printf("\n\t|----- ---- --- -- -\n");
		printf("\n\tERRO: Nao foi possivel encontrar o arquivo (Input.txt).");
		printf("\n\tOBS.: Crie um arquivo com nome (Input.txt) no mesmo diretorio do (DynamicTravelingSalesman.exe).");
		printf("\n\t|----- ---- --- -- -\n\n");
		exit(0);
	}

	for(int i = 0; fgets(stringDataCity, 25, codeTomasulo) != NULL, i++)
	{
		if(strlen(stringDataCity) > 9)
		{
			printf("\n\t|----- ---- --- -- -\n");
			printf("\n\tERRO: Valor da Linha (%d) do aquivo nao foi reconhecido.", i);
			printf("\n\t|----- ---- --- -- -\n\n");
			exit(0);
		}
	}

	printVectorCity(&vectorCity);
	
	return(0);
}