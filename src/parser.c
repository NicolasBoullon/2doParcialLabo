/*
 * parser.c
 *
 *  Created on: 30 nov 2022
 *      Author: usuario
 */
#include "parser.h"

int parser_peliculaFromText(FILE* pFile , LinkedList* pArrayListaPelicula)
{
	int retorno=-1;

	Pelicula* AuxPel=NULL;

	char id[10];
	char titulo[50];
	char genero[50];
	char duracion[10];
	char fantasma[300];
	if(pFile!=NULL && pArrayListaPelicula!=NULL)
	{
		fscanf(pFile,"%s",fantasma);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,genero,duracion);

			AuxPel=pel_newParametros(id, titulo, genero, duracion);

			if(AuxPel!=NULL)
			{
				ll_add(pArrayListaPelicula, AuxPel);
			}
		}
		retorno=1;
	}
	return retorno;
}
