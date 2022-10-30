/*
 * confederacion.c
 *
 *  Created on: 25 oct. 2022
 *      Author: Usuario
 */
#include "nexo.h"
#define OCUPADO 0
#define LIBRE 1
int CONFE_inicializarArray(eConfederacion empleados[], int tam)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			empleados[i].isEmpty=LIBRE;
			todoOk=1;
		}
	}
	return todoOk;
}
/// @brief busco un lugar libre en el array de estructuras
///
/// @param empleados estructura donde busco el lugar libre
/// @param tam tamaño de la estrucutra
/// @return retorno una posicion libre si se encontro
int CONFE_buscarArrayLibre(eConfederacion empleados[],int tam)
{
	int retorno=-1;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/// @brief pido datos para cargar a una estrucutra
///
/// @param id id que cargo desde el main para que sea autoincremental
/// @return retorno la estructura
eConfederacion CONFE_pedirDatoEmpleado(int id)
{
	eConfederacion aux;
	aux.id=id;
	UTN_pedirCadenaSolotexto("\nIngrese nombre confederacion :", aux.nombre,10);
	UTN_pedirCadenaSolotexto("\nIngrese region de la confederacion :", aux.region,15);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese anio de creacion :", &aux.anioCreacion, 4, 1900, 2022);
	aux.isEmpty=OCUPADO;
	return aux;
}
/// @brief cargo los datos al array de estructura
///
/// @param empleados la estructura donde los cargo
/// @param tam tamaño de la estructura
/// @param id id autoincremental desde el main
/// @return retorno 1 si si salio bien
int CONFE_altaEmpleados(eConfederacion empleados[],int tam,int id)
{
	int todoOk=0;
	int posicionLibre;
	eConfederacion empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=CONFE_buscarArrayLibre(empleados, tam);
		empleado=CONFE_pedirDatoEmpleado(id);
		if(posicionLibre!=-1)
		{
			empleados[posicionLibre]=empleado;
			todoOk=1;
		}
	}
	return todoOk;
}

/// @brief Muestro un empleado
///
/// @param empleado la estructura para mostrar
void CONFE_mostrarEmpleado(eConfederacion empleado)
{
	printf("\n|%-4d|%-15s|%-15s|%-15hu|",
			empleado.id,
			empleado.nombre,
			empleado.region,
			empleado.anioCreacion);
}
/// @brief muestro los empleados del array de estructura
///
/// @param empleados empleados que necesito para mostrar
/// @param tam tamaño de la estructura
/// @return retorno 1 si salio bien
int CONFE_mostrarEmpleados(eConfederacion empleados[],int tam)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		printf("\n|%*s|%*s|%*s|%*s|",4," ID ",15," CONFEDERACION ",15, "  REGION ",
						15,"ANIO CREACION");
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				CONFE_mostrarEmpleado(empleados[i]);
			}
		}
		todoOk=1;
	}

	return todoOk;
}
/// @brief busco una estructura por id
///
/// @param empleados necesario para buscar el jugador
/// @param tam tamaño del array de estructuras
/// @param id el indice para buscar en la estructura
/// @return retorno la estructura.
eConfederacion CONFE_buscarUnoPorId(eConfederacion empleados[],int tam,int id)
{
	eConfederacion aux;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].id==id)
			{
				aux=empleados[i];
				break;
			}
		}
	}
	return aux;
}
/// @brief busco posicion pedida por el id.
///
/// @param empleados estructura donde busco la posicion
/// @param tam tamaño de la estructura
/// @param id indice para buscar en la estructura
/// @return posicion
int CONFE_buscarPosicionPorId(eConfederacion empleados[],int tam,int id)
{
	int aux;
	aux=-1;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].id==id)
			{
				aux=i;
				break;
			}
		}
	}
	return aux;
}


