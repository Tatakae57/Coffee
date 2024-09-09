#include <stdio.h>
#include <string.h>

extern unsigned short x, y;
extern char title[];

// Auxiliars
//		Colors
static void con(unsigned short color) {
	attron(COLOR_PAIR(color));
}

static void coff(unsigned short color) {
	attroff(COLOR_PAIR(color));
}

//		Draw
static void draw_line(unsigned short posx, unsigned short posy, unsigned short length) {
	for (unsigned short i = 0; i != length; i++) {
		mvaddch(posy, posx + i, ' ');
	}
}

static void clear_screen() {
	getmaxyx(stdscr, y, x);
	for (unsigned short i = 0; i != y; i++) {
		for (unsigned short j = 0; j != x; j++) {
			mvaddch(i, j, ' ');
		}
	}
}

//		Information
static void draw_title() {
	attron(A_BOLD);
	con(2);
	draw_line(0, 0, x);
	mvprintw(0, x / 2 - strlen(title), "%s", title);
	coff(2);
}

static void draw_command() {
	
}

void draw_tui() {
	draw_title();
	refresh();
}
