/*
 * menus.h
 *
 *  Created on: 30 nov 2022
 *      Author: usuario
 */

#ifndef MENUS_H_
#define MENUS_H_
#include <stdio.h>
#include <stdlib.h>


int menuPrincipal();
int menuGenero();
int generoAdventure(void* pElement);
int generoDrama(void* pElement);
int generoComedy(void* pElement);
int generoRomance(void* pElement);
int generoDocumentary(void* pElement);
int generoHorror(void* pElement);
int generoAnimation(void* pElement);
int generoThriller(void* pElement);
int generoWestern(void* pElement);

#endif /* MENUS_H_ */
