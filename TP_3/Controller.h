#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"


int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador);
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
void controller_guardarIdSiguiente(int idActual);
int controller_GenId();
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_getIndex(LinkedList* pArrayListJugador, int index);
int controller_CriterioNombre(void* item1, void* item2);
int controller_CriterioNacionalidad(void* item1, void* item2);
int controller_sortList(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);
int controller_QuitarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_CriterioConfed(void* item1, void* item2);
int controller_CriterioEdad(void* item1, void* item2);
int controller_listadosGeneral(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_getIndexSelecc(LinkedList* pArrayListSeleccion, int index);
int controller_removerJugadorYSelecc(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
void jug_mostrarJugadorConDescipcion(Jugador* unJugador,LinkedList* pArrayListSeleccion);
int controller_listarTodosJugadoresConDescripcion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadoresNoConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadoresSiConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_validarIdJugador(LinkedList* pArrayListJugador, int id);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_GenerarTxtBinario(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_saveAsText(char* path , LinkedList* pArrayListJugador);
