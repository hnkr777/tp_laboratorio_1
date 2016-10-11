
/*
Examen

Autor: Federico Adolfo Honeker
Fecha: 8 de Octubre de 2016
*/

#include "defines.h"
#include "main.h"
#include "functions.h"
#include "lib.h"

int main(int argsc, char **argsv){
	int option = 0;
	int asocCount = 0;
	structAsoc *asoc = NULL;

	int callsCount = 0;
	structCall *calls = NULL;

	asoc = loadStructDataFromFile(asoc, &asocCount);

	do{
		option = menu(MAIN_MENU_LIST, MAIN_MENU_ADD, MAIN_MENU_EXIT);

		switch(option){
            case MAIN_MENU_ADD:
				asoc = addAsoc(asoc, &asocCount);
				saveStructToFile(asoc, asocCount);
                break;

            case MAIN_MENU_MODIFY:
				modifyAsoc(asoc, asocCount);
				saveStructToFile(asoc, asocCount);
                break;

            case MAIN_MENU_DELETE:
				disableAsoc(asoc, asocCount);
				saveStructToFile(asoc, asocCount);
                break;

            case MAIN_MENU_NEW_CALL:
				calls = newCall(calls, &callsCount, asoc, asocCount);
                break;

			case MAIN_MENU_ASIGN_AMB:
				asignAmbulance(calls, callsCount, asoc, asocCount);
                break;

			case MAIN_MENU_INFORM:
                inform(asoc, asocCount, calls, callsCount);
                break;

			case MAIN_MENU_ASOC_LIST:
				printAsocList(asoc, asocCount); // for debug purposes
				break;

			case MAIN_MENU_CALLS_LIST:
				printCallsList(calls, callsCount); // for debug purposes
				break;

			case MAIN_MENU_EXIT:
				printf("\x20\x3B\x29\x07");
				break;

			default:
				printf("\n Numero de opcion incorrecta.\n\n\x07");
				system("pause");
        }
    } while(option!=MAIN_MENU_EXIT);

	saveStructToFile(asoc, asocCount); // se guarda al final o antes para evitar la perdida de datos ingresados si se cierra el programa
	free(asoc);
	free(calls);
	asoc = NULL;
	calls = NULL;

    return 0;
}
