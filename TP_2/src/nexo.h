/*
 * nexo.h
 *
 *  Created on: 25 oct. 2022
 *      Author: Usuario
 */


#include "confederacion.h"
#include "jugador.h"
#include "utn.h"

#ifndef NEXO_H_
#define NEXO_H_


#endif /* NEXO_H_ */
eJugador NEXO_pedirDatoEmpleado(int id,eConfederacion confederaciones[],int tamConf);
int NEXO_altaEmpleados(eJugador empleados[],int tam,int id,eConfederacion confederaciones[],int tamConf);
void NEXO_mostrarEmpleado(eJugador empleado,eConfederacion confederaciones[],int tamConf);
int NEXO_mostrarEmpleados(eJugador empleados[],int tam,eConfederacion confederaciones[],int tamConf);
int NEXO_darDebajaEmpleado(eJugador empleados[],int tamEmp,eConfederacion confederaciones[],int tamConf);
int NEXO_modificarEmpleado(eJugador empleados[],int tamEmp,eConfederacion confederaciones[],int tamConf);
int NEXO_ordenXTipoYdestino(eJugador empleados[],int tam, eConfederacion tipos[],int tamT);
int NEXO_listarJugadoresXConfe(eJugador empleados[],int tam, eConfederacion tipos[],int tamT);
int NEXO_listarSalarioYpromAsalariados(eJugador empleados[],int tam);
int NEXO_listarConfMayorCtdContratos(eJugador empleados[],int tam, eConfederacion tipos[],int tamT);
int NEXO_listarPorcentXConf(eJugador empleados[],int tam, eConfederacion tipos[],int tamT);
int contarCantidad(eJugador empleados [],int tam,int id, int* cantidad);
int NEXO_retCantJugadoresMayorConf(eJugador empleados[],int tam,int* retCant);
int NEXO_listarMayorJugXConf(eJugador empleados[],int tam, eConfederacion tipos[],int tamT);
int mostrarSegunId(eJugador jugadores[], int tam,eConfederacion tipos[], int tamT , int id);
