#include <iostream>
#include <ctime>
#include <string>
#include <ncurses.h>
#include <vector>

using namespace std;

// Variables globales
bool finJuego;
int ancho = 120;
int alto = 40;

// Declaración de Funciones
void pantallaInicio();

int main()
{

	initscr();
	pantallaInicio();	
	endwin();
	return 0;
}

void pantallaInicio()
{
	WINDOW * win = newwin(40,120,0,0);
	refresh();
	box(win, 0, 0);
	mvwprintw(win, 10, 35, "Llora una vez, pero no llores dos veces;");
	mvwprintw(win, 11, 35, "tus primeras lágrimas me regalan un río que cruzar,");
	mvwprintw(win, 12, 35, "pero las siguientes provocan tormentas imposibles de salvar...");
	mvwprintw(win, 13, 35, "Llora una vez, pero no llores dos;");
	mvwprintw(win, 14, 35, "te prometo ser feliz allá donde voy.");
	mvwprintw(win, 16, 80, "-Crónicas del Mictlán");
	wrefresh(win);
	
	refresh();
	getch();
}