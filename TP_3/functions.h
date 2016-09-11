#ifndef FUNCTIONS_H
#define FUNCTIONS_H


/**
* \brief Crea un archivo HTML a trav�s del vector structMovie pasado como par�metro
*		 guardando los datos de cada pelicula en el archivo de manera que puedan
*		 visualizarse correctamente
* \param structMovie movie es un puntero a un vector de estructuras el cual guarda
*		 el contenido de las peliculas ingresadas anteriormente
* \param int movieCount indica la cantidad de peliculas guardadas por el array de estructuras
*		 movie
* \param char* outputFile es un vector de char (cadena) el cual guarda el nombre del
*		 archivo de salida HTML en donde guardar los datos del array movie
* \return int Devuelve 1 si todo salio correctamente, en caso de no poder crearse
*		  el archivo de salida HTML devuelve -1
*
*/
int generateHTML(structMovie* movie, int movieCount, char* outputFile);


/**
* \brief Carga los datos del archivo binario de entrada en el array de estructuras
*		 movie, devolviendo la nueva direccion de memoria al array si todo sale bien
* \param structMovie* movie movie es un puntero a un vector de estructuras en el cual guardar
*		 los datos le�dos desde el archivo binario de entrada
* \param int *movieCount almacena la cantidad de estructuras del array, en este caso
*		 le�da en el archivo de entrada
* \return structMovie* devuelve la nueva direcci�n en memoria del array din�mico de
*		  estructuras
*
*/
structMovie* loadMovieFile(structMovie* movie, int* movieCount);


/**
* \brief Guarda en el archivo binario de entrada/salida los datos del array de vectores
*		 para poder cargarlos en el siguiente inicio del programa
* \param structMovie* movie Es el vector de entrada del cual se leen los datos a
*		 guardar en el archivo de entrada/salida
* \param int movieCount es la cantidad de estructuras que tiene el vector, ya que
*		 es din�mico
* \return int devuelve 1 si se pudo abrir el archivo, caso contrario devuelve 0
*
*/
int saveMovieFile(structMovie* movie, int movieCount);

/**
* \brief Agrega una pelicula (datos) al vector estructura y lo redimensiona
* \param structMovie *movie es el vector en el cual se agrega la pelicula
* \param int movieCount es la cantidad de peliculas en el vector
* \return structMovie* devuelve la nueva direcci�n en memoria al array movie redimensionado
*
*/
structMovie* addMovie(structMovie* movie, int movieCount);

/**
* \brief Borra una persona (datos del registro) del vector, se selecciona el
*		 elemento a borrar mediante el n�mero de c�digo, (movie[x].code) el cual
*		 es �nico para cada elemento del array
* \param structMovie *movie es el vector de registros del cual se borra un elemento
* \param int movieCount indica la cantidad de elementos en el vector movie
* \return int si se pudo eliminar el elemento retorna 1,
*		  en caso contrario retorna 0
*/
int deleteMovie(structMovie* movie, int movieCount);

/**
* \brief Setea los valores del elemento indicado por el argumento index a los
*		 valores por defecto, en el vector de estructuras de entrada movie
* \param structMovie *movie vector del cual borrar el elemento indicado por index
* \param int movieCount cantidad de elementos en el vector movie
* \param int index variable de entrada que indica qu� elemento borrar
* \return void
*
*/
void resetMovie(structMovie* movie, int movieCount, int index);

/**
* \brief Modifica los datos de un elemento del array movie, determinando el elemento
*		 por su c�digo (movie[x].code) y en caso de no existir lo indica
* \param structMovie *movie es el array en el cual modificar los datos de un elemento del mismo
* \param int movieCount es la cantidad de elementos en el array movie
* \return void
*
*/
void modifyMovie(structMovie* movie, int movieCount);

/**
* \brief Imprime la lista de elementos del array de entrada movie
* \param structMovie *movie Es el vector a ser impreso por consola
* \param int movieCount Es la cantidad de elementos en el vector movie
* \return void
*
*/
void printMovieList(structMovie* movie, int movieCount);

/**
* \brief Le pide al usuario el ingreso de datos por cada miembro de la nueva estructura
*		 agregada al vector movie, valida el ingreso del puntaje y la duraci�n con m�ximos y m�nimos
* \param structMovie* input array en el cual se guardan, en el �ltimo elemento,
*		 los datos ingresados por el usuario
* \param int movieCount cantidad de elementos del array input
* \return void
*
*/
void loadMovieData(structMovie* input, int movieCount);

/**
* \brief Compacta el vector de entrada, dejando los elementos vac�os al final
* \param structMovie* movie array a compactar
* \param int movieCount cantidad de elementos en el array movie
* \return void
*
*/
void compactMovieList(structMovie* movie, int movieCount);


/**
* \brief Devuelve el primer c�digo de pelicula sin usar disponible empezando por 1
* \param structMovie* movie array en el cual verificar los c�digos de pel�culas
* \param int movieCount cantidad de elementos en el array movie
* \return int devuelve el primer (valor m�s bajo empezando por 1) c�digo sin usar
*		  encontrado en el array movie
*
*/
int getFirstCode(structMovie* movie, int movieCount);

/**
* \brief Modifica los valores en cada elemento de la estructura indicada por index,
*		 si se ingresa 0 (cero) deja los valores actuales para ese valor
* \param structMovie* input Array en el cual modificar un valor
* \param int index �ndice el cual indica que valor modificar en el array movie
* \return void
*
*/
void modifyMovieData(structMovie* input, int index);

#endif // FUNCTIONS_H
