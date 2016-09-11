#ifndef DEFINES_H
#define DEFINES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 0xFF
#define MIN_MOVIE_DURATION     1
#define MAX_MOVIE_DURATION  1440
#define MIN_MOVIE_SCORE        1
#define MAX_MOVIE_SCORE      100

#define MENU_ADD             1
#define MENU_DELETE          2
#define MENU_MODIFY          3
#define MENU_GENERATE_HTML   4
#define MENU_PRINT_LIST      5

#define MENU_LIST "Ingrese una opcion:\n\n 1) Agregar pelicula\n 2) Borrar pelicula\n 3) Modificar pelicula\n 4) Generar pagina web\n 5) Imprimir lista de peliculas\n 6) Salir\n\nOpcion: "

#define FILE_MOVIE_DATA  "./movies.dat"
#define FILE_OUTPUT_HTML "./index.html"

#define HTML_FIRST_PART "<!DOCTYPE html>\n<!-- Template by Quackit.com and Fede -->\n<html lang='en'>\n<head>\n\t<meta charset='utf-8'>\n\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n\t<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n\t<title>Lista peliculas</title>\n\t<!-- Bootstrap Core CSS -->\n\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n\t<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n\t<link href='css/custom.css' rel='stylesheet'>\n\t<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n\t<!-- WARNING: Respond.js doesn't work if you view the page via file:\x2f\x2f -->\n\t<!--[if lt IE 9]>\n\t\t<script src='https:\x2f\x2foss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n\t\t<script src='https:\x2f\x2foss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n\t<![endif]-->\n</head>\n<body>\n\t<div class='container'>\n\t\t<div class='row'>\n"
#define HTML_1 "\n\n\t\t\t<!-- Repetir esto para cada pelicula -->\n\t\t\t<article class='col-md-4 article-intro'>\n\t\t\t\t<a href='#'>\n\t\t\t\t\t<img class='img-responsive img-rounded' src='"
#define HTML_2 "' alt=''>\n\t\t\t\t</a>\n\t\t\t\t<h3>\n\t\t\t\t\t<a href='#'>"
#define HTML_3 "</a>\n\t\t\t\t</h3>\n\t\t\t\t<ul>\n\t\t\t\t\t<li>"
#define HTML_4 "</li>\n\t\t\t\t\t<li>"
#define HTML_5 "</li>\n\t\t\t\t\t<li>"
#define HTML_6 "</li>\n\t\t\t\t</ul>\n\t\t\t\t<p>"
#define HTML_7 "</p>\n\t\t\t</article>\n\t\t\t<!-- Repetir esto para cada pelicula -->\n\n\n"
#define HTML_LAST_PART "\t\t</div>\n\t\t<!-- /.row -->\n\t</div>\n\t<!-- /.container -->\n\t<!-- jQuery -->\n\t<script src='js/jquery-1.11.3.min.js'></script>\n\t<!-- Bootstrap Core JavaScript -->\n\t<script src='js/bootstrap.min.js'></script>\n\t<!-- IE10 viewport bug workaround -->\n\t<script src='js/ie10-viewport-bug-workaround.js'></script>\n\t<!-- Placeholder Images -->\n\t<script src='js/holder.min.js'></script>\n</body>\n</html>"

typedef struct structMovie{
	int code;
	char title[MAX_STR_LEN];
	char genre[MAX_STR_LEN];
	int duration;
	char description[MAX_STR_LEN];
	int score;
	char linkImage[MAX_STR_LEN];
} structMovie;

#endif // DEFINES_H
