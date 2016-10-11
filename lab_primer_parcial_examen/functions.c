
#include "defines.h"
#include "functions.h"
#include "lib.h"

structAsoc* loadStructDataFromFile(structAsoc* asoc, int* asocCount){
	FILE* asocFile;
	int size, x;

	asocFile = fopen(FILE_ASOC_DATA, "r");
	if(asocFile==NULL){
		printf("\n No existe el archivo %s.\n\n", FILE_ASOC_DATA);
		system("pause");
		return asoc;
	}

	fseek(asocFile, 0, SEEK_END);
	size = ftell(asocFile);
	(*asocCount) = size / sizeof(structAsoc);
	fseek(asocFile, 0, SEEK_SET);
	asoc = (structAsoc*) realloc(asoc, sizeof(structAsoc) * (*asocCount));

	if(asoc==NULL){
		printf("\n Error: no se pudo reservar memoria.\n");
		system("pause");
		return asoc; // return NULL;
	}

	for(x=0; x<(*asocCount); x++){ // se lee registro por registro para posibles modificaciones en el futuro...
		fread(&asoc[x], sizeof(structAsoc), 1, asocFile);
        asoc[x].calls = 0; // atencion aca, reseteamos las llamadas
	}
	fclose(asocFile);

	return asoc;
}

int saveStructToFile(structAsoc* asoc, int asocCount){
	FILE* asocFile;
	int ret = ERROR;

	asocFile = fopen(FILE_ASOC_DATA, "w");
	if(asocFile==NULL){
		printf("\n No se pudo guardar el archivo %s.\n\n\x07", FILE_ASOC_DATA);
		system("pause");
	}else{
		fwrite(asoc, sizeof(structAsoc), asocCount, asocFile);
		ret = SUCCESS;
	}
	fclose(asocFile);

	return ret;
}

void printCallsList(structCall *calls, int callsCount){
	int x;

	if(callsCount==0){
		printf("\n No hay llamadas que mostrar.\n\n\x07");
		system("pause");
		return;
	}

	system("cls");
	printf("\n Lista de llamadas:\n");

	for(x=0; x<callsCount; x++){
		printf("\n  ID de llamada = %d\n", calls[x].id ); // el miembro no se usa pero se deja para futuros usos
		printf("  ID de asociado que llamo = %d\n", calls[x].asocID );
		printf("  ID de ambulancia asignada = %d\n", calls[x].state==STATE_ACCOMPLISHED?calls[x].ambulanceID:0 );
		printf("  Motivo de la llamada = %s\n", calls[x].mot==MOT_ACV?MOT_ACV_STR:(calls[x].mot==MOT_FLU?MOT_FLU_STR:(calls[x].mot==MOT_INFART?MOT_INFART_STR:"")));
		printf("  Estado de la llamada = %s\n", calls[x].state==STATE_ACCOMPLISHED?STATE_ACCOMPLISHED_STR:(calls[x].state==STATE_CURRENT?STATE_CURRENT_STR:""));
		printf("  Tiempo en segundos = %lu\n", calls[x].state==STATE_ACCOMPLISHED?calls[x].time:0 );
	}

	printf("\n");
	system("pause");
}

void printAsocList(structAsoc* asoc, int asocCount){
	int x;
	if(asocCount>0){
		system("cls");
		printf(" Lista de asociados:\n");
		for(x=0; x<asocCount; x++){
			printf("\n *ID de asociado: %d\n", asoc[x].id);
			printf("  Nombre y apellido: %s %s\n", asoc[x].name, asoc[x].lastName);
			printf("  DNI: %d\n", asoc[x].dni);
			printf("  Edad: %d\n", asoc[x].age);
			printf("  Estado: %s\n", asoc[x].status==STATUS_ENABLED?"ACTIVO":"INHABILITADO");
			printf("  Cantidad de llamadas: %d\n", asoc[x].calls);
		}
	}else{
		printf("\n No hay registros que mostrar.\n\x07");
	}
	printf("\n");
	system("pause");
}

void getTimeString(char *str){
	time_t currentTime;
	struct tm *timeVar;
	char ret[MAX_STR];

	time(&currentTime);
	timeVar = localtime(&currentTime);

	if(timeVar->tm_hour<10){
		sprintf(ret, "0%d", timeVar->tm_hour);
	}else{
		sprintf(ret, "%d", timeVar->tm_hour);
	}

	if(timeVar->tm_min<10){
		sprintf(ret, "%s:0%d", ret, timeVar->tm_min);
	}else{
		sprintf(ret, "%s:%d", ret, timeVar->tm_min);
	}

	if(timeVar->tm_sec<10){
		sprintf(ret, "%s:0%d", ret, timeVar->tm_sec);
	}else{
		sprintf(ret, "%s:%d", ret, timeVar->tm_sec);
	}
	strcpy(str, ret);
}

unsigned long getTimeInSeconds(){
	time_t currentTime;
	struct tm *timeVar;

	time(&currentTime);
	timeVar = localtime(&currentTime);

	return timeVar->tm_yday*86400 + timeVar->tm_hour*3600 + timeVar->tm_min*60 + timeVar->tm_sec;
}

int getAsocByID(structAsoc* asoc, int asocCount, int ID){
    int x, ret = ERROR;

    for(x=0; x<asocCount; x++){
        if(asoc[x].id==ID){
			ret = x;
			break;
        }
    }
    return ret;
}

int loadAsocData(structAsoc *input, int asocCount){
	char tmp[MAX_STR];
	int ret = ERROR, tmpInt = 0;

	system("cls");
	if(getString(tmp, "\nAlta del asociado:\n\n Ingrese el nombre: ", " Nombre invalido.\n\x07", 1, 255)==ERROR){
		return ret;
	}
	strcpy(input[asocCount-1].name, tmp);

	if(getString(tmp, " Ingrese el apellido: ", " Apellido invalido.\n\x07", 1, 255)==ERROR){
		return ret;
	}
	strcpy(input[asocCount-1].lastName, tmp);

	if(getInt(&tmpInt, " Ingrese el DNI: ", " Numero de DNI invalido.\n\x07", MIN_DNI_VALUE, MAX_DNI_VALUE)==ERROR){
		return ret;
	}
	if(validateDNI(input, asocCount, tmpInt)==SUCCESS){
		input[asocCount-1].dni = tmpInt;
	}else{
		printf("\n El DNI numero %d ya fue ingresado.\n\n\x07", tmpInt);
		system("pause");
		return ret;
	}

	if(getInt(&tmpInt, " Ingrese la edad (entre 1 y 150): ", " Edad invalida.\n\x07", MIN_ASOC_AGE, MAX_ASOC_AGE)==ERROR){
		return ret;
	}
	input[asocCount-1].age = tmpInt;

	input[asocCount-1].id = asocCount;
	input[asocCount-1].status = STATUS_ENABLED;
	input[asocCount-1].calls = 0;

	return SUCCESS;
}

int validateDNI(structAsoc *input, int asocCount, int dni){
	int x, ret = SUCCESS;

	for(x=0; x<asocCount; x++){
		if(input[x].dni==dni){
            ret = ERROR;
            break;
		}
	}

	return ret;
}

int modifyAsocData(structAsoc* input, int index){
	char tmp[MAX_STR];
	int ret = ERROR, option = 0;

	do{
		option = menu(MODIF_MENU_LIST, MODIF_MENU_NAME, MODIF_MENU_EXIT);
		switch(option){
			case MODIF_MENU_NAME:
				sprintf(tmp, "  Nombre actual: %s\n  Ingrese el nuevo nombre: ", input[index].name);
				if(getString(tmp, tmp, " Nombre invalido.\n", 1, MAX_STR)==0 && (strcmp(tmp, "")!=0)){
					strcpy(input[index].name, tmp);
					ret = SUCCESS;
					printf("\n El nombre ha sido modificado.\n\n");
					system("pause");
				}
				break;

			case MODIF_MENU_LAST_NAME:
				sprintf(tmp, "  Apellido actual: %s\n  Ingrese el nuevo apellido: ", input[index].lastName);
				if(getString(tmp, tmp, " Apellido invalido.\n", 1, MAX_STR)==0 && (strcmp(tmp, "")!=0)){
					strcpy(input[index].lastName, tmp);
					ret = SUCCESS;
					printf("\n El apellido ha sido modificado.\n\n");
					system("pause");
				}
				break;

			case MODIF_MENU_EXIT:
				break;

			default:
				printf("\n Numero de opcion incorrecta.\x07\n\n");
				system("pause");
		}
	} while(option!=MODIF_MENU_EXIT);

	return ret;
}

int getInt(int *input, char *message, char *eMessage, int lowLimit, int hiLimit){
    char buff[MAX_STR];
    int out, ret = ERROR;

	printf("%s", message);
	scanf("%s", buff);
	out = atoi(buff);

	if(out>=lowLimit && out<=hiLimit){
		(*input) = out;
        ret = SUCCESS;
	}else{
		if(strcmp(eMessage, "")!=0){
			printf("\n%s\n\n\x07", eMessage);
			system("pause");
		}
	}
    return ret;
}

int getFloat(float* input, char *message, char *eMessage, float lowLimit, float hiLimit){
    char buff[MAX_STR];
    int ret = ERROR;
    float number;

	printf("%s", message);
	scanf("%s", buff);
	number = atof(buff);

	if(ret==0 && number>=lowLimit && number<=hiLimit){
		(*input) = number;
		ret = SUCCESS;
	}else{
		if(strcmp(eMessage, "")!=0){
			printf("\n%s\n\n\x07", eMessage);
			system("pause");
		}
	}

    return ret;
}

int getChar(char* input,char *message,char *eMessage, char lowLimit, char hiLimit){
    char buff[MAX_STR];
    int ret = ERROR;
    char chr;

	printf("%s", message);
	scanf("%s", buff);
	chr = buff[0];

	if(strlen(buff)>1 || isalpha(chr)==0 || !(chr>=lowLimit && chr<=hiLimit)){
		printf("\n%s\n\x07", eMessage);
		system("pause");
	}else{
		(*input) = chr;
		ret = SUCCESS;
	}

    return ret;
}

int getString(char* input, char *message, char *eMessage, int lowLimit, int hiLimit){
    char buff[MAX_STR];
    int size, ret = ERROR;

	printf("%s", message);
	fflush(stdin);
	gets(buff);
	fflush(stdin);
	size = strlen(buff);

	if(size>=lowLimit && size<=hiLimit){
		strcpy(input, buff);
		ret = SUCCESS;
	}else{
		printf("\n%s\n\x07", eMessage);
		system("pause");
	}

    return ret;
}

int menu(char *view, int min, int max){
	int menuOption = ERROR;

	system("cls");
	printf(view);
	getInt(&menuOption, "", "", min, max );

	return menuOption;
}
