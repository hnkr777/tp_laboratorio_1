#ifndef LIB_H
#define LIB_H


/**
* \brief Agrega un nuevo elemento (asociado) al vector de estructuras asoc redimension�ndolo
* \param structAsoc *asoc es el vector en el cual se agrega el asociado
* \param int *asocCount indica la cantidad actual de elementos en el vector
* \return structAsoc* devuelve la nueva direcci�n en memoria asignada al array asoc redimensionado
* \note La estructura de la funci�n es extra�a debido a un error en tiempo de ejecuci�n que no pudo
*   	ser solucionado de otra manera, ya que se redimensiona antes de ver si el usuario
*		cancel� o no el ingreso de datos, aunque igualmente funciona bien,
*		volviendo a redimensionar el array cuando el usuario ingres� datos correctamente
*/
structAsoc* addAsoc(structAsoc* asoc, int *asocCount);


/**
* \brief Da de baja un asociado (baja l�gica) del vector, se selecciona el
*		 elemento a borrar mediante el n�mero de ID, (asoc[x].id) el cual
*		 es �nico para cada elemento del array
* \param structAsoc *asoc es el vector de registros del cual se da de baja un elemento
* \param int asocCount indica la cantidad de elementos en el vector asoc
* \return int Devuelve SUCCESS en caso de haber dado de baja correctamente un asociado,
*		  en caso contrario devuelve ERROR
*/
int disableAsoc(structAsoc* asoc, int asocCount);


/**
* \brief Valida una nueva llamada en curso, solo si hay asociados y no hay otra llamada en curso
* \param structCall *calls es el array de registros de llamadas
* \param int *callsCount indica la cantidad de elementos actuales en el array calls
* \param structAsoc *asoc es el array de registros de asociados
* \param int asocCount indica la cantidad de elementos en el array asoc
* \return structCall Devuelve la nueva direcci�n en memoria del array de entrada calls, ya redimensionado
*		  en caso de ser v�lidos los datos de llamada ingresados
*/
structCall* newCall(structCall *calls, int *callsCount, structAsoc *asoc, int asocCount);


/**
* \brief Asigna una ambulancia (ID �nico) para cada llamada en curso,
* 		 solo si hay asociados y hay una llamada en curso
* \param structCall *calls es el array de registros de llamadas
* \param int *callsCount indica la cantidad de elementos actuales en el array calls
* \param structAsoc *asoc es el array de registros de asociados
* \param int asocCount indica la cantidad de elementos en el array asoc
* \return int Devuelve la SUCCESS si pudo asignar una ambulancia exitosamente,
*		  en caso contrario devuelve ERROR
*/
int asignAmbulance(structCall *calls, int callsCount, structAsoc *asoc, int asocCount);



/**
* \brief Evalua si dentro del array calls hay un elemento en el que su miembro
*		 .ambulanceID coincida con el par�metro id, si lo encuentra retorna SUCCESS
* \param structCall *calls Puntero a un vector de estructura de datos con las llamadas
* \param int callsCount cantidad de elementos del vector calls
* \param int ID identificador del elemento el cual buscar en el vector asoc
* \return int Devuelve SUCCESS si el id del par�metro existe dentro del vector calls
*		  caso contrario devuelve ERROR
*
*/
int existAmbulanceByID(structCall *calls, int callsCount, int id);


/**
* \brief Modifica los datos de un elemento del array asoc, determinando el elemento
*		 por su ID (asoc.id) y en caso de no existir lo indica
* \param structAsoc *asoc es el array en el cual modificar los datos de un elemento del mismo
* \param int asocCount es la cantidad de elementos en el array asoc
* \return int Devuelve SUCCESS en caso de haberse modificado alg�n dato, caso contrario ERROR
*
*/
int modifyAsoc(structAsoc* asoc, int asocCount);


/**
* \brief Muestra un informe por pantalla de todos los datos requeridos seg�n la
* 		 consigna, ya que es un requerimiento tan espec�fico se opt� por dejar todo
*		 junto en la misma funci�n...
* \param structAsoc *asoc es el array de registros de asociados
* \param int asocCount indica la cantidad de elementos en el array asoc
* \param structCall *calls es el array de registros de llamadas
* \param int *callsCount indica la cantidad de elementos actuales en el array calls
* \return void
*
*/
void inform(structAsoc* asoc, int asocCount, structCall *calls, int callsCount);


#endif // LIB_H
