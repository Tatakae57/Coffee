#include "files.h"
#include "keyboard.h"
#include <ncurses.h>
#include "screen.h"

// Variables
unsigned short x, y, exit_program = 0, key, total_files = 0, current_file = 0, cmd = 0;
char title[50];

// Structs
struct File files[10];

// Functions
void init_program() {
	initscr();
	raw();
	curs_set(FALSE);
	noecho();
	keypad(stdscr, TRUE);
}

void init_colors() {
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
}

void get_files(unsigned short f_index, char **f_names) {
	if (f_index > 1) {
		for (unsigned short i = 1; i != f_index; i++)
			open_file(f_names[i]); // Try to open every file name received.
	}
	else new_file(1);
	sprintf(title, "%s", files[0].filename);
}

int main(unsigned short f_index, char **f_names) {
	// Start program
	init_program();
	init_colors();
	
	// Get files from command line
	get_files(f_index, f_names);

	// Loop
	while (!exit_program) {
		clear_screen();
		mvprintw(10, 10, "Key: %d| Current File: %d | Total Files: %d", key, current_file, total_files);
		draw_tui();
		get_key();
	}
	endwin();
	return 0;
}
