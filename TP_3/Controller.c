#include "controller.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int todoOk=-1;
	char id[30];
	char nombreCompleto[30];
	char edad[30];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[30];
	Jugador* jugador;

	FILE* pFile= fopen(path,"r");

	if(pFile!=NULL&&pArrayListJugador!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
			jugador=jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			if(jugador!=NULL)
			{
				ll_add(pArrayListJugador,jugador);
				todoOk=1;
			}
		}
		fclose(pFile);
	}
    return todoOk;
}
/// @brief genero un binario de convocados segun confederacion
///
/// @param pArrayListJugador array donde busca datos
/// @param pArrayListSeleccion	array donde busca datos
/// @return 1 si salio bien
int controller_GenerarTxtBinario(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk=-1;
	FILE* f=fopen("ConfeConvocados.bin","wb");
	Seleccion* seleccion;
	Jugador* jugador;
	char auxConfe[100];
	char CONFEDERACIONSELECCION[100];
	int rta;
	int auxJugIdSeleccion;
	int auxSeleccionId;
	if(pArrayListJugador!=NULL&&pArrayListSeleccion!=NULL)
	{
		rta=mostrarMenuConfeBinario();
			switch(rta)
			{
			case 1:
				strcpy(auxConfe,"AFC");
				break;
			case 2:
				strcpy(auxConfe,"CAF");
				break;
			case 3:
				strcpy(auxConfe,"CONCACAF");
				break;
			case 4:
				strcpy(auxConfe,"CONMEBOL");
				break;
			case 5:
				strcpy(auxConfe,"UEFA");
				break;
			default:
				rta=-1;
				break;
			}

			if(rta>0)
			{
				for(int i=0;i<ll_len(pArrayListJugador);i++)
				{
					jugador=ll_get(pArrayListJugador,i);
					jug_getSIdSeleccion(jugador, &auxJugIdSeleccion);

					for(int j=0;j<ll_len(pArrayListSeleccion);j++)
					{
						seleccion=ll_get(pArrayListSeleccion,j);
						selec_getConfederacion(seleccion, CONFEDERACIONSELECCION);
						selec_getId(seleccion, &auxSeleccionId);
						if(strcmp(auxConfe,CONFEDERACIONSELECCION)==0&&auxJugIdSeleccion==auxSeleccionId)
						{
							fwrite(jugador,sizeof(Jugador),1,f);
							todoOk=1;
						}
					}
				}
			}else
				{
					printf("\nOpcion invalida.");
				}
	}
	fclose(f);
	return todoOk;
}
/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListJugador)
{
	int todoOk=-1;
	int cantidad;
	Jugador* auxJugador=NULL;
	FILE* fAUX=fopen("ConfeConvocados.bin","rb");
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	if(path!=NULL&&pArrayListJugador!=NULL)
	{
		 while (!feof(fAUX))
		    {
		    	auxJugador=jug_new();
		    	cantidad=fread(auxJugador,sizeof(Jugador),1,fAUX);
		    	if(cantidad==1)
		    	{
		    		jug_getId(auxJugador, &id);
		    		jug_getNombreCompleto(auxJugador, nombreCompleto);
		    		jug_getEdad(auxJugador, &edad);
		    		jug_getPosicion(auxJugador, posicion);
		    		jug_getNacionalidad(auxJugador, nacionalidad);
		    		jug_getSIdSeleccion(auxJugador, &idSeleccion);
		    		printf("%d%s%d%s%s%d\n",id, nombreCompleto, edad, posicion, nacionalidad,idSeleccion);
		    	}
		    }
		    fclose(fAUX);
	}
	return todoOk;
}

/// @brief agrego un jugador a la lista de array
///
/// @param pArrayListJugador donde almaceno el jugador
/// @return retorno 1 si salio bien
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int todoOk =-1;

	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion=0;
	Jugador* jugador;
	if(pArrayListJugador!=NULL)
	{
		jugador=jug_new();
		if(jugador!=NULL)
		{
			id=controller_GenId();
			jug_setId(jugador, id);
			UTN_pedirCadena(nombreCompleto, "Ingrese su nombre completo(Caracteres maximos: 128)\n", "Error.Ingrese su nombre nuevamente(Caracteres maximos: 128)\n", 128);
			jug_setNombreCompleto(jugador, nombreCompleto);
			UTN_pedirCadenaSoloNumRangoINT("\nIngrese edad entre 18 y 45", &edad, 3, 18, 45);
			jug_setEdad(jugador, edad);
			UTN_pedirCadenaSolotexto("\nIngrese posicion", posicion, 20);
			jug_setPosicion(jugador, posicion);
			UTN_pedirCadenaSolotexto("\nIngrese nacionalidad", nacionalidad, 20);
			jug_setNacionalidad(jugador, nacionalidad);
			jug_setIdSeleccion(jugador, idSeleccion);
			ll_add(pArrayListJugador, jugador);
			controller_guardarIdSiguiente(id);
			todoOk=1;
		}
	}
    return todoOk;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int todoOk=-1;
	Jugador* jugador;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int id;
	int auxRetValidId;

	int indice;
	if(pArrayListJugador!=NULL)
	{
		printf("\nMenu modificacion");
		controller_listarJugadores(pArrayListJugador);
		UTN_pedirCadenaSoloNumSinRangoINT("\nSeleccione el id correspondiente para modificar datos del jugador.", &id, 3);
		auxRetValidId=controller_validarIdJugador(pArrayListJugador, id);
		while(auxRetValidId!=1)
		{
			controller_listarJugadores(pArrayListJugador);
			UTN_pedirCadenaSoloNumSinRangoINT("\nSeleccione el id correspondiente para modificar datos del jugador.", &id, 3);
			auxRetValidId=controller_validarIdJugador(pArrayListJugador, id);
		}
		indice=controller_getIndex(pArrayListJugador, id);
		jugador=ll_get(pArrayListJugador, indice);
		if(indice==-1)
		{
			printf("\nIndice no encontrado.");
		}else
			{
				switch(mostrarMenuModificacion())
				{
					case 1:
						UTN_pedirCadena(nombreCompleto, "Ingrese su nombre completo(Caracteres maximos: 128)\n", "Error.Ingrese su nombre nuevamente(Caracteres maximos: 128)\n", 128);
						jug_setNombreCompleto(jugador, nombreCompleto);
						printf("\nModificacion exitosa.");
						break;
					case 2:
						UTN_pedirCadenaSoloNumRangoINT("\nIngrese edad entre 18 y 45", &edad, 3, 18, 45);
						jug_setEdad(jugador, edad);
						printf("\nModificacion exitosa.");
						break;
					case 3:
						UTN_pedirCadenaSolotexto("\nIngrese posicion", posicion, 20);
						jug_setPosicion(jugador, posicion);
						printf("\nModificacion exitosa.");
						break;
					case 4:
						UTN_pedirCadenaSolotexto("\nIngrese nacionalidad", nacionalidad, 20);
						jug_setNacionalidad(jugador, nacionalidad);
						printf("\nModificacion exitosa.");
						break;
					case 5:
						printf("\n Modificacion cancelada.");
						break;
					case 6:
						printf("\nOpcion invalida.");
						fflush(stdin);
						break;
				}
				todoOk=1;
			}
	}
    return todoOk;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int todoOk=-1;
	if(pArrayListJugador!=NULL)
	{
		Jugador* jugador;
			int id;
			printf("\nMenu de baja jugadores");
			controller_listarJugadores(pArrayListJugador);
			printf("\nSeleccione el id correspondiente para modificar datos del jugador.");
			scanf("%d",&id);
			jugador=ll_get(pArrayListJugador, id);
			while(jugador==NULL)
			{
				controller_listarJugadores(pArrayListJugador);
				printf("\nError, id no encontrado... Seleccione el id correspondiente para modificar datos del jugador.");
				scanf("%d",&id);
				jugador=ll_get(pArrayListJugador, id);
			}
			ll_remove(pArrayListJugador, id);
	}
    return todoOk;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int todoOk = -1;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	Jugador* jugador = NULL;
	if(pArrayListJugador != NULL)
	{
		printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|",5,"ID",25,"NOMBRE",8,"EDAD",20,"POSICION",15,"NACIONALIDAD",5,"IDSELECCION");
		for(int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			jugador = ll_get(pArrayListJugador, i);
			if(jugador != NULL)
			{
				jug_getId(jugador, &id);
				jug_getNombreCompleto(jugador, nombreCompleto);
				jug_getEdad(jugador,&edad);
				jug_getPosicion(jugador,posicion);
				jug_getNacionalidad(jugador,nacionalidad);
				jug_getSIdSeleccion(jugador,&idSeleccion);
				printf("\n|%-5d|%-25s|%-8d|%-20s|%-15s|%-5d|",id, nombreCompleto, edad, posicion, nacionalidad,idSeleccion);
			}
				todoOk = 1;
		}
		todoOk=0;
	}
    return todoOk;
}


/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int todoOk=-1;
	char id[30];
	char pais[30];
	char confederacion[30];
	char convocados[30];
	Seleccion* seleccion;
	FILE* pFile= fopen(path,"r");
	if(pFile!=NULL&&pArrayListSeleccion!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
			seleccion=selec_newParametros(id, pais, confederacion, convocados);
			if(seleccion!=NULL)
			{
				ll_add(pArrayListSeleccion,seleccion);
				todoOk=1;
			}
		}
	}
    return todoOk;
}

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	Seleccion* seleccion = NULL;
	if(pArrayListSeleccion != NULL)
	{
		printf("\n|%*s|%*s|%*s|%*s|",5,"ID",15,"PAIS",15,"CONFEDERACION",12,"CONVOCADOS");
		for(int i = 0; i < ll_len(pArrayListSeleccion); i++)
		{
			seleccion = ll_get(pArrayListSeleccion, i);
			if(seleccion != NULL)
			{
				selec_getId(seleccion, &id);
				selec_getPais(seleccion, pais);
				selec_getConfederacion(seleccion, confederacion);
				selec_getConvocados(seleccion, &convocados);
				printf("\n|%-5d|%-15s|%-15s|%-12d|",id, pais, confederacion, convocados);
			}
				todoOk = 1;
		}
	}
    return todoOk;
}


/// @brief genero un id en un txt aparte
///
/// @return retorno el id siguiente
int controller_GenId()
{
	FILE* f=fopen("miId.txt","r");
	int* idActual=(int*)malloc(sizeof(int));
	int siguienteId;

	if(f==NULL)
	{
		siguienteId=371;
	}else
		{
			fscanf(f, "%d", idActual);
			siguienteId=*idActual+1;
		}
	fclose(f);

	return siguienteId;
}
/// @brief abro el archivo para sobreescribir el id
///
/// @param idActual
void controller_guardarIdSiguiente(int idActual)
{
    FILE* f=fopen("miId.txt", "r+");
    if(f==NULL)
    {
        f=fopen("miId.txt", "w");
    }
    fprintf(f,"%d", idActual);
    fclose(f);
}

/// @brief convoco un jugador
///
/// @param pArrayListJugador array donde busco el jugador
/// @param pArrayListSeleccion array para relacionar los id
/// @return retorno 1 si salio bien
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
		int todoOk=-1;
		Jugador* jugador;
		Seleccion* seleccion;
		int idJugador;
		int idSelecc;
		int contadorConvocados;
		int aux;
		int auxSelecId;
		int auxJugId;
		int auxSelecConvoc;
		int auxJugIdSelec;

		if(pArrayListJugador!=NULL&&pArrayListSeleccion!=NULL)
		{
			printf("\nConvocacion de jugadores.\n");
			controller_listarJugadoresNoConvocados(pArrayListJugador, pArrayListSeleccion);
			UTN_pedirCadenaSoloNumSinRangoINT("\nSeleccione el id correspondiente del jugador a convocar", &idJugador, 3);
			aux=controller_getIndex(pArrayListJugador, idJugador);
			jugador=ll_get(pArrayListJugador, aux);
			while(jugador==NULL)
			{
				controller_listarJugadoresNoConvocados(pArrayListJugador, pArrayListSeleccion);
				UTN_pedirCadenaSoloNumSinRangoINT("\nError, Seleccione el id correspondiente del jugador a convocar", &idJugador, 3);
				aux=controller_getIndex(pArrayListJugador, idJugador);
				jugador=ll_get(pArrayListJugador, aux);
			}
			controller_listarSelecciones(pArrayListSeleccion);
			UTN_pedirCadenaSoloNumRangoINT("\nSeleccione id de seleccion a la que sera convocado.", &idSelecc, 2, 1, 32);
			for(int i = 0; i < ll_len(pArrayListSeleccion); i++)
			{
				seleccion = ll_get(pArrayListSeleccion, i);
				selec_getId(seleccion, &auxSelecId);
				jug_getId(jugador, &auxJugId);
				jug_getSIdSeleccion(jugador, &auxJugIdSelec);
				selec_getConvocados(seleccion, &auxSelecConvoc);
				if(jugador!=NULL&&idSelecc==auxSelecId&&idJugador==auxJugId&&auxSelecConvoc<22&&auxJugIdSelec==0)
				{
					selec_getConvocados(seleccion, &contadorConvocados);
					selec_setConvocados(seleccion,contadorConvocados+1);
					jug_setIdSeleccion(jugador, idSelecc);
					todoOk = 1;
					break;
				}else
					{
						todoOk=0;
					}
			}
			if(todoOk==0)
			{
				printf("\nError, el jugador ya ha sido convocado o la seleccion alcanzo el maximo permitido (22).");
			}
		}

	return todoOk;
}


/// @brief  comparo criterios para el ordenamiento
///
/// @param item1 puntero a comparar
/// @param item2 puntero a comparar
/// @return 1 si salio bien
int controller_CriterioNacionalidad(void* item1, void* item2)
{
	int todoOk = 0;
	Jugador* empleado1 = NULL;
	Jugador* empleado2 = NULL;
	char nombre1[128];
	char nombre2[128];

	empleado1 = (Jugador*) item1;
	empleado2 = (Jugador*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(jug_getNacionalidad(empleado1, nombre1) == 1 && jug_getNacionalidad(empleado2, nombre2) == 1)
		{
			if(strcmp(nombre1, nombre2) > 0)
			{
				todoOk = 1;
			}
			else if(strcmp(nombre1, nombre2) < 0)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

/// @brief comparo por criterio de confederacion
///
/// @param item1 puntero a seleccion para comparar
/// @param item2	puntero a seleccion para comparar
/// @return 1 si salio bien
int controller_CriterioConfed(void* item1, void* item2)
{
	int todoOk = 0;
	Seleccion* seleccion1 = NULL;
	Seleccion* seleccion2 = NULL;
	char nombre1[128];
	char nombre2[128];

	seleccion1 = (Seleccion*) item1;
	seleccion2 = (Seleccion*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(selec_getConfederacion(seleccion1, nombre1) == 1 && selec_getConfederacion(seleccion2, nombre2) == 1)
		{
			if(strcmp(nombre1, nombre2) > 0)
			{
				todoOk = 1;
			}
			else if(strcmp(nombre1, nombre2) < 0)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

/// @brief comparo por criterio de edad
///
/// @param item1 puntero a jugador para comparar
/// @param item2	puntero a jugador para comparar
/// @return 1 si salio bien
int controller_CriterioEdad(void* item1, void* item2)
{
	int todoOk = 0;
	Jugador* jugador = NULL;
	Jugador* jugador2 = NULL;
	int edad1;
	int edad2;

	jugador = (Jugador*) item1;
	jugador2 = (Jugador*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(jug_getEdad(jugador, &edad1) == 1 && jug_getEdad(jugador2, &edad2) == 1)
		{
			if(edad1>edad2)
			{
				todoOk = 1;
			}
			else if(edad1<edad2)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

/// @brief comparo por criterio nombre 2 punteros
///
/// @param item1 puntero para comparar
/// @param item2 puntaro para comparar
/// @return 1 si salio bien
int controller_CriterioNombre(void* item1, void* item2)
{
	int todoOk = 0;
	Jugador* empleado1 = NULL;
	Jugador* empleado2 = NULL;
	char nombre1[128];
	char nombre2[128];

	empleado1 = (Jugador*) item1;
	empleado2 = (Jugador*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(jug_getNombreCompleto(empleado1, nombre1) == 1 && jug_getNombreCompleto(empleado2, nombre2) == 1)
		{
			if(strcmp(nombre1, nombre2) > 0)
			{
				todoOk = 1;
			}
			else if(strcmp(nombre1, nombre2) < 0)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}


/// @brief ordenar lista segun criterio que ingrese el usuario.
///
/// @param pArrayListJugador array para comparar
/// @param pArrayListSeleccion array para comparar
/// @return 1 si salio bien
int controller_sortList(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int todoOk=-1;
	int criterio;
	LinkedList* auxJugador;
	LinkedList* auxSeleccion;
	if(pArrayListJugador!=NULL&&pArrayListSeleccion!=NULL)
	{
		auxJugador=ll_clone(pArrayListJugador);
		auxSeleccion=ll_clone(pArrayListSeleccion);
		criterio=mostrarMenuCriterio();
		switch(mostrarMenuOrdenarYlistar())
		{
			case 1:
				ll_sort(auxJugador, controller_CriterioNacionalidad, criterio);
				controller_listarJugadores(auxJugador);
				break;
			case 2:
				ll_sort(auxSeleccion, controller_CriterioConfed,criterio);
				controller_listarSelecciones(auxSeleccion);
				break;
			case 3:
				ll_sort(auxJugador, controller_CriterioEdad, criterio);
				controller_listarJugadores(auxJugador);
				break;
			case 4:
				ll_sort(auxJugador, controller_CriterioNombre, criterio);
				controller_listarJugadores(auxJugador);
				break;
			case 5:
				printf("\nOperacion cancelada.");
				break;
			case 6:
				printf("\nOpcion invalida.");
				fflush(stdin);
				break;
		}
		todoOk=1;
		ll_deleteLinkedList(auxJugador);
		ll_deleteLinkedList(auxSeleccion);
	}
	return todoOk;
}

/// @brief listo jugadores y cargo descripcion convocados.
///
/// @param pArrayListJugador array para cargar datos
/// @return retorno 1 si salio bien
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{

	int todoOk = 0;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	int idConvoc;

	int contEntradas=0;
	Jugador* jugador = NULL;
	if(pArrayListJugador != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			jugador = ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(jugador, &idConvoc);
			if(jugador != NULL&&idConvoc>=1)
			{
				jug_getId(jugador, &id);
				jug_getNombreCompleto(jugador, nombreCompleto);
				jug_getEdad(jugador,&edad);
				jug_getPosicion(jugador,posicion);
				jug_getNacionalidad(jugador,nacionalidad);
				jug_getSIdSeleccion(jugador,&idSeleccion);
				printf("%d   %s   %d   %s   %s    %d \n",id, nombreCompleto, edad, posicion, nacionalidad,idSeleccion);
				contEntradas++;
			}
				todoOk = 1;
		}
		if(contEntradas==0)
		{
			printf("\nNo se encontraron convocados.");
		}
	}
    return todoOk;
}
/// @brief obtengo la posicion de un jugador
///
/// @param pArrayListJugador array donde busco el idnnice
/// @param index indice
/// @return retorno la posicion o -1 si no encontro nada
int controller_getIndex(LinkedList* pArrayListJugador, int index)
{
	Jugador* aux;
	int ret=-1;
	int auxIdJug;
	if(pArrayListJugador!=NULL&&index>0)
	{
		for(int i=0;i<ll_len(pArrayListJugador);i++)
		{
			aux=ll_get(pArrayListJugador,i);
			jug_getId(aux, &auxIdJug);
			if(aux!=NULL&&index==auxIdJug)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

/// @brief busco la posicion de un elemento en un array de seleccion
///
/// @param pArrayListSeleccion array donde busco la posicion
/// @param index indice para que busque el id
/// @return retorno la posicion
int controller_getIndexSelecc(LinkedList* pArrayListSeleccion, int index)
{
	Seleccion* aux;
	int ret=-1;
	int auxSelecId;
	if(pArrayListSeleccion!=NULL&&index>0)
	{
		for(int i=0;i<ll_len(pArrayListSeleccion);i++)
		{
			aux=ll_get(pArrayListSeleccion,i);
			selec_getId(aux, &auxSelecId);
			if(aux!=NULL&&index==auxSelecId)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}


/// @brief saco un jugador convocado de la lista
///
/// @param pArrayListJugador donde busco el jugador
/// @param pArrayListSeleccion para relacionar ids
/// @return retorno 1 si salio bien
int controller_QuitarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
		int todoOk=-1;
		Jugador* jugador;
		Seleccion* seleccion;
		int idJugador;
		int contadorConvocados;
		int auxIndice;
		int auxValidarId;
		int auxJugIdSelec;
		int auxSelecId;
		if(pArrayListJugador!=NULL&&pArrayListSeleccion!=NULL)
		{
			printf("\nQuitar convocados.\n");
			controller_listarJugadoresSiConvocados(pArrayListJugador, pArrayListSeleccion);
			UTN_pedirCadenaSoloNumSinRangoINT("\nSeleccione el id correspondiente del jugador convocado a quitar", &idJugador, 3);
			auxValidarId=controller_validarIdJugador(pArrayListJugador, idJugador);
			while(auxValidarId!=1)
			{
				controller_listarJugadoresSiConvocados(pArrayListJugador, pArrayListSeleccion);
				UTN_pedirCadenaSoloNumSinRangoINT("\nSeleccione el id correspondiente del jugador convocado a quitar", &idJugador, 3);
				auxValidarId=controller_validarIdJugador(pArrayListJugador, idJugador);
			}
			auxIndice=controller_getIndex(pArrayListJugador, idJugador);
			jugador=ll_get(pArrayListJugador, auxIndice);
			if(auxIndice==-1)
			{
				printf("\nIndice no encontrado.");
			}else
				{
					jug_getSIdSeleccion(jugador, &auxJugIdSelec);
					for(int i = 0; i < ll_len(pArrayListSeleccion); i++)
					{
						seleccion = ll_get(pArrayListSeleccion, i);
						selec_getId(seleccion, &auxSelecId);
						if(jugador!=NULL&&auxSelecId==auxJugIdSelec)
						{
							selec_getConvocados(seleccion, &contadorConvocados);
							contadorConvocados--;
							selec_setConvocados(seleccion,contadorConvocados);
							jug_setIdSeleccion(jugador, 0);
							todoOk = 1;
						}
					}

				}
		}

	return todoOk;
}


/// @brief menu de listado general que muestra uno en base a la opcion elegida
///
/// @param pArrayListJugador donde busca la informacion
/// @param pArrayListSeleccion donde busca la informacion
/// @return 1 si salio bien
int controller_listadosGeneral(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	if(pArrayListJugador!=NULL&&pArrayListSeleccion!=NULL)
	{
		switch(mostrarMenuListados())
		{
			case 1:
				controller_listarTodosJugadoresConDescripcion(pArrayListJugador, pArrayListSeleccion);
				retorno=1;
				break;
			case 2:
				controller_listarSelecciones(pArrayListSeleccion);
				retorno=1;
				break;
			case 3:
				if(controller_listarJugadoresSiConvocados(pArrayListJugador, pArrayListSeleccion)!=1)
				{
					printf("\nNo se encontraron datos.");
				}else
				{
					retorno=1;
				}
				break;
			case 4:
				printf("\nOperacion cancelada.");
				break;
			case 5:
				printf("\nOpcion invalida.");
				break;
		}
	}
	return retorno;
}

/// @brief menu de convocacion de jugadores o para quitarlos
///
/// @param pArrayListJugador donde busca la info
/// @param pArrayListSeleccion donde busca la info
/// @return retorna 1 si salio bien
int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk=-1;
	int rta;
	if(pArrayListJugador!=NULL&&pArrayListSeleccion!=NULL)
	{
		printf("\n1.Convocar jugador:\n2.Quitar de la seleccion:");
		UTN_pedirCadenaSoloNumSinRangoINT("\nIngrese opcion.", &rta, 1);
		if(rta==1)
		{
			controller_convocarJugador(pArrayListJugador, pArrayListSeleccion);
			todoOk=1;
		}else
			{
				if(rta==2)
					{
						controller_QuitarJugador(pArrayListJugador, pArrayListSeleccion);
						todoOk=1;
					}else
						{
							printf("\nOpcion invalida.");
						}
			}
	}
	return todoOk;
}


/// @brief baja de jugadores
///
/// @param pArrayListJugador array donde busco la informacion
/// @param pArrayListSeleccion array donde busco al informacion
/// @return retorno 1 si la baja fue exitosa
int controller_removerJugadorYSelecc(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk=-1;
	Jugador* jugador;
	Seleccion* seleccion;
	int id;
	int indice;
	int convocados;
	char respuesta;
	int auxRetValidId;
	int auxIdSeleccion;

	if(pArrayListJugador!=NULL&&pArrayListSeleccion!=NULL)
	{
		printf("\n			Menu de baja jugadores\n");
		printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|",5,"ID",25,"NOMBRE",5,"EDAD",25,"POSICION",25,"NACIONALIDAD",15,"IDSELECCION");
		controller_listarTodosJugadoresConDescripcion(pArrayListJugador, pArrayListSeleccion);
		UTN_pedirCadenaSoloNumSinRangoINT("\nSeleccione el id correspondiente para eliminar datos del jugador.", &id, 3);
		auxRetValidId=controller_validarIdJugador(pArrayListJugador, id);
		while(auxRetValidId!=1)
		{
			controller_listarTodosJugadoresConDescripcion(pArrayListJugador, pArrayListSeleccion);
			UTN_pedirCadenaSoloNumSinRangoINT("\nId invalido, Seleccione el id correspondiente para eliminar datos del jugador.", &id, 3);
			auxRetValidId=controller_validarIdJugador(pArrayListJugador, id);
		}
		indice=controller_getIndex(pArrayListJugador, id);
		jugador=ll_get(pArrayListJugador, indice);
		jug_getSIdSeleccion(jugador, &auxIdSeleccion);
		if(indice==-1)
		{
			printf("\nIndice no encontrado.");
		}else
			{
				respuesta=UTN_validarConfirmacion("\nEsta seguro de eliminar el jugador ? [S/N]", "\nError, seleccione S si desea eliminar el jugador o N para cancelar la operacion.");
				if(respuesta=='s'&&auxIdSeleccion>0)
				{
					indice=controller_getIndexSelecc(pArrayListSeleccion, jugador->idSeleccion);
					seleccion=ll_get(pArrayListSeleccion,indice);
					selec_getConvocados(seleccion, &convocados);
					convocados--;
					selec_setConvocados(seleccion, convocados);
					ll_remove(pArrayListJugador, indice);
					printf("\nEliminacion exitosa.");
		    		todoOk=1;
				}else
					{
						if(respuesta=='s'&&auxIdSeleccion==0)
						{
							ll_remove(pArrayListJugador, indice);
				    		todoOk=1;
						}else
							{
								printf("\nEliminacion cancelada.");
							}
					}
			}

	}
	return todoOk;
}

/// @brief muestro un jugador con descripcion convocado o no
///
/// @param unJugador donde obtengo los datos
/// @param pArrayListSeleccion necesaria para usar funciones complementarias
void jug_mostrarJugadorConDescipcion(Jugador* unJugador,LinkedList* pArrayListSeleccion)
{

	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	char noConvocado[30]="No convocado";
	int indice;
	char paisSeleccionado[30];
	Seleccion* seleccion;

	if(unJugador != NULL&&pArrayListSeleccion!=NULL)
	{
		jug_getId(unJugador, &id);
		jug_getNombreCompleto(unJugador, nombreCompleto);
		jug_getEdad(unJugador, &edad);
		jug_getPosicion(unJugador, posicion);
		jug_getNacionalidad(unJugador, nacionalidad);
		jug_getSIdSeleccion(unJugador, &idSeleccion);
		if(idSeleccion>0)
		{
			indice=controller_getIndexSelecc(pArrayListSeleccion, idSeleccion);
			seleccion=ll_get(pArrayListSeleccion, indice);
			selec_getPais(seleccion, paisSeleccionado);

			printf("\n|%-5d|%-25s|%-5d|%-25s|%-25s|%-15s|",id, nombreCompleto, edad ,posicion, nacionalidad,paisSeleccionado);
		}else
		{
			printf("\n|%-5d|%-25s|%-5d|%-25s|%-25s|%-15s|",id, nombreCompleto, edad ,posicion, nacionalidad,noConvocado);
		}
	}
}

/// @brief listo todos los jugadores con descripcion convocados on o
///
/// @param pArrayListJugador donde busco los jugadores
/// @param pArrayListSeleccion necesario para funcion complementaria
/// @return retorno 1 si salio bien
int controller_listarTodosJugadoresConDescripcion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	Jugador* jugador;
	int todoOk = -1;
	if(pArrayListJugador != NULL&&pArrayListSeleccion!=NULL)
	{
		for(int i=0;i < ll_len(pArrayListJugador);i++)
		{
			jugador=ll_get(pArrayListJugador,i);
			jug_mostrarJugadorConDescipcion(jugador, pArrayListSeleccion);
		}
		todoOk=1;
	}
    return todoOk;
}

/// @brief listo jugadores solamente no convocados para menu convocar
///
/// @param pArrayListJugador donde busco la info
/// @param pArrayListSeleccion complementaria para otra funcion
/// @return retorno 1 si salio bien
int controller_listarJugadoresNoConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	Jugador* jugador;
	int todoOk = -1;
	int idSelec;
	if(pArrayListJugador != NULL&&pArrayListSeleccion!=NULL)
	{
		for(int i=0;i < ll_len(pArrayListJugador);i++)
		{
			jugador=ll_get(pArrayListJugador,i);
			jug_getSIdSeleccion(jugador, &idSelec);
			if(idSelec==0)
			{
				jug_mostrarJugadorConDescipcion(jugador, pArrayListSeleccion);
				todoOk=1;
			}
			todoOk=0;
		}
	}
    return todoOk;
}



/// @brief listo jugadores solamente convocados
///
/// @param pArrayListJugador donde los busco
/// @param pArrayListSeleccion complementaria para funcion mostrar jugador
/// @return retorno 1 si salio bien
int controller_listarJugadoresSiConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	Jugador* jugador;
	int todoOk = -1;
	int idSelec;
	if(pArrayListJugador != NULL&&pArrayListSeleccion!=NULL)
	{
		for(int i=0;i < ll_len(pArrayListJugador);i++)
		{
			jugador=ll_get(pArrayListJugador,i);
			jug_getSIdSeleccion(jugador, &idSelec);
			if(idSelec>=1)
			{
				jug_mostrarJugadorConDescipcion(jugador, pArrayListSeleccion);
				todoOk=1;
			}
			todoOk=0;
		}
	}
    return todoOk;
}

/// @brief busco si existe el id del jugador
///
/// @param pArrayListJugador donde busco los datos
/// @param id lo uso como indice
/// @return 1 si existe
int controller_validarIdJugador(LinkedList* pArrayListJugador, int id)
{
	Jugador* jugador;
	int idJugador;
	int ret=-1;
	if(pArrayListJugador!=NULL)
	{
		for(int i=0;i<ll_len(pArrayListJugador);i++)
		{
			jugador=ll_get(pArrayListJugador,i);
			jug_getId(jugador, &idJugador);

			if(jugador!=NULL&&id==idJugador)
			{
				ret = 1;
				break;
			}
			else
				{
					ret=0;
				}
		}
	}
	return ret;
}

/// @brief guardo los cambios
///
/// @param path archivo donde se guardan o reescriben
/// @param pArrayListJugador donde busco la info apra guardar
/// @return retorno 1 si salio bien
int controller_saveAsText(char* path , LinkedList* pArrayListJugador)
{
	int todoOk;
	FILE* f;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	Jugador* auxJugador;
	if(path != NULL && pArrayListJugador != NULL)
	{
		f = fopen(path, "w");
		auxJugador = jug_new();

		fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");
		for(int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			auxJugador = ll_get(pArrayListJugador, i);
			if(auxJugador != NULL)
			{
	    		jug_getId(auxJugador, &id);
	    		jug_getNombreCompleto(auxJugador, nombreCompleto);
	    		jug_getEdad(auxJugador, &edad);
	    		jug_getPosicion(auxJugador, posicion);
	    		jug_getNacionalidad(auxJugador, nacionalidad);
	    		jug_getSIdSeleccion(auxJugador, &idSeleccion);
	    		fprintf(f,"%d%s%d%s%s%d\n",id, nombreCompleto, edad, posicion, nacionalidad,idSeleccion);
				todoOk = 1;
			}
			else
			{
				printf("\nnosepudo");
				break;
			}
		}
		fclose(f);
	}
    return todoOk;
}

