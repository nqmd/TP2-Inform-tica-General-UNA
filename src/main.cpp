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
	wattron(wmenu, A_BOLD);
	mvwprintw(wmenu, 3, 26, "JUGAR");
	mvwprintw(wmenu, 6, 22, "INSTRUCCIONES");
	mvwprintw(wmenu, 9, 26, "SALIR");
	wattron(wmenu, A_BLINK);
	mvwprintw(wmenu, 13, 2, "Presiona la primer letra de la opción que desees");

	char letra;

	while (letra = wgetch(wmenu))
	{
		switch (letra)
		{
		case 'j':
			wclear(wmenu);
			wattroff(wmenu, A_BLINK);
			mvwprintw(wmenu, 7, 22, "Ya estás Jugando");
			box(wmenu, 0, 0);
			break;

		case 'J':
			wclear(wmenu);
			wattroff(wmenu, A_BLINK);
			mvwprintw(wmenu, 7, 22, "Ya estás Jugando");
			box(wmenu, 0, 0);
			break;

		case 'i':
			wclear(wmenu);
			wattroff(wmenu, A_BLINK);
			box(wmenu, 0, 0);
			wattroff(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 0, 4, "JUGAR");
			mvwprintw(wmenu, 0, 49, "SALIR");
			wattron(wmenu, A_BLINK);
			wattron(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 0, 25, "INSTRUCCIONES");
			break;

		case 'I':
			wclear(wmenu);
			wattroff(wmenu, A_BLINK);
			box(wmenu, 0, 0);
			wattroff(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 0, 4, "JUGAR");
			mvwprintw(wmenu, 0, 49, "SALIR");
			wattron(wmenu, A_BLINK);
			wattron(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 0, 25, "INSTRUCCIONES");
			break;

		case 's':
			werase(wmenu);
			endwin();
			exit(EXIT_SUCCESS);
			break;

		case 'S':
			werase(wmenu);
			endwin();
			exit(EXIT_SUCCESS);
			break;

		default:
			wattron(wmenu, A_BLINK);
			wattron(wmenu, A_BOLD);
			mvwprintw(wmenu, 4, 26, "JUGAR");
			mvwprintw(wmenu, 7, 22, "INSTRUCCIONES");
			mvwprintw(wmenu, 10, 26, "SALIR");
			break;
		}
	}
}
