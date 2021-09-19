//Joshua Frías

#include <iostream>
#include <ctime>
#include <string>
#include <ncurses.h>
#include <vector>

using namespace std;

// Variables globales
bool finJuego;
int yMax, xMax;

// Declaración de Funciones
void intro();
void pantallaInicio();

int main()
{

	initscr();
	noecho();
	curs_set(0);
	getmaxyx(stdscr, yMax, xMax);

	pantallaInicio();

	endwin();
	return 0;
}

void pantallaInicio()
{

	WINDOW *wmenu = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);

	box(wmenu, 0, 0);

	//Firmas
	wattron(wmenu, A_DIM);
	mvwprintw(wmenu, 0, 5, "IG II");
	mvwprintw(wmenu, 19, 30, "Made by Icarus Black Magic");

	//Opciones
	wattron(wmenu, A_BLINK);
	wattron(wmenu, A_BOLD);
	mvwprintw(wmenu, 7, 26, "JUGAR");
	mvwprintw(wmenu, 9, 22, "INSTRUCCIONES");
	mvwprintw(wmenu, 11, 26, "SALIR");

	char letra;

	while (letra = wgetch(wmenu))
	{
		switch (letra)
		{
		case 'j':
			wattron(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 7, 26, "JUGAR");
			wattroff(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 9, 22, "INSTRUCCIONES");
			mvwprintw(wmenu, 11, 26, "SALIR");
			break;

		case 'i':
			wattron(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 9, 22, "INSTRUCCIONES");
			wattroff(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 7, 26, "JUGAR");
			mvwprintw(wmenu, 11, 26, "SALIR");
			break;

		case 's':
			werase(wmenu);
			endwin();
			exit(EXIT_SUCCESS);
			break;

		default:
			wattron(wmenu, A_BLINK);
			wattron(wmenu, A_BOLD);
			mvwprintw(wmenu, 7, 26, "JUGAR");
			mvwprintw(wmenu, 9, 22, "INSTRUCCIONES");
			mvwprintw(wmenu, 11, 26, "SALIR");
			break;
		}
	}
}
