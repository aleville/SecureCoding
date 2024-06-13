#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";
    char argOne[BUFSIZE-8] = {0};
    strncat(argOne, argv[1], BUFSIZE-8);
    strncat(cmd, argOne, BUFSIZE-8);
    system(cmd);
}
