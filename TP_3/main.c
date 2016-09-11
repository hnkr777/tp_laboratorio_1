
/*
Trabajo práctico Nº 3

Autor: Federico Adolfo Honeker
Fecha: 07 de Septiembre de 2016
*/

#include "defines.h"
#include "main.h"
#include "functions.h"

int main(int args, char** argsv){
	int option = 0;
	int movieCount = 0;
	structMovie *movie = NULL;

	movie = loadMovieFile(movie, &movieCount);

	do{
		option = menu();

		switch(option){
            case MENU_ADD:
            	movieCount++;
				movie = addMovie(movie, movieCount);
				saveMovieFile(movie, movieCount); // se puede guardar al archivo aca o al final del main
                break;

            case MENU_DELETE:
                if(movieCount>0){
					if(deleteMovie(movie, movieCount)==1){
						movieCount--;
						movie = (structMovie*) realloc(movie, sizeof(structMovie) * movieCount);
						saveMovieFile(movie, movieCount);
					}
                }else{
                	printf("\n No hay peliculas registradas.\n\n");
                	system("pause");
                }
                break;

            case MENU_MODIFY:
				if(movieCount>0){
					modifyMovie(movie, movieCount);
					saveMovieFile(movie, movieCount);
                }else{
                	printf("\n No hay peliculas registradas.\n\n");
                	system("pause");
                }
                break;

            case MENU_GENERATE_HTML:
                if(generateHTML(movie, movieCount, FILE_OUTPUT_HTML)==1){
					printf("\n Archivo %s generado.\n\n", FILE_OUTPUT_HTML);
                	system("pause");
                }
                break;

			case MENU_PRINT_LIST:
                printMovieList(movie, movieCount);
                system("pause");
                break;
        }
    } while(option!=6);

	saveMovieFile(movie, movieCount); // se guarda al final o antes para evitar la perdida de datos ingresados
	free(movie);
	movie = NULL;
    return 0;
}

int menu(void){
	char tmp[MAX_STR_LEN]; // vector temporal donde almacenar la entrada por teclado

	system("cls");
	printf(MENU_LIST);
	scanf("%3s", tmp);

	if(isdigit(tmp[0])){
		return atoi(&tmp[0]);
	}else{
		return 0;
	}
}
