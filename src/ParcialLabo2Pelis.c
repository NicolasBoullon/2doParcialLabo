/*
 ============================================================================
 Name        : ParcialLabo2Pelis.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "menus.h"
#include "controller.h"
#include "LinkedList.h"
#include "time.h"
int main(void) {
	setbuf(stdout,NULL);
	srand(time(NULL));
	char opcion='n';
	int banderaTiempos=0;
//	char nombreArchivo[100];
	LinkedList* listaPeliculas = ll_newLinkedList();
	LinkedList* listaPeliculasFiltro= ll_newLinkedList();
	LinkedList* listaClonada= ll_newLinkedList();
	do{

		switch(menuPrincipal())
		{
		case 1:

			if(controller_cargarPeliculaFromText("movies.csv",listaPeliculas))
			{
				printf("Carga de peliculas con exito!\n");
			}
			break;

		case 2:
			if(ll_isEmpty(listaPeliculas))
			{
				printf("Primero debe dar de alta las peliculas!\n");
			}
			else
			{
				controller_listarPeliculas(listaPeliculas);
			}

			break;

		case 3:
			if(ll_isEmpty(listaPeliculas))
			{
				printf("Primero debe dar de alta las peliculas!\n");
			}
			else
			{
			banderaTiempos=1;
			controller_asignarTiempos(listaPeliculas);
			controller_listarPeliculas(listaPeliculas);
			}
			break;

		case 4:
			if(ll_isEmpty(listaPeliculas) || (banderaTiempos==0))
			{
				printf("Primero debe dar de alta las peliculas y entrar al punto 3!\n");
			}
			else
			{
			listaPeliculasFiltro=controller_filtrarPorTipo(listaPeliculas);
			controller_listarPeliculas(listaPeliculasFiltro);
			controller_guardarPeliculasModoTexto("filtradas.csv", listaPeliculasFiltro);
			}
			break;

		case 5:
			if(ll_isEmpty(listaPeliculas) || (banderaTiempos==0))
			{
				printf("Primero debe dar de alta las peliculas y entrar al punto 3!\n");
			}
			else
			{
			listaClonada=ll_clone(listaPeliculas);
			ll_sort(listaClonada, ordenarPeliculasPorDuracionGenero, 1);
			controller_listarPeliculas(listaClonada);
			}
			break;

		case 6:
			if(ll_isEmpty(listaPeliculas))
			{
				printf("Primero debe dar de alta las peliculas!\n");
			}
			else
			{
			controller_guardarPeliculasModoTexto("ordenadas.csv", listaClonada);
			}
			break;

		case 7:
			opcion=confirmaSalir();
			break;
		}


	}while(opcion=='n');


	return EXIT_SUCCESS;
}
