#include <stdio.h>

// File data
enum State {
	New,
	Saved
};

struct File {
	enum State state;
	char filename[50];
	unsigned short current_line, total_lines;
	char lines[2000][1000];
};

// Variables
extern struct File files[];
extern unsigned short total_files, current_file;

// Functions
void open_file(char *f_name) {
	FILE *file = fopen(f_name, "w");
}

void new_file(unsigned short program_started) {
	// If the program has already started.
	if (!program_started) {
		total_files++;
		current_file = total_files;
	}
	
	// Update total and index file.
	struct File new_file;
	new_file.state = New;
	sprintf(new_file.filename, "New File");
	new_file.current_line = 1;
	new_file.total_lines = 1;
	files[total_files] = new_file;
}
