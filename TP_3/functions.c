
#include "defines.h"
#include "functions.h"

int generateHTML(structMovie* movie, int movieCount, char* outputFile){
	FILE *fileHTML;
	int x;

	fileHTML = fopen(outputFile, "w");
	if(fileHTML==NULL){
		printf("\n Error creando el archivo %s", outputFile);
		system("pause");
		return -1;
	}

	fprintf(fileHTML, "%s", HTML_FIRST_PART);

	for(x=0; x<movieCount; x++){
		fprintf(fileHTML, "%s", HTML_1);
		fprintf(fileHTML, "%s", movie[x].linkImage);
		fprintf(fileHTML, "%s", HTML_2);
		fprintf(fileHTML, "%s", movie[x].title);
		fprintf(fileHTML, "%s", HTML_3);
		fprintf(fileHTML, "%s", movie[x].genre);
		fprintf(fileHTML, "%s", HTML_4);
		fprintf(fileHTML, "%d", movie[x].score);
		fprintf(fileHTML, "%s", HTML_5);
		fprintf(fileHTML, "%d", movie[x].duration);
		fprintf(fileHTML, "%s", HTML_6);
		fprintf(fileHTML, "%s", movie[x].description);
		fprintf(fileHTML, "%s", HTML_7);
	}

	fprintf(fileHTML, "%s", HTML_LAST_PART);
	fclose(fileHTML);

	return 1;
}

structMovie* loadMovieFile(structMovie* movie, int* movieCount){
	FILE* movieFile;
	int size, x;

	movieFile = fopen(FILE_MOVIE_DATA, "r");
	if(movieFile==NULL){
		printf("\n No existe el archivo %s.\n\n", FILE_MOVIE_DATA);
		system("pause");
		return NULL;
	}

	fseek(movieFile, 0, SEEK_END);
	size = ftell(movieFile);
	(*movieCount) = size / sizeof(structMovie);
	fseek(movieFile, 0, SEEK_SET);
	movie = (structMovie*) realloc(movie, sizeof(structMovie) * (*movieCount));

	if(movie==NULL){
		printf("\n Error: no se pudo reservar memoria.\n");
		system("pause");
		return NULL;
	}

	for(x=0; x<(*movieCount); x++){
		fread(&movie[x], sizeof(structMovie), 1, movieFile);
	}

	return movie;
}

int saveMovieFile(structMovie* movie, int movieCount){
	FILE* movieFile;

	movieFile = fopen(FILE_MOVIE_DATA, "w");
	if(movieFile==NULL){
		printf("\n No se pudo guardar el archivo %s.\n\n", FILE_MOVIE_DATA);
		system("pause");
		return 0;
	}
	fwrite(movie, sizeof(structMovie), movieCount, movieFile);
	return 1;
}

structMovie* addMovie(structMovie* movie, int movieCount){
	movie = (structMovie*) realloc(movie, sizeof(structMovie) * movieCount);

	if(movie==NULL){
		printf("\nNo se pudo reservar memoria.\n");
		system("pause");
	}else{
		loadMovieData(movie, movieCount);
	}
	return movie;
}

int deleteMovie(structMovie* movie, int movieCount){
	int del, x;
	int ret = 0;

	system("cls");
	printf("\nBorrar pelicula:\n\n Ingrese el numero de codigo a borrar: ");
	scanf("%6d", &del);
	fflush(stdin);

	for(x=0; x<movieCount; x++){
		if(del==movie[x].code){
			movie[x].code = 0;
			resetMovie(movie, movieCount, x);
			ret = 1;
			compactMovieList(movie, movieCount);
			printf("\n Pelicula no. %d borrada.\n\n", del);
			system("pause");
		}
	}

	if(ret==0){
		ret = 0;
		printf("\n Numero de codigo invalido.\n\n");
		system("pause");
	}

	return ret;
}

void resetMovie(structMovie* movie, int movieCount, int index){
	strcpy(movie[index].title, "\0");
	strcpy(movie[index].genre, "\0");
	strcpy(movie[index].description, "\0");
	strcpy(movie[index].linkImage, "\0");
	movie[index].score = 0;
	movie[index].duration = 0;
	movie[index].code = 0;
}

void modifyMovie(structMovie* movie, int movieCount){
	int del, x, ret = 0;

	system("cls");
	printf("\n Modificar pelicula:\n\n Ingrese el numero de codigo a modificar: ");
	scanf("%6d", &del);
	fflush(stdin);

	for(x=0; x<movieCount; x++){
		if(del==movie[x].code){
			ret = 1;
			printf("\n  Codigo: %d\n", movie[x].code);
			printf("  Modifique los datos, cero para dejar los actuales:\n");
			modifyMovieData(movie, x);
		}
	}

	if(ret==0){
		ret = 0;
		printf("\n Numero de codigo invalido.\n\n");
		system("pause");
	}
}

void printMovieList(structMovie* movie, int movieCount){
	int x;

	system("cls");
	for(x=0; x<movieCount; x++){
		printf("\n Registro no. %d\n", x+1);
		printf(" *Codigo: %d\n", movie[x].code);
		printf("  Titulo: %s\n", movie[x].title);
		printf("  Genero: %s\n", movie[x].genre);
		printf("  Descripcion: %s\n", movie[x].description);
		printf("  Duracion: %d\n", movie[x].duration);
		printf("  Puntaje: %d\n", movie[x].score);
		printf("  Link de la imagen: %s\n", movie[x].linkImage);
	}
}

void loadMovieData(structMovie* input, int movieCount){
	char tmp[MAX_STR_LEN];

	system("cls");
	printf("\nAgregar pelicula:\n\n Ingrese el titulo: ");
    fflush(stdin);
	gets(tmp);
	strcpy(input[movieCount-1].title, tmp); // strcpy((input+movieCount-1)->title, tmp);

	printf(" Ingrese el genero: ");
	fflush(stdin);
	gets(tmp);
	strcpy(input[movieCount-1].genre, tmp);

	printf(" Ingrese la descripcion: ");
	fflush(stdin);
	gets(tmp);
	strcpy(input[movieCount-1].description, tmp);

	printf(" Ingrese el link a la imagen: ");
	fflush(stdin);
	gets(tmp);
	strcpy(input[movieCount-1].linkImage, tmp);

	do{
		printf(" Ingrese la duracion en minutos: ");
		scanf("%4d", &input[movieCount-1].duration);
		fflush(stdin);
	} while(input[movieCount-1].duration>MAX_MOVIE_DURATION || input[movieCount-1].duration<MIN_MOVIE_DURATION);

	do{
		printf(" Ingrese el puntaje (entre 1 y 100): ");
		scanf("%3d", &input[movieCount-1].score);
		fflush(stdin);
	} while(input[movieCount-1].score<MIN_MOVIE_SCORE || input[movieCount-1].score>MAX_MOVIE_SCORE);

	input[movieCount-1].code = getFirstCode(input, movieCount);
	system("pause");
}

int getFirstCode(structMovie* movie, int movieCount){
    int x, ret = 1;

    for(x=0; x<movieCount; x++){
        if(movie[x].code==ret){
			ret++;
			x=-1;
        }
    }
    return ret;
}

void compactMovieList(structMovie* movie, int movieCount){
	int x, y;  // variables de control de los bucles for
	structMovie tmp;  // estructura de almacen temporal

	for(x=0; x < (movieCount-1); x++){
		for(y=(x+1); y<movieCount; y++){
			if(movie[x].code==0 && movie[y].code>0){
				tmp = movie[x];
				movie[x] = movie[y];
				movie[y] = tmp;
			}
		}
	}
}

void modifyMovieData(structMovie* input, int index){
	char tmp[MAX_STR_LEN];
	int tmpInt;

	printf("  Titulo: %s\n", input[index].title);
	printf("  Ingrese el nuevo titulo: ");
    fflush(stdin);
	gets(tmp);
	if(strcmp(tmp, "0")!=0)
		strcpy(input[index].title, tmp);

	printf("\n  Genero: %s\n", input[index].genre);
	printf("  Ingrese el genero: ");
	fflush(stdin);
	gets(tmp);
	if(strcmp(tmp, "0")!=0)
		strcpy(input[index].genre, tmp);

	printf("\n  Descripcion: %s\n", input[index].description);
	printf("  Ingrese la descripcion: ");
	fflush(stdin);
	gets(tmp);
	if(strcmp(tmp, "0")!=0)
		strcpy(input[index].description, tmp);

	printf("\n  Link de la imagen: %s\n", input[index].linkImage);
	printf("  Ingrese el link a la imagen: ");
	fflush(stdin);
	gets(tmp);
	if(strcmp(tmp, "0")!=0)
		strcpy(input[index].linkImage, tmp);

	do{
		printf("\n  Duracion: %d\n", input[index].duration);
		printf("  Ingrese la duracion en minutos: ");
		scanf("%4d", &tmpInt);
		fflush(stdin);
		if(tmpInt!=0)
			input[index].duration = tmpInt;
	} while(input[index].duration>1440 || input[index].duration<1);

	do{
		printf("\n  Puntaje: %d\n", input[index].score);
		printf("  Ingrese el puntaje (entre 1 y 100): ");
		scanf("%3d", &tmpInt);
		fflush(stdin);
		if(tmpInt!=0)
			input[index].score = tmpInt;
	} while(input[index].score<1 || input[index].score>100);

	printf("\n Pelicula modificada.\n\n");
	system("pause");
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
