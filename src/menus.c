/*
 * menus.c
 *
 *  Created on: 30 nov 2022
 *      Author: usuario
 */


#include "menus.h"
#include "inputs.h"
#include "pelicula.h"

int menuPrincipal()
{
	int opcion;
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"|        MENU PRINCIPAL        |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"
			"| 1  | Cargar archivos         |\n"
			"| 2  | Imprimir lista          |\n"
			"| 3  | Asignar tiempos         |\n"
			"| 4  | Filtrar por tipo        |\n"
			"| 5  | Mostarar duraciones     |\n"
			"| 6  | Guardar peliculas       |\n"
			"| 7  | Salir                   |\n"
			"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
//			"Ingrese Opcion: ");
//	scanf("%d",&opcion);
	utn_getInt(&opcion, "Ingrese Opcion: ", "ERROR.", 1, 7, 100);
	return opcion;
}


int menuGenero()
{
	int opcion;
	printf("1) Adventure \n"
			"2) Drama\n"
			"3) Comedy\n"
			"4) Romance\n"
			"5) Documentary\n"
			"6) Horror\n"
			"7) Animation\n"
			"8) Thriller\n"
			"9) Western\n");
	utn_getInt(&opcion, "Ingrese opcion: ", "ERROR.", 1, 9, 100);
	return opcion;
}



//int switchGenero(int opcion)
//{
//	if(opcion!=NULL && opcion>0)
//	{
//		switch(opcion)
//		{
//		case 1:
//			ll_filter(this, pFunc)
//			break;
//		}
//	}
//}

int generoAdventure(void* pElement)
{
	int retorno=0;
	 Pelicula* AuxPel=NULL;

	 if(pElement!=NULL)
	 {
	 AuxPel=pElement;
	 if(strcmp(AuxPel->genero,"Adventure")==0)
	 {
	 retorno =1;
	 }

	}
	 return retorno;
}


int generoDrama(void* pElement)
{
	int retorno=0;
	 Pelicula* AuxPel=NULL;

	 if(pElement!=NULL)
	 {
	 AuxPel=pElement;
	 if(strcmp(AuxPel->genero,"Drama")==0)
	 {
	 retorno =1;
	 }

	}
	 return retorno;
}


int generoComedy(void* pElement)
{
	int retorno=0;
	 Pelicula* AuxPel=NULL;

	 if(pElement!=NULL)
	 {
	 AuxPel=pElement;
	 if(strcmp(AuxPel->genero,"Comedy")==0)
	 {
	 retorno =1;
	 }

	}
	 return retorno;
}


int generoRomance(void* pElement)
{
	int retorno=0;
	 Pelicula* AuxPel=NULL;

	 if(pElement!=NULL)
	 {
	 AuxPel=pElement;
	 if(strcmp(AuxPel->genero,"Romance")==0)
	 {
	 retorno =1;
	 }

	}
	 return retorno;
}


int generoDocumentary(void* pElement)
{
	int retorno=0;
	 Pelicula* AuxPel=NULL;

	 if(pElement!=NULL)
	 {
	 AuxPel=pElement;
	 if(strcmp(AuxPel->genero,"Documentary")==0)
	 {
	 retorno =1;
	 }

	}
	 return retorno;
}


int generoHorror(void* pElement)
{
	int retorno=0;
	 Pelicula* AuxPel=NULL;

	 if(pElement!=NULL)
	 {
	 AuxPel=pElement;
	 if(strcmp(AuxPel->genero,"Horror")==0)
	 {
	 retorno =1;
	 }

	}
	 return retorno;
}


int generoAnimation(void* pElement)
{
	int retorno=0;
	 Pelicula* AuxPel=NULL;

	 if(pElement!=NULL)
	 {
	 AuxPel=pElement;
	 if(strcmp(AuxPel->genero,"Animation")==0)
	 {
	 retorno =1;
	 }

	}
	 return retorno;
}


int generoThriller(void* pElement)
{
	int retorno=0;
	 Pelicula* AuxPel=NULL;

	 if(pElement!=NULL)
	 {
	 AuxPel=pElement;
	 if(strcmp(AuxPel->genero,"Thriller")==0)
	 {
	 retorno =1;
	 }

	}
	 return retorno;
}

int generoWestern(void* pElement)
{
	int retorno=0;
	 Pelicula* AuxPel=NULL;

	 if(pElement!=NULL)
	 {
	 AuxPel=pElement;
	 if(strcmp(AuxPel->genero,"Western")==0)
	 {
	 retorno =1;
	 }

	}
	 return retorno;
}

