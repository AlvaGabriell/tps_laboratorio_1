#include "Controller.h"

/// @brief Funcion constructora para crear un nuevo jugador
///
/// @return retorno un jugador
Jugador* jug_new()
{
	Jugador* aux;
	aux=(Jugador*)malloc(sizeof(Jugador)*1);
	if (aux!=NULL)
	{
		aux->id=0;
		aux->edad=0;
		aux->idSeleccion=0;
		strcpy(aux->nacionalidad,"-");
		strcpy(aux->nombreCompleto,"-");
		strcpy(aux->posicion,"-");
	}
	return aux;
}

/// @brief Funcion constructora para crear un nuevo jugador a partir de parametros establecidos.
///
/// @param idStr a cargar en el jugador
/// @param nombreCompletoStr	a cargar en el jugador
/// @param edadStr	a cargar en el jugador
/// @param posicionStr	a cargar en el jugador
/// @param nacionalidadStr	a cargar en el jugador
/// @param idSelccionStr	a cargar en el jugador
/// @return retorno 1 si salio bien
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* jugador;
	int id;
	int edad;
	int idSeleccion;

	id=atoi(idStr);
	edad=atoi(edadStr);
	idSeleccion=atoi(idSelccionStr);

	jugador= jug_new();

	jug_setId(jugador, id);
	jug_setNombreCompleto(jugador, nombreCompletoStr);
	jug_setEdad(jugador, edad);
	jug_setPosicion(jugador, posicionStr);
	jug_setNacionalidad(jugador, nacionalidadStr);
	jug_setIdSeleccion(jugador, idSeleccion);


	return jugador;
}

/// @brief cargo el id del jugador
///
/// @param this puntero a la lista de jugadores
/// @param id a cargar
/// @return retorno 1 si salio bien
int jug_setId(Jugador* this,int id)
{
	int retorno=-1;
	if(this!=NULL&&id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}
/// @brief obtengo el id del jugador
///
/// @param this puntero a lista de jugador
/// @param id que recibo por referencia
/// @return retorno 1 si salio bien
int jug_getId(Jugador* this,int* id)
{
	int retorno=-1;
	if(this!=NULL&&id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

/// @brief seteo nombre del jugador
///
/// @param this puntero a lista del jugador
/// @param nombreCompleto parametro que seteo
/// @return retorno 1 si salio bien
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this!=NULL&&nombreCompleto!=NULL)
	{
		strcpy(this->nombreCompleto,nombreCompleto);
		retorno=1;
	}
	return retorno;
}
/// @brief obtengo nombre del jugador
///
/// @param this puntero a la lista del jugador
/// @param nombreCompleto parametro que recibo
/// @return 1 si salio bien
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this!=NULL&&nombreCompleto!=NULL)
	{
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno=1;
	}
	return retorno;
}
/// @brief seteo la posicion del jugador
///
/// @param this puntero a la lista donde se setea
/// @param posicion lo que seteo
/// @return 1 si salio bien
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;
	if(this!=NULL&&posicion!=NULL)
	{
		strcpy(this->posicion,posicion);
		retorno=1;
	}
	return retorno;
}
/// @brief obtengo posicion
///
/// @param this puntero a lista jugador
/// @param posicion que recibo por parametro
/// @return 1 si salio bien
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;
	if(this!=NULL&&posicion!=NULL)
	{
		strcpy(posicion,this->posicion);
		retorno=1;
	}
	return retorno;
}


/// @brief seteo nacionalidad
///
/// @param this puntero a lista jugador
/// @param nacionalidad lo que seteo
/// @return 1 si salio bien
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL&&nacionalidad!=NULL)
	{
		strcpy(this->nacionalidad,nacionalidad);
		retorno=1;
	}
	return retorno;
}

/// @brief obtengo nacionalidad
///
/// @param this puntero a lista
/// @param nacionalidad lo que recibo
/// @return 1 si salio bien
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL&&nacionalidad!=NULL)
	{
		strcpy(nacionalidad,this->nacionalidad);
		retorno=1;
	}
	return retorno;
}

/// @brief seteo edad en el jugador
///
/// @param this puntero a jugador
/// @param edad lo que seteo
/// @return 1 si salio bien
int jug_setEdad(Jugador* this,int edad)
{
	int retorno=-1;
	if(this!=NULL&&edad>0)
	{
		this->edad=edad;
		retorno=1;
	}
	return retorno;
}

/// @brief obtengo edad del jugador
///
/// @param this puntero a jugador
/// @param edad lo que recibo
/// @return 1 si salio bien
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno=-1;
	if(this!=NULL&&edad!=NULL)
	{
		*edad=this->edad;
		retorno=1;
	}
	return retorno;
}
/// @brief setear id de seleccion
///
/// @param this puntero a jugador donde seteo
/// @param idSeleccion lo que seteo
/// @return 1 si salio bien
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno=-1;
	if(this!=NULL&&idSeleccion>-1)
	{
		this->idSeleccion=idSeleccion;
		retorno=1;
	}
	return retorno;
}

/// @brief  obtengo un id de seleccion del puntero a jugador
///
/// @param this puntero a jugador
/// @param idSeleccion lo que obtengo por referencia
/// @return 1 si salio bien
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno=-1;
	if(this!=NULL&&idSeleccion!=NULL)
	{
		*idSeleccion=this->idSeleccion;
		retorno=1;
	}
	return retorno;
}



