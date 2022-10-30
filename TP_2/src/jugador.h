/*
 * jugador.h
 *
 *  Created on: 25 oct. 2022
 *      Author: Usuario
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;
#endif /* JUGADOR_H_ */
int PLAYER_inicializarArray(eJugador empleados[], int tam);
int PLAYER_buscarArrayLibre(eJugador empleados[],int tam);
eJugador PLAYER_pedirDatoEmpleado(int id);
int PLAYER_altaEmpleados(eJugador empleados[],int tam,int id);
void PLAYER_mostrarEmpleado(eJugador empleado);
int PLAYER_mostrarEmpleados(eJugador empleados[],int tam);
eJugador PLAYER_buscarUnoPorId(eJugador empleados[],int tam,int id);
int PLAYER_buscarPosicionPorId(eJugador empleados[],int tam,int id);
int PLAYER_contarCantidad(eJugador empleados [],int tam,int id, int* cantidad);
