// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int * listaDePrimos;
int numListaDePrimos = 0;
void AgregarArregloInt(int valor, int * size, int** lista)
{	
	int _size = *size;
	_size++;
	int  * temp = (int*)realloc(*lista, _size * sizeof(int));
	if (temp != NULL)
	{
		*lista = temp;
		(*lista)[(*size)] = valor;
		*size = _size;
	}
	else
	{
		printf("ERROR AL ASIGNAR MEMORIA A LISTA");
		exit(1);
	}
}

int primos(int n) 
{
	int i, j;
	int freq = n - 1;

	//el 1 es primo
	AgregarArregloInt(1, &numListaDePrimos, &listaDePrimos);

	bool esPrimo = true;
	for (i = 2; i <= n; ++i)
	{
		//todos son primos hasta que se demuestre lo contrario
		esPrimo = true;
		for (j = sqrt(i); j > 1; --j)
		{
			//printf("i=%i,j=%i\n", i, j);
			if (i%j == 0)
			{
				--freq;
				esPrimo = false;
				break;
			}
		}
		if (esPrimo)
		{
			AgregarArregloInt(i, &numListaDePrimos, &listaDePrimos);
			printf("%i\n", i);
		}
	}
	return freq;
}

int main(int argc, char** argv)
{
	clock_t t;
	int f;
	listaDePrimos = NULL;

	if (argc < 2)
	{
		puts("Error: falta argumento");
		puts("Uso del programa: primos.exe n donde n es el rango de enteros que se buscaran los primos");
		system("PAUSE");
		return 0;
	}
	
	t = clock();
	int n = atoi(argv[1]);
	f = primos( n  );
	std::cout << "Primos entre 0 y " << n << ": " << f << std::endl;

	t = clock() - t;

	std::cout << "Tiempo de calculo: " << ((float)t) / CLOCKS_PER_SEC << "s"<< std::endl;

	printf("num = %i", numListaDePrimos);
	//for (int i = 0; i < numListaDePrimos; i++)
	//{
	//	printf("es primo: %i \n", listaDePrimos[i]  );
	//}
	getchar();
	return 0;
}



