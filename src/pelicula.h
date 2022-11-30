/*
 * pelicula.h
 *
 *  Created on: 30 nov 2022
 *      Author: usuario
 */

#ifndef PELICULA_H_
#define PELICULA_H_
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct
{
	int id;
	char titulo[100];
	char genero[100];
	float duracion;

}Pelicula;

Pelicula* pel_new();
Pelicula* pel_newParametros(char* id, char* titulo, char* genero, char* duracion);


int pel_setId(Pelicula* this,int id);
int pel_getId(Pelicula* this,int* id);
int pel_setTitulo(Pelicula* this,char* titulo);
int pel_getTitulo(Pelicula* this,char* titulo);
int pel_setGenero(Pelicula* this,char* genero);
int pel_getGenero(Pelicula* this,char* genero);
int pel_setDuracion(Pelicula* this,float duracion);
int pel_getDuracion(Pelicula* this,float* duracion);
int pel_mostrarPelicula(Pelicula* peliculaAux);

#endif /* PELICULA_H_ */
