/*
 * inputs.c
 *
 *  Created on: 30 nov 2022
 *      Author: usuario
 */


#include "inputs.h"


int utn_getInt ( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int retorno = -1;
	fflush(stdin);
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getInt(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

int getInt ( int * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==0 && esNumericaInt(buffer) == 1)
		{
			*pResultado = atoi (buffer);
			retorno = 1;
		}
	}
	return retorno;
}

int esNumericaInt(char * cadena)
{
	int retorno;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = -1;
				break ;
			}
			i++;
		}
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

int myGets(char * cadena, int longitud)
{
	if (cadena != NULL && longitud >0 && fgets (cadena,longitud,stdin)==cadena)
	{
		fflush (stdin);
		if (cadena[ strlen (cadena)-1] == '\n' )
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}
		return 0;
	}
	return -1;
}

char confirmaSalir()
{
	char salir;
	printf("Seguro que desea salir?   (S/N): ");
	fflush(stdin);
	scanf("%c",&salir);
	while(salir!= 'S' && salir!= 's' && salir!='N' && salir!= 'n')
	{
		printf("Ingrese opcion correcta  (S/N): ");
		fflush(stdin);
		scanf("%c",&salir);
	}
	if(salir== 'N' || salir == 'n')
	{
		salir='n';
	}
	else if(salir== 'S' || salir == 's')
	{
		salir='s';
	}
	return salir;
}

int numeroRandomInt(int min,int max)
{
    int valor;

    for(int i=0; i<100; i++)
    {
        valor= ((rand() % (max - min + 1)) + min);
    }

    return valor;
}

float numeroRandomFloat(int min,int max)
{

    float valor;
    for(int i=0; i<100; i++)
    {
        valor= (float) ((rand() % (max - min + 1)) + min) / 10;
    }

    return valor;
}
