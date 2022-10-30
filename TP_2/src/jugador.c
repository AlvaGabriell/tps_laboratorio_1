/*
 * jugador.c
 *
 *  Created on: 25 oct. 2022
 *      Author: Usuario
 */
#include "nexo.h"
#define OCUPADO 0
#define LIBRE 1
/// @brief inicializo array de estrucutras
///
/// @param empleados la estructura a inicializar
/// @param tam tamaño de la estrucutra
/// @return retorno 1 si estuvo salio bien.
int PLAYER_inicializarArray(eJugador empleados[], int tam)
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
int PLAYER_buscarArrayLibre(eJugador empleados[],int tam)
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
eJugador PLAYER_pedirDatoEmpleado(int id)
{
	eJugador aux;
	aux.id=id;
	UTN_pedirCadenaSolotexto("\nIngrese nombre sin espacios o numeros :", aux.nombre,10);
	UTN_pedirCadenaSolotexto("\nIngrese posicion sin espacios o numeros :", aux.posicion,15);
	UTN_pedirCadenaSoloNumRangoShort("\nIngrese numero de camiseta (entre 1 y 99)",&aux.numeroCamiseta, 2, 1, 99);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese id confederacion :", &aux.idConfederacion, 3, 100, 105);
	UTN_pedirCadenaSoloNumRangoFloat("\nIngrese salario entre 5000 y 20000", &aux.salario, 6, 5000, 200000);
	UTN_pedirCadenaSoloNumRangoShort("\nIngrese anios del contrato (max:10)", &aux.aniosContrato, 2, 1, 10);
	aux.isEmpty=OCUPADO;
	return aux;
}
/// @brief cargo los datos al array de estructura
///
/// @param empleados la estructura donde los cargo
/// @param tam tamaño de la estructura
/// @param id id autoincremental desde el main
/// @return retorno 1 si si salio bien
int PLAYER_altaEmpleados(eJugador empleados[],int tam,int id)
{
	int todoOk=0;
	int posicionLibre;
	eJugador empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=PLAYER_buscarArrayLibre(empleados, tam);
		empleado=PLAYER_pedirDatoEmpleado(id);
		if(posicionLibre!=-1)
		{
			empleados[posicionLibre]=empleado;
			todoOk=1;
		}
	}
	return todoOk;
}
/// @brief muestro una estructura
///
/// @param empleado estructura a mostrar
void PLAYER_mostrarEmpleado(eJugador empleado)
{
	printf("\n%3d     %s      %s          %hu         %d		   %.2f         %hu",
			empleado.id,
			empleado.nombre,
			empleado.posicion,
			empleado.numeroCamiseta,
			empleado.idConfederacion,
			empleado.salario,
			empleado.aniosContrato);
}
/// @brief muestro el array de estructuras
///
/// @param empleados estructura que muestro
/// @param tam tamaño de la estructura
/// @return retorno 1 si salio bien
int PLAYER_mostrarEmpleados(eJugador empleados[],int tam)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		printf("\n  ID       NOMBRE         POSICION            NUMERO CAMISETA 		ID CONFEDERACION 		SALARIO 		ANIOS CONTRATO");
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				PLAYER_mostrarEmpleado(empleados[i]);
			}
		}
	}

	return todoOk;
}
///@brief busco uno por id en la estructura
///
/// @param empleados estructura donde busco
/// @param tam tamanio de la estrucutra
/// @param id de referencia para buscar en la estructura
/// @return retorno una estructura desde la posicion
eJugador PLAYER_buscarUnoPorId(eJugador empleados[],int tam,int id)
{
	eJugador aux;
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
/// @brief busco posicion por id en la estructura
///
/// @param empleados estructura donde busco posicion
/// @param tam tamaño de la estructura
/// @param id indice para buscar en la estructura
/// @return retorno el indice si se encontro
int PLAYER_buscarPosicionPorId(eJugador empleados[],int tam,int id)
{
	int aux;
	aux=-1;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO&&empleados[i].id==id)
			{
				aux=i;
				break;
			}
		}
	}
	return aux;
}

/// @brief  cuento cantidad de ingresos en uan array de estructura
///
/// @param empleados array de estructura para buscar los ingresos
/// @param tam tamanio del array
/// @param id que uso como indice para la condicion
/// @param cantidad retorno por parametros el valor
/// @return retorno 1 si salio bien
int PLAYER_contarCantidad(eJugador empleados [],int tam,int id, int* cantidad)
{
	int todoOk=-1;
	int contadorJugador=0;

	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO&&empleados[i].idConfederacion==id)
			{
				contadorJugador++;
				*cantidad=contadorJugador;
			}
		}

		*cantidad=contadorJugador;
		todoOk=1;
	}
	return todoOk;
}
