/*
 * confederacion.h
 *
 *  Created on: 25 oct. 2022
 *      Author: Usuario
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_
typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
}eConfederacion;


#endif /* CONFEDERACION_H_ */
void CONFE_mostrarEmpleado(eConfederacion empleado);
int CONFE_mostrarEmpleados(eConfederacion empleados[],int tam);
eConfederacion CONFE_buscarUnoPorId(eConfederacion empleados[],int tam,int id);
int CONFE_buscarPosicionPorId(eConfederacion empleados[],int tam,int id);
