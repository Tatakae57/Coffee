#include <ncurses.h>

// Variables
extern unsigned short exit_program, key, current_file, total_files;

// Shortcuts
//		Program
#define EXIT_KEY  27 // Escape
#define RIGHT_FILE 569 // Ctrl-Right
#define LEFT_FILE 554 // Ctrl-Left

//		Files
#define NEW_FILE 14 // Ctrl-N
#define OPEN_FILE 15 // Ctrl-O
#define SAVE_FILE 19 // Ctrl-S
#define SAVE_AS 1 // Ctrl-A
#define CLOSE_FILE 17 // Ctrl-Q

//		Edit
#define UNDO 26 // Ctrl-Z
#define REDO 25 // Ctrl-Y
#define CUT 24 // Ctrl-X
#define PASTE 10 // Ctrl-V

void get_key() {
	key = getch();

	// Verify keys
	switch (key) {
		case EXIT_KEY:
			exit_program = 1;
			break;
		case RIGHT_FILE:
			if (current_file != total_files) current_file++;
			break;
		case LEFT_FILE:
			if (current_file != 0) current_file--;
			break;

		case NEW_FILE:
			new_file(0);
			break;
		case OPEN_FILE:
			break;
		case SAVE_FILE:
			break;
		case SAVE_AS:
			break;
		case CLOSE_FILE:
			if (total_files == 1) exit_program = 1;
			break;

		case UNDO:
			break;
		case REDO:
			break;
		case CUT:
			break;
		case PASTE:
			break;
	}
}
