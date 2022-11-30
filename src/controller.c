/*
 * controller.c
 *
 *  Created on: 30 nov 2022
 *      Author: usuario
 */
#include "controller.h"
#include "LinkedList.h"
#include "pelicula.h"
#include "parser.h"
#include "inputs.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>

int controller_cargarPeliculaFromText(char* path , LinkedList* pArrayListaPeliculas)
{
	int todoOk = -1;

	FILE* pArchivo = NULL;

	if(path!=NULL)
	{
		pArchivo=fopen(path,"r");

		if(pArchivo!=NULL)
		{
			parser_peliculaFromText(pArchivo, pArrayListaPeliculas);
			todoOk=1;
		}
		fclose(pArchivo);
	}
    return todoOk;
}


int controller_listarPeliculas(LinkedList* pArrayListaPeliculas)
{
	int todoOk=-1;
	int tam=ll_len(pArrayListaPeliculas);

	Pelicula* PelAux;

	if(pArrayListaPeliculas!=NULL)
	{
		printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
				"|                            MENU  PELICULAS                              |\n"
				"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
				"|  ID  |           TITULO            |        GENERO         |  DURACION  |\n"
				"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");


		for(int i=0;i<tam;i++)
		{
			PelAux = ll_get(pArrayListaPeliculas, i);
			pel_mostrarPelicula(PelAux);
		}
		todoOk = 0;
	}

	return todoOk;
}

int controller_asignarTiempos(LinkedList* pArrayListaPeliculas)
{
	int todoOk=0;
	if(pArrayListaPeliculas!=NULL)
	{
		ll_map(pArrayListaPeliculas, asignarTiempos);
		todoOk=1;
	}
	return todoOk;
}


void* asignarTiempos(void* elemento)
{
	int num;
	Pelicula* AuxPel=NULL;
	if(elemento!=NULL)
	{
		AuxPel=(Pelicula*)elemento;
		num=numeroRandomInt(100, 240);
		pel_setDuracion(AuxPel, num);
	}

	return AuxPel;
}

void* controller_filtrarPorTipo(LinkedList* pArrayListaPeliculas)
{
	int todoOk=0;

	LinkedList* auxList=NULL;

	if(pArrayListaPeliculas!=NULL)
	{
		switch(menuGenero())
		{
		case 1:
			auxList=ll_filter(pArrayListaPeliculas, generoAdventure);
			break;

		case 2:
			auxList=ll_filter(pArrayListaPeliculas, generoDrama);
			break;

		case 3:
			auxList=ll_filter(pArrayListaPeliculas, generoComedy);
			break;

		case 4:
			auxList=ll_filter(pArrayListaPeliculas, generoRomance);
			break;

		case 5:
			auxList=ll_filter(pArrayListaPeliculas, generoDocumentary);
			break;

		case 6:
			auxList=ll_filter(pArrayListaPeliculas, generoHorror);
			break;

		case 7:
			auxList=ll_filter(pArrayListaPeliculas, generoAnimation);
			break;

		case 8:
			auxList=ll_filter(pArrayListaPeliculas, generoThriller);
			break;

		case 9:
			auxList=ll_filter(pArrayListaPeliculas, generoWestern);
			break;
		}
	}

	return auxList;
}


int controller_guardarPeliculasModoTexto(char* path , LinkedList* pArrayListPeliculas)
{
	int todoOk=0;
	Pelicula* PelAux=NULL;
	int id;
	char titulo[100];
	char genero[100];
	float duracion;

	int tam;
	FILE* f=fopen(path,"w");

	tam=ll_len(pArrayListPeliculas);

	if(path!=NULL && pArrayListPeliculas!=NULL && f!=NULL)
	{
	fprintf(f,"id_peli,titulo,genero,duracion\n");
		for(int i=0;i<tam;i++)
		{
			PelAux=(Pelicula*)ll_get(pArrayListPeliculas, i);
			pel_getId(PelAux, &id);
			pel_getTitulo(PelAux, titulo);
			pel_getGenero(PelAux, genero);
			pel_getDuracion(PelAux, &duracion);
			fprintf(f,"%d,%s,%s,%.2f\n",id,titulo,genero,duracion);
			todoOk=1;
		}
	}
	fclose(f);
    return todoOk;
}


int ordenarPeliculasPorDuracionGenero(void* pPrimerPelicula, void* pSegundaPelicula)
{
	int retorno=0;
	float duracionPrimeraPelicula;
	float duracionSegundaPelicula;

	char generoPrimeraPelicula[100];
	char generoSegundaPelicula[100];

	Pelicula* PelAuxUno;
	Pelicula* PelAuxDos;
	if(pPrimerPelicula!=NULL && pSegundaPelicula!=NULL)
	{
		PelAuxUno=(Pelicula*) pPrimerPelicula;
		PelAuxDos=(Pelicula*) pSegundaPelicula;

		pel_getDuracion(PelAuxUno, &duracionPrimeraPelicula);
		pel_getDuracion(PelAuxDos, &duracionSegundaPelicula);

		pel_getGenero(PelAuxUno, generoPrimeraPelicula);
		pel_getGenero(PelAuxDos, generoSegundaPelicula);

		if(strcmp(generoPrimeraPelicula,generoSegundaPelicula)>0 ||
				(strcmp(generoPrimeraPelicula,generoSegundaPelicula)==0 && duracionPrimeraPelicula<duracionSegundaPelicula))

		{
			retorno=1;
		}
//		else if(strcmp(generoPrimeraPelicula,generoSegundaPelicula)==0 && duracionPrimeraPelicula<duracionSegundaPelicula)
//		{
//			retorno=-1;
//		}
	}
	return retorno;
}
