//Joshua Frías

#include <iostream>
#include <ctime>
#include <string>
#include <ncurses.h>
#include <vector>

using namespace std;

// Variables globales
bool finJuego;
bool initjuego;
int yMax, xMax;

// Declaración de Funciones
void intro();
void pantallaInicio();
void juego();
void inventario();

int main()
{
	initscr();

	noecho();
	curs_set(0);

	//Definicion de colores
	start_color();
	init_extended_color;

	//Fondo negro
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_BLUE, COLOR_BLACK);

	//Fondo blanco
	init_pair(8, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(9, COLOR_RED, COLOR_WHITE);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(11, COLOR_CYAN, COLOR_WHITE);
	init_pair(12, COLOR_GREEN, COLOR_WHITE);
	init_pair(13, COLOR_YELLOW, COLOR_WHITE);
	init_pair(14, COLOR_BLUE, COLOR_WHITE);

	//Fondo amarillo
	init_pair(15, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(16, COLOR_RED, COLOR_YELLOW);
	init_pair(17, COLOR_BLACK, COLOR_YELLOW);
	init_pair(18, COLOR_CYAN, COLOR_YELLOW);
	init_pair(19, COLOR_GREEN, COLOR_YELLOW);
	init_pair(20, COLOR_WHITE, COLOR_YELLOW);
	init_pair(21, COLOR_BLUE, COLOR_YELLOW);

	//Fondo azul
	init_pair(22, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(23, COLOR_RED, COLOR_BLUE);
	init_pair(24, COLOR_BLACK, COLOR_BLUE);
	init_pair(25, COLOR_CYAN, COLOR_BLUE);
	init_pair(26, COLOR_GREEN, COLOR_BLUE);
	init_pair(27, COLOR_WHITE, COLOR_BLUE);
	init_pair(28, COLOR_YELLOW, COLOR_BLUE);
	//Definición de pantalla modular
	getmaxyx(stdscr, yMax, xMax);

	//Funciones
	intro();
	pantallaInicio();
	endwin();
	return 0;
}

void intro()
{
	WINDOW *introw = newwin(yMax, xMax, yMax, xMax);
	//clear(introw);
	
	attron(A_STANDOUT);
	attron(COLOR_PAIR(24));
	mvprintw(15, 10, R"( __   __  __   __  ___  _______  _______  ___  ___       _______  _______  __   __  ___     
          |  | |  ||  | |  ||   ||       ||       ||   ||   |     |   _   ||       ||  | |  ||   |    
          |  |_|  ||  | |  ||   ||_     _||____   ||   ||   |     |  |_|  ||____   ||  | |  ||   |    
          |       ||  |_|  ||   |  |   |   ____|  ||   ||   |     |       | ____|  ||  |_|  ||   |    
          |       ||       ||   |  |   |  | ______||   ||   |___  |       || ______||       ||   |___ 
          |   _   ||       ||   |  |   |  | |_____ |   ||       | |   _   || |_____ |       ||       |
          |__| |__||_______||___|  |___|  |_______||___||_______| |__| |__||_______||_______||_______|)");
	attroff(COLOR_PAIR(24));
	attroff(A_STANDOUT);
	attron(A_BLINK);
	mvprintw(25, 48, "OJO DE JAGUAR");
	attroff(A_BLINK);
	attron(A_STANDOUT);
	mvprintw(38, 2, "Presiona ENTER para continuar...");
	attroff(A_STANDOUT);
	getch();
}

void pantallaInicio()
{

	WINDOW *wmenu = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
	wattron(wmenu, COLOR_PAIR(3));
	box(wmenu, 0, 0);
	wattroff(wmenu, COLOR_PAIR(3));
	wattron(wmenu, A_DIM);
	wattron(wmenu, A_BLINK);
	wattron(wmenu, COLOR_PAIR(5));
	mvwprintw(wmenu, 0, 4, " IG II ");
	mvwprintw(wmenu, 19, 30, " Made by Icarus Black Magic ");
	wattroff(wmenu, COLOR_PAIR(5));
	wattroff(wmenu, A_BLINK);
	wattroff(wmenu, A_DIM);
	wattron(wmenu, A_BOLD);
	wattron(wmenu, COLOR_PAIR(1));
	mvwprintw(wmenu, 5, 28, "JUGAR");
	mvwprintw(wmenu, 8, 24, "INSTRUCCIONES");
	mvwprintw(wmenu, 11, 28, "SALIR");
	wattroff(wmenu, COLOR_PAIR(1));
	wattron(wmenu, COLOR_PAIR(3));
	mvwprintw(wmenu, 17, 2, "Presiona la inicial del menú que deseas...");
	wattroff(wmenu, COLOR_PAIR(3));

	char letra;

	while (letra = wgetch(wmenu))
	{
		switch (letra)
		{
		case 'j':
			werase(wmenu);
			juego();
			break;

		case 'J':
			juego();
			break;

		case 'i':
			wclear(wmenu);
			wattroff(wmenu, A_BLINK);
			wattron(wmenu, COLOR_PAIR(3));
			box(wmenu, 0, 0);
			wattroff(wmenu, COLOR_PAIR(3));
			wattroff(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 0, 3, " JUGAR ");
			mvwprintw(wmenu, 0, 47, " SALIR ");
			wattron(wmenu, A_BLINK);
			wattron(wmenu, A_STANDOUT);
			wattron(wmenu, COLOR_PAIR(17));
			mvwprintw(wmenu, 0, 22, " INSTRUCCIONES ");
			wattroff(wmenu, COLOR_PAIR(17));
			wattroff(wmenu, A_BLINK);
			wattroff(wmenu, A_STANDOUT);
			wattron(wmenu, COLOR_PAIR(7));
			mvwprintw(wmenu, 3, 3, "Hola alma viajera:");
			mvwprintw(wmenu, 5, 3, "Somos los recuerdos de tus antepasados. Sabemos que");
			mvwprintw(wmenu, 6, 3, "puedes tener sentimientos encontrados por lo que");
			mvwprintw(wmenu, 7, 3, "estás pasando.");
			mvwprintw(wmenu, 10, 3, "Te alegrará saber que solamente es un tránsito");
			mvwprintw(wmenu, 11, 3, "pero tendrás que ser valiente.");
			mvwprintw(wmenu, 14, 27, "ATTE: Los que ya se fueron.");
			wattroff(wmenu, COLOR_PAIR(7));
			break;

		case 'I':
			wclear(wmenu);
			wattroff(wmenu, A_BLINK);
			wattron(wmenu, COLOR_PAIR(3));
			box(wmenu, 0, 0);
			wattroff(wmenu, COLOR_PAIR(3));
			wattroff(wmenu, A_STANDOUT);
			mvwprintw(wmenu, 0, 3, " JUGAR ");
			mvwprintw(wmenu, 0, 47, " SALIR ");
			wattron(wmenu, A_BLINK);
			wattron(wmenu, A_STANDOUT);
			wattron(wmenu, COLOR_PAIR(17));
			mvwprintw(wmenu, 0, 22, " INSTRUCCIONES ");
			wattroff(wmenu, COLOR_PAIR(17));
			wattroff(wmenu, A_BLINK);
			wattroff(wmenu, A_STANDOUT);
			wattron(wmenu, COLOR_PAIR(7));
			mvwprintw(wmenu, 3, 3, "Hola alma viajera:");
			mvwprintw(wmenu, 5, 3, "Somos los recuerdos de tus antepasados. Sabemos que");
			mvwprintw(wmenu, 6, 3, "puedes tener sentimientos encontrados por lo que");
			mvwprintw(wmenu, 7, 3, "estás pasando.");
			mvwprintw(wmenu, 10, 3, "Te alegrará saber que solamente es un tránsito");
			mvwprintw(wmenu, 12, 3, "pero tendrás que ser fuerte y seguir tu instinto.");
			mvwprintw(wmenu, 15, 27, "ATTE: Los que ya se fueron.");
			wattroff(wmenu, COLOR_PAIR(7));
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

void juego()
{
	
}