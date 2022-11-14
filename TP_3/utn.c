#include "utn.h"
/// @brief muestro menu principal
///
/// @return retorno opcion ingresada
int mostrarMenuP()
{
	int respuesta;
	printf("\n\n              ----------Menu Principal-------------");
	printf("\n1. CARGA DE ARCHIVOS:");
	printf("\n2. ALTA DE JUGADOR:");
	printf("\n3. MODIFICACIÓN DE JUGADOR:");
	printf("\n4. BAJA DE JUGADOR:");
	printf("\n5. LISTADOS:");
	printf("\n6. CONVOCAR JUGADORES:");
	printf("\n7. ORDENAR Y LISTAR:");
	printf("\n8. GENERAR ARCHIVO BINARIO:");
	printf("\n9. CARGAR ARCHIVO BINARIO:");
	printf("\n10. GUARDAR ARCHIVOS .CSV:");
	printf("\n11. SALIR:");

	scanf("%d",&respuesta);
	return respuesta;
}
/// @brief muestro menu de modificaciones
///
/// @return retorno opcion ingresada
int mostrarMenuConfeBinario()
{
	int respuesta;
	printf("\nSeleccione una confederacion.");
	printf("\n1. cargar confederacion AFC.");
	printf("\n2. cargar confederacion CAF");
	printf("\n3. cargar confederacion CONCACAF");
	printf("\n4. cargar confederacion CONMEBOL");
	printf("\n5. cargar confederacion UEFA");
	printf("\n6. salir del menu.");
	scanf("%d",&respuesta);
	return respuesta;
}

/// @brief muestro menu modificacion
///
/// @return respuesta
int mostrarMenuModificacion()
{
	int respuesta;
	printf("\nMenu modificacion.");
	printf("\n1. modificar nombre.");
	printf("\n2. modificar edad");
	printf("\n3. modificar posicion");
	printf("\n4. modificar nacionalidad");
	printf("\n6. salir del menu.");
	scanf("%d",&respuesta);
	return respuesta;
}


/// @brief muestro menu de ordenamientos
///
/// @return respuesta
int mostrarMenuOrdenarYlistar()
{
	int respuesta;
	printf("\nSeleccione opcion.");
	printf("\n1. JUGADORES POR NACIONALIDAD.");
	printf("\n2. SELECCIONES POR CONFEDERACIÓN.");
	printf("\n3. JUGADORES POR EDAD.");
	printf("\n4. JUGADORES POR NOMBRE.");
	printf("\n5. Salir menu listados");
	scanf("%d",&respuesta);
	return respuesta;
}
///  @brief muestro menu de criterios
///
/// @return respuesta
int mostrarMenuCriterio()
{
    int opcion;
    printf("\nSeleccione opcion de criterio.");
    printf("\n0. Descendente. (Z-A)");
    printf("\n1. Ascendente.(A-Z)");
    scanf("%d", &opcion);
    return opcion;
}

/// @brief muestro menu de modificaciones
///
/// @return retorno opcion ingresada
int mostrarMenuListados()
{
	int respuesta;
	printf("\nSeleccione que opcion quiere listar.");
	printf("\n1. LISTAR TODOS LOS JUGADORES:");
	printf("\n2. TODAS LAS SELECCIONES:");
	printf("\n3. JUGADORES CONVOCADOS:");
	printf("\n4. Salir menu modificacion");
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
/// @brief ordeno caracteres por mayuscula
///
/// @param name parametro que recibo
/// @return 1 si salio bien
int UTN_ordenarCaracteresMayuscula(char name[])
{
    int todoOk = 0;
    int i = 0;

    if(name != NULL)
    {
        strlwr(name);
        name[0] = toupper(name[0]);

        while(name[i] != '\0')
        {
            if(name[i] == ' ')
            {
                name[i + 1] = toupper(name [i + 1]);
            }
            i++;
        }
        todoOk = 1;
    }
    return todoOk;
}


/// @brief filtro solo letras
///
/// @param name lo que necesito para filtrar
/// @return 1 si salio bien
int UTN_soloLetras(char name[])
{
    int i = 0;
    int todoOk;

    if(name != NULL)
    {
        while(name[i] != '\0')
        {
            if(!isalpha(name[i]) && name[i] != ' ')
            {
				todoOk = 0;

				while(todoOk == 0)
				{
					printf("Error. Ingreselo nuevamente solo con letras(hasta 30 caracteres)\n");
					fflush(stdin);
					gets(name);
					i = 0;
					todoOk = 1;
				}
            }
            i++;
        }
    }
    return todoOk;
}
/// @brief pido cadena
///
/// @param cadena donde almaceno el dato pedido
/// @param mensaje mensaje que varia segun lo que necesite
/// @param mensajeError mensaje de error que varia segun lo que necesite
/// @param max cantidad de caracteres maximo
/// @return 1 si salio bien
int UTN_pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int todoOk = -1;
	char buffer[256];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(buffer);

		UTN_soloLetras(buffer);
		fflush(stdin);

		while(strlen(buffer)>max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(buffer);
			UTN_soloLetras(buffer);
		}

		UTN_ordenarCaracteresMayuscula(buffer);

		strcpy(cadena, buffer);
		todoOk = 0;
	}
	return todoOk;
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

/// @brief valido la respuesta que uso frecuentemente para un msj de salida
///
/// @param mensaje msj que varia segun la necesidad
/// @param mensaje2 msj de erorr
/// @return retorno el caracter validado.
char UTN_validarConfirmacion(char mensaje[],char mensaje2[])
{
	char letra;
	printf(mensaje);
	fflush(stdin);
	scanf("%c",&letra);
	letra=tolower(letra);
	while(letra!='s'&&letra!='n')
	{
		printf(mensaje2);
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

/// @brief pido cadena solo numeros sin rango y enteros
///
/// @param mensaje mensaje que varia segun la necesidad
/// @param valorRet dato que devuelvo por referencia
/// @param largoNombre maximo largo del nombre
/// @return 1 si salio bien
int UTN_pedirCadenaSoloNumSinRangoINT(char mensaje[],int* valorRet, int largoNombre)
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
		while(!(auxCadNum)||!(auxCadSpacio)|| auxRet==-1)
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


