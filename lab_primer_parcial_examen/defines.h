#ifndef DEFINES_H
#define DEFINES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define SUCCESS  	0
#define ERROR    	-1

#define MAX_STR 0xFF
#define MIN_DNI_VALUE     1
#define MAX_DNI_VALUE  100000000
#define MIN_ASOC_AGE        1
#define MAX_ASOC_AGE      150

#define MAIN_MENU_ADD             1
#define MAIN_MENU_MODIFY          2
#define MAIN_MENU_DELETE          3
#define MAIN_MENU_NEW_CALL		  4
#define MAIN_MENU_ASIGN_AMB       5
#define MAIN_MENU_INFORM		  6
#define MAIN_MENU_ASOC_LIST		  7
#define MAIN_MENU_CALLS_LIST	  8
#define MAIN_MENU_EXIT			  9

#define MODIF_MENU_NAME				1
#define MODIF_MENU_LAST_NAME		2
#define MODIF_MENU_EXIT				3

#define MOT_INFART	 		1
#define MOT_INFART_STR 		"Infarto"
#define MOT_ACV 	 		2
#define MOT_ACV_STR 		"Accidente cerebro vascular"
#define MOT_FLU 	 		3
#define MOT_FLU_STR 		"Gripe"

#define STATE_CURRENT       1
#define STATE_CURRENT_STR "PENDIENTE"
#define STATE_ACCOMPLISHED  2
#define STATE_ACCOMPLISHED_STR "CUMPLIDO"

#define STATUS_UNUSED 		0
#define STATUS_DISABLED 	1
#define STATUS_ENABLED 		2

#define MAIN_MENU_LIST "Ingrese una opcion:\n\n 1) Alta del asociado\n 2) Modificar datos del asociado\n 3) Baja del asociado\n\n 4) Nueva llamada\n 5) Asignar ambulancia\n\n 6) Informar\n 7) Lista de asociados (extra)\n 8) Lista de llamadas (extra)\n 9) Salir\n\nOpcion: "
#define MODIF_MENU_LIST "Modificar asociado\n Ingrese una opcion:\n\n  1) Modificar nombre\n  2) Modificar apellido\n  3) Salir\n\nOpcion: "

#define FILE_ASOC_DATA  "./asociados.dat"  // here stores asociated database (struct), file can be deleted if you wanna reset database

typedef struct{
	int asocID; 			// structAsoc.id
	char mot;   			// MOT_ACV / MOT_FLU / MOT_INFART
	char state; 			// STATE_ACCOMPLISHED / STATE_CURRENT
	int ambulanceID; 		// ambulance identifier
	unsigned long time; 	// time until STATE_ACCOMPLISHED
	int id;   				// for future uses
} structCall;

typedef struct{
	int id;					// autoincrement identifier
	char name[MAX_STR];
	char lastName[MAX_STR];
	int dni;			   // between MIN_DNI_VALUE & MAX_DNI_VALUE
	int age;			   // between MIN_ASOC_AGE & MAX_ASOC_AGE
	char status;           // can be: STATUS_UNUSED / STATUS_DISABLED / STATUS_ENABLED
	int calls;             // calls counter
} structAsoc;

#endif // DEFINES_H
