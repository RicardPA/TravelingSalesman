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
#include <math.h>

// Valores definidos para a criacao das cidades
#define LENGTH_CITY 100
#define LENGTH_MATRIX 1000

// Representacao de cidades
typedef struct 
{
	bool busy;
	float distances[LENGTH_CITY];
	float coordinate_x;
	float coordinate_y;
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
		for(int j = 0; j < LENGTH_CITY; j++)
		{
			vectorCity->city[i].distances[j] = 0.0;
		}
	}
}

void printVectorCity(VectorCity *vectorCity)
{
	printf("|--- [Vetor de Cidades] ---|\n");
	for(int i = 0; i < LENGTH_CITY && vectorCity->city[i].busy; i++) 
	{
		printf("|");
		printf("%d) ", i);
		printf("X: %.2f |", vectorCity->city[i].coordinate_x);
		printf("Y: %.2f |", vectorCity->city[i].coordinate_y);
		printf("Usado: %d", vectorCity->city[i].busy);
		printf("|\n");
	}
	printf("|----- ---- --- -- -\n");
}

void printMatrixDistances(VectorCity *vectorCity, int numberCity)
{
	printf("|--- [Matriz de Distancias] ---|\n");
	for(int i = 0; i < numberCity; i++)
	{
		printf("|");
		for(int j = 0; j < numberCity; j++)
		{
			printf("%.2f\t", vectorCity->city[i].distances[j]);
		}
		printf("|\n");
	}
	printf("|----- ---- --- -- -\n");
}

int bestRoute(VectorCity *vectorCity, int numberCity, int accessed) {
	
	return(0);
}

void menssageErrorReadFile(int row)
{
	printf("\n\t|----- ---- --- -- -");
	printf("\n\t| ERRO: Valor da Linha (%d) do aquivo nao foi reconhecido.", row);
	printf("\n\t| OBS.: Certifique-se que os valores colocados estao separados por um espaco e variam de 0 ate 1000.");
	printf("\n\t|----- ---- --- -- -\n\n");
	exit(0);
}

int main(void) {
	// Variaveis
	int numberCity, coordinate_x, coordinate_y = -1;
	VectorCity vectorCity;
	FILE *dataCity;
	
	// Inicializar
	createVectorCity(&vectorCity);
	dataCity = fopen("Input.txt", "r");

	// Verificar se o arquivo necessario existe
	if(dataCity == NULL)
	{
		printf("\n\t|----- ---- --- -- -\n");
		printf("\n\t| ERRO: Nao foi possivel encontrar o arquivo (Input.txt).");
		printf("\n\t| OBS.: Crie um arquivo com nome (Input.txt) no mesmo diretorio do (DynamicTravelingSalesman.exe).");
		printf("\n\t|----- ---- --- -- -\n\n");
		exit(0);
	}

	// Obter e verificar o numero total de cidades
	fscanf(dataCity, "%d", &numberCity);
	
	if(numberCity > 100 && numberCity < 0)
	{
		menssageErrorReadFile(1);
	}

	// Ler e armazenar o valor das cidades
	for(int i = 0; fscanf(dataCity, "%d %d", &coordinate_x, &coordinate_y) != EOF && i < numberCity; i++)
	{
		if((coordinate_x > 1000 && coordinate_x < 0) || (coordinate_y > 1000 && coordinate_y < 0))
		{
			menssageErrorReadFile(i+2);
		}

		vectorCity.city[i].busy = true;
		vectorCity.city[i].coordinate_x = coordinate_x;
		vectorCity.city[i].coordinate_y = coordinate_y;
	}

	for(int i = 0; i < numberCity; i++) 
	{
		for(int j = 0; j < numberCity; j++)
		{
			if(i != j) {
				if(vectorCity.city[i].coordinate_x == vectorCity.city[j].coordinate_x)
				{
					vectorCity.city[i].distances[j] = abs(vectorCity.city[i].coordinate_y - vectorCity.city[j].coordinate_y);
				}
				else if(vectorCity.city[i].coordinate_y == vectorCity.city[j].coordinate_y)
				{
					vectorCity.city[i].distances[j] = abs(vectorCity.city[i].coordinate_x - vectorCity.city[j].coordinate_x);
				}
				else
				{
					float cat_01 = pow(abs(vectorCity.city[i].coordinate_x - vectorCity.city[j].coordinate_x), 2); 
					float cat_02 = pow(abs(vectorCity.city[i].coordinate_y - vectorCity.city[j].coordinate_y), 2);
					vectorCity.city[i].distances[j] = sqrt(cat_01 + cat_02);
				}
			}
		} 
	}

	// Mostrar as cidades, distancias e melhor caminho 
	printVectorCity(&vectorCity);
	printMatrixDistances(&vectorCity, numberCity);
	bestRoute(&vectorCity, numberCity, 0);

	return(0);
}