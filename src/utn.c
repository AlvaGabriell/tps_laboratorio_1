/*
 * utn.c
 *
 *  Created on: 24 sep. 2022
 *      Author: Usuario
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "utn.h"

/// @brief
/// 	muestro menu, retorno segun opcion ingresada y paso por pasaje los valores que deben modificarse.
/// @param contComida costo comida
/// @param contHosp costo hospedaje
/// @param contTrans costo transporte
/// @param contadorArq contador arquero
/// @param contadorDef contador defensor
/// @param contadorMedioc contador mediocampista
/// @param contadorDelant contador delantero
/// @return retorno valor de la opcion elegida
int mostrarMenuP(int* contComida,int* contHosp,int* contTrans,int* contadorArq,int* contadorDef,int* contadorMedioc,int* contadorDelant)

{
	int respuesta;
	printf("\n----------Menu Principal-------------");
	printf("\n1. Ingreso de los costos de mantenimiento.");
	printf("\n-. Costo de comida :%d",*contComida);
	printf("\n-. Costo de hospedaje :%d",*contHosp);
	printf("\n-. Costo de transporte :%d",*contTrans);
	printf("\n2. Carga de jugadores.");
	printf("\nArqueros -> %d",*contadorArq);
	printf("\nDefensores -> %d",*contadorDef);
	printf("\nMediocampistas -> %d",*contadorMedioc);
	printf("\nDelanteros -> %d",*contadorDelant);
	printf("\n3. Realizar todos los calculos.");
	printf("\n4. Informar todos los resultados.");
	printf("\n5. Salir");
	scanf("%d",&respuesta);
	return respuesta;
}
/// @brief
/// muestro un submenu de jugadores y retorno en base a lo que seleccione
///
/// @return numero que sea ingresado.
int mostrarMenuJugadores()
{
	int retorno;
	printf("1. Seleccione posicion del jugador :\n");
	printf("---------------------------");
	printf("\n1.- Arquero :");
	printf("\n2.- Defensor :");
	printf("\n3.- Mediocampista :");
	printf("\n4.- Delantero :");
	scanf("%d",&retorno);
	return retorno;
}
/// @brief
/// creo un sub menu para mostrar confederaciones y que retorne una opcion
/// @return numero que fue ingresado por el usuario
int mostrarConfederacion()
{
	int respuesta;
	printf("1. Seleccione confederacion del jugador :\n");
	printf("---------------------------\n");
	printf("\n1.- CONMEBOL   (Sudamerica) :");
	printf("\n2.- UEFA (Europa) :");
	printf("\n3.- CONCACAF (Centroamerica) :");
	printf("\n4.- AFC (Asia) :");
	printf("\n5.- OFC (Oceania) :");
	printf("\n6.- CAF (Africa) :");
	scanf("%d",&respuesta);
	return respuesta;
}

/// @brief
/// pido un entero y retorno lo que ingreso.
/// @param mensaje escribo la razon para pedir un ingreso
/// @return retorno un entero ingresado por el usuario
int ingresarEntero(char mensaje[])
{
    int numeroIngresado;
    printf("%s",mensaje);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}
/// @brief
/// pido en una funcion , que me ingrese la confederacion y el numero de camiseta.
/// @param camiseta la retorno en caso de ser necesario
/// @return retorno la confederacion seleccionada.
int cargarJugadores(int* camiseta)
{
	int aux1;
	int confederacion;
	confederacion=mostrarConfederacion();
	aux1=ingresarEntero("\nIngrese numero de camiseta");
	*camiseta=aux1;
	return confederacion;
}
/// @brief
/// cuento segun la condicion el contador necesario.
/// @param numeroret la condicion para que adicione o no el contador.
/// @param num1 contador ingresado como parametro a adicionar
/// @param num2	contador ingresado como parametro a adicionar
/// @param num3	contador ingresado como parametro a adicionar
/// @param num4	contador ingresado como parametro a adicionar
/// @param num5	contador ingresado como parametro a adicionar
/// @param num6	contador ingresado como parametro a adicionar
void contarConf(int numeroret, int* num1,int* num2, int* num3, int* num4,int* num5, int* num6)
{
	switch(numeroret)
	{
		case 1:
			*num1=*num1+1;
			break;
		case 2:
			*num2=*num2+1;
			break;
		case 3:
			*num3=*num3+1;
			break;
		case 4:
			*num4=*num4+1;
			break;
		case 5:
			*num5=*num5+1;
			break;
		case 6:
			*num6=*num6+1;
	}
}
/// @brief
/// muestro promedios
/// @param promC variable que quiero mostrar por printf
/// @param promU	variable que quiero mostrar por printf
/// @param promCon	variable que quiero mostrar por printf
/// @param promA	variable que quiero mostrar por printf
/// @param promO	variable que quiero mostrar por printf
/// @param promCaf	variable que quiero mostrar por printf
void mostrarPromedios(float promC, float promU,float promCon, float promA,float promO, float promCaf)
{
	printf("\nPromedio CONMEBOL es : %.2f",promC);
	printf("\nPromedio UEFA es : %.2f",promU);
	printf("\nPromedio CONCAF es : %.2f",promCon);
	printf("\nPromedio AFC es : %.2f",promA);
	printf("\nPromedio OFC es : %.2f",promO);
	printf("\nPromedio CAF es : %.2f",promCaf);
}
/// @brief
/// promedio jugador por confederacion
/// @param totalJugador cantidad acumulada de jugadores
/// @param contConf cantidad ingresada de jugadores por confederacion
/// @return retorno el promedio
float promediarJugador(int totalJugador, int contConf)
{
	float total;
	total=(float)contConf/totalJugador;
	return total;
}
/// @brief
/// promedio jugadores
/// @param totalJugador cantidad de total jugadores sobre el que promediar
/// @param conme cantidad de jugadores de la confederacion
/// @param uefa	variable que quiero mostrar por printf
/// @param concaf	variable que quiero mostrar por printf
/// @param afc	variable que quiero mostrar por printf
/// @param ofc	variable que quiero mostrar por printf
/// @param caf	variable que quiero mostrar por printf
/// @param conme1 retorno por pasaje el promedio
/// @param uefa1	retorno por pasaje el promedio
/// @param concaf1	retorno por pasaje el promedio
/// @param afc1	retorno por pasaje el promedio
/// @param ofc1	retorno por pasaje el promedio
/// @param caf1	retorno por pasaje el promedio
void promediarJugadores(int totalJugador,int conme, int uefa, int concaf,int afc , int ofc , int caf, float* conme1, float* uefa1, float* concaf1, float* afc1, float* ofc1, float* caf1 )
{
	float aux1;
	float aux2;
	float aux3;
	float aux4;
	float aux5;
	float aux6;
	aux1=promediarJugador(totalJugador, conme);
	aux2=promediarJugador(totalJugador, uefa);
	aux3=promediarJugador(totalJugador, concaf);
	aux4=promediarJugador(totalJugador, afc);
	aux5=promediarJugador(totalJugador, ofc);
	aux6=promediarJugador(totalJugador, caf);
	*conme1=aux1;
	*uefa1=aux2;
	*concaf1=aux3;
	*afc1=aux4;
	*ofc1=aux5;
	*caf1=aux6;
}
/// @brief
/// busco el mayor promedio en base a los parametros ingresados
/// @param num1 parametro para que compare
/// @param num2	parametro para que compare
/// @param num3	parametro para que compare
/// @param num4	parametro para que compare
/// @param num5	parametro para que compare
/// @param num6	parametro para que compare
/// @return
float buscarMayorPromedio(float num1, float num2, float num3, float num4, float num5, float num6)
{
	float mayor;
	if(num1>num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1>num6)
	{
		mayor=num1;
	}else
		{
			if(num2>num1&&num2>num3&&num2>num4&&num2>num5&&num2>num6)
				{
					mayor=num2;
				}else
					{
						if(num3>num1&&num3>num2&&num3>num4&&num3>num5&&num3>num6)
							{
								mayor=num3;
							}else
								{
									if(num4>num1&&num4>num2&&num4>num3&&num4>num5&&num4>num6)
										{
											mayor=num4;
										}else
											{
												if(num5>num1&&num5>num2&&num5>num3&&num5>num4&&num5>num6)
													{
														mayor=num5;
													}else
														{
															mayor=num6;
														}
											}
								}
					}
		}
	return mayor;
}
/// @brief
/// calcula el porcentaje
/// @param numeroTotal valor total
/// @param porcentaje porcentaje por el cual operar
/// @return retorna el valor con el porcentaje de aumento
float calcularPorcentaje(int numeroTotal, int porcentaje)
{
	float resultado;
	float resultadoTotal;
	resultado=(float)numeroTotal*porcentaje/100;
	resultadoTotal=numeroTotal+resultado;
	return resultadoTotal;
}

/// @brief
/// creo una funcion que junte todas las operacioens a realizar sin mostrar resultados.
/// @param acumTotalCoste parametro acumulador
/// @param acumHos	parametro acumulador
/// @param acumCom	parametro acumulador
/// @param acumTrans	parametro acumulador
/// @param sumaJugadores	contador de jugadores totales
/// @param conme parametro contador
/// @param uefa	parametro contador
/// @param concaf	parametro contador
/// @param afc	parametro contador
/// @param ofc	parametro contador
/// @param caf	parametro contador
/// @param promConme promedio confederacion
/// @param promUefa	 promedio confederacion
/// @param promConc	 promedio confederacion
/// @param promAfc	 promedio confederacion
/// @param promOfc	 promedio confederacion
/// @param promCaf	 promedio confederacion
/// @param contadorArc parametro contador
/// @param contadorDef	parametro contador
/// @param contadorMed	parametro contador
/// @param contadorDel parametro contador
/// @param mayorProm  mayor promedio
/// @param impuestoAlbertito impuesto con porcentaje incluido
void cargarDatos(int* acumTotalCoste, int acumHos, int acumCom, int acumTrans,int* sumaJugadores,int conme,int uefa,int concaf,int afc,int ofc,int caf, float* promConme,
		float* promUefa,float* promConc, float* promAfc, float* promOfc, float* promCaf, int contadorArc,int contadorDef,
		int contadorMed,int contadorDel, float* mayorProm,float* impuestoAlbertito)
{
	int aux;
	float prom;
	float prom2;
	float prom3;
	float prom4;
	float prom5;
	float prom6;
	float auxim;
	float auxProm;
	prom=*promConme;
	prom2=*promUefa;
	prom3=*promConc;
	prom4=*promAfc;
	prom5=*promOfc;
	prom6=*promCaf;

	aux=contadorArc+contadorDef+contadorMed+contadorDel;
	*acumTotalCoste=acumHos+acumCom+acumTrans;
	promediarJugadores(aux, conme, uefa, concaf, afc, ofc, caf, &prom, &prom2,&prom3, &prom4, &prom5, &prom6);
	*sumaJugadores=aux;

	auxProm=buscarMayorPromedio(prom,prom2,prom3,prom4,prom5,prom6);
	if(auxProm==prom2)
	{
		auxim=calcularPorcentaje(*acumTotalCoste, 35);
	}
	*promConme=prom;
	*promUefa=prom2;
	*promConc=prom3;
	*promAfc=prom4;
	*promOfc=prom5;
	*promCaf=prom6;
	*mayorProm=auxProm;
	*impuestoAlbertito=auxim;
	printf("\nCarga exitosa.");
}
/// @brief
/// muestro los datos
/// @param promConme parametro a mostrar
/// @param promUefa	parametro a mostrar
/// @param promConc	parametro a mostrar
/// @param promAfc	parametro a mostrar
/// @param promOfc	parametro a mostrar
/// @param promCaf	parametro a mostrar
/// @param mayorProm	parametro a mostrar
/// @param impuestoAlbertito	parametro a mostrar
/// @param acumTotalCoste	parametro a mostrar
void mostrarDatos(float promConme, float promUefa, float promConc, float promAfc,float promOfc, float promCaf,float mayorProm, int impuestoAlbertito,int acumTotalCoste)
{
	mostrarPromedios(promConme, promUefa, promConc, promAfc, promOfc, promCaf);
	if(mayorProm==promUefa)
	{
		printf("\nEl coste de mantenimiento es : %d con un recargo del %%35 por mayoria de jugadores en confederacion europea. Total :%d ",acumTotalCoste,impuestoAlbertito);
	}else
		{
			printf("\nEl coste de mantenimiento es : %d",acumTotalCoste);
		}
}

/// @brief
/// valido salida, y contemplo la mayuscula
/// @return retorno el valor de la salida.
char validarSalida()
{
	char respuesta;
	printf("\nSalir ?");
	fflush(stdin);
	respuesta=tolower(respuesta);
	scanf("%c",&respuesta);
		return respuesta;
}

/// @brief
/// valido entradas
/// @param flag1 parametro a comparar
/// @param flag2 parametro a comparar
/// @return retorno un 1 si ingreso al caso final.
int validarEntradas (int flag1,int flag2)
{
	int retorno=0;
	if(flag1==0&&flag2==0)
	{
		printf("\nNo se ingresaron datos.");
	}else
		{
			if(flag1==1&&flag2==0)
				{
					printf("\nNo se ingresaron jugadores.");
				}else
					{
						if(flag1==0&&flag2==1)
							{
								printf("\nNo se ingresaron los costes de mantenimiento.");
							}else
								{
									retorno=1;
								}
					}
		}
	return retorno;
}


