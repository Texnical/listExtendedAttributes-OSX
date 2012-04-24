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
#include <string>
#include <stdlib.h>
// #include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/xattr.h>
using namespace std;

// Definitions
#define MAX_BUFFER_SIZE 100
#define MAX_FILENAME_SIZE 50
#define NO_OPTIONS 0

// Function Prototypes
void listAttributes(const char *path, int size);
void getAttribute(const char *path, const char *attributeName, int size);

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
		int status;

		printf("\n");

		if (strcmp(argv[1], "-l") == 0) {
			status = listxattr(argv[2], NULL, 0, NO_OPTIONS);
			listAttributes(argv[2], status);
		} // End list entry
		else if (strcmp(argv[1], "-g") == 0) {
			status = getxattr(argv[3], argv[2], NULL, NULL, 0, NO_OPTIONS);
			getAttribute(argv[3], argv[2], status);
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
	int status;
	char buffer[size];

	status = listxattr(path, buffer, size, XATTR_SHOWCOMPRESSION);

	if (status == 0) {
		printf("No extended attributes exist for %s.\n", path);
	} // End no-ext-attribs
	else if (status == -1) {
		perror("An error occurred while retrieving the list of extended attributes for the file(s) given");
	} // End error-listing-ext-attribs
	else {
		// Variables
		char *attribute;

		printf("Listing extended attributes for %s:\n\n", path);

		for (int i = 0; i < size; i++)
			if (buffer[i] == '\0')
				buffer[i] = '\n';

		attribute = strtok(buffer, "\n");
		while (attribute) {
			printf("%s\n", attribute);
			attribute = strtok(NULL, "\0");
		}
	} // End list-ext-attribs 
} // End List Attributes

// ################################################
void getAttribute(const char *path, const char *attributeName, int size) {
	// Variables
	int status;
	char buffer[size];

	status = getxattr(path, attributeName, buffer, size, 0, XATTR_SHOWCOMPRESSION);

	if (status == -1) {
		perror("An error occurred while retrieving the value of the extended attribute for the file given");
	} // End bad-ext-attrib
	else {
		printf("Getting extended attribute %s for %s:\n\n", attributeName, path);
		printf("%s\n\n", buffer);
	} // End get-ext-attrib
} // End Get Attribtues
