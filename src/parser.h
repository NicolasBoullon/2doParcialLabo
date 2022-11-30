/*
 * parser.h
 *
 *  Created on: 30 nov 2022
 *      Author: usuario
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pelicula.h"

int parser_peliculaFromText(FILE* pFile , LinkedList* pArrayListaPelicula);

#endif /* PARSER_H_ */
