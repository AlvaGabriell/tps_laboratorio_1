#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"

int main()
{
	setbuf(stdout,NULL);
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    int bandera1 = 0;
    int bandera2 = 0;
    int bandera3 = 0;

    char respuesta='n';
    do{
        switch(mostrarMenuP())
        {
            case 1:
            	if(bandera1==0)
            	{
                	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
                	controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);
                	bandera1++;
            	}else
            		{
            			printf("\nYa has cargado los datos y puedes perder los que no hayas guardado...\nVe a la opcion 10 para guardar los cambios o presiona salir para volver a cargar los archivos.");
            		}
            	break;
            case 2:
                	controller_agregarJugador(listaJugadores);
                	bandera2++;
                break;
            case 3:
            	if(bandera1!=0||bandera2!=0)
            	{
            		controller_editarJugador(listaJugadores);
            		bandera2++;
            	}else
            		{
            			printf("\nDebes cargar los datos previos o ingresar un alta de jugadores para hacer una modificacion.");
            		}
                break;
            case 4:
            	if(bandera1!=0||bandera2!=0)
            	{
            		controller_removerJugadorYSelecc(listaJugadores, listaSelecciones);
            		bandera2--;
            	}else
            		{
            			printf("\nDebes cargar los datos previos o ingresar un alta de jugadores para hacer una baja de datos.");
            		}
            	break;
            case 5:
            	if(bandera1!=0||bandera2!=0)
            	{
            		controller_listadosGeneral(listaJugadores, listaSelecciones);
            	}else
            		{
            		printf("\nDebes cargar los datos previos o ingresar un alta de jugadores para acceder a los listados");
            		}
            	break;
            case 6:
            	if(bandera1!=0||bandera2!=0)
                	{
						controller_convocarJugadores(listaJugadores, listaSelecciones);
						bandera2++;
                	}else
                		{
                			printf("\nDebes cargar los datos previos o ingresar un alta de jugadores para convocar jugadores.");
                		}
            	break;
            case 7:
            	if(bandera1!=0||bandera2!=0)
                	{
            			controller_sortList(listaJugadores,listaSelecciones);
                	}else
                		{
                			printf("\nDebes cargar los datos previos o ingresar un alta de jugadores para hacer una lista de ordanamiento.");
                		}
            	break;
            case 8:
              	if(bandera1!=0||bandera2!=0)
                	{
              			controller_GenerarTxtBinario(listaJugadores, listaSelecciones);
              		    bandera3++;
                	}else
                		{
                			printf("\nDebes cargar los datos previos o ingresar un alta de jugadores para generar un archivo binario.");
                		}
            	break;
            case 9:
            	if(bandera3==0)
            	{
            		printf("\nDebes generar un archivo binario primero para acceder a esta opcion.");
            	}else
            		{
                		controller_loadFromBinary("ConfeConvocados.bin", listaJugadores);
            		}
            	break;
            case 10:
              	if(bandera1!=0||bandera2!=0)
                	{
              			controller_saveAsText("data.csv", listaJugadores);
              		    printf("\nDatos guardados con exito.");

                	}else
                	{
                		printf("\nDebes ingresar datos para guardar cambios.");
                	}
            	break;
            case 11:
              	if(bandera3!=0||bandera2!=0)
                	{
              		respuesta=UTN_validarConfirmacion("Tiene datos para guardar, seguro que desea salir ? [S/N]","Letra invalida , presione S si desea salir o N si desea continuar.");
                	}else
                	{
                		respuesta=UTN_validarConfirmacion("Esta seguro que desea salir ? [S/N]","Letra invalida , presione S si desea salir o N si desea continuar.");
                	}
				break;
            case 12:
            	printf("\n Opcion invalida.");
            	fflush(stdin);
            	break;
        }
    }while(respuesta == 'n');

    return 0;
}
