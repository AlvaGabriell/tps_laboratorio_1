/*
 * utn.c
 *
 *  Created on: 25 oct. 2022
 *      Author: Usuario
 */
#include "nexo.h"
/// @brief muestro menu principal
///
/// @return retorno opcion ingresada
int mostrarMenuP()
{
	int respuesta;
	printf("\n\n              ----------Menu Principal-------------");
	printf("\n1. ALTA DE JUGADOR:");
	printf("\n2. BAJA DE JUGADOR:");
	printf("\n3. MODIFICACIÓN DE JUGADOR:");
	printf("\n4. INFORMES:");
	printf("\n5. SALIR");
	scanf("%d",&respuesta);
	return respuesta;
}
/// @brief muestro menu de informes
///
/// @return retorno opcion ingresada
int submenuListar()
{
	int respuesta;
	printf("\n\n              ----------Menu Listados-------------");
	printf("\n1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.");
	printf("\n2. Listado de confederaciones con sus jugadores.");
	printf("\n3. Total y promedio de todos los salarios y cuántos jugadores cobran más del promedio.");
	printf("\n4. Informar la confederación con mayor cantidad de años de contratos total.");
	printf("\n5. Informar porcentaje de jugadores por cada confederación.");
	printf("\n6. Informar cual es la región con más jugadores y el listado de los mismos.");

	scanf("%d",&respuesta);
	return respuesta;
}
/// @brief muestro menu de modificaciones
///
/// @return retorno opcion ingresada
int mostrarMenuModificacion()
{
	int respuesta;
	printf("\nSeleccione opcion.");
	printf("\n1. Modificar nombre.");
	printf("\n2. Modificar posicion.");
	printf("\n3. Modificar numero de camiseta.");
	printf("\n4. Modificar confederacion");
	printf("\n5. Modificar salario.");
	printf("\n6. Modificar anios de contrato");
	printf("\n7. Salir menu modificacion");
	scanf("%d",&respuesta);
	return respuesta;
}
/// @brief valido letras si tienen espacios
///
/// @param cadena a evaluar
/// @return retorno si salio bien 1
int validarLetras(char* cadena)
{
	int todoOk=-1;
	int auxCad;
	if(cadena!=NULL)
	{
		for(int i=0;i<strlen(cadena);i++)
		{
			if((auxCad=isalpha(cadena[i])==0))
			{
				todoOk=0;
				break;
			}
			todoOk=1;
		}
	}
	return todoOk;
}
/// @brief valido si hay espacios en el array
///
/// @param cadena a evaluar
/// @return 1 si salio bien
int validarEspacio(char cadena[])
{
	int todoOk=-1;
	if(cadena!=NULL)
	{
		for(int i=0;i<strlen(cadena);i++)
		{
			if(isspace(cadena[i]))
			{
				todoOk=0;
				break;
			}
			todoOk=1;
		}
	}
	return todoOk;
}
/// @brief valido salida del menu
///
/// @param mensaje1 mensaje principal
/// @param mensaje2 mensaje en caso de error
/// @return retorno 1 si salio bien
char validarSalida(char mensaje1[], char mensaje2[])
{
	char respuesta;
	printf(mensaje1);
	fflush(stdin);
	scanf("%c",&respuesta);
	respuesta=tolower(respuesta);
	while((isalpha(respuesta)==0&&isspace(respuesta)==0)||(respuesta!='n'&&respuesta!='s'))
	{
		printf(mensaje2);
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=tolower(respuesta);
	}
	return respuesta;
}
/// @brief valido que solo se ingresen numeros en la cadena
///
/// @param numero a evaluar
/// @return retorno 1 si salio bien
int validarCadNumerica(char numero[])
{
	int todoOk=-1;
	if(numero!=NULL)
	{
		for(int i=0;i<strlen(numero);i++)
		{
			if(!(isdigit(numero[i])))
			{
				todoOk=0;
				break;
			}
			todoOk=1;
		}
	}
	return todoOk;
}
/// @brief pido cadena para validar y retorno como entero un short
///
/// @param mensaje mensaje a mostrar
/// @param valorRet lo que retorno
/// @param largoNombre el largo de la cadena
/// @param rangoMin el rango numerico
/// @param rangoMayor rango numerico
/// @return retorno 1 si salio bien
int UTN_pedirCadenaSoloNumRangoShort(char mensaje[],short* valorRet, int largoNombre,int rangoMin,int rangoMayor)
{
	int todoOk=-1;
	if(mensaje!=NULL&&largoNombre>0)
	{
		int auxCadNum;
		int auxCadSpacio;
		int auxRet=-1;
		char nombre[largoNombre];
		printf(mensaje);
		fflush(stdin);
		gets(nombre);
		if(strlen(nombre)<=largoNombre)
		{
			auxRet=atoi(nombre);
		}
		auxCadNum=validarCadNumerica(nombre);
		auxCadSpacio=validarEspacio(nombre);
		while(!(auxCadNum)||!(auxCadSpacio)||(rangoMin>auxRet||rangoMayor<auxRet) || auxRet==-1)
		{
			printf(mensaje);
			fflush(stdin);
			gets(nombre);
			if(strlen(nombre)<=largoNombre)
			{
				auxRet=atoi(nombre);
				*valorRet=auxRet;
				todoOk=1;
			}
			auxCadNum=validarCadNumerica(nombre);
			auxCadSpacio=validarEspacio(nombre);
		}
		*valorRet=auxRet;
		todoOk=1;
	}
	return todoOk;
}


/// @brief pido cadena y devuelvo como entero para validar ingreso
///
/// @param mensaje a mostrar
/// @param valorRet retorno por parametros el valor
/// @param largoNombre largo de la cadena
/// @param rangoMin rango numerico
/// @param rangoMayor rango numerico
/// @return
int UTN_pedirCadenaSoloNumRangoINT(char mensaje[],int* valorRet, int largoNombre,int rangoMin,int rangoMayor)
{
	int todoOk=-1;
	if(mensaje!=NULL&&largoNombre>0)
	{
		int auxCadNum;
		int auxCadSpacio;
		int auxRet=-1;
		char nombre[largoNombre];
		printf(mensaje);
		fflush(stdin);
		gets(nombre);
		if(strlen(nombre)<=largoNombre)
		{
			auxRet=atoi(nombre);
		}
		auxCadNum=validarCadNumerica(nombre);
		auxCadSpacio=validarEspacio(nombre);
		while(!(auxCadNum)||!(auxCadSpacio)||(rangoMin>auxRet||rangoMayor<auxRet) || auxRet==-1)
		{
			printf(mensaje);
			fflush(stdin);
			gets(nombre);
			if(strlen(nombre)<=largoNombre)
			{
				auxRet=atoi(nombre);
				*valorRet=auxRet;
				todoOk=1;
			}
			auxCadNum=validarCadNumerica(nombre);
			auxCadSpacio=validarEspacio(nombre);
		}
		*valorRet=auxRet;
		todoOk=1;
	}
	return todoOk;
}
/// @brief pido cadena para validarla y retorno flotante
///
/// @param mensaje a mostrar
/// @param valorRet retorno por aca
/// @param largoNombre largo de la cadena
/// @param rangoMin rango numerico
/// @param rangoMayor rango numerico
/// @return retorno 1 si salio bien
int UTN_pedirCadenaSoloNumRangoFloat(char mensaje[],float* valorRet, int largoNombre,int rangoMin,int rangoMayor)
{
	int todoOk=-1;
	if(mensaje!=NULL&&largoNombre>0)
	{
		int auxCadNum;
		int auxCadSpacio;
		float auxRet=-1;
		char nombre[largoNombre];
		printf(mensaje);
		fflush(stdin);
		gets(nombre);
		if(strlen(nombre)<=largoNombre)
		{
			auxRet=atof(nombre);
		}
		auxCadNum=validarCadNumerica(nombre);
		auxCadSpacio=validarEspacio(nombre);
		while(!(auxCadNum)||!(auxCadSpacio)||(rangoMin>auxRet||rangoMayor<auxRet) || auxRet==-1)
		{
			printf(mensaje);
			fflush(stdin);
			gets(nombre);
			if(strlen(nombre)<=largoNombre)
			{
				auxRet=atof(nombre);
				*valorRet=auxRet;
				todoOk=1;
			}
			auxCadNum=validarCadNumerica(nombre);
			auxCadSpacio=validarEspacio(nombre);
		}
		*valorRet=auxRet;
		todoOk=1;
	}
	return todoOk;
}


/// @brief pido cadena solo texto
///
/// @param mensaje mensaje a mostrar
/// @param nombre variable a validar
/// @param largoNombre largo de la cadena
void UTN_pedirCadenaSolotexto(char mensaje[],char* nombre, int largoNombre)
{
	printf(mensaje);
	fflush(stdin);
	gets(nombre);
	strlwr(nombre);
	while(strlen(nombre)>largoNombre||(!validarLetras(nombre)||validarEspacio(nombre)!=1))
	{
		printf("\nError, cadena invalida ... ");
		printf(mensaje);
		fflush(stdin);
		gets(nombre);
		strlwr(nombre);
	}
}
/// @brief promedio un valor
///
/// @param total suma total
/// @param cantidad cantidad de ingresos
/// @param totalRet retorno el valor
/// @return 1 si salio bien
int UTN_promediarJugador(int total, int cantidad, float* totalRet)
{
	int todoOk=-1;
	float importeTotal;
	if(cantidad>0)
	{
		importeTotal=(float)total/cantidad;
		*totalRet=importeTotal;
		todoOk=1;
	}else
	{
		todoOk=0;
	}
	return todoOk;
}
/// @brief valido salida para menu
///
/// @return retorno la letra validada.
char UTN_validarSalidaLetra()
{
	char letra;
	printf("\nDesea salir? [S/N]");
	fflush(stdin);
	scanf("%c",&letra);
	letra=tolower(letra);
	while(letra!='s'&&letra!='n')
	{
		printf("\nError, opcion incorrecta ... presione S o N para salir [S/N]");
		fflush(stdin);
		scanf("%c",&letra);
		letra=tolower(letra);
	}
	return letra;
}


/// @brief  sacar porcentaje para valores
///
/// @param ctdadInvidi cantidad individual
/// @param cantidadGral cantidad general
/// @param retorno retorno el valor
/// @return retorno 1 si salio bien
int UTN_sacarPorcentaje(int ctdadInvidi,int cantidadGral,float* retorno)
{
	int todoOk=-1;
	float resp;
		if(cantidadGral!=0)
		{
			resp=(float)ctdadInvidi*100/cantidadGral;
			*retorno=resp;
			todoOk=1;
		}
		else
		{
			todoOk=0;
		}
	return todoOk;
}





