/*
 * utn.h
 *
 *  Created on: 7 nov. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
int mostrarMenuP();
int submenuListar();
int mostrarMenuOrdenarYlistar();
int mostrarMenuCriterio();
int mostrarMenuListados();
int mostrarMenuConfeBinario();
int UTN_soloLetras(char name[]);
int UTN_ordenarCaracteresMayuscula(char name[]);
int UTN_pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);
int UTN_pedirEnteroRango(char* mensaje, int numMin, int numMax);
int validarLetras(char* cadena);
char validarSalida(char mensaje1[], char mensaje2[]);
int mostrarMenuModificacion();
int validarEspacio(char cadena[]);
int validarCadNumerica(char numero[]);
int UTN_pedirCadenaSoloNumRangoINT(char mensaje[],int* valorRet, int largoNombre,int rangoMin,int rangoMayor);
int UTN_pedirCadenaSoloNumRangoShort(char mensaje[],short* valorRet, int largoNombre,int rangoMin,int rangoMayor);
void UTN_pedirCadenaSolotexto(char mensaje[],char* nombre, int largoNombre);
int UTN_pedirCadenaSoloNumRangoFloat(char mensaje[],float* valorRet, int largoNombre,int rangoMin,int rangoMayor);
int UTN_promediarJugador(int total, int cantidad, float* totalRet);
char UTN_validarSalidaLetra();
int UTN_sacarPorcentaje(int ctdadInvidi,int cantidadGral,float* retorno);
void UTN_pedirCadenaSolotextoCnEspacio(char mensaje[],char* nombre, int largoNombre);
int UTN_pedirCadenaSoloNumSinRangoINT(char mensaje[],int* valorRet, int largoNombre);

char UTN_validarConfirmacion(char mensaje[],char mensaje2[]);
