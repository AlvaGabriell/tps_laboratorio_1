
#include "Controller.h"

/// @brief funcion constructora
///
/// @return retorno la seleccion si salio bien
Seleccion* selec_new()
{
	Seleccion* aux;
	aux=(Seleccion*)malloc(sizeof(Seleccion)*1);
	if (aux!=NULL)
	{
		aux->id=0;
		strcpy(aux->pais,"-");
		strcpy(aux->confederacion,"-");
		aux->convocados=0;
	}
	return aux;
}

/// @brief Funcion constructora para crear un nuevo jugador a partir de parametros establecidos.
///
/// @param idStr a setear
/// @param paisStr a setear
/// @param confederacionStr a setear
/// @param convocadosStr a setear
/// @return retorno la seleccion creada si tuvo exito
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* seleccion;
	int id;
	int convocados;

	id=atoi(idStr);
	convocados=atoi(convocadosStr);
	seleccion= selec_new();
	selec_setId(seleccion, id);
	selec_setPais(seleccion, paisStr);
	selec_setConfederacion(seleccion, confederacionStr);
	selec_setConvocados(seleccion, convocados);

	return seleccion;

}


/// @brief seteo id
///
/// @param this puntero a seleccion donde seteo
/// @param id lo que seteo
/// @return 1 si salio bien
int selec_setId(Seleccion* this,int id)
{
	int retorno=-1;
	if(this!=NULL&&id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

/// @brief obtengo id
///
/// @param this puntero a jugador de donde lo obtengo
/// @param id lo que obtengo
/// @return 1 si salio bien
int selec_getId(Seleccion* this,int* id)
{
	int retorno=-1;
	if(this!=NULL&&id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

/// @brief seteo un pais en seleccion
///
/// @param this puntero donde seteo
/// @param pais lo que seteo
/// @return 1 si salio bien
int selec_setPais(Seleccion* this,char* pais)
{
	int retorno=-1;
	if(this!=NULL&&pais!=NULL)
	{
		strcpy(this->pais,pais);
		retorno=1;
	}
	return retorno;

}
/// @brief obtengo un pais del putnero a seleccion
///
/// @param this puntero a seleccion donde obtengo el campo
/// @param pais lo que obtengo
/// @return 1 si salio bien
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno=-1;

		if(this!=NULL&&pais!=NULL)
		{
			strcpy(pais,this->pais);
			retorno=1;
		}
		return retorno;
}

/// @brief seteo confederacion en el putnero a seleccion
///
/// @param this seleccion donde seteo
/// @param confederacion lo que seteo
/// @return 1 si salio bien
int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;
	if(this!=NULL&&confederacion!=NULL)
	{
		strcpy(this->confederacion,confederacion);
		retorno=1;
	}
	return retorno;

}

/// @brief obtengo confederacion del putnero a seleccion
///
/// @param this puntero a seleccion donde obtengo el dato
/// @param confederacion lo que obtengo
/// @return 1 si salio bien
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;

		if(this!=NULL&&confederacion!=NULL)
		{
			strcpy(confederacion,this->confederacion);
			retorno=1;
		}
		return retorno;
}


/// @brief seteo convocados en seleccion
///
/// @param this puntero donde seteo
/// @param convocados lo que seteo
/// @return 1 si salio bien
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno=-1;
	if(this!=NULL&&convocados>-1)
	{
		this->convocados=convocados;
		retorno=1;
	}
	return retorno;
}

/// @brief obtengo un dato desde el puntero a seleccion
///
/// @param this puntero a seleccion
/// @param convocados lo que obtengo
/// @return 1 si salio bien
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno=-1;
	if(this!=NULL&&convocados!=NULL)
	{
		*convocados=this->convocados;
		retorno=1;
	}
	return retorno;
}

