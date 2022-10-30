/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "nexo.h"
#define TAM_JUGADORES 3000
#define TAM_CONFEDERACIONES 6
int main(void) {
	setbuf(stdout,NULL);
	int id=1;
	int cont=0;
	eConfederacion confederaciones[TAM_CONFEDERACIONES]=
	{
			{100,"CONMEBOL","SUDAMERICA",1916},
			{101,"UEFA","EUROPA",1954},
			{102,"CAF","AFRICA",1957},
			{103,"AFC","ASIA",1954},
			{104,"CONCACAF","CENTROAMERICA",1961},
			{105,"OFC", "OCEANIA",1966}
	};

	eJugador jugadores[3000];
	char respuesta='n';
	PLAYER_inicializarArray(jugadores, TAM_JUGADORES);
	while(respuesta=='n')
	{
		switch(mostrarMenuP())
		{
			case 1:
				NEXO_altaEmpleados(jugadores, TAM_JUGADORES, id, confederaciones, TAM_CONFEDERACIONES);
				cont++;
				id++;
				break;
			case 2:
				if(cont>0)
				{
					NEXO_darDebajaEmpleado(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFEDERACIONES);
				}else
					{
						printf("\nDebes ingresar datos primero.");
					}
				break;
			case 3:
				if(cont>0)
				{
					NEXO_modificarEmpleado(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFEDERACIONES);
					cont--;
				}else
					{
						printf("\nDebes ingresar datos primero.");
					}
				break;
			case 4:
				if(cont>0)
				{
					switch(submenuListar())
					{
						case 1:
							NEXO_ordenXTipoYdestino(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFEDERACIONES);
							NEXO_mostrarEmpleados(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFEDERACIONES);
							break;
						case 2:
							NEXO_listarJugadoresXConfe(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFEDERACIONES);
							break;
						case 3:
							NEXO_listarSalarioYpromAsalariados(jugadores, TAM_JUGADORES);
							break;
						case 4:
							NEXO_listarConfMayorCtdContratos(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFEDERACIONES);
							break;
						case 5:
							NEXO_listarPorcentXConf(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFEDERACIONES);
							break;
						case 6:
							NEXO_listarMayorJugXConf(jugadores, TAM_JUGADORES, confederaciones, TAM_CONFEDERACIONES);
							break;
						case 7:
							printf("\nOpcion invalida");
							fflush(stdin);
							break;
					}
				}else
					{
						printf("\nDebes ingresar datos primero.");
					}
				break;
			case 5:
				respuesta=UTN_validarSalidaLetra();
				break;
			default:
				printf("\nOpcion invalida");
				fflush(stdin);
		}
	}
	return EXIT_SUCCESS;
}


