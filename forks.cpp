///////////////////////////////////////////////////////////////////
// Student name: Mark Smullen
// Course: COSC 3503 - Operating Systems
// Assignment: #13 - Named Forks Demo
// File name: forks.cpp
// Program's Purpose: To use the four named fork functions
// Program's Limitations: Assumes the user does not input invalid information.
// Development Computer: MacBook Pro 5,5 (Model A1278)
// Operating System:Mac OS X 10.6.7 (Snow Leopard)
// Integrated Development Environment (IDE): VIM
// Compiler: G++
// Program's Operational Status: In progress
///////////////////////////////////////////////////////////////////

// Includes
#include <iostream>
#include <stdlib.h>
// #include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/xattr.h>

// Definitions
#define MAX_BUFFER_SIZE 100
#define MAX_FILENAME_SIZE 50
#define NO_OPTIONS 0

// Function Prototypes
void listAttributes(const char *path, int size);

// Main
int main(int argc, char *argv[]) {
	if (argc == 1 || (strcmp(argv[1], "-l") != 0 && strcmp(argv[1], "-g") != 0 && strcmp(argv[1], "-s") != 0 && strcmp(argv[1], "-r") != 0)) {
		printf("      %s -l <file>\n", argv[0]);
		printf("      %s -g <attribute name> <file>\n", argv[0]);
		printf("      %s -s <attribute name> <attribute value> <file>\n", argv[0]);
		printf("      %s -r <attribute name> <file>\n", argv[0]);
		return 0;
	} // End usage statements
	else {
		// Variables
		int size;
		int status;

		if (strcmp(argv[1], "-l") == 0) {
			printf("Listing extended attributes.\n\n");
			size = listxattr(argv[2], NULL, 0, NO_OPTIONS);
			listAttributes(argv[2], size * MAX_FILENAME_SIZE);
		} // End list entry
		else if (strcmp(argv[1], "-g") == 0) {
			printf("Getting extended attributes.\n\n");
		} // End get entry
		else if (strcmp(argv[1], "-s") == 0) {
			printf("Setting extended attributes.\n\n");
		} // End set entry
		else if (strcmp(argv[1], "-r") == 0) {
			printf("Removing extended attributes.\n\n");
		} // End remove entry
		else {
			printf("Error in input! We should have never gotten here; aborting.\n\n");
			return 1;
		}
	}

	return 0;
} // End main

// Function Definitions

// ################################################
void listAttributes(const char *path, int size) {
	// Variables
	int statussize;
	char buffer[size];

	statussize = listxattr(

	printf("size: %d\n", size);
}

// ################################################
// getAttribute(