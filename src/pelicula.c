/*
 * pelicula.c
 *
 *  Created on: 30 nov 2022
 *      Author: usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
//#include "parser.h"
#include "pelicula.h"

Pelicula* pel_new()
{
	return malloc(sizeof(Pelicula));
}

Pelicula* pel_newParametros(char* id, char* titulo, char* genero, char* duracion)
{
	Pelicula* pel;

	pel= pel_new();

	if(id!=NULL && titulo!=NULL && genero!=NULL && duracion!=NULL )
	{
		pel_setId(pel, atoi(id));
		pel_setTitulo(pel, titulo);
		pel_setGenero(pel, genero);
		pel_setDuracion(pel, atof(duracion));
	}

	return pel;
}

int pel_setId(Pelicula* this,int id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->id = id;
		retorno=1;
	}

	return retorno;
}

int pel_getId(Pelicula* this,int* id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*id=this->id;
		retorno=1;
	}

	return retorno;
}

int pel_setTitulo(Pelicula* this,char* titulo)
{
	int retorno=-1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo, titulo);
		retorno=1;
	}

	return retorno;
}

int pel_getTitulo(Pelicula* this,char* titulo)
{
	int retorno=-1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo, this->titulo);
		retorno=1;
	}

	return retorno;
}

int pel_setGenero(Pelicula* this,char* genero)
{
	int retorno=-1;
	if(this!=NULL && genero!=NULL)
	{
		strcpy(this->genero, genero);
		retorno=1;
	}

	return retorno;
}

int pel_getGenero(Pelicula* this,char* genero)
{
	int retorno=-1;
	if(this!=NULL && genero!=NULL)
	{
		strcpy(genero, this->genero);
		retorno=1;
	}

	return retorno;
}

int pel_setDuracion(Pelicula* this,float duracion)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->duracion = duracion;
		retorno=1;
	}

	return retorno;
}

int pel_getDuracion(Pelicula* this,float* duracion)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*duracion=this->duracion;
		retorno=1;
	}

	return retorno;
}
int pel_mostrarPelicula(Pelicula* pelAux)
{
	int retorno=-1;

	int id;
	char titulo[50];
	char genero[50];
	float duracion;

	if(pelAux!=NULL)
	{

		pel_getId(pelAux, &id);
		pel_getTitulo(pelAux, titulo);
		pel_getGenero(pelAux, genero);
		pel_getDuracion(pelAux, &duracion);

		printf("|  %2d  |  %25s  |  %20s |     %3.f    |\n",id, titulo, genero, duracion);
		retorno=1;
	}



	return retorno;
}
