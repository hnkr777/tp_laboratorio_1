
#include "defines.h"
#include "lib.h"
#include "functions.h"

structAsoc* addAsoc(structAsoc *asoc, int *asocCount){ /// leer notas de esta funcion
    asoc = realloc(asoc, sizeof(structAsoc) * ((*asocCount)+1));
	if(asoc==NULL){
		printf("\n No se pudo reservar memoria.\n\n\x07");
		system("pause");
		return asoc;
	}

	if(loadAsocData(asoc, ((*asocCount)+1))==SUCCESS){
		(*asocCount)++;
		asoc = realloc(asoc, sizeof(structAsoc) * (*asocCount));
		printf("\n Asociado numero %d agregado.\n\n", asoc[(*asocCount)-1].id);
		system("pause");
		return asoc;
	}
	return asoc;
}

int disableAsoc(structAsoc* asoc, int asocCount){
	int del, x, ret = ERROR;

	if(asocCount==0){
		printf("\n No hay asociados registrados.\n\n\x07");
		system("pause");
		return ret;
	}

	system("cls");
	if(getInt(&del, "\nBaja asociado:\n\n Ingrese el numero de id a dar de baja: ", " Numero de id invalido.\n\x07", 1, asocCount)==SUCCESS){
		for(x=0; x<asocCount; x++){
			if(del==asoc[x].id && asoc[x].status==STATUS_ENABLED){
				asoc[x].status = STATUS_DISABLED;
				ret = SUCCESS;
				printf("\n El asociado %s %s, ID numero %d ha sido dado de baja exitosamente.\n\n", asoc[x].name, asoc[x].lastName, del);
				system("pause");
				break;
			}else if(del==asoc[x].id && asoc[x].status==STATUS_DISABLED){
				printf("\n El asociado %s %s, ID numero %d ya esta dado de baja.\n\n\x07", asoc[x].name, asoc[x].lastName, del);
				system("pause");
				break;
			}
		}
	}

	return ret;
}

structCall* newCall(structCall *calls, int *callsCount, structAsoc *asoc, int asocCount){
	int mot, asocID = 0, asocIndex = -1;
	char tmpStr[MAX_STR];

	if((*callsCount)>0 && calls[(*callsCount)-1].state==STATE_CURRENT){
		printf("\n Hay una emergencia en curso, primero deberia asignarle una ambulancia.\x07\n\n");
		system("pause");
		return calls;
	}

	if(asocCount==0){
		printf("\n No hay asociados registrados.\n\n\x07");
		system("pause");
		return calls;
	}

	system("cls");

	if(getInt(&asocID, "\n Ingrese un numero de asociado: ", " Numero de asociado no valido.\x07\n", 1, INT_MAX)==0){
		asocIndex = getAsocByID(asoc, asocCount, asocID);
		if(asocIndex>-1 && asoc[asocIndex].status==STATUS_ENABLED){ // si existe un asociado con el ID ingresado, entonces...
			if(getInt(&mot, "\n Ingrese un motivo (1=" MOT_INFART_STR ", 2=" MOT_ACV_STR ", 3=" MOT_FLU_STR "): ", " Numero de motivo incorrecto.\x07\n", MOT_INFART, MOT_FLU)==0){
				(*callsCount)++;
				calls = realloc(calls, sizeof(structCall) * (*callsCount));
				if(calls==NULL){
					printf("\n No se pudo reservar memoria.\n");
					system("pause");
				}else{
					calls[(*callsCount)-1].id = (*callsCount);
					calls[(*callsCount)-1].state = STATE_CURRENT;
					asoc[asocIndex].calls++;
					calls[(*callsCount)-1].mot = mot;
					calls[(*callsCount)-1].asocID = asocID;
					calls[(*callsCount)-1].ambulanceID = 0;
					calls[(*callsCount)-1].time = getTimeInSeconds();
                    //printf("\n Tiempo en segundos: %lu\n", calls[(*callsCount)-1].time); // debug purposes
					printf("\n Se ha registrado al asociado %s %s,", asoc[asocIndex].name, asoc[asocIndex].lastName);
					getTimeString(tmpStr);
					printf(" a las %s con estado " STATE_CURRENT_STR ".\n\n", tmpStr);
					system("pause");
				}
			}
		}else{
			printf("\n El ID de asociado numero %d no existe o fue dado de baja.\n\n\x07", asocID);
			system("pause");
		}
	}

	return calls;
}

int asignAmbulance(structCall *calls, int callsCount, structAsoc *asoc, int asocCount){
	int tmpInt, ret = ERROR, mins = 0, secs = 0, timeElapsed;
	char tmpStr[MAX_STR];

	if(callsCount==0 || calls[callsCount-1].state==STATE_ACCOMPLISHED){
		printf("\n No hay una emergencia en curso.\n\n\x07");
		system("pause");
	}else if(callsCount>0 && getInt(&tmpInt, "\n Ingrese el ID de la ambulancia (1~100): ", "\n ID de ambulancia invalido.\n", 1, 100)==0){
		if(existAmbulanceByID(calls, callsCount, tmpInt)==SUCCESS){
			printf("\n ID de ambulancia en uso.\x07\n\n");
			system("pause");
		}else{
			calls[callsCount-1].ambulanceID = tmpInt;
			calls[callsCount-1].state = STATE_ACCOMPLISHED;
			calls[callsCount-1].time = getTimeInSeconds()-calls[callsCount-1].time;
			getTimeString(tmpStr);
			printf("\n Ambulancia numero %d asignada, hora: %s\n", tmpInt, tmpStr);
			timeElapsed = calls[callsCount-1].time;
			mins = timeElapsed / 60;
			secs = timeElapsed - mins*60;
			printf(" Tiempo total transcurrido: %d minutos y %d segundos\n\n", mins, secs);
			system("pause");
			ret = SUCCESS;
		}
	}

	return ret;
}

int existAmbulanceByID(structCall *calls, int callsCount, int id){
	int x, ret = ERROR;

	for(x=0; x<callsCount; x++){
		if(calls[x].ambulanceID==id){
			ret = SUCCESS;
			break;
		}
	}

	return ret;
}

int modifyAsoc(structAsoc* asoc, int asocCount){
	int del, index, ret = ERROR;

	if(asocCount>0){
		system("cls");
		if(getInt(&del, "\n Modificar datos del asociado:\n\n Ingrese el numero de ID a modificar: ", " Numero de ID invalido.", 1, asocCount )==SUCCESS){
            index = getAsocByID(asoc, asocCount, del);
            if(index!=ERROR){
				ret = modifyAsocData(asoc, index);
            }
		}
	}else{
		printf("\n No hay asociados registrados.\n\n\x07");
		system("pause");
	}
	return ret;
}

void inform(structAsoc* asoc, int asocCount, structCall *calls, int callsCount){
	int x, maxCallsAsoc = 0, maxCallsIndex = -1;
	int motACVCount = 0, motFluCount = 0, motInfCount = 0, recurrentCount = 0;
	char motRecurrent[MAX_STR], tmpStr[MAX_STR];
	int promAcv = 0, promFlu = 0, promInf = 0, maxProm = 0;

	if(asocCount==0){
		printf("\n No hay registros que mostrar.\n\n\x07");
		system("pause");
		return;
	}else if(callsCount==0){
		printf("\n No hay llamadas registradas.\n\n\x07");
		system("pause");
		return;
	}else if(calls[callsCount-1].state==STATE_CURRENT){
		printf("\n Hay una emergencia en curso, primero deberia asignarle una ambulancia.\n\n\x07");
		system("pause");
		return;
	}

	system("cls");
	for(x=0; x<asocCount; x++){
		if(asoc[x].status==STATUS_ENABLED){ // si el asociado esta dado de baja, no lo evaluamos en la cuenta
			if(asoc[x].calls>maxCallsAsoc && asoc[x].calls>0){
				maxCallsAsoc = asoc[x].calls;
				maxCallsIndex = x;
			}
		}
	}
	if(maxCallsIndex!=-1){
		sprintf(tmpStr, "%s %s", asoc[maxCallsIndex].name, asoc[maxCallsIndex].lastName);
	}else{
		sprintf(tmpStr, "ninguno");
	}

	for(x=0; x<callsCount; x++){
		if(asoc[getAsocByID(asoc, asocCount, calls[x].asocID)].status==STATUS_ENABLED){ // si el asociado esta dado de baja, no lo evaluamos en la cuenta
            switch(calls[x].mot){
				case MOT_INFART:
					motInfCount++;
					promInf += calls[x].time;
					break;

				case MOT_ACV:
					motACVCount++;
					promAcv += calls[x].time;
					break;

				case MOT_FLU:
					motFluCount++;
					promFlu += calls[x].time;
					break;
            }
		}
	}

	if(motInfCount>motACVCount && motInfCount>motFluCount){              // infarto
		sprintf(motRecurrent, MOT_INFART_STR);
		recurrentCount = motInfCount;
	}else if(motACVCount>motInfCount && motACVCount>motFluCount){        // ACV
		sprintf(motRecurrent, MOT_ACV_STR);
		recurrentCount = motACVCount;
	}else if(motFluCount>motInfCount && motFluCount>motACVCount){        // gripe
		sprintf(motRecurrent, MOT_FLU_STR);
		recurrentCount = motFluCount;
	}else if(motFluCount==motInfCount && motFluCount>motACVCount){        // gripe==infarto>acv
		sprintf(motRecurrent, MOT_FLU_STR " y " MOT_INFART_STR);
		recurrentCount = motFluCount;
	}else if(motFluCount==motACVCount && motFluCount>motInfCount){        // gripe==acv>infarto
		sprintf(motRecurrent, MOT_FLU_STR " y " MOT_ACV_STR);
		recurrentCount = motFluCount;
	}else if(motInfCount==motACVCount && motInfCount>motFluCount){        // infarto==acv>gripe
		sprintf(motRecurrent, MOT_INFART_STR " y " MOT_ACV_STR);
		recurrentCount = motACVCount;
	}else if(motFluCount==0 && motInfCount==0 && motACVCount==0){        // gripe==0 infarto==0 acv==0
		sprintf(motRecurrent, "ninguno");
		recurrentCount = 0;
	}else if(motFluCount==motInfCount && motFluCount==motACVCount){        // gripe==infarto==acv
		sprintf(motRecurrent, MOT_FLU_STR ", " MOT_ACV_STR " e " MOT_INFART_STR);
		recurrentCount = motFluCount;
	}

	// Motivo que mas demora en ser resuelto en promedio
    if(motACVCount) promAcv = promAcv/motACVCount;
    if(motInfCount) promInf = promInf/motInfCount;
    if(motFluCount) promFlu = promFlu/motFluCount;

	printf("\n El asociado con mas llamadas es %s, con %d llamadas realizadas.\n", tmpStr, maxCallsAsoc );
	printf("\n El motivo de llamada mas recurrente es: %s, con %d llamadas c/u.\n", motRecurrent, recurrentCount);

    if(promAcv>promInf && promAcv>promFlu){
		sprintf(tmpStr, MOT_ACV_STR);
		maxProm = promAcv;
    }else if(promInf>promFlu && promInf>promAcv){
    	sprintf(tmpStr, MOT_INFART_STR);
    	maxProm = promInf;
    }else if(promFlu>promInf && promFlu>promAcv){
		sprintf(tmpStr, MOT_FLU_STR);
		maxProm = promFlu;
    }
	printf("\n El motivo que mas tiempo tarda en ser resuelto es: %s, con una demora promedio de %d segundos.\n\n", tmpStr, maxProm );
	system("pause");
}
