#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
* \brief Carga los datos del archivo binario de entrada en el array de estructuras
*		 asoc, devolviendo la nueva direccion de memoria al array si todo sale bien
* \param structAsoc* asoc Es un puntero a un vector de estructuras en el cual guardar
*		 los datos leídos desde el archivo binario de entrada
* \param int *asocCount Almacena la cantidad de estructuras del array, en este caso
*		 leída en el archivo de entrada
* \return structAsoc* devuelve la nueva dirección en memoria del array dinámico de
*		  estructuras, caso contrario NULL
*
*/
structAsoc* loadStructDataFromFile(structAsoc* asoc, int* asocCount);

/**
* \brief Guarda en el archivo binario de entrada/salida los datos del array de vectores
*		 para poder cargarlos en el siguiente inicio del programa
* \param structAsoc* asoc Es el vector de entrada del cual se leen los datos a
*		 guardar en el archivo de entrada/salida
* \param int asocCount es la cantidad de estructuras que tiene el vector, ya que
*		 es dinámico
* \return int devuelve ERROR en caso de error, caso contrario devuelve SUCCESS
*
*/
int saveStructToFile(structAsoc* asoc, int asocCount);


/**
* \brief Si los hay, imprime la lista de elementos del array de entrada calls, o sea, la lista de llamadas
* \param structCall *calls Es el vector a ser impreso por consola
* \param int callsCount Es la cantidad de elementos en el vector calls
* \return void
*
*/
void printCallsList(structCall *calls, int callsCount);


/**
* \brief Imprime la lista de elementos del array de entrada asoc, o la lista de asociados
* \param structAsoc *asoc Es el vector a ser impreso por consola
* \param int asocCount Es la cantidad de elementos en el vector asoc
* \return void
*
*/
void printAsocList(structAsoc* asoc, int asocCount);


/**
* \brief Devuelve en la variable de entrada *str la hora con formato HH:MM:SS
* \param char *str Es un puntero a una cadena en el cual guardar la hora actual con formato
* \return void
*
*/
void getTimeString(char *str);


/**
* \brief Devuelve el tiempo en segundos, desde el primer día del año actual...
* 		 en caso de estar en el 31 de diciembre cerca de la medianoche iniciando una llamada
*		 y asignarle una ambulancia en el siguiente año, el comportamiento es impredecible
* \param void
* \return unsigned long Devuelve el tiempo en segundos
*
*/
unsigned long getTimeInSeconds();


/**
* \brief Devuelve el indice al elemento dentro del vector asoc que coincida en
*		 miembro .id al parametro ID, si no lo encuentra retorna ERROR
* \param structAsoc *asoc Puntero a un vector de la estructura de datos con los asociados
* \param int asocCount cantidad de elementos del vector asoc
* \param int ID identificador del elemento el cual buscar en el vector asoc
* \return int Devuelve el indice al elemento del array asoc.id coincidente con ID
*
*/
int getAsocByID(structAsoc* asoc, int asocCount, int ID);


/**
* \brief Le pide al usuario el ingreso de datos por cada miembro de uso de la nueva estructura
*		 valida cada dato en cuanto a valores, máximos y mínimos y en caso de dato incorrecto
*		 vuelve a la función que la llamó devolviendo ERROR (-1)
* \param structAsoc* input array en el cual se guardan, en el último elemento,
*		 los datos ingresados por el usuario
* \param int asocCount cantidad de elementos del array input
* \return int Devuelve SUCCESS si el ingreso fue correcto, caso contrario ERROR
*
*/
int loadAsocData(structAsoc* input, int asocCount);


/**
* \brief Valida el numero de DNI pasado en el parámetro dni comparándolo dentro del
*		 vector con el miembro input.dni, en caso de una coincidencia devuelve ERROR,
*		 caso contrario SUCCESS
* \param structAsoc *input Puntero a un vector de la estructura de datos con los asociados
* \param int asocCount cantidad de elementos del vector asoc
* \param int dni valor a buscar en el vector asoc comparando la igualdad con el miembro .dni
* \return int Devuelve ERROR en caso de coincidencia, caso contrario devuelve SUCCESS
*
*/
int validateDNI(structAsoc *input, int asocCount, int dni);

/**
* \brief Muestra un menú y modifica los valores de los elementos elegidos
*		 dentro del array de entrada input y en la estructura indicada por index,
*		 si se presiona enter deja los valores actuales para ese valor
* \param structAsoc *input Array en el cual modificar un elemento(index)
* \param int index Índice el cual indica que valor modificar en el array input
* \return int Devuelve SUCCESS si se modificó algún valor, sino ERROR
*
*/
int modifyAsocData(structAsoc* input, int index);

/**
* \brief Solicita un número entero al usuario y lo valida dentro del mínimo y máximo
*		 en caso de ingreso erroneo y de tener mensaje de error, muestra el mensaje de error eMessage
* \param int *input Se guarda el número ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error, si no hay mensaje no muestra nada
* \param lowLimit Límite inferior a validar
* \param hiLimit Límite superior a validar
* \return Si obtuvo el numero SUCCESS, caso contrario devuelve ERROR
*
*/
int getInt(int* input,char *message,char *eMessage, int lowLimit, int hiLimit);

/**
* \brief Solicita un número flotante al usuario y lo valida dentro del mínimo y máximo
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error, si lo hay
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero devuelve SUCCESS, caso contrario ERROR
*
*/
int getFloat(float* input,char *message,char *eMessage, float lowLimit, float hiLimit);

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter devuelve SUCCESS, en caso contrario ERROR
*
*/
int getChar(char* input,char *message,char *eMessage, char lowLimit, char hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida dentro del tamaño mínimo y máximo
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena devuelve SUCCESS, en caso contrario ERROR
*
*/
int getString(char* input, char *message, char *eMessage, int lowLimit, int hiLimit);

/**
* \brief Muestra el menú guardado en el parámetro view y espera por la entrada
*		 de la opción elegida y la valida dentro del rango de min y max
* \param char *view Menú a ser mostrado por consola
* \param int min Valor mínimo a validar del menú
* \param int max Valor máximo a validar dentro del menú
* \return int Devuelve el número de opción elegido por el usuario, caso contrario ERROR
*/
int menu(char *view, int min, int max);

#endif // FUNCTIONS_H
