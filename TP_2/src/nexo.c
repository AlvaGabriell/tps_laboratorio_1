/*
 * nexo.c
 *
 *  Created on: 25 oct. 2022
 *      Author: Usuario
 */
#include "nexo.h"
#define OCUPADO 0
#define LIBRE 1
/// @brief pido una carga para el array
///
/// @param id autoincremental se carga desde main
/// @param confederaciones estructura que utilizo para mostrar y que se guie
/// @param tamConf tamaño de la estructura
/// @return retorno la estructura
eJugador NEXO_pedirDatoEmpleado(int id,eConfederacion confederaciones[],int tamConf)
{
	eJugador aux;
	aux.id=id;
	UTN_pedirCadenaSolotexto("\nIngrese nombre sin espacios o numeros :", aux.nombre,10);
	UTN_pedirCadenaSolotexto("\nIngrese posicion sin espacios o numeros :", aux.posicion,15);
	UTN_pedirCadenaSoloNumRangoShort("\nIngrese numero de camiseta (entre 1 y 99)",&aux.numeroCamiseta, 2, 1, 99);
	CONFE_mostrarEmpleados(confederaciones, tamConf);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese id confederacion :", &aux.idConfederacion, 3, 100, 105);
	UTN_pedirCadenaSoloNumRangoFloat("\nIngrese salario entre 5000 y 20000", &aux.salario, 6, 5000, 200000);
	UTN_pedirCadenaSoloNumRangoShort("\nIngrese anios del contrato (max:10)", &aux.aniosContrato, 2, 1, 10);
	aux.isEmpty=OCUPADO;
	return aux;
}
/// @brief cargo los datos al array de estructura
///
/// @param empleados array de estructura donde los guardo
/// @param tam tamaño del array de estructura
/// @param id autoincremental desde el main
/// @param confederaciones estructura que uso como hija de otra funcion
/// @param tamConf tamaño de la estructura
/// @return retorno 1 si salio bien
int NEXO_altaEmpleados(eJugador empleados[],int tam,int id,eConfederacion confederaciones[],int tamConf)
{
	int todoOk=0;
	int posicionLibre;
	eJugador empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=PLAYER_buscarArrayLibre(empleados, tam);
		empleado=NEXO_pedirDatoEmpleado(id, confederaciones, tamConf);
		if(posicionLibre!=-1)
		{
			empleados[posicionLibre]=empleado;
			todoOk=1;
		}
	}
	return todoOk;
}
/// @brief muestro un empleado
///
/// @param empleado estructura que uso para mostrarla
/// @param confederaciones estructura que uso para cargar una descripcion
/// @param tamConf tamaño de la estructura
void NEXO_mostrarEmpleado(eJugador empleado,eConfederacion confederaciones[],int tamConf)
{
	int id;
	eConfederacion aux;
	id=empleado.idConfederacion;
	aux=CONFE_buscarUnoPorId(confederaciones, tamConf, id);
	printf("\n|%-4d|%-10s|%-15s|%-15hu|%-15s|%-10.2f|%-15hu|",
			empleado.id,
			empleado.nombre,
			empleado.posicion,
			empleado.numeroCamiseta,
			aux.nombre,
			empleado.salario,
			empleado.aniosContrato);
}
/// @brief muestro datos de la estructura
///
/// @param empleados estructura desde la que muestro datos
/// @param tam tamaño de la estrucutra
/// @param confederaciones la utilizo apra cargar descripcion
/// @param tamConf tamaño de la estructura
/// @return retorno 1 si salio bien
int NEXO_mostrarEmpleados(eJugador empleados[],int tam,eConfederacion confederaciones[],int tamConf)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0&&confederaciones!=NULL&&tamConf>0)
	{
		printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|",4," ID ",10," NOMBRE ",15, "  POSICION ",
				15,"NUMERO CAMISETA",15,"CONFEDERACION",10,"SALARIO",15,"ANIOS CONTRATO");

		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				NEXO_mostrarEmpleado(empleados[i], confederaciones, tamConf);
			}
		}
		todoOk=1;
	}
	return todoOk;
}
/// @brief doy de baja una estructura del array
///
/// @param empleados array de estructura
/// @param tamEmp tamaño del array de estructura
/// @param confederaciones estructura que uso como referencia para mostrar descripcion
/// @param tamConf tamaño de la estructura
/// @return retorno 1 si salio bien
int NEXO_darDebajaEmpleado(eJugador empleados[],int tamEmp,eConfederacion confederaciones[],int tamConf)
{
	int todoOk=-1;
	int id;
	int posicion;
	if(empleados!=NULL&&tamEmp>0&&confederaciones!=NULL&&tamConf>0)
	{
		printf("\n\t\t******BAJA DE EMPLEADOS******");
		NEXO_mostrarEmpleados(empleados,tamEmp,confederaciones,tamConf);
		UTN_pedirCadenaSoloNumRangoINT("\nSeleccione un id : ", &id, 4, 1, 3000);
		posicion=PLAYER_buscarPosicionPorId(empleados, tamEmp, id);
		while(posicion==-1)
		{
			NEXO_mostrarEmpleados(empleados,tamEmp,confederaciones,tamConf);
			UTN_pedirCadenaSoloNumRangoINT("\nId no encontrado, seleccione id : ", &id, 4, 1, 3000);
			posicion=PLAYER_buscarPosicionPorId(empleados, tamEmp, id);
		}
		if(validarSalida("\nSeguro que desea eliminar ? [S/N]", "Letra ingresada incorrecta , vuelva a intentar [S/N]")!='s')
		{
			printf("\nOperacion cancelada...");
		}else
			{
				empleados[posicion].isEmpty=LIBRE;
				printf("\nEliminacion exitosa.!!!");
			}
		todoOk=1;
	}
	return todoOk;
}
/// @brief modifico una estructura
///
/// @param empleados array de estructuras que necesito para modificar
/// @param tamEmp tamaño del array de estructura
/// @param confederaciones estructura guia que uso para cargar descripcion
/// @param tamConf tamaño de la estructura
/// @return devuelvo 1 si salio bien
int NEXO_modificarEmpleado(eJugador empleados[],int tamEmp,eConfederacion confederaciones[],int tamConf)
{
	int todoOk=-1;
	int id;
	int posicion;
	char auxRespuesta='n';
	if(empleados!=NULL&&tamEmp>0&&confederaciones!=NULL&&tamConf>0)
	{
		printf("\n\t\t******MODIFICACION DE EMPLEADOS******");
		NEXO_mostrarEmpleados(empleados,tamEmp,confederaciones,tamConf);
		UTN_pedirCadenaSoloNumRangoINT("\nSeleccione un id : ", &id, 4, 1, 3000);
		posicion=PLAYER_buscarPosicionPorId(empleados, tamEmp, id);
		while(posicion==-1)
		{
			NEXO_mostrarEmpleados(empleados,tamEmp,confederaciones,tamConf);
			UTN_pedirCadenaSoloNumRangoINT("\nNo se encontro el id, Seleccione un id nuevamente : ", &id, 4, 1, 3000);
			posicion=PLAYER_buscarPosicionPorId(empleados, tamEmp, id);
		}
		while(auxRespuesta=='n')
		{
			switch(mostrarMenuModificacion())
			{
			case 1:
				UTN_pedirCadenaSolotexto("\nIngrese nombre sin espacios o numeros :", empleados[posicion].nombre,10);
				break;
			case 2:
				UTN_pedirCadenaSolotexto("\nIngrese posicion sin espacios o numeros :", empleados[posicion].posicion,15);
				break;
			case 3:
				UTN_pedirCadenaSoloNumRangoShort("\nIngrese numero de camiseta (entre 1 y 99)",&empleados[posicion].numeroCamiseta, 2, 1, 99);
				break;
			case 4:
				CONFE_mostrarEmpleados(confederaciones, tamConf);
				UTN_pedirCadenaSoloNumRangoINT("\nIngrese id confederacion :", &empleados[posicion].idConfederacion, 3, 100, 105);

				break;
			case 5:
				UTN_pedirCadenaSoloNumRangoFloat("\nIngrese salario entre 5000 y 20000", &empleados[posicion].salario, 6, 5000, 200000);
				break;
			case 6:
				UTN_pedirCadenaSoloNumRangoShort("\nIngrese anios del contrato (max:10)", &empleados[posicion].aniosContrato, 2, 1, 10);
				break;
			case 7:
				auxRespuesta='s';
				printf("\nModificacion cancelada.");
				break;
			default:
				printf("\nOpcion invalida.");
				fflush(stdin);
				break;
		}
			}
		todoOk=1;
	}
	return todoOk;
}

/// @brief orden doble criterio
///
/// @param empleados array que necesito para ordenar
/// @param tam tamaño del array
/// @param tipos array que necesito para cargar descripciones
/// @param tamT tamaño del array
/// @return devuelve 1 si salio bien
int NEXO_ordenXTipoYdestino(eJugador empleados[],int tam, eConfederacion tipos[],int tamT)
{
	int todoOk=0;
	eJugador aux;
	int aux1;
	int aux2;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam-1;i++)
		{

			for(int j=i+1;j<tam;j++)
			{
				if(empleados[j].isEmpty==OCUPADO)
				{
					aux1=CONFE_buscarPosicionPorId(tipos, tamT, empleados[i].idConfederacion);
					aux2=CONFE_buscarPosicionPorId(tipos, tamT, empleados[j].idConfederacion);
					if(strcmp(tipos[aux1].nombre,tipos[aux2].nombre)>0||((strcmp(tipos[aux1].nombre,tipos[aux2].nombre)==0)&&strcmp(empleados[i].nombre,empleados[j].nombre)>0))
					{
						aux=empleados[i];
						empleados[i]=empleados[j];
						empleados[j]=aux;
					}
				}
			}
		}
		todoOk=1;
	}
	return todoOk;
}
/// @brief ordenarjugadorespor confederacion
///
/// @param empleados array del que busco los datos
/// @param tam tamaño del array
/// @param tipos array que uso para cargar descripciones
/// @param tamT tamaño del array
/// @return retorno 1 si salio bien
int NEXO_listarJugadoresXConfe(eJugador empleados[],int tam, eConfederacion tipos[],int tamT)
{
	int todoOk=-1;
	int contador;
	if(empleados!=NULL&&tam>0&&tipos!=NULL&&tamT>0)
	{
		for(int i=0;i<tamT;i++)
		{
			contador=0;
			printf("\n%s : ",tipos[i].nombre);
			for(int j=0;j<tam;j++)
			{
				if(empleados[j].isEmpty==OCUPADO&&empleados[j].idConfederacion==tipos[i].id)
				{
					NEXO_mostrarEmpleado(empleados[j], tipos, tamT);
					contador++;
				}
			}
			if(contador<=0)
			{
				printf("\nNo se encontraon datos.");
			}
		}
		todoOk=1;
	}
	return todoOk;
}
/// @brief mnuestro el total de salario, promedio y quien gana mas de aquello
///
/// @param empleados array de estructura que utilizo para buscar los datos
/// @param tam tamaño del array
/// @return devuelvo 1 si salio bien
int NEXO_listarSalarioYpromAsalariados(eJugador empleados[],int tam)
{
	int todoOk=-1;
	float acum=0;
	int contador=0;
	float total;
	int contadorMayorProm=0;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				acum+=empleados[i].salario;
				contador++;
			}
		}
		printf("Total salarios : %.2f",acum);
		if(UTN_promediarJugador(acum, contador, &total)!=1)
		{
			printf("\nNo se pudo promediar");
		}else
		{
			printf("\nPromedio total %.2f",total);
			todoOk=1;
		}

		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO&&empleados[i].salario>total)
			{
				contadorMayorProm++;
			}
		}
		printf("\nCantidad de personas que cobran mas del promedio : %d",contadorMayorProm);
	}

	return todoOk;
}
/// @brief muestroconfederacion con mas cantidad de años de contrato
///
/// @param empleados array de estructura donde guardo los datos
/// @param tam tamaño del array
/// @param tipos array que uso para cargar descripciones o buscar indices
/// @param tamT tamaño del array
/// @return devuelvo 1 si salio bien
int NEXO_listarConfMayorCtdContratos(eJugador empleados[],int tam, eConfederacion tipos[],int tamT)
{
	int todoOk=-1;
	int acum=0;
	int auxAcum2;
	char auxConfeMayor[15];
	if(empleados!=NULL&&tam>0&&tipos!=NULL&&tamT>0)
	{
		for(int i=0;i<tamT;i++)
		{
			auxAcum2=0;
			for(int j=0;j<tam;j++)
			{
				if(empleados[j].isEmpty==OCUPADO&&empleados[j].idConfederacion==tipos[i].id)
				{
					auxAcum2+=empleados[j].aniosContrato;
					if(auxAcum2>acum)
					{
						acum=auxAcum2;
						strcpy(auxConfeMayor,tipos[i].nombre);
					}
				}
			}
		}
		todoOk=1;
	}
	printf("Region mayor cantidad de anios de contrato acumulados es %s : %d",auxConfeMayor,acum);
	return todoOk;
}
/// @brief muestro el porcentaje de cada region
///
/// @param empleados array de estructura donde guardo los datos
/// @param tam tamaño del array
/// @param tipos estructura que necesito para otra funcion
/// @param tamT tamaño del array de estructura
/// @return devuelvo 1 si salio bien
int NEXO_listarPorcentXConf(eJugador empleados[],int tam, eConfederacion tipos[],int tamT)
{
	int todoOk=-1;

	if(empleados!=NULL&&tam>0&&tipos!=NULL&&tamT>0)
	{
		int auxRetConnme;
		int auxRetUefa;
		int auxRetOfc;
		int auxRetAfc;
		int auxRetConcaf;
		int auxRetCaf;
		int total;
		float porcentaje;
		PLAYER_contarCantidad(empleados,tam,100,&auxRetConnme);
		PLAYER_contarCantidad(empleados,tam,101,&auxRetUefa);
		PLAYER_contarCantidad(empleados,tam,102,&auxRetCaf);
		PLAYER_contarCantidad(empleados,tam,103,&auxRetAfc);
		PLAYER_contarCantidad(empleados,tam,104,&auxRetConcaf);
		PLAYER_contarCantidad(empleados,tam,105,&auxRetOfc);
		total=auxRetConnme+auxRetUefa+auxRetCaf+auxRetAfc+auxRetConcaf+auxRetOfc;
		if(UTN_sacarPorcentaje(auxRetConnme, total, &porcentaje)==1)
		{
			printf("\nporcentaje de jugadores en conmebol : %.2f%%",porcentaje);
		}
		if(UTN_sacarPorcentaje(auxRetUefa, total, &porcentaje)==1)
		{
			printf("\nporcentaje de jugadores en uefa : %.2f%%",porcentaje);
		}
		if(UTN_sacarPorcentaje(auxRetCaf, total, &porcentaje)==1)
		{
			printf("\nporcentaje de jugadores en uefa : %.2f%%",porcentaje);
		}
		if(UTN_sacarPorcentaje(auxRetAfc, total, &porcentaje)==1)
		{
			printf("\nporcentaje de jugadores en uefa : %.2f%%",porcentaje);
		}
		if(UTN_sacarPorcentaje(auxRetConcaf, total, &porcentaje)==1)
		{
			printf("\nporcentaje de jugadores en uefa : %.2f%%",porcentaje);
		}
		if(UTN_sacarPorcentaje(auxRetOfc, total, &porcentaje)==1)
		{
			printf("\nporcentaje de jugadores en uefa : %.2f%%",porcentaje);
		}

		todoOk=1;
	}
	return todoOk;
}
/// @brief muestro que region tiene la mayor cant de jugadores
///
/// @param empleados array de estructura de donde saco los datos
/// @param tam tamaño del array de estructuras
/// @param tipos la necesito para usar en otras funciones
/// @param tamT tamaño de la estructura
/// @return retorno 1 si salio bien
int NEXO_listarMayorJugXConf(eJugador empleados[],int tam, eConfederacion tipos[],int tamT)
{
	int todoOk=-1;
	int contador=0;
	int cantidadMayor;
	NEXO_retCantJugadoresMayorConf(empleados, tam, &cantidadMayor);
	if(empleados!=NULL&&tam>0&&tipos!=NULL&&tamT>0)
	{
		for(int i=0;i<tamT;i++)
		{
			contador=0;
			for(int j=0;j<tam;j++)
			{
				if(empleados[j].isEmpty==OCUPADO&&tipos[i].id==empleados[j].idConfederacion)
				{
					contador++;
					if(contador>=cantidadMayor)
					{
						printf("\nRegion %s tiene mayor cantidad de jugadores : %d",tipos[i].nombre,cantidadMayor);
						mostrarSegunId(empleados, tam, tipos, tamT, tipos[i].id);
					}
				}
			}
		}
		todoOk=1;
	}

	return todoOk;
}
/// @brief retorno la cantidad mayor de jugadores ingresadas por confederacion
///
/// @param empleados array donde busco los datos
/// @param tam tamaño del array
/// @param retCant retorno la cantidad
/// @return devuelvo 1 si salio bien
int NEXO_retCantJugadoresMayorConf(eJugador empleados[],int tam,int* retCant)
{
	int todoOk=-1;
	if(empleados!=NULL&&tam>0)
	{
		int auxRetConnme;
		int auxRetUefa;
		int auxRetOfc;
		int auxRetAfc;
		int auxRetConcaf;
		int auxRetCaf;
		PLAYER_contarCantidad(empleados,tam,100,&auxRetConnme);
		PLAYER_contarCantidad(empleados,tam,101,&auxRetUefa);
		PLAYER_contarCantidad(empleados,tam,102,&auxRetCaf);
		PLAYER_contarCantidad(empleados,tam,103,&auxRetAfc);
		PLAYER_contarCantidad(empleados,tam,104,&auxRetConcaf);
		PLAYER_contarCantidad(empleados,tam,105,&auxRetOfc);
		if(auxRetConnme>=auxRetUefa&&auxRetConnme>=auxRetCaf&&auxRetConnme>=auxRetAfc&&auxRetConnme>=auxRetConcaf&&auxRetConnme>=auxRetOfc)
		{
			*retCant=auxRetConnme;
		}else
			{
				if(auxRetUefa>=auxRetCaf&&auxRetUefa>=auxRetAfc&&auxRetUefa>=auxRetConcaf&&auxRetUefa>=auxRetOfc)
				{
					*retCant=auxRetUefa;
				}else
					{
						if(auxRetCaf>=auxRetAfc&&auxRetCaf>=auxRetConcaf&&auxRetCaf>=auxRetOfc)
						{
							*retCant=auxRetCaf;
						}
						else
							{
								if(auxRetAfc>=auxRetConcaf&&auxRetAfc>=auxRetOfc)
									{
										*retCant=auxRetAfc;
									}
									else
										{
											if(auxRetConcaf>=auxRetOfc)
												{
													*retCant=auxRetConcaf;
												}
												else
													{
														*retCant=auxRetOfc;
													}
										}
							}
					}
			}
		todoOk=1;
	}
	return todoOk;
}


/// @brief muestro una cadena segun el id
///
/// @param jugadores array que uso para buscar los datos
/// @param tam tamaño del array donde busco
/// @param tipos estructura que uso como referencia
/// @param tamT tamaño de la estructura
/// @param id indice para buscar en el array
/// @return 1 si salio bien
int mostrarSegunId(eJugador jugadores[], int tam,eConfederacion tipos[], int tamT , int id)
{
	int todoOk=-1;
		for(int i=0;i<tam;i++)
		{
			if(jugadores[i].isEmpty==OCUPADO&&jugadores[i].idConfederacion==id)
			{
				NEXO_mostrarEmpleado(jugadores[i], tipos, tamT);
			}
		}
	return todoOk;
}



