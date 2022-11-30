/*
 * controller.h
 *
 *  Created on: 30 nov 2022
 *      Author: usuario
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"

int controller_cargarPeliculaFromText(char* path , LinkedList* pArrayListaPeliculas);
int controller_listarPeliculas(LinkedList* pArrayListaPeliculas);
int controller_asignarTiempos(LinkedList* pArrayListaPeliculas);
void* controller_filtrarPorTipo(LinkedList* pArrayListaPeliculas);
int controller_guardarPeliculasModoTexto(char* path , LinkedList* pArrayListPeliculas);
int ordenarPeliculasPorDuracionGenero(void* pPrimerPelicula, void* pSegundaPelicula);
void* asignarTiempos(void* elemento);
#endif /* CONTROLLER_H_ */
