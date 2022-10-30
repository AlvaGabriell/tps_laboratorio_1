/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
char validarSalida();
int validarEntradas (int flag1,int flag2);
int main(void) {
	setbuf(stdout,NULL);
	char respuesta='n';
	int mostrarMenuP();
	int contadorArc=0;
	int contadorDef=0;
	int contadorMed=0;
	int contadorDel=0;
	int costoHospedaje=0;
	int costoComida=0;
	int costoTransporte=0;
	int camis;
	int confJugador;
	int conme=0;
	int uefa=0;
	int concaf=0;
	int afc=0;
	int ofc=0;
	int caf=0;
	int sumaJugadores;
	float promConme;
	float promUefa;
	float promConc;
	float promAfc;
	float promOfc;
	float promCaf;
	int acumTotalCoste;
	float impuestoAlbertito;
	float mayorProm;
	int flag1=0;
	int flag2=0;
	int flag3=0;

	while(respuesta =='n')
	{
		switch(mostrarMenuP(&costoComida,&costoHospedaje,&costoTransporte,&contadorArc,&contadorDef,&contadorMed,&contadorDel))
		{
			case 1:
				costoComida=ingresarEntero("Ingrese costo de comida ");
				costoHospedaje=ingresarEntero("Ingrese costo de hospedaje ");
				costoTransporte=ingresarEntero("Ingrese costo de transporte");
				flag1=1;
				break;
			case 2:
				switch(mostrarMenuJugadores())
				{
				case 1:
					if(contadorArc<2)
					{
						confJugador=cargarJugadores(&camis);
						contarConf(confJugador, &conme, &uefa, &concaf, &afc, &ofc, &caf);
						contadorArc++;
					}else
						{
							printf("\nMaxima cantidad permitida alcanzada (2)");
						}
					break;
				case 2:
					if(contadorDef<8)
					{
						confJugador=cargarJugadores(&camis);
						contarConf(confJugador, &conme, &uefa, &concaf, &afc, &ofc, &caf);
						contadorDef++;
					}else
						{
							printf("\nMaxima cantidad permitida alcanzada (8)");
						}
					break;
				case 3:
					if(contadorMed<8)
					{
						confJugador=cargarJugadores(&camis);
						contarConf(confJugador, &conme, &uefa, &concaf, &afc, &ofc, &caf);
						contadorMed++;
					}else
						{
							printf("\nMaxima cantidad permitida alcanzada (8)");
						}
					break;
				case 4:
					if(contadorDel<4)
					{
						confJugador=cargarJugadores(&camis);
						contarConf(confJugador, &conme, &uefa, &concaf, &afc, &ofc, &caf);
						contadorDel++;
					}else
						{
							printf("\nMaxima cantidad permitida alcanzada (4)");
						}
					break;
				}
				flag2=1;
				break;
			case 3:
				if(validarEntradas(flag1, flag2))
					{
						cargarDatos(&acumTotalCoste, costoHospedaje, costoComida, costoTransporte, &sumaJugadores, conme, uefa, concaf, afc, ofc, caf, &promConme,
											&promUefa, &promConc, &promAfc, &promOfc, &promCaf, contadorArc, contadorDef, contadorMed, contadorDel,
											&mayorProm,&impuestoAlbertito);
					}
				break;
			case 4:
				if(flag3)
				{
					mostrarDatos(promConme, promUefa, promConc, promAfc, promOfc, promCaf, mayorProm, impuestoAlbertito, acumTotalCoste);
				}else
					{
						printf("\nNo hay datos ingresados...");
					}

				break;
			case 5:
				respuesta=validarSalida();
				break;
			default:
				fflush(stdin);
				printf("Opcion invalida\n");
		}
	}
	return EXIT_SUCCESS;
}
