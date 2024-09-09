#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[]) //argc is an integer parameter for the amount of arguments passed into the program. argv is an array of strings where each string is an argument.
{
    if (argc != 2) { // This if statement checks if the number of arguments is exactly 1 (not 2 because argc automatically adds 1 for the name of the program)
	fprintf(stderr, "usage: cpu <string>\n");
	exit(1);
    }
    char *str = argv[1]; // This line of code essentially stores the reference to an entered argument in the argv array as a char in a different variable called str

    while (1) {
	printf("%s\n", str);
	Spin(1); //Spin command basically makes the program wait for the given amount of time, in this case 1 second.
    }
    return 0; // The program will never reach this line due to the infinite loop happening before it.
}

