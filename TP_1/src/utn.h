/*
 * utn.h
 *
 *  Created on: 24 sep. 2022
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
int mostrarMenuP(int contComida,int contHosp,int contTrans,int contadorArq,int contadorDef,int contadorMedioc,int contadorDelant);
int mostrarMenuCostos();
int ingresarEntero(char mensaje[],int* retorno);
int mostrarMenuJugadores();
int ingresarEntero();
int mostrarConfederacion();
int cargarJugadores();
float calcularPorcentaje(int numeroTotal, int porcentaje);
int contarConf(int numeroret, int* num1,int* num2, int* num3, int* num4,int* num5, int* num6);
void mostrarPromedios(float promC, float promU,float promCon, float promA,float promO, float promCaf);
int promediarJugadores(int totalJugador,int conme, int uefa, int concaf,int afc , int ofc , int caf, float* conme1, float* uefa1, float* concaf1, float* afc1, float* ofc1, float* caf1 );
int promediarJugador(int totalJugador, int contConf,float* retorno);
float buscarMayorPromedio(float num1, float num2, float num3, float num4, float num5, float num6);
int cargarDatos(int* acumTotalCoste, int acumHos, int acumCom, int acumTrans,int* sumaJugadores,int conme,int uefa,int concaf,int afc,int ofc,int caf, float* promConme,
		float* promUefa,float* promConc, float* promAfc, float* promOfc, float* promCaf, int contadorArc,int contadorDef,
		int contadorMed,int contadorDel, float* mayorProm,float* impuestoAlbertito);
void mostrarDatos(float promConme, float promUefa, float promConc, float promAfc,float promOfc, float promCaf,float mayorProm, int impuestoAlbertito,int acumTotalCoste);
int validarEntradas (int flag1,int flag2);
char validarSalida();


int cargarCostosMantenimiento(int* costoComida, int* costoHospedaje,int* costoTransporte);
